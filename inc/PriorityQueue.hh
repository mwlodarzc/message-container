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
    const T &min() const;
    void removeMin() const;
};
template <typename T>
int PriorityQueue<T>::size() const { return elements.size(); }

template <typename T>
bool PriorityQueue<T>::empty() const { return this->size() == 0; }

template <typename T>
const T &PriorityQueue<T>::min() const { return *elements.root(); }

template <typename T>
void PriorityQueue<T>::insert(const T &elem)
{
    elements.addLast(elem);
    Position<T> elem_pos = elements.last();
    while (!elements.isRoot(elem_pos))
    {
        Position<T> tmp = elements.parent(elem_pos);
        if (!isLess(*elem_pos, *tmp))
            break;
        elements.swap(elem_pos, tmp);
        elem_pos = tmp;
    }
}

template <typename T>
void PriorityQueue<T>::removeMin() const
{
    if (this->size() == 1)
        elements.removeLast();
    else
    {
        Position<T> tmp = elements.root();
        elements.swap(tmp, elements.last());
        elements.removeLast();
        while (elements.hasLeft(tmp))
        {
            Position<T> tmp_child = elements.left(tmp);
            if (elements.hasRight(tmp) && isLess(*elements.right(tmp), *tmp_child))
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