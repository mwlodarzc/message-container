#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "Position.hh"
#include "IndexedLetter.hh"

class IdLetComparator
{
public:
    static bool isLess(Position<IndexedLetter> &first, Position<IndexedLetter> &second)
    {
        return (*first).key < (*second).key;
    }
};
#endif