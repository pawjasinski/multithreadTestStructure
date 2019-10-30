#ifndef CLIENT_H
#define CLIENT_H

#include "baseClass.h"
#include "server.h"

class Client : public BaseClass {
private:
    Packet pack;
public:
    Client(Priority p): pack{Packet{p}} {
                                            prior = p;
                                            serv = nullptr;
                                            }
    ~Client() {}
    Packet getPacket() const {return pack;}
    Priority getPriority() {return prior;}
    void newPacket();

    void update();
};

#endif