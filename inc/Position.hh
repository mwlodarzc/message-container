#ifndef POSITION_HH
#define POSITION_HH
#include "Node.hh"

// value created and exists are used only for checking if the memory is leaked and should be deleted from the final project
template <typename T>
class Position
{
private:
    Node<T> *n;
    Node<T> *get_node() { return n; }

public:
    Position() { n = NULL; };
    T &operator*() { return n->get_element(); }
    Position(Position &pos) : n(pos.get_node()){};
    Position(Node<T> *n_) : n(n_){};
    Position left() const { return Position(n->get_left()); }
    Position right() const { return Position(n->get_right()); }
    Position parent() const { return Position(n->get_parent()); }
    bool isRoot() const { return n->get_parent() == NULL; }
    bool isExternal() const { return *n->get_left() == NULL && n->get_right() == NULL; }
};
#endif