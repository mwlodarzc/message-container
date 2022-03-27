#ifndef CIRCLE_LIST_HH
#define CIRCLE_LIST_HH
#include <stdexcept>
#include "Node.hh"

template <typename T>
class CircleList
{
private:
    Node<T> *cursor;

public:
    CircleList() { cursor = nullptr; };               // ready
    ~CircleList() { delete cursor; }                  // check if any left and if function leaks anything
    bool empty() const;                               // ready
    const T &front() const;                           // think about using exceptions for error checking
    const T &back() const;                            // think about using exceptions for error checking
    void advance() { cursor = &cursor->get_next(); }; // check what happens when only one element is on the list
    void add(const T &new_elem);
    void remove();
};
template <typename T>
bool CircleList<T>::empty() const
{
    if (cursor == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
const T &CircleList<T>::front() const
{
    if (empty())
        throw std::out_of_range("List is empty!");
    return cursor->get_elem();
}

template <typename T>
const T &CircleList<T>::back() const
{
    if (empty())
        throw std::out_of_range("List is empty!");
    return cursor->get_next().get_elem();
}

template <typename T>
void CircleList<T>::add(const T &new_elem)
{
    Node<T> *new_node = new Node(new_elem);
    if (empty())
    {
        new_node->set_next(*new_node);
        cursor = new_node;
    }
    else
    {
        new_node->set_next(cursor->get_next());
        cursor->set_next(*new_node);
        advance();
    }
}

template <typename T>
void CircleList<T>::remove()
{
    Node<T> *tmp = NULL;
    if (empty())
        throw std::out_of_range("List is empty!");
    else
    {
        if (&cursor->get_next() == cursor)
        {
            delete cursor;
            cursor = nullptr;
        }
        else
        {
            tmp = &cursor->get_next().get_next();
            delete &(cursor->get_next());
            cursor->set_next(*tmp);
            tmp = NULL;
        }
    }
}
#endif