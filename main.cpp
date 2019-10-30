#include "include/client.h"
#include "include/server.h"
#include "include/recipient.h"
#include "include/trafficmonitor.h"
#include "include/baseClass.h"
#include <csignal>
#include <thread>
#include <iostream>

void clientSet(BaseClass* cl);
void serverGet(BaseClass* rec);
void measure(BaseClass* tf);

auto interval = std::chrono::milliseconds(1000);
bool run = true;

int main(int argc, char** argv) {
    srand(time(nullptr));
    Server* server = Server::getInstance();
    BaseClass* client1 = new Client{Priority::low};
    BaseClass* client2 = new Client{Priority::mid};
    BaseClass* client3 = new Client{Priority::high};
    BaseClass* recipient = new Recipient{Priority::highest};
    BaseClass* tf = new TrafficMonitor{Priority::low};

    server->attach(client1);
    server->attach(client2);
    server->attach(client3);
    server->attach(recipient);
    server->attach(tf);

    // watki wkladajace pakiety
    std::thread set1{clientSet, client1};
    std::thread set2{clientSet, client2};
    std::thread set3{clientSet, client3};
    // watek wyciagajacy pakiety
    std::thread get{serverGet, recipient};
    // watek pomiarowy
    std::thread monitor{measure, tf};
    
    set1.join();
    set2.join();
    set3.join();
    get.join();
    monitor.join();
}

void clientSet(BaseClass* cl) {
    while(run) {
        cl->update();
        Client* cc = static_cast<Client*>(cl);
        cc->newPacket();
    }
}

void serverGet(BaseClass* rec) {
    while(run) {
        rec->update();
    }
}

void measure(BaseClass* tf) {
    //measure every 1000 miliseconds
    while(run) {
        auto period = std::chrono::high_resolution_clock::now() + interval;
        tf->update();
        TrafficMonitor* tt = static_cast<TrafficMonitor*>(tf);
        tt->show();
        tt->reset();
        std::this_thread::sleep_until(period);
    }
}