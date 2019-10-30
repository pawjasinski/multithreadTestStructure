#ifndef SERVER_H
#define SERVER_H

#include <list>
#include <mutex>
#include "packet.h"
#include "client.h"
#include <queue>

class BaseClass;

class Server {
private:
    static Server* _instance;
    std::list<BaseClass*> clients;
    Server() {}
    std::list<Packet> l; //low priority
    std::list<Packet> m; //mid priority
    std::list<Packet> h; //high priority
    unsigned int addPacketsLow  = 0;
    unsigned int addPacketsMid  = 0;
    unsigned int addPacketsHigh = 0;
    unsigned int getPackets     = 0;
    
    std::mutex mm;
    std::mutex lowPr;
    std::mutex midPr;
    std::mutex highPr;
    std::mutex highestPr;

public:
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    static Server* getInstance();
    Packet getPacket();
    void addPacket(const Packet pac);

    void attach(BaseClass* c);
    void detach(BaseClass*c);

    void resetNumberOfPackets();

    unsigned int getteraddPacketsLow();
    unsigned int getteraddPacketsMid();
    unsigned int getteraddPacketsHigh();
    unsigned int gettergetPackets();
};
#endif