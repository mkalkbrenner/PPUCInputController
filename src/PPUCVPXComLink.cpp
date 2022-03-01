#include "PPUCVPXComLink.h"

void PPUCVPXComLink::setSerial(HardwareSerial &reference) {
    hwSerial = (HardwareSerial*) &reference;
    hwSerial->begin(115200, SERIAL_8N1);
}

void PPUCVPXComLink::update() {
    if (hwSerial->available() >= 5) {
        byte startByte = hwSerial->read();
        if (startByte == 255) {
            byte sourceId = hwSerial->read();
            if (sourceId != 0) {
                word eventId = word(hwSerial->read(), hwSerial->read());
                if (eventId != 0) {
                    byte value = hwSerial->read();
                    byte stopByte = hwSerial->read();
                    if (stopByte == 255) {
                        eventDispatcher->dispatch(new PPUCEvent((char) sourceId, eventId, value));
                    }
                }
            }
        }
    }
}
