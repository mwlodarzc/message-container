#ifndef POSITION_HH
#define POSITION_HH
#include "Node.hh"

// value created and exists are used only for checking if the memory is leaked and should be deleted from the final project
template <typename T>
class Position : public Node<T>
{
private:
    Node<T> *n;

public:
    Position()
    {
        n = new Node<T>();
    }
    Position(const Position &pos)
    {
        n->element = pos.element;
    }
    Position(Node<T> *n_) : n(n_) {}
    T operator*()
    {
        std::cout << n->get_elem();
        return n->get_elem();
    }
    Position left() const { return Position(n->left); }
    Position right() const { return Position(n->right); }
    Position parent() const { return Position(n->parent); }
    bool isRoot() const { return n->parent == NULL; }
    bool isExternal() const { return n->left == NULL && n->right == NULL; }
};
#endif