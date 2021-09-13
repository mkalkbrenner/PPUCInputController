#include "PPUCMatrix.h"

PPUCMatrix::PPUCMatrix(PPUCEventDispatcher* eD, byte pf) {
    eventDispatcher = eD;
    platform = pf;

    setLastColToRead(8);

    for (int i = 0; i < lastColToRead; i++) {
        rows[i] = B00000000;
        previousRows[i] = B00000000;
    }
}

void PPUCMatrix::setLastColToRead(byte last) {
    lastColToRead = last;
}

void PPUCMatrix::registerFieldAsEvent(byte row, byte column, byte number) {
    if (registeredFieldsCounter < (MAX_FIELDS_REGISTERED - 1)) {
        registeredFieldRowCol[++registeredFieldsCounter] = word(row - 1, column - 1);
        registeredFieldNum[registeredFieldsCounter] = number;
    }
}

void PPUCMatrix::registerAllFieldsAsEvent() {
    registeredFieldsCounter = -1;

    if (platform == PLATFORM_WPC) {
        for (byte col = 1; col <= NUM_COLS; col++) {
            for (byte row = 1; row <= 8; row++) {
                registerFieldAsEvent(row, col, col * 10 + row);
            }
        }
    }
    else if (platform == PLATFORM_DATA_EAST) {
        byte number = 0;
        for (byte col = 1; col <= NUM_COLS; col++) {
            for (byte row = 1; row <= 8; row++) {
                registerFieldAsEvent(row, col, ++number);
            }
        }
    }
}

void PPUCMatrix::update() {
    uint32_t ms = millis();
    if (nextUpdate < ms) {
        for (int col = 0; col < lastColToRead; col++) {
            for (int row = 0; row < 8; row++) {
                word row_col = word(row, col);
                for (byte i = 0; i <= registeredFieldsCounter; i++) {
                    if (row_col == registeredFieldRowCol[i]) {
                        byte bit = 1 << row;
                        if ((rows[col] & bit) != (previousRows[col] & bit)) {
                            eventDispatcher->dispatch(
                                new PPUCEvent(eventSource, word(0, registeredFieldNum[i]), (rows[col] & bit) ? 1 : 0)
                            );
                        }
                    }
                }
            }
            previousRows[col] = rows[col];
            rows[col] = B00000000;
        }

        if (platform == PLATFORM_WPC) {
            // On WPC the switches are read every 2ms. Ensure that we have a complete read before sending next events.
            nextUpdate = ms + 3;
        }
        else if (platform == PLATFORM_DATA_EAST) {
            // @todo
            nextUpdate = ms + 1;
        }
    }
}

void PPUCMatrix::print() {
    Serial.print("Matrix "); Serial.println(eventSource);
    Serial.println("  8 7 6 5 4 3 2 1");
    for (int i = 0; i < lastColToRead; i++) {
        Serial.print(i + 1);
        for (byte mask = 0x80; mask; mask >>= 1) {
            Serial.print(mask & rows[i] ? " *" : " -");
        }
        Serial.println();
    }
}
