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
    BinaryTree() : positions(1), _root(NULL)
    {
        positions.insert(0, NULL);
    }
    int size() const;
    Position<T> left(const Position<T> &p);
    Position<T> right(const Position<T> &p);
    Position<T> parent(const Position<T> &p);
    bool hasLeft(const Position<T> &p);
    bool hasRight(const Position<T> &p);
    bool isRoot(const Position<T> &p);
    Position<T> root();
    Position<T> last();
    void addLast(const T &elem);
    void removeLast();
    void swap(Position<T> &p, Position<T> &q);

public:
    typedef typename Vector<Position<T>>::Iterator iter;
    Position<T> pos(int i);
    int idx(const Position<T> &p);
};
template <typename T>
Position<T> BinaryTree<T>::pos(int i)
{
    iter it(positions.begin());
    return *(it[i]);
}

template <typename T>
int BinaryTree<T>::idx(const Position<T> &p)
{
    iter it(&p);
    return positions.end() - positions.begin();
}

template <typename T>
int BinaryTree<T>::size() const { return positions.size() - 1; } // unsure

template <typename T>
Position<T> BinaryTree<T>::left(const Position<T> &p) { return (pos(2 * idx(p))); }

template <typename T>
Position<T> BinaryTree<T>::right(const Position<T> &p) { return (pos(2 * idx(p) + 1)); }

template <typename T>
Position<T> BinaryTree<T>::parent(const Position<T> &p) { return (pos(idx(p) / 2)); }

template <typename T>
bool BinaryTree<T>::hasLeft(const Position<T> &p) { return 2 * idx(p) <= size(); }

template <typename T>
bool BinaryTree<T>::hasRight(const Position<T> &p) { return 2 * idx(p) + 1 <= size(); }

template <typename T>
bool BinaryTree<T>::isRoot(const Position<T> &p) { return idx(p) == 1; }

template <typename T>
Position<T> BinaryTree<T>::root()
{
    if (size() == 0)
        throw(std::range_error("Binary Tree is empty!"));
    return positions[1];
}

template <typename T>
Position<T> BinaryTree<T>::last()
{
    if (size() == 0)
        throw(std::range_error("Binary Tree is empty!"));
    return positions[size()];
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
void BinaryTree<T>::swap(Position<T> &p, Position<T> &q)
{
    T tmp = *q;
    *q = *p;
    *p = tmp;
}
#endif