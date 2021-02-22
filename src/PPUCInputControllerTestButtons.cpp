#include "PPUCInputControllerTestButtons.h"

PPUCInputControllerTestButtons::PPUCInputControllerTestButtons(PPUCEventDispatcher* eD) {
    eventDispatcher = eD;

    pinMode(52, INPUT_PULLUP);
    pinMode(53, INPUT_PULLUP);
}

void PPUCInputControllerTestButtons::update() {
    bool state = !digitalRead(52);
    if (state && button3 != state) {
        eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_SWITCH, word(203)));
    }
    button3 = state;

    state = !digitalRead(53);
    if (state && button4 != state) {
        eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_SWITCH, word(204)));
    }
    button4 = state;
}
