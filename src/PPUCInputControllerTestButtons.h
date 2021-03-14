/*
  PPUCInputControllerTestButtons.h
  Created by Markus Kalkbrenner, 2021.

  Play more pinball!
*/

#ifndef PPUCInputControllerTestButtons_h
#define PPUCInputControllerTestButtons_h

#include <Arduino.h>
#include <Bounce2.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>

class PPUCInputControllerTestButtons {
public:
    PPUCInputControllerTestButtons(PPUCEventDispatcher* eD);

    void update();

protected:
    PPUCEventDispatcher* eventDispatcher;
    Bounce2::Button* button[2];
};

#endif
