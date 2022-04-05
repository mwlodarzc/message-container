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

public:

#endif