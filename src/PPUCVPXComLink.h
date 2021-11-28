/*
  PPUCVPXComLink.h
  Created by Markus Kalkbrenner, 2021.

  Play more pinball!
*/

#ifndef PPUCVPXCOMLINK_h
#define PPUCVPXCOMLINK_h

#include <Arduino.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>

class PPUCVPXComLink {
public:
    PPUCVPXComLink(PPUCEventDispatcher* eD) {
        eventDispatcher = eD;
    }

    void setSerial(HardwareSerial &reference);

    void update();

    void setDebug(bool value);

private:
    PPUCEventDispatcher* eventDispatcher;

    HardwareSerial* hwSerial;

    bool debug = false;

    bool led = false;

};

#endif
