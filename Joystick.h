#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class Joystick {
    public:     Joystick(int, int, int, bool, float, float, float, bool, float);
                float readX();
                float readY();
                bool readZ();
                String toString();
                bool isUp();
                bool isDown();
                bool isLeft();
                bool isRight();
    private:    int pinX;
                int pinY;
                int pinZ;
                bool centerOrigin;
                float minXY;
                float maxXY;
                bool enableDiagonals;
                float activationMargin;
                float triggerSensitivity;
};

#endif
