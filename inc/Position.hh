#ifndef POSITION_HH
#define POSITION_HH
#include "Node.hh"

template <typename T> // works
class Position
{
private:
    Node<T> *n;
    const Node<T> *get_node() const { return n; }

public:
    Position() { n = NULL; }; // works
    T &operator*() { return n->get_element(); }
    Position(Position &pos) : n((Node<T> *)pos.get_node()){};                           // works
    Position(Node<T> *n_) : n(n_){};                                                    // works
    Position(const Node<T> *n_) : n((Node<T> *)n_){};                                   // works
    Position get_left() const { return Position(n->get_left()); }                       // works
    Position get_right() const { return Position(n->get_right()); }                     // works
    Position get_parent() const { return Position(n->get_parent()); }                   // works
    void set_left(const Position *left_) { n->set_left(left_->get_node()); }            // works
    void set_right(const Position *right_) { n->set_right(right_->get_node()); }        // works
    void set_parent(const Position *parent_) { n->set_parent(parent_->get_node()); }    // works
    bool isRoot() const { return n->get_parent() == NULL; }                             // works
    bool isExternal() const { return n->get_left() == NULL && n->get_right() == NULL; } // works
};
#endif