#ifndef NODE_HH
#define NODE_HH

template <typename T> // everything working
class Node
{
private:
    T element;
    Node *parent;
    Node *left;
    Node *right;

public:
    Node() : element(), parent(NULL), left(NULL), right(NULL) {}
    Node(const T &element_) : element{element_}, parent(NULL), left(NULL), right(NULL) {}
    Node(const T &element_, Node &parent_, Node &left_, Node &right_) : element{element_}, parent(parent_), left(left_), right(right_) {}
    inline ~Node() = default;
    inline const T &get_element() const { return this->element; };             // works
    inline void set_element(const T &elem) { element = elem; };                // works
    inline const Node *get_right() const { return right; };                    // works
    inline void set_right(const Node *right_) { right = (Node *)right_; };     // works
    inline const Node *get_left() const { return left; };                      // works
    inline void set_left(const Node *left_) { left = (Node *)left_; };         // works
    inline const Node *get_parent() const { return parent; };                  // works
    inline void set_parent(const Node *parent_) { parent = (Node *)parent_; }; // works
};
#endif