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
    Position(Node<T> *n_ = NULL) : n(n_) {}
    const T &operator*() { return n->element; }
    Position left() const { return Position(n->left); }
    Position right() const { return Position(n->right); }
    Position parent() const { return Position(n->parent); }
    bool isRoot() const { return n->parent == NULL; }
    bool isExternal() const { return n->left == NULL && n->right == NULL; }
};
#endif