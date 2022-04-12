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
    char *current_message;
    std::string input_filename = "./LoremIpsum.txt";
    std::string output_filename = "./data.txt";
    std::fstream input_file;
    std::fstream output_file;
    int x_points = 50000001;
    int step_size = 500000;
    int *data_milestones = new int[x_points / step_size];
    std::chrono::duration<double> elapsed;
    std::cout << sizeof(IndexedLetter) << std::endl;
    input_file.open(input_filename, std::ios::in);
    if (!input_file)
    {
        std::cerr << "File doesnt exist!";
    }
    output_file.open(output_filename, std::ios::app);
    if (!output_file)
    {
        std::cerr << "File doesnt exist!";
    }
    for (int mes_size = 0, data_index = 0; mes_size < x_points; mes_size += step_size, data_index++)
    {
        data_milestones[data_index] = mes_size;
        current_message = get_message(input_filename, mes_size);
        output_file << mes_size << "  " << sizeof(char) * mes_size << "  " << sizeof(IndexedLetter) * mes_size << "   ";
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < mes_size; j++)
        {
            queue.insert({j, current_message[j]});
        }
        auto mid = std::chrono::high_resolution_clock::now();
        while (!queue.empty())
        {
            queue.removeMin();
        }
        auto finish = std::chrono::high_resolution_clock::now();
        elapsed = mid - start;
        output_file << elapsed.count() << "   ";
        elapsed = finish - mid;
        output_file << elapsed.count() << "    ";
        elapsed = finish - start;
        output_file << elapsed.count() << std::endl;
    }
    // auto start = std::chrono::high_resolution_clock::now();
    // auto finish = std::chrono::high_resolution_clock::now();
    // std::cout << "Elapsed time: " << elapsed.count() << std::endl;
    input_file.close();
    output_file.close();
    delete data_milestones;
    delete current_message;
    return EXIT_SUCCESS;
}

int main()
{
    //  Variables used in examples
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
    delete current_message;
    return EXIT_SUCCESS;
}