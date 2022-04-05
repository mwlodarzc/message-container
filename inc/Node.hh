#ifndef NODE_HH
#define NODE_HH

// value created and exists are used only for checking if the memory is leaked and should be deleted from the final project
template <typename T>
class Node
{
private:
    inline static int created = 0;
    inline static int exists = 0;

public:
    T element;
    Node *parent;
    Node *left;
    Node *right;

public:
    Node() : element(), parent(NULL), left(NULL), right(NULL)
    {
        created++;
        exists++;
    }
    Node(const T &element_) : element{element_}, parent(NULL), left(NULL), right(NULL)
    {
        created++;
        exists++;
    };
    Node(const T &element_, Node &parent_, Node &left_, Node &right_) : element{element_}, parent(parent_), left(left_), right(right_)
    {
        created++;
        exists++;
    };
    T &get_elem()
    {
        std::cout << element;
        return element;
    }
    ~Node() { exists--; }
    static int existing_number() { return exists; }
    static int created_number() { return created; }
};
#endif