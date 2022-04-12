#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "Position.hh"
#include "IndexedLetter.hh"
/*!
 * @brief Comparator specified for exercise purpose. It takes Position object reference of IndexedLetter class as paremters and compares their value.
 */
class IdLetComparator
{
public:
    bool compare(Position<IndexedLetter> &first, Position<IndexedLetter> &second) // isLess comparator
    {
        return (*first).key < (*second).key;
    }
};
#endif