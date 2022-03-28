#include <iostream>
#include <stdlib.h>
#include "Queue.hh"
#include "IndexedLetter.hh"

class Message
{
private:
    Queue<IndexedLetter> letters;

public:
    Message();
    Message(char *msg);
    void simulate_transmission();
    char *receive();
};

Message::Message(char *msg)
{
    for (long unsigned int i = 0; i < sizeof(msg) - 1; i++)
        letters.enqueue(IndexedLetter(msg[i], i));
}

void Message::simulate_transmission()
{
}

int main()
{
    return EXIT_SUCCESS;
}