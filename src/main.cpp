#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "PriorityQueue.hh"
#include "Comparator.hh"
#include "IndexedLetter.hh"

char *get_message(const std::string &filename, int size)
{
    char *current_message = new char[size];
    std::fstream file;
    char c;
    file.open(filename, std::ios::in);
    if (!file)
    {
        std::cerr << "File doesnt exist!";
    }
    for (int i = 0; i < size && !file.eof(); i++)
    {
        file.get(c);
        current_message[i] = c;
    }
    file.close();
    return current_message;
}

int main()
{
    PriorityQueue<IndexedLetter, IdLetComparator> queue;
    std::string filename = "./LoremIpsum.txt";
    char *current_message;
    int size = 26;

    // Simulating receiving a message and inputing it into
    current_message = get_message(filename, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << current_message[i];
        queue.insert({i, current_message[i]});
    }
    std::cout << std::endl;

    // Inputing received message into the PriorityQueue ADT implementation
    while (!queue.empty())
    {
        std::cout << queue.min().value;
        queue.removeMin();
    }
    std::cout << std::endl;

    // Simulating receiving unsorted message with right indexes.
    char alphabet[] = "hidfekcbagj";
    int indexes[] = {7, 8, 3, 5, 4, 10, 2, 1, 0, 6, 9};
    int alphabet_size = 11;
    for (int i = 0; i < alphabet_size; i++)
    {
        std::cout << alphabet[i];
        queue.insert({indexes[i], alphabet[i]});
    }
    std::cout << std::endl;

    // Inputing unsorted message to container and receiving sorted message.
    while (!queue.empty())
    {
        std::cout << queue.min().value;
        queue.removeMin();
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}