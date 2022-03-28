#include <iostream>
#include <stdlib.h>
#include "Queue.hh"
#include "IndexedLetter.hh"

int main()
{
    Queue<IndexedLetter> q;
    q.enqueue(IndexedLetter('a', 1));
    std::cout << q.front().get_letter() << "  " << q.front().get_index() << std::endl;
    q.dequeue();
    try
    {
        q.dequeue();
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}