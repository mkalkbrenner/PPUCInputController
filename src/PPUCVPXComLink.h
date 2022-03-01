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

private:
    PPUCEventDispatcher* eventDispatcher;

    HardwareSerial* hwSerial;

    bool led = false;

};

#endif
