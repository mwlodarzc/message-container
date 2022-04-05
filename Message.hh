#ifndef VECTOR_HH
#define VECTOR_HH
#include <stdexcept>
// Vector class based on Extandable Array
template <typename T>
class Vector
{
private:
    int capacity;      // current array size;
    int n_of_elements; // number of elements in vector
    T *elements;

public:
    Vector() : capacity(0), n_of_elements(0), A(NULL) {}
    int size() const { return n_of_elements; }
    bool empty() const { return (n_of_elements == 0); }
    T &operator[](int i) { return at(i); }
    T &at(int i) { return (i < n_of_elements) ? elements[i] : throw : std::out_of_range("Indexed value is outside Vector!"); }
};
#endif