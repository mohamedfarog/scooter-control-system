#include "pincontroller.h"

PinController::PinController()
{
    wiringPiSetup();
}


int
PinController::Read(int pin)
{
    int ReadGPIO;
    ReadGPIO = digitalRead(pin);
    return ReadGPIO;
}

void
PinController::Write(int pin, int value)
{
    digitalWrite(pin, value);
}

void
PinController::Mode(int pin, int mode)
{
    pinMode(pin, mode);
}
