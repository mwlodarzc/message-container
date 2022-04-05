#ifndef VECTOR_HH
#define VECTOR_HH
#include <stdexcept>
#include <iostream>
// Vector class based on Extandable Array
template <typename T>
class Vector
{
private:
    int capacity;      // current array size;
    int n_of_elements; // number of elements in vector
    T *elements;

public:
    // inline
    Vector() : capacity(0), n_of_elements(0), elements(NULL) {}
    Vector(T *e, size_t arr_size); // check in tests
    ~Vector() { delete elements; };
    int size() const { return n_of_elements; }
    bool empty() const { return (n_of_elements == 0); }
    T &operator[](int i) { return at(i); }
    T &at(int i);
    void set(int i, const T &elem) { elements[i] = elem; }

    // tbd
    void insert(int i, const T &elem);
    void erase(int i);
    void reserve(int N);
};
template <typename T>
Vector<T>::Vector(T *e, size_t arr_size)
{
    elements = new T[arr_size];
    for (long unsigned int i = 0; i < arr_size; i++)
        elements[i] = e[i];
    n_of_elements = arr_size;
    capacity = arr_size;
}

template <typename T>
T &Vector<T>::at(int i)
{
    if (i < 0 || i >= n_of_elements)
        throw std::out_of_range("Indexed array element is out of range!");
    return elements[i];
}

template <typename T>
void Vector<T>::erase(int i)
{
    for (int j = i + 1; j < n_of_elements; j++)
        elements[j - 1] = elements[j];
    n_of_elements--;
}

template <typename T>
void Vector<T>::reserve(int N)
{
    if (capacity >= N)
        return;
    T *elements_tmp = new T[N];
    for (int j = 0; j < n_of_elements; j++)
        elements_tmp[j] = elements[j];
    if (elements != NULL)
        delete[] elements;
    elements = elements_tmp;
    capacity = N;
}

template <typename T>
void Vector<T>::insert(int i, const T &elem)
{
    if (n_of_elements >= capacity)
        reserve(std::max(1, 2 * capacity));
    for (int j = n_of_elements - 1; j >= i; j--)
        elements[j + 1] = elements[j];
    elements[i] = elem;
    n_of_elements++;
}
#endif