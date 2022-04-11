#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH
#include "BinaryTree.hh"

template <typename T>
class PriorityQueue
{
private:
    BinaryTree<T> elements;
    bool isLess(const T &first, const T &second)
    {
        return first < second;
    }

public:
    int size() const;
    bool empty() const;
    void insert(const T &elem);
    const T &min();
    void removeMin() const;
};
template <typename T>
int PriorityQueue<T>::size() const { return elements.size(); }

template <typename T>
bool PriorityQueue<T>::empty() const { return this->size() == 0; }

template <typename T>
const T &PriorityQueue<T>::min() { return **elements.root(); }

template <typename T>
void PriorityQueue<T>::insert(const T &elem)
{
    elements.addLast(elem);
    typename BinaryTree<T>::iter last_elem = elements.last();
    while (!elements.isRoot(last_elem))
    {
        typename BinaryTree<T>::iter parent_elem = elements.parent(last_elem);
        if (!isLess(**parent_elem, **last_elem))
            break;
        elements.swap(last_elem, parent_elem);
        last_elem = parent_elem;
    }
}

template <typename T>
void PriorityQueue<T>::removeMin() const
{
    if (this->size() == 1)
        elements.removeLast();
    else
    {
        typename BinaryTree<T>::iter tmp = elements.root();
        elements.swap(tmp, elements.last());
        elements.removeLast();
        while (elements.hasLeft(tmp))
        {
            typename BinaryTree<T>::iter tmp_child = elements.left(tmp);
            if (elements.hasRight(tmp) && isLess(**elements.right(tmp), **tmp_child))
                tmp_child = elements.right(tmp);
            if (isLess(*tmp_child, *tmp))
            {
                elements.swap(tmp, tmp_child);
                tmp = tmp_child;
            }
            else
                break;
        }
    }
}
#endif