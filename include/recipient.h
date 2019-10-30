#ifndef RECIPIENT_H
#define RECIPIENT_H
#include "packet.h"
#include "server.h"
#include "baseClass.h"
#include <list>

class Recipient: public BaseClass {
private:
std::list<Packet> packets;
public:
Recipient(Priority p) {prior = p; }
~Recipient() {}
void update();
};

#endif