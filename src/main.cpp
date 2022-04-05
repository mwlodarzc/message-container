#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <iomanip>

#include "PriorityQueue.hh"
#include "Comparator.hh"

int main()
{
    BinaryTree<int> tree;
    tree.addLast(11);
    tree.addLast(123);
    std::cout << *tree.last() << std::endl;
    // Node<int> n1(5);
    // Node<int> n2(7);
    // Position<int> a(&n1);
    // Position<int> b(&n2);
    // Vector<Position<int>> v(1);
    // v.insert(0, NULL);
    // std::cout << v.size() << std::endl;
    // v.insert(v.size(), a);
    // std::cout << *v[v.size() - 1] << std::endl;
    // std::cout << v.size() << std::endl;
    // v.insert(v.size(), b);
    // std::cout << *v[v.size() - 1] << std::endl;
    // std::cout << v.size() << std::endl;

    // Position<int> c;
    // std::cout
    // << (tree.pos(2).get_posit_elem()) << std::endl;

    // std::cout << queue.min() << std::endl;
    // queue.insert(2);
    // std::cout << queue.min() << std::endl;
    // queue.insert(5);
    // std::cout << queue.min() << std::endl;
    // queue.insert(1);
    // std::cout << queue.min() << std::endl;

    // char *current_message = new char[10000];
    // int x_points = 10001;
    // int step_size = 10;
    // int *data_milestones = new int[x_points / step_size];
    // for (int i = 0; i < x_points; i += step_size)
    // {
    //     data_milestones[i] = i;
    //     std::cout << data_milestones[i] << std::endl;
    // }

    // std::fstream file;
    // file.open("./LoremIpsum.txt", std::ios::in);
    // if (!file)
    // {
    //     std::cerr << "File doesnt exist!";
    // }
    // char x;
    // int i = 0;
    // while (1)
    // {
    //     file >> x;
    //     current_message[i] = x;
    //     if (file.eof())
    //         break;
    //     std::cout << x << std::endl;
    // }

    // // auto start = std::chrono::high_resolution_clock::now();
    // // auto finish = std::chrono::high_resolution_clock::now();
    // // std::chrono::duration<double> elapsed = finish - start;
    // // std::cout << "Elapsed time: " << elapsed.count() << std::endl;
    // file.close();
    // delete data_milestones;
    // return EXIT_SUCCESS;
}