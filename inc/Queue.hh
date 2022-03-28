#ifndef QUEUE_HH
#define QUEUE_HH
#include "CircleList.hh"

template <typename T>
class Queue
{
private:
    CircleList<T> list;
    int _size = 0;

public:
    int size() const { return _size; };
    bool empty() const { return list.empty(); };
    void enqueue(const T &e);
    void dequeue();
    const T &front() const;
};

template <typename T>
void Queue<T>::enqueue(const T &e)
{
    list.add(e);
    _size++;
}

template <typename T>
void Queue<T>::dequeue()
{
    try
    {
        list.remove();
    }
    catch (const std::out_of_range &e)
    {
        throw std::out_of_range("Queue empty!");
    }
    _size--;
}
template <typename T>
const T &Queue<T>::front() const
{
    try
    {
        return list.back();
    }
    catch (const std::out_of_range &e)
    {
        throw std::out_of_range("Queue empty!");
    }
}

#endif