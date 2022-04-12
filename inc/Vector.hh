#ifndef VECTOR_HH
#define VECTOR_HH
#include <stdexcept>
#include <iostream>
/*!
 * @file Vector.hh
 *  Vector class based on Extandable Array.
 */

/*!
 * @brief Vetor class with nested Iterator class.
 */
template <typename T>
class Vector
{
private:
    /*!
     * @brief Alocated aray size.
     */
    int capacity;

    /*!
     * @brief Number of elements curently stored in vector.
     */
    int n_of_elements;

    /*!
     * @brief Pointer to template typename T that acts as an array.
     */
    T *elements;

public:
    /*!
     * @brief Iterator class used for going through vector elements.
     */
    class Iterator
    {
    private:
        /*!
         * @brief Pointer to template typename T that points to the current indexed element.
         */
        T *current_element;

    public:
        /*!
         * @brief Constructor for Iterator class
         * @param cur Pointer to curent element held in another Iterator object.
         */
        Iterator(T *cur) : current_element(cur) {}
        /*!
         * @brief Const constructor for Iterator class
         * @param cur Const pointer to curent element held in another Iterator object.
         */
        Iterator(const T *cur);
        /*!
         * @brief Pre-increment iterator operator overload.
         * @return Iterator reference
         */
        Iterator &operator++();
        /*!
         * @brief Post-increment iterator operator overload.
         * @return Iterator copy
         */
        Iterator operator++(int);
        /*!
         * @brief Pre-decriment iterator operator overload.
         * @return Iterator reference
         */
        Iterator &operator--();
        /*!
         * @brief Post-decriment iterator operator overload.
         * @return Iterator copy
         */
        Iterator operator--(int);
        /*!
         * @brief Subtraction. Difference operator overload between two iterators. Doesn't change the object.
         * @param iter Subtracted iterator.
         * @return Subtraction value;
         */
        int operator-(const Iterator &iter) const;
        /*!
         * @brief Operator overload that returns iterator.
         * @param i index of iterator to be returned.
         * @return Iterator at index i.
         */
        Iterator operator[](int i) const;
        /*!
         * @brief Operator overload that returns iterator pointer.
         * @return returnes curent iterator pointer.
         */
        Iterator *operator->();
        /*!
         * @brief Operator overload that returns value
         * @return curent iterators value.
         */
        T &operator*() const;
        /*!
         * @brief Operator overload that bool value.
         * @param iter iterator object.
         * @return true if object equals iter.
         */
        bool operator==(const Iterator &iter) const;
        /*!
         * @brief Operator overload that bool value.
         * @param iter iterator object.
         * @return true if object not equals iter.
         */
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