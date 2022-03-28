#ifndef INDEXED_LETTER_HH
#define INDEXED_LETTER_HH
#include <stdexcept>

class IndexedLetter
{
private:
    char letter;
    int index;

public:
    inline IndexedLetter(const char &letter_, const int &i) : letter{letter_}, index{i}
    {
        if (i < 0)
            throw std::out_of_range("Letter index isnt a real number!");
    }
    const char get_letter() const { return letter; };
    const int &get_index() const { return index; };
};

#endif