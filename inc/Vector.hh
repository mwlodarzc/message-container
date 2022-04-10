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
    class Iterator
    {
    private:
        T *current_element;

    public:
        Iterator(T *cur) : current_element(cur) {}
        Iterator(const T *cur);
        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
        int operator-(const Iterator &iter) const;
        Iterator operator[](int i) const;
        Iterator *operator->();
        T &operator*() const;
        bool operator==(const Iterator &iter) const;
        bool operator!=(const Iterator &iter) const;
    };

public:
    // inline
    Vector() : capacity(0), n_of_elements(0), elements(NULL) {}
    Vector(T *e, size_t arr_size); // check in tests
    Vector(int i);
    ~Vector();
    int size() const;
    bool empty() const;
    T &at(int i);
    void set(int i, const T &elem);
    void insert(int i, const T &elem);
    void erase(int i);
    void reserve(int N);
    T &operator[](int i) { return at(i); }
    Iterator begin();
    Iterator end();
};
template <typename T>
Vector<T>::Vector(int i)
{
    elements = new T[i];
    capacity = i;
    n_of_elements = 0;
}
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
Vector<T>::~Vector() {}

template <typename T>
int Vector<T>::size() const { return n_of_elements; }

template <typename T>
bool Vector<T>::empty() const { return (n_of_elements == 0); }

template <typename T>
T &Vector<T>::at(int i)
{
    if (i < 0 || i >= n_of_elements)
        throw std::out_of_range("Indexed array element is out of range!");
    return elements[i];
}

template <typename T>
void Vector<T>::set(int i, const T &elem) { elements[i] = elem; }

template <typename T>
void Vector<T>::erase(int i)
{
    if (i < 0 || i >= n_of_elements)
        throw std::out_of_range("Indexed array element is out of range!");
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

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return Iterator(elements);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return Iterator(elements + n_of_elements);
}
template <typename T>
Vector<T>::Iterator::Iterator(const T *cur)
{
    current_element = (T *)cur;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator++()
{
    current_element++;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator--()
{
    current_element--;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
int Vector<T>::Iterator::operator-(const Iterator &iter) const
{
    return current_element - iter.current_element;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator[](int i) const
{

    return (current_element + i);
}

template <typename T>
typename Vector<T>::Iterator *Vector<T>::Iterator::operator->()
{
    return current_element;
}

template <typename T>
T &Vector<T>::Iterator::operator*() const
{
    return *current_element;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const Iterator &iter) const
{
    return current_element == iter.current_element;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator &iter) const
{
    return !(current_element == iter.current_element);
}
#endif