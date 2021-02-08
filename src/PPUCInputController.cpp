#include "PPUCInputController.h"

PPUCInputController::PPUCInputController(String controllerType) {
    _eventDispatcher = new PPUCEventDispatcher();
    _solenoids = new PPUCSolenoids(controllerType, _eventDispatcher);

    if (controllerType == "PPUC-Arduino-0.1.0") {
        _switchMatrix = new PPUCSwitchMatrix(_eventDispatcher);
        _lightMatrix = new PPUCLightMatrix(_eventDispatcher);
        _pin2Dmd = new PPUCPIN2DMD(_eventDispatcher);
        _pupComLink = new PUPComLink();
    } else {
        Serial.print("Unsupported Input Controller: ");
        Serial.println(controllerType);
    }
}

PPUCSolenoids *PPUCInputController::solenoids() {
    return _solenoids;
}

PPUCSwitchMatrix *PPUCInputController::switchMatrix() {
    return _switchMatrix;
}

PPUCLightMatrix *PPUCInputController::lightMatrix() {
    return _lightMatrix;
}

PPUCPIN2DMD *PPUCInputController::pin2Dmd() {
    return _pin2Dmd;
}

PPUCPUPComLink *PPUCInputController::pupComLink() {
    return _pupComLink;
}

PPUCEventDispatcher *PPUCInputController::eventDispatcher() {
    return _eventDispatcher;
}
