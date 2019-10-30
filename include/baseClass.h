#ifndef BASECLASS_H
#define BASECLASS_H
#include "packet.h"

class Server;

class BaseClass {
protected:
    Priority prior;
    Server* serv;
public:
virtual ~BaseClass() {}
virtual void update() = 0;
void attach(Server* s) {serv = s;}
void detach() {serv = nullptr;}
};

#endif