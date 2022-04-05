#ifndef LINKED_BINARY_TREE_HH
#define LINKED_BINARY_TREE_HH
#include <stdexcept>
#include "Position.hh"

template <typename T>
class LinkedBinaryTree : public Position<T>
{
private:
    Node *_root;
    int n;

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

#endif