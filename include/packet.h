#ifndef PACKET_H
#define PACKET_H
#include <cstdlib>

enum class Priority{low, mid, high, highest};

class Packet {
protected:
    //Priorytet pakietu nie ma znaczenia(dodalem dla siebie)
    //Znaczenie ma priorytet klienta
    Priority priority;
    int content;
public:
    Packet(Priority p): priority{p}, content(rand()%10) {}
    virtual ~Packet() {}
    Priority getPriority() const {return priority;}
    int getContent() const {return content;}
};

#endif