/*
  PPUCSolenoids.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/
#ifndef PPUCSOLENOIDS_h
#define PPUCSOLENOIDS_h

#define NUM_PINS 26

#include <Arduino.h>
#include <PPUCEventDispatcher.h>

class PPUCSolenoids {
public:
    //Constructor
    PPUCSolenoids(String controllerType, PPUCEventDispatcher* eD);

    // WPC
    void registerJ3(byte pin, byte number);
    void registerJ122(byte pin, byte number);
    void registerJ123(byte pin, byte number);
    void registerJ124(byte pin, byte number);
    void registerJ125(byte pin, byte number);
    void registerJ126(byte pin, byte number);

    // WPC95
    void registerJ110(byte pin, byte number);
    void registerJ111(byte pin, byte number);

    // Sega
    void registerJ9(byte pin, byte number);
    void registerP11(byte pin, byte number);
    void registerP12(byte pin, byte number);

    void update();

    void print();

private:
    PPUCEventDispatcher* eventDispatcher;

    int pins[NUM_PINS];
    bool pinStates[NUM_PINS];
    byte previousPinStates[NUM_PINS];

    byte registeredNum[NUM_PINS];
};


#endif
