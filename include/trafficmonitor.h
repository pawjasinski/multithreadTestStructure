#ifndef TRAFFICMONITOR_H
#define TRAFFICMONITOR_H
#include "baseClass.h"
#include "server.h"
/* 
    Predkosc wkladania pakietow danego priorytetu na sekunde
    predkosc oprozniania struktury pakietow na sekudbe
*/

class TrafficMonitor: public BaseClass {
private:
unsigned int addPacketsLow = 0;
unsigned int addPacketsMid = 0;
unsigned int addPacketsHigh = 0;
unsigned int getPackets    = 0;
public:
TrafficMonitor(Priority p){ prior = p;}
~TrafficMonitor() {}
void update();
void reset();
void show();
};

#endif