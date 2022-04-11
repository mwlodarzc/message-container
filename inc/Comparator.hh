#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "Position.hh"
#include "IndexedLetter.hh"

class IdLetComparator
{
public:
    bool compare(Position<IndexedLetter> &first, Position<IndexedLetter> &second) // isLess comparator
    {
        return (*first).key < (*second).key;
    }
};
#endif