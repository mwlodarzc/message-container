#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH
#include "BinaryTree.hh"

template <typename T, typename C>
class PriorityQueue
{
private:
    BinaryTree<T> elements;
    C comparator;

public:
    int size() const;
    bool empty() const;
    void insert(const T &elem);
    const T &min();
    void removeMin();
};
template <typename T, typename C>
int PriorityQueue<T, C>::size() const { return elements.size(); }

template <typename T, typename C>
bool PriorityQueue<T, C>::empty() const { return this->size() == 0; }

template <typename T, typename C>
const T &PriorityQueue<T, C>::min() { return **elements.root(); }

template <typename T, typename C>
void PriorityQueue<T, C>::insert(const T &elem)
{
    elements.addLast(elem);
    typename BinaryTree<T>::iter last_elem = elements.last();
    while (!elements.isRoot(last_elem))
    {
        typename BinaryTree<T>::iter parent_elem = elements.parent(last_elem);
        if (!comparator.compare(*last_elem, *parent_elem))
            break;
        elements.swap(last_elem, parent_elem);
        last_elem = parent_elem;
    }
}

template <typename T, typename C>
void PriorityQueue<T, C>::removeMin()
{
    if (this->size() == 1)
        elements.removeLast();
    else
    {
        typename BinaryTree<T>::iter parent_elem = elements.root();
        typename BinaryTree<T>::iter last_elem = elements.last();
        elements.swap(parent_elem, last_elem);
        elements.removeLast();
        while (elements.hasLeft(parent_elem))
        {
            typename BinaryTree<T>::iter child_elem = elements.left(parent_elem);
            if (elements.hasRight(parent_elem) && comparator.compare(*elements.right(parent_elem), *child_elem))
                child_elem = elements.right(parent_elem);
            if (comparator.compare(*child_elem, *parent_elem))
            {
                elements.swap(parent_elem, child_elem);
                parent_elem = child_elem;
            }
            else
                break;
        }
    }
}
#endif