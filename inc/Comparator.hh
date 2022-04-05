#ifndef COMPARATOR_HH
#define COMPARATOR_HH

class isLess
{
public:
    bool operator()(const int &first, const int &second) const { return first < second; }
};
#endif