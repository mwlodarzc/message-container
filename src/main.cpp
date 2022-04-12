#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "PriorityQueue.hh"
#include "Comparator.hh"
#include "IndexedLetter.hh"
/*!
 * @brief Function that gets specified number of characters from file.
 * @param filename Name of file.
 * @param size Number of characters
 * @return character array (pointer).
 */
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
void collect_data()
{
    PriorityQueue<IndexedLetter, IdLetComparator> queue;
    char *current_message;
    std::string input_filename = "./LoremIpsum.txt";
    std::string output_filename = "./data.txt";
    std::fstream input_file;
    std::fstream output_file;
    int x_points = 50000001;                              // maximum character data size
    int step_size = 500000;                               // step size on characteristic
    int *data_milestones = new int[x_points / step_size]; // all x datapoints
    std::chrono::duration<double> elapsed;                // time variable
    input_file.open(input_filename, std::ios::in);        // opening input file
    if (!input_file)
    {
        std::cerr << "File doesnt exist!";
    }
    output_file.open(output_filename, std::ios::app); // opening output file
    if (!output_file)
    {
        / std::cerr << "File doesnt exist!";
    }
    for (int mes_size = 0, data_index = 0; mes_size < x_points; mes_size += step_size, data_index++)
    {
        data_milestones[data_index] = mes_size;
        current_message = get_message(input_filename, mes_size);
        output_file << mes_size << "  " << sizeof(char) * mes_size << "  " << sizeof(IndexedLetter) * mes_size << "   ";
        // begining of algorithms work timestamp
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < mes_size; j++)
        {
            std::cout << current_message[j];
            queue.insert({j, current_message[j]});
        }
        std::cout << std::endl;
        // ending of data loading and begining of data sorting timestamp
        auto mid = std::chrono::high_resolution_clock::now();
        while (!queue.empty())
        {
            std::cout << queue.min().value;
            queue.removeMin();
        }
        std::cout << std::endl;
        // ending of algorithms work timestamp
        auto finish = std::chrono::high_resolution_clock::now();
        // calculating time used by algorithm
        elapsed = mid - start;
        output_file << elapsed.count() << "   ";
        elapsed = finish - mid;
        output_file << elapsed.count() << "    ";
        elapsed = finish - start;
        output_file << elapsed.count() << std::endl;
    }
    // deleting alocated data.
    input_file.close();
    output_file.close();
    delete data_milestones;
    delete current_message;
}

int main()
{
    // collect_data();
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