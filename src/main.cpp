#include <iostream>
#include "CircleList.hh"
int main()
{
    CircleList<int> cl;
    int i1 = 1, i2 = 2, i3 = 3, i4 = 4;
    cl.add(i1);
    cl.add(i2);
    cl.add(i3);
    cl.add(i4);
    while (!cl.empty())
    {
        try
        {
            std::cout << cl.back() << std::endl;
            cl.remove();
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return EXIT_SUCCESS;
}