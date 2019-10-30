#include "../include/server.h"

Server* Server::_instance = nullptr;

Server* Server::getInstance() {
    if(_instance == nullptr)
        _instance = new Server;
    return _instance;
}

void Server::addPacket(const Packet pac) {
    //mozna by to rozwiazac lepiej, moze przekazac priotytet jako argument
    std::unique_lock<std::mutex> lck{mm};
    Priority pr = pac.getPriority();
    switch (pr)
    {
    case Priority::high: {
        std::unique_lock<std::mutex> lckH{highPr};
        lck.unlock();
        std::unique_lock<std::mutex> lckHH{highPr};
        lckH.unlock();
        h.push_back(pac);
        ++addPacketsHigh;
        break;
        }

    case Priority::mid: {
        std::unique_lock<std::mutex> lckM{midPr};
        lck.unlock();
        std::unique_lock<std::mutex> lckH{highPr};
        lckM.unlock();
        std::unique_lock<std::mutex> lckHH{highPr};
        lckH.unlock();
        m.push_back(pac);
        ++addPacketsMid;
        break;
        }
    case Priority::low: {
        std::unique_lock<std::mutex> lckL{lowPr};
        lck.unlock();
        std::unique_lock<std::mutex> lckM{midPr};
        std::unique_lock<std::mutex> lckH{highPr};
        lckM.unlock();
        std::unique_lock<std::mutex> lckHH{highPr};
        lckH.unlock();
        m.push_back(pac);
        ++addPacketsLow;
        break;
        }
    default:
        break;
    }
}

Packet Server::getPacket() {
    std::unique_lock<std::mutex> lckHH{highPr};
    if(h.size()) {
        Packet p = h.front();
        h.pop_front();
        ++getPackets;
        return p;
    }
    else if(m.size()) {
        Packet p = m.front();
        m.pop_front();
        ++getPackets;
        return p;
    }
    else if(l.size()) {
        Packet p = l.front();
        l.pop_front();
        ++getPackets;
        return p;
    }
}

void Server::attach(BaseClass* c) {
    //porownanie po adresie obiektu
    for(std::list<BaseClass*>::iterator i = clients.begin(); i != clients.end(); ++i) {
        if(c == *i ) return;
    }
    clients.push_back(c);
    c->attach(this);
}

void Server::detach(BaseClass*c) {
    //porownanie po adresie obiektu
    for(std::list<BaseClass*>::iterator i = clients.begin(); i != clients.end(); ++i) {
        if(c == *i ) clients.erase(i);
    }
    c->detach();
}

void Server::resetNumberOfPackets() {
    addPacketsLow   = 0;
    addPacketsMid   = 0;
    addPacketsHigh  = 0;
    getPackets      = 0;
}

    unsigned int Server::getteraddPacketsLow()  {return addPacketsLow  ;}
    unsigned int Server::getteraddPacketsMid()  {return addPacketsMid  ;}
    unsigned int Server::getteraddPacketsHigh() {return addPacketsHigh ;}
    unsigned int Server::gettergetPackets()     {return getPackets     ;}