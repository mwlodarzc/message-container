#ifndef BINARY_TREE_HH
#define BINARY_TREE_HH
#include <stdexcept>
#include "Position.hh"
#include "Vector.hh"

template <typename T>
class BinaryTree : public Position<T>
{
private:
    Vector<Position<T>> nodes;
    Node<T> *_root;

public:
    BinaryTree() : nodes(1), _root(NULL)
    {
        nodes.insert(0, NULL);
    }
    int size() const;
    Position<T> left(const Position<T> &p);
    Position<T> right(const Position<T> &p);
    Position<T> parent(const Position<T> &p);
    bool hasLeft(const Position<T> &p) const;
    bool hasRight(const Position<T> &p) const;
    bool isRoot(const Position<T> &p) const;
    Position<T> root();
    Position<T> last();
    void addLast(const T &elem);
    void removeLast();
    void swap(Position<T> &p, Position<T> &q);

public:
    Position<T> pos(int i);
    int idx(const Position<T> &p) const;
};
template <typename T>
Position<T> BinaryTree<T>::pos(int i)
{
    return nodes[i];
} // unsure

template <typename T>
int BinaryTree<T>::idx(const Position<T> &p) const
{
    std::cout << p - nodes[0] << std::endl;
    return p - nodes[0];
}

template <typename T>
int BinaryTree<T>::size() const { return nodes.size() - 1; } // unsure

template <typename T>
Position<T> BinaryTree<T>::left(const Position<T> &p) { return pos(2 * idx(p)); }

template <typename T>
Position<T> right(const Position<T> &p) { return pos(2 * idx(p) + 1); }

template <typename T>
Position<T> BinaryTree<T>::parent(const Position<T> &p) { return pos(idx(p) / 2); }

template <typename T>
bool BinaryTree<T>::hasLeft(const Position<T> &p) const { return 2 * idx(p) <= size(); }

template <typename T>
bool BinaryTree<T>::hasRight(const Position<T> &p) const { return 2 * idx(p) + 1 <= size(); }

template <typename T>
bool BinaryTree<T>::isRoot(const Position<T> &p) const { return idx(p) == 1; }

template <typename T>
Position<T> BinaryTree<T>::root() { return pos(1); }

template <typename T>
Position<T> BinaryTree<T>::last()
{
    return nodes[2];
}

template <typename T>
void BinaryTree<T>::addLast(const T &elem)
{
    Node<T> *tmp = new Node<T>(elem);
    Position<T> *tmp_pos = new Position<T>(tmp);
    std::cout << tmp_pos->operator*() << std::endl;
    nodes.insert(nodes.size(), tmp_pos);
}

template <typename T>
void BinaryTree<T>::removeLast() { nodes.erase(nodes.size()); }

template <typename T>
void BinaryTree<T>::swap(Position<T> &p, Position<T> &q)
{
    T tmp = *q;
    *q = *p;
    *p = tmp;
}
#endif