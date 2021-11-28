#include "PPUCVPXComLink.h"

void PPUCVPXComLink::setSerial(HardwareSerial &reference) {
    hwSerial = (HardwareSerial*) &reference;
    hwSerial->begin(115200, SERIAL_8N1);
}

void PPUCVPXComLink::update() {
    if (hwSerial->available() >= 5) {
        byte startByte = hwSerial->read();
        if (debug) {
            eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DEBUG, word(0, 1), startByte));
        }
        if (startByte == 255) {
            byte sourceId = hwSerial->read();
            if (debug) {
                eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DEBUG, word(0, 2), sourceId));
            }
            if (sourceId != 0) {
                word eventId = hwSerial->read();
                if (debug) {
                    eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DEBUG, word(0, 3), eventId));
                }
                if (eventId != 0) {
                    byte value = hwSerial->read();
                    if (debug) {
                        eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DEBUG, word(0, 4), value));
                    }
                    byte stopByte = hwSerial->read();
                    if (debug) {
                        eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_DEBUG, word(0, 5), stopByte));
                    }
                    if (stopByte == 255) {
                        eventDispatcher->dispatch(new PPUCEvent((char) sourceId, word(0, eventId), value));
                    }
                }
            }
        }
    }
}

void PPUCVPXComLink::setDebug(bool value) {
    debug = value;
}
