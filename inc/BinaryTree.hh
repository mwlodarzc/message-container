#ifndef BINARY_TREE_HH
#define BINARY_TREE_HH
#include <stdexcept>
#include "Position.hh"
#include "Vector.hh"
/*!
 * @brief BinaryTree class implementation
 */
template <typename T>
class BinaryTree
{
private:
    /*!
     * @brief Vector of elements in binary tree (positions).
     */
    Vector<Position<T>> positions;
    /*!
     * @brief First position in binary tree. // unused in this implememntation / only for form completion
     */
    Node<T> *_root;

public:
    /*!
     * @brief Iterator class type specifier used for shorter implementation
     */
    typedef typename Vector<Position<T>>::Iterator iter;

    /*!
     * @brief No parameter constructor. Inserts one element into positions vector
     */
    BinaryTree() : positions(1), _root(NULL) // works
    {
        Node<T> *tmp = new Node<T>();
        Position<T> *tmp_pos = new Position<T>(tmp);
        positions.insert(0, *tmp_pos);
    }
    /*!
     * @brief Size return method.
     */
    int size() const; // works
    /*!
     * @brief Return left position iterator in a tree from current position iterator method
     */
    iter left(const iter &p);
    /*!
     * @brief Return right position iterator in a tree from current position iterator method
     */
    iter right(const iter &p);
    /*!
     * @brief Return parent position iterator in a tree from current position iterator method
     */
    iter parent(const iter &p);
    /*!
     * @brief Check for left position iterator from current position iterator method.
     */
    bool hasLeft(const iter &p);
    /*!
     * @brief Check for right position iterator from current position iterator method.
     */
    bool hasRight(const iter &p);
    /*!
     * @brief Check if curent position iterator is the root position iterator method.
     */
    bool isRoot(const iter &p);
    /*!
     * @brief Root position iterator return method.
     */
    iter root();
    /*!
     * @brief Last position iterator return method.
     */
    iter last();
    /*!
     * @brief Add in last element method.
     */
    void addLast(const T &elem);
    /*!
     * @brief remove last element method.
     */
    void removeLast();
    /*!
     * @brief Swap two iterator position specified in parameters method.
     * @param p First iterator position.
     * @param q Second iterator position.
     */
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
bool BinaryTree<T>::hasLeft(const typename BinaryTree<T>::iter &p)
{
    return 2 * idx(p) <= size();
}

template <typename T>
bool BinaryTree<T>::hasRight(const typename BinaryTree<T>::iter &p)
{
    return 2 * idx(p) + 1 <= size();
}

template <typename T>
bool BinaryTree<T>::isRoot(const typename BinaryTree<T>::iter &p)
{
    return idx(p) == 1;
}

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