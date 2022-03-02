#include "PPUCInputController.h"

PPUCInputController::PPUCInputController(String controllerType, byte pf) {
    pinMode(LED_BUILTIN, OUTPUT);

    platform = pf;
    _eventDispatcher = new PPUCEventDispatcher();
    _solenoids = new PPUCSolenoids(controllerType, _eventDispatcher);

    if (controllerType == "ArduinoMega") {
        _switchMatrix = new PPUCSwitchMatrix(_eventDispatcher, platform);
        _lightMatrix = new PPUCLightMatrix(_eventDispatcher, platform);
        _pin2Dmd = new PPUCPIN2DMD(_eventDispatcher);
        _pupComLink = new PPUCPUPComLink();
        _testButtons = new PPUCInputControllerTestButtons(_eventDispatcher);
    } else {
        Serial.print("Unsupported Input Controller: ");
        Serial.println(controllerType);
    }
}

PPUCSolenoids* PPUCInputController::solenoids() {
    return _solenoids;
}

PPUCSwitchMatrix* PPUCInputController::switchMatrix() {
    return _switchMatrix;
}

PPUCLightMatrix* PPUCInputController::lightMatrix() {
    return _lightMatrix;
}

PPUCPIN2DMD* PPUCInputController::pin2Dmd() {
    return _pin2Dmd;
}

PPUCPUPComLink* PPUCInputController::pupComLink() {
    return _pupComLink;
}

PPUCInputControllerTestButtons* PPUCInputController::testButtons() {
    return _testButtons;
}

PPUCEventDispatcher* PPUCInputController::eventDispatcher() {
    return _eventDispatcher;
}
