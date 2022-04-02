#ifndef DOUBLY_LINKED_LIST_HH
#define DOUBLY_LINKED_LIST_HH
#include <stdexcept>
#include "Node.hh"

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *header;
    Node<T> *trailer;

protected: // protected members declared here beacause of possible specialization errors
    void add(Node<T> *node, const T &elem)
    {
        Node<T> *tmp = new Node<T>(elem);
        tmp->set_next(*node);
        tmp->set_prev(node->get_prev());
        node->get_prev().set_next(*tmp);
        node->set_prev(*tmp);
        tmp = nullptr;
    }

    void remove(Node<T> *v)
    {
        v->get_prev().set_next(v->get_next());
        v->get_next().set_prev(v->get_prev());
        delete v;
    }

public:
    DoublyLinkedList();           // working
    ~DoublyLinkedList();          // working
    bool empty() const;           // working
    const T &front() const;       // working
    const T &back() const;        // working
    void addFront(const T &elem); // working
    void addBack(const T &elem);  // working
    void removeFront();           // working
    void removeBack();            // working
};

template <typename T>
bool DoublyLinkedList<T>::empty() const
{
    if (&header->get_next() == trailer)
        return true;
    return false;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    header = new Node<T>;
    trailer = new Node<T>;
    header->set_next(*trailer);
    trailer->set_prev(*header);
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (!this->empty())
        removeFront();
    delete header;
    delete trailer;
}

template <typename T>
const T &DoublyLinkedList<T>::front() const
{
    if (this->empty())
        throw std::out_of_range("List is empty!");
    return header->get_next().get_elem();
}

template <typename T>
const T &DoublyLinkedList<T>::back() const
{
    if (this->empty())
        throw std::out_of_range("List is empty!");
    return trailer->get_prev().get_elem();
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T &elem)
{
    this->add(&header->get_next(), elem);
    // Node<T> *tmp = new Node<T>(elem);
    // tmp->set_next(header->get_next());
    // tmp->set_prev(*header);
    // header->get_next().set_prev(*tmp);
    // header->set_next(*tmp);
    // tmp = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T &elem)
{
    this->add(trailer, elem);
    // Node<T> *tmp = new Node<T>(elem);
    // tmp->set_next(*trailer);
    // tmp->set_prev(trailer->get_prev());
    // trailer->get_prev().set_next(*tmp);
    // trailer->set_prev(*tmp);
    // tmp = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::removeFront()
{
    this->remove(&(header->get_next()));
    // Node<T> *tmp = nullptr;
    // if (this->empty())
    //     throw std::out_of_range("List is empty!");
    // tmp = &header->get_next();
    // header->get_next().get_next().set_prev(*header);
    // header->set_next(header->get_next().get_next());
    // delete tmp;
    // tmp = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::removeBack()
{
    this->remove(&trailer->get_prev());
    // Node<T> *tmp = nullptr;
    // if (this->empty())
    //     throw std::out_of_range("List is empty!");
    // tmp = &trailer->get_prev();
    // trailer->get_prev().get_prev().set_next(*trailer);
    // trailer->set_prev(trailer->get_prev().get_prev());
    // delete tmp;
    // tmp = nullptr;
}

#endif