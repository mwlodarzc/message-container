#ifndef NODE_HH
#define NODE_HH

// value created and exists are used only for checking if the memory is leaked and should be deleted from the final project
template <typename T>
class Node
{
private:
    T elem;
    Node *next;
    Node *prev;
    inline static int created = 0;
    inline static int exists = 0;

public:
    Node()
    {
        created++;
        exists++;
    }
    Node(const T &elem_) : elem{elem_}
    {
        created++;
        exists++;
    };
    Node(const T &elem_, Node &next_) : elem{elem_}, next{&next_}
    {
        created++;
        exists++;
    };
    ~Node() { exists--; }
    const T &get_elem() const { return elem; };
    Node &get_next() const { return *next; };
    void set_next(Node &next_) { next = &next_; };
    Node &get_prev() const { return *prev; };
    void set_prev(Node &prev_) { prev = &prev_; };
    static int existing_number() { return exists; }
    static int created_number() { return created; }
};
#endif