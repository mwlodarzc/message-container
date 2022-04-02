#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH
#include "DoublyLinkedList.hh"

template <typename T, typename C>
class PriorityQueue
{
private:
    DoublyLinkedList<T> list;
    int _size_ = 0;

public:
    int size() const { return _size_; };
    bool empty() const { return list.empty(); };
    void insert(const T &elem);
    const T &min() const;
    const T &removeMin() const;
};

template <typename T, typename C>
void PriorityQueue<T, C>::insert(const T &elem)
{
    if (list.empty())
        list.addFront(elem);
    else
    {
        
    }
}

template <typename T, typename C>
const T &PriorityQueue<T, C>::min() const
{
}
template <typename T, typename C>
const T &PriorityQueue<T, C>::removeMin() const
{
}
#endif