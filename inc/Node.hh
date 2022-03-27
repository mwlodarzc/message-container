#ifndef NODE_HH
#define NODE_HH
template <typename T>
class Node
{
private:
    T elem;
    Node *next;

public:
    Node(const T &elem_) : elem{elem_} {};
    Node(const T &elem_, Node &next_) : elem{elem_}, next{&next_} {};
    const T &get_elem() const { return elem; };
    Node &get_next() const { return *next; };
    void set_next(Node &next_) { next = &next_; };
};
#endif