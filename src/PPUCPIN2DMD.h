/*
  PPUCPIN2DMD.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

#ifndef PPUCPIN2DMD_h
#define PPUCPIN2DMD_h

#include <Arduino.h>
#include <PPUCEventDispatcher.h>

#define PIN2DMD_EVENT_CACHE_SIZE 10

class PPUCPIN2DMD {
public:
    PPUCPIN2DMD(EventDispatcher* eD) {
        eventDispatcher = eD;
        reset();
    }

    void setSerial(HardwareSerial &reference);

    void reset();

    void print();

    void update();

private:
    PPUCEventDispatcher* eventDispatcher;

    uint16_t eventCache[PIN2DMD_EVENT_CACHE_SIZE];
    int eventCacheCounter;

    Stream *hwSerial;

};

#endif
