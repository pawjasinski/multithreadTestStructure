#include "../include/trafficmonitor.h"
#include <iostream>

void TrafficMonitor::update() {
    if(serv==nullptr) return;
    addPacketsLow = serv->getteraddPacketsLow();
    addPacketsMid = serv->getteraddPacketsMid();
    addPacketsHigh = serv->getteraddPacketsHigh();
    getPackets    = serv->gettergetPackets();
}

void TrafficMonitor::reset() {
    serv->resetNumberOfPackets();
    addPacketsLow = 0;
    addPacketsMid = 0;
    addPacketsHigh = 0;
    getPackets    = 0;
}

void TrafficMonitor::show() {
    std::cout << "Add packets low priority: " << addPacketsLow  << "\n";
    std::cout << "Add packets mid priority: " << addPacketsMid  << "\n";
    std::cout << "Add packets high priority: "<< addPacketsHigh << "\n";
    std::cout << "Get packets all priority: " << getPackets     << "\n";
}