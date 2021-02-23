#include "PPUCPIN2DMD.h"

void PPUCPIN2DMD::setSerial(HardwareSerial &reference) {
    hwSerial = (HardwareSerial*) &reference;
    hwSerial->begin(57600);
}

void PPUCPIN2DMD::reset() {
    for (int i = 0; i < PIN2DMD_EVENT_CACHE_SIZE; i++) {
        eventCache[i] = 0;
    }
    eventCacheCounter = 0;
}

void PPUCPIN2DMD::update() {
    if (hwSerial->available() > 2) {
        byte deviceByte = hwSerial->read();
        if (deviceByte != 0) {
            byte eventByte = hwSerial->read();
            if (eventByte != 0) {
                byte nullByte = hwSerial->read();
                if (nullByte == 0) {
                    eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DMD, word(deviceByte - 100, eventByte)));

                    if (++eventCacheCounter > PIN2DMD_EVENT_CACHE_SIZE) {
                        eventCacheCounter = 0;
                    }
                }
            }
        }
    }
}

void PPUCPIN2DMD::print() {
    Serial.println("PIN2DMD events");
    for (int i = 0; i < PIN2DMD_EVENT_CACHE_SIZE; i++) {
        Serial.print("device: "); Serial.print(highByte(eventCache[i]));
        Serial.print(" command: "); Serial.println(lowByte(eventCache[i]));
    }
}
