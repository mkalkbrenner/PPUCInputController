#include "PPUCSwitchMatrix.h"

// see https://forum.arduino.cc/index.php?topic=398610.0
PPUCSwitchMatrix* SwitchMatrix::switchMatrixInstance = NULL;

void PPUCSwitchMatrix::start() {
    attachInterrupt(digitalPinToInterrupt(2), PPUCSwitchMatrix::_readRow, RISING);
    attachInterrupt(digitalPinToInterrupt(3), PPUCSwitchMatrix::_readRow, RISING);
}

void PPUCSwitchMatrix::stop() {
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
}

void PPUCSwitchMatrix::_readRow() {
    if (!digitalRead(4)) {
        switchMatrixInstance->columnCounter = 0;
    }

    if (switchMatrixInstance->columnCounter >= 0 &&
            switchMatrixInstance->columnCounter <= switchMatrixInstance->lastColToRead
    ) {
        // Read row return at PIN 22 - 29.
        switchMatrixInstance->rows[switchMatrixInstance->columnCounter] |= PINA ^ B11111111;
        //matrixInstance->rows[matrixInstance->columnCounter] |= PINA;
        switchMatrixInstance->columnCounter++;
    }
}
