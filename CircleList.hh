#include <iostream>
#include <string>

typedef int Elem;
class Node
{
protected:
    Elem elem;
    Node *next;

public:
    const Elem &get_elem() { return elem; };
};

class CircleList : public Node
{
private:
    Node *cursor;

public:
    CircleList() { cursor = nullptr; };
    ~CircleList() { delete cursor; }
    bool empty() const;
    const Elem &front() const;
    const Elem &back() const;
    void advance();
    void add(const Elem &new_elem);
    void remove();
};