#include "PPUCInputControllerTestButtons.h"

PPUCInputControllerTestButtons::PPUCInputControllerTestButtons(PPUCEventDispatcher* eD) {
    eventDispatcher = eD;

    for (int i = 0; i <= 1; i++) {
        button[i] = new Bounce2::Button();
        button[i]->attach(52 + i, INPUT_PULLUP);
        button[i]->interval(10);
        button[i]->setPressedState(LOW);
    }
}

void PPUCInputControllerTestButtons::update() {
    for (int i = 0; i <= 1; i++) {
        button[i]->update();
        if (button[i]->pressed()) {
            eventDispatcher->dispatch(new PPUCEvent(EVENT_SOURCE_SWITCH, word(0, 203 + i)));
        }
    }
}
