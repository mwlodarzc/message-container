#include <iostream>
#include <stdlib.h>
#include "DoublyLinkedList.hh"
int main()
{
    DoublyLinkedList<int> list;
    list.addFront(2);
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    list.addFront(1);
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    list.addBack(3);
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    list.removeBack();
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    list.removeFront();
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    //     switch (input)
    //     {
    //     case 'a':
    //         list.addFront(rand());
    //         std::cout << tmp << std::endl;
    //         break;
    //     case 'r':
    //         try
    //         {
    //             list.removeFront();
    //         }
    //         catch (const std::out_of_range &e)
    //         {
    //             std::cerr << e.what() << '\n';
    //         }
    //         break;
    //     case 's':
    //         list.addBack(rand());
    //         std::cout << tmp << std::endl;

    //         break;
    //     case 't':
    //         try
    //         {
    //             list.removeBack();
    //         }
    //         catch (const std::out_of_range &e)
    //         {
    //             std::cerr << e.what() << '\n';
    //         }
    //         break;
    //     default:
    //         std::cerr << "Invalid input!" << std::endl;
    //         break;
    //     }
    //     std::cout << i.existing_number() << ":" << i.created_number() << std::endl;
    // }
    return EXIT_SUCCESS;
}