#include "Message.hh"
Message::Message(char *msg)
{
    for (long unsigned int i = 0; i < sizeof(msg) - 1; i++)
        letters.enqueue(IndexedLetter(msg[i], i));
}

void Message::simulate_transmission()
{
}
