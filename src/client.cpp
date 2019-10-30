#include "../include/client.h"

void Client::newPacket() {
    pack = Packet{prior};
}

void Client::update() {
    if(serv==nullptr) return;
    serv->addPacket(pack);
}