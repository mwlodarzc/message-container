#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "BinaryTree.hh"
// #include "Vector.hh"
// #include "PriorityQueue.hh"
#include "Comparator.hh"

int main()
{
    // Vector<Position<int>> v(1);
    // Node<int> *n1 = new Node<int>(1);
    // Node<int> *n2 = new Node<int>(2);

    // Position<int> *p1 = new Position<int>(n1);
    // Position<int> *p2 = new Position<int>(n2);
    // std::cout << p1->isExternal() << std::endl;
    // std::cout << p1->isRoot() << std::endl;
    // p1->set_parent(p2);
    // p1->set_left(p2);
    // p1->set_right(p2);
    // std::cout << p1->isExternal() << std::endl;
    // std::cout << p1->isRoot() << std::endl;

    // Node<int> *n3 = new Node<int>(3);
    // Node<int> *n4 = new Node<int>(4);
    // Node<int> *n5 = new Node<int>(5);

    // Position<int> *p3 = new Position<int>(n3);
    // Position<int> *p4 = new Position<int>(n4);
    // Position<int> *p5 = new Position<int>(n5);
    // v.insert(0, *p1);
    // v.insert(0, *p2);
    // v.insert(0, *p3);
    // v.insert(0, *p4);
    // v.insert(0, *p5);
    // Vector<Position<int>>::Iterator iter(p1);
    // iter++;
    // iter++;
    // std::cout << iter - v.begin() << std::endl;

    // BinaryTree<int> tree;
    // tree.addLast(11);
    // std::cout << tree.last().isRoot() << std::endl;
    // tree.addLast(12);
    // tree.addLast(13);
    // std::cout << tree.last().isRoot() << std::endl;
    // tree.addLast(14);
    // std::cout << tree.last().isRoot() << std::endl;
    // tree.addLast(15);
    // std::cout << tree.last().right().isRoot() << std::endl;
    // tree.addLast(16);
    // std::cout << tree.last().isRoot() << std::endl;

    // PriorityQueue<int> queue;
    // queue.insert(2);
    // std::cout << queue.min() << std::endl;
    // queue.insert(5);
    // std::cout << queue.min() << std::endl;
    // queue.insert(1);
    // std::cout << queue.min() << std::endl;
    // // queue.removeMin();
    // queue.insert(6);
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
    return EXIT_SUCCESS;
}