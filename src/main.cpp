#include <iostream>
#include <stdlib.h>
#include "Vector.hh"
int main()
{
    int tmp[] = {1, 2, 3, 4, 5};
    Vector<int> v(tmp, sizeof(tmp) / sizeof(tmp[0]));
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    while (!v.empty())
    {
        try
        {
            std::cout << v[0] << std::endl;
            v.erase(0);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return EXIT_SUCCESS;
}