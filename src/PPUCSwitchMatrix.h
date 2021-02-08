/*
  PPUCSwitchMatrix.h.
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

#ifndef PPUCSwitchMatrix_h
#define PPUCSwitchMatrix_h

#include <Arduino.h>
#include <PPUCEventDispatcher.h>

#include "PPUCMatrix.h"

class PPUCSwitchMatrix : public PPUCMatrix {
public:
    PPUCSwitchMatrix(PPUCEventDispatcher* eD) : PPUCMatrix(eD) {
        switchMatrixInstance = this;

        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);

        pinMode(22, INPUT);
        pinMode(23, INPUT);
        pinMode(24, INPUT);
        pinMode(25, INPUT);
        pinMode(26, INPUT);
        pinMode(27, INPUT);
        pinMode(28, INPUT);
        pinMode(29, INPUT);
    }

    void start();

    void stop();

    static void _readRow();

    volatile byte columnCounter = -1;

protected:
    char eventSource = EVENT_SOURCE_SWITCH;

private:
    static PPUCSwitchMatrix* switchMatrixInstance;
};

#endif
