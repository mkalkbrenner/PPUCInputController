/*
  PPUCPIN2DMD.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

#ifndef PPUCPIN2DMD_h
#define PPUCPIN2DMD_h

#include <Arduino.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>

class PPUCPIN2DMD {
public:
    PPUCPIN2DMD(PPUCEventDispatcher* eD) {
        eventDispatcher = eD;
    }

    void setSerial(HardwareSerial &reference);

    void update();

    void setDebug(bool value);

private:
    PPUCEventDispatcher* eventDispatcher;

    HardwareSerial* hwSerial;

    bool debug = false;

};

#endif
