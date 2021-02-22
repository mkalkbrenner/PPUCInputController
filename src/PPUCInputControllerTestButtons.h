/*
  PPUCInputControllerTestButtons.h
  Created by Markus Kalkbrenner, 2021.

  Play more pinball!
*/

#ifndef PPUCInputControllerTestButtons_h
#define PPUCInputControllerTestButtons_h

#include <Arduino.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>

class PPUCInputControllerTestButtons {
public:
    PPUCInputControllerTestButtons(PPUCEventDispatcher* eD);

    void update();

protected:
    PPUCEventDispatcher* eventDispatcher;
    bool button3;
    bool button4;
};

#endif
