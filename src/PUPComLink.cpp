#include "PUPComLink.h"

void PPUCPUPComLink::setSerial(HardwareSerial &reference) {
    hwSerial = (HardwareSerial*) &reference;
    hwSerial->begin(115200, SERIAL_8N1);
}

void PPUCPUPComLink::handleEvent(PPUCEvent* event) {
    write(PUP_POST_EVENT_COMMAND, event->sourceId, event->eventId, event->value);
}

void PPUCPUPComLink::postEvent(char msgtype, int msgindex, int msgvalue) {
    write(PUP_POST_EVENT_COMMAND, msgtype, word(msgindex), word(msgvalue));
}

void PPUCPUPComLink::customCommand(char msgtype, int msgindex, int msgvalue) {
    write(PUP_CUSTOM_COMMAND, msgtype, word(msgindex), word(msgvalue));
}

void PPUCPUPComLink::setVolume(int volume) {
    write(PUP_CUSTOM_COMMAND, PUP_CUSTOM_VOLUME, word(0), word(volume));
}

void PPUCPUPComLink::startBatch(int id) {
    write(PUP_CUSTOM_COMMAND, PUP_CUSTOM_BATCH, word(0), word(id));
}

void PPUCPUPComLink::restart() {
    write(PUP_CUSTOM_COMMAND, PUP_CUSTOM_RESTART, word(0), word(1));
}

void PPUCPUPComLink::shutdown() {
    write(PUP_CUSTOM_COMMAND, PUP_CUSTOM_SHUTDOWN, word(0), word(1));
}

int PPUCPUPComLink::available() {
    return hwSerial->available();
}

byte PPUCPUPComLink::read() {
    return hwSerial->read();
}

void PPUCPUPComLink::write(byte command, char msgtype, word msgindex, word msgvalue) {
    byte msg[8];

    msg[0] = command;
    msg[1] = msgtype;
    msg[2] = highByte(msgindex);
    msg[3] = lowByte(msgindex);
    msg[4] = highByte(msgvalue);
    msg[5] = lowByte(msgvalue);
    msg[6] = msg[0]^msg[1]^msg[2]^msg[3]^msg[4]^msg[5];
    msg[7] = PUP_EOF;

    hwSerial->write(msg, 8);
}
