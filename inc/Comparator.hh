#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "Position.hh"

template <typename T>
class Comparator
{
public:
    bool isLess(const T &first, const T &second)
    {
        return first < second;
    }
};
#endif