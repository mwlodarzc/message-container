#include <iostream>
#include <stdlib.h>
#include "Vector.hh"
int main()
{
    Vector<int> v;
    v.insert(0, rand());
    std::cout << v[0] << std::endl;
    for (int i = 0; i < 10; i++)
        v.insert(i, i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << std::endl;
    return EXIT_SUCCESS;
}