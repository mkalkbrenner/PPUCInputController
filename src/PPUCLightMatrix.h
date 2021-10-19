/*
  PPUCLightMatrix.h
  Created by Markus Kalkbrenner, 2020.
  Derived from afterglow: 2018-2019 Christoph Schmid

  Play more pinball!
*/

#ifndef PPUCLightMatrix_h
#define PPUCLightMatrix_h

#include <Arduino.h>
#include <PPUCEvent.h>

#include "PPUCMatrix.h"

// Number of consistent data samples required for matrix update
#define SINGLE_UPDATE_CONS 3

class PPUCLightMatrix : public PPUCMatrix {
public:
    PPUCLightMatrix(PPUCEventDispatcher* eD, byte pf) : PPUCMatrix(eD, pf) {
        eventSource = EVENT_SOURCE_LIGHT;
        maxChangesPerRead = MAX_FIELDS_REGISTERED;

        pinMode(5, INPUT);
        pinMode(6, OUTPUT);
        pinMode(7, OUTPUT);
    }

    void start();

    void stop();

    void update();

private:
    uint16_t sampleInput();

    bool updateValid(byte inColMask, byte inRowMask);

    void updateCol(uint32_t col, byte rowMask);

    void readRow();

    // remember the last column and row samples
    byte sLastColMask = 0;
    byte sLastRowMask = 0;

    bool running = false;
};

#endif
