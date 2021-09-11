#include "PPUCSwitchMatrix.h"

// see https://forum.arduino.cc/index.php?topic=398610.0
PPUCSwitchMatrix* PPUCSwitchMatrix::switchMatrixInstance = NULL;

void PPUCSwitchMatrix::start() {
    attachInterrupt(digitalPinToInterrupt(CS_ODD), PPUCSwitchMatrix::_readRowForOddColumn, RISING);
}

void PPUCSwitchMatrix::stop() {
    detachInterrupt(digitalPinToInterrupt(CS_ODD));
    detachInterrupt(digitalPinToInterrupt(CS_EVEN));
}

void PPUCSwitchMatrix::_readRowForOddColumn() {
    delayMicroseconds(switchMatrixInstance->rowReadDelay);
    //Serial.println("odd");

    if (!digitalRead(CS_X)) {
        //Serial.println("xxxxxxxxx");
        switchMatrixInstance->columnCounter = 0;
    }

    if (switchMatrixInstance->columnCounter >= 0 &&
        switchMatrixInstance->columnCounter < switchMatrixInstance->lastColToRead
    ) {
        //Serial.println(switchMatrixInstance->columnCounter, DEC);
        //Serial.println(PINA, BIN);
        // Read row return at PIN 22 - 29.
        switchMatrixInstance->rows[switchMatrixInstance->columnCounter] |= PINA ^ B11111111;
        //switchMatrixInstance->rows[matrixInstance->columnCounter] |= PINA;
        switchMatrixInstance->columnCounter++;
    }

    detachInterrupt(digitalPinToInterrupt(CS_ODD));
    attachInterrupt(digitalPinToInterrupt(CS_EVEN), PPUCSwitchMatrix::_readRowForEvenColumn, RISING);
}

void PPUCSwitchMatrix::_readRowForEvenColumn() {
    delayMicroseconds(switchMatrixInstance->rowReadDelay);
    //Serial.println("even");

    if (switchMatrixInstance->columnCounter >= 1 &&
        switchMatrixInstance->columnCounter < switchMatrixInstance->lastColToRead
    ) {
        //Serial.println(switchMatrixInstance->columnCounter, DEC);
        //Serial.println(PINA, BIN);
        // Read row return at PIN 22 - 29.
        switchMatrixInstance->rows[switchMatrixInstance->columnCounter] |= PINA ^ B11111111;
        //switchMatrixInstance->rows[matrixInstance->columnCounter] |= PINA;
        switchMatrixInstance->columnCounter++;
    }

    detachInterrupt(digitalPinToInterrupt(CS_EVEN));
    attachInterrupt(digitalPinToInterrupt(CS_ODD), PPUCSwitchMatrix::_readRowForOddColumn, RISING);
}
