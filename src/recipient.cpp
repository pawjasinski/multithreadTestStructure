#include "../include/recipient.h"

void Recipient::update() {
    if(serv==nullptr) return;
    //can save data to structure but not implemented
    serv->getPacket();
}