#include <iostream>
#include <stdlib.h>
#include "Queue.hh"

int main()
{
    Queue<int> q;
    int tmp;
    char user_input;
    while (1)
    {
        tmp = rand();
        std::cin >> user_input;
        switch (user_input)
        {
        case 'a':
            q.enqueue(tmp);
            std::cout << tmp << std::endl;
            break;
        case 'r':
            try
            {
                std::cout << q.front() << std::endl;
                q.dequeue();
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << e.what() << '\n';
            }

            break;

        default:
            std::cerr << "Invalid input!" << std::endl;
            break;
        }
        q.size();
    }
    return EXIT_SUCCESS;
}