#ifndef BINARY_TREE_HH
#define BINARY_TREE_HH
#include <stdexcept>
#include "Position.hh"
#include "Vector.hh"

template <typename T>
class BinaryTree
{
private:
    Vector<Position<T>> positions;
    Node<T> *_root;

public:
    typedef typename Vector<Position<T>>::Iterator iter;

    BinaryTree() : positions(1), _root(NULL) // works
    {
        Node<T> *tmp = new Node<T>(0);
        Position<T> *tmp_pos = new Position<T>(tmp);
        positions.insert(0, *tmp_pos);
    }
    int size() const; // works
    iter left(const iter &p);
    iter right(const iter &p);
    iter parent(const iter &p);
    bool hasLeft(const iter &p);  // works
    bool hasRight(const iter &p); // works
    bool isRoot(const iter &p);   // works
    iter root();
    iter last();
    void addLast(const T &elem);
    void removeLast();
    void swap(iter &p, iter &q);

public:
    iter pos(int i);
    int idx(const iter &p);
};
template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::pos(int i)
{
    iter it(positions.begin());
    return (it[i]);
}

template <typename T>
int BinaryTree<T>::idx(const typename BinaryTree<T>::iter &p)
{
    // std::cout << p - position.begin() << std::endl;
    return p - positions.begin();
}

template <typename T>
int BinaryTree<T>::size() const { return positions.size() - 1; } // unsure

template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::left(const typename BinaryTree<T>::iter &p)
{
    if (!hasLeft(p))
        throw(std::range_error("Position doesnt have a left Node"));
    return (pos(2 * idx(p)));
}

template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::right(const typename BinaryTree<T>::iter &p)
{
    if (!hasRight(p))
        throw(std::range_error("Position doesnt have a right Node"));

    return (pos(2 * idx(p) + 1));
}

template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::parent(const typename BinaryTree<T>::iter &p)
{
    if (isRoot(p))
        throw(std::range_error("Root's parent cannot be accessed"));
    return (pos(idx(p) / 2));
}

template <typename T>
bool BinaryTree<T>::hasLeft(const typename BinaryTree<T>::iter &p) { return 2 * idx(p) <= size(); }

template <typename T>
bool BinaryTree<T>::hasRight(const typename BinaryTree<T>::iter &p) { return 2 * idx(p) + 1 <= size(); }

template <typename T>
bool BinaryTree<T>::isRoot(const typename BinaryTree<T>::iter &p) { return idx(p) == 1; }

template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::root()
{
    iter it(positions.begin());
    if (size() == 0)
        throw(std::range_error("Binary Tree is empty!"));
    return it[1];
}

template <typename T>
typename BinaryTree<T>::iter BinaryTree<T>::last()
{
    iter it(positions.begin());
    if (size() == 0)
        throw(std::range_error("Binary Tree is empty!"));
    return it[size()];
}

template <typename T>
void BinaryTree<T>::addLast(const T &elem)
{
    Node<T> *tmp = new Node<T>(elem);
    Position<T> *tmp_pos = new Position<T>(tmp);
    positions.insert(positions.size(), *tmp_pos);
}

template <typename T>
void BinaryTree<T>::removeLast()
{
    if (size() == 0)
        throw(std::range_error("Binary Tree is empty!"));
    positions.erase(size());
}

template <typename T>
void BinaryTree<T>::swap(BinaryTree<T>::iter &p, BinaryTree<T>::iter &q)
{
    T tmp = **q;
    **q = **p;
    **p = tmp;
}
#endif