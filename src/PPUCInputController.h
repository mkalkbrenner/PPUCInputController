/*
  PPUCInputController.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

#ifndef PPUCINPUTCONTROLLER_h
#define PPUCINPUTCONTROLLER_h

#include <Arduino.h>
#include <PPUCEventDispatcher.h>
#include <PPUCEventListener.h>

#include "PPUCSolenoids.h"
#include "PPUCSwitchMatrix.h"
#include "PPUCLightMatrix.h"
#include "PPUCPIN2DMD.h"
#include "PUPComLink.h"

class PPUCInputController {
public:
    PPUCInputController(String controllerType);

    PPUCSolenoids *solenoids();

    PPUCSwitchMatrix *switchMatrix();

    PPUCLightMatrix *lightMatrix();

    PPUCPIN2DMD *pin2Dmd();

    PPUCPUPComLink *pupComLink();

    PPUCEventDispatcher *eventDispatcher();

private:
    PPUCSolenoids *_solenoids;
    PPUCSwitchMatrix *_switchMatrix;
    PPUCLightMatrix *_lightMatrix;
    PPUCPIN2DMD *_pin2Dmd;
    PPUCPUPComLink *_pupComLink;
    PPUCEventDispatcher *_eventDispatcher;
};

#endif
