#include "Joystick.h"

// Constructor - It saves all the joystick data
Joystick::Joystick(int pinX, int pinY, int pinZ, bool centerOrigin, float minXY, float maxXY, float activationMargin, bool enableDiagonals, float triggerSensitivity) {
    this->pinX = pinX;
    this->pinY = pinY;
    this->pinZ = pinZ;
    this->centerOrigin = centerOrigin;
    this->minXY = minXY;
    this->maxXY = maxXY;
    this->activationMargin = activationMargin;
    this->enableDiagonals = enableDiagonals;
    this->triggerSensitivity = triggerSensitivity;

    pinMode(pinZ, INPUT);

    digitalWrite(this->pinZ, HIGH);
}


// Functions
float Joystick::readX() {
    float rawValue = (float)analogRead(this->pinX);
    float value = (rawValue - 0) * (maxXY - minXY) / (1023 - 0) + minXY;
    if(centerOrigin){
        value -= ((maxXY - minXY) / 2.0);
    }
    if(value > 0 && value < activationMargin){
        value = 0;
    }else if(value < 0 && value > (-1 * activationMargin)){
        value = 0;
    }
    return value;
}

float Joystick::readY() {
    float rawValue = (float)analogRead(this->pinY);
    float value = (rawValue - 0) * (maxXY - minXY) / (1023 - 0) + minXY;
    if(centerOrigin){
        value -= ((maxXY - minXY) / 2.0);
    }
    if(value > 0 && value < activationMargin){
        value = 0;
    }else if(value < 0 && value > (-1 * activationMargin)){
        value = 0;
    }
    value *= -1;
    return value;
}

bool Joystick::readZ() {
    bool value = digitalRead(this->pinZ);
    value = !value;

    return value;
}

bool Joystick::isUp() {
    float val = readY();
    bool value = false;
    if(val > triggerSensitivity){value = true;}
    return value;
}

bool Joystick::isDown() {
    float val = readY();
    bool value = false;
    if(val < (-1 * triggerSensitivity)){value = true;}
    return value;
}

bool Joystick::isRight() {
    float val = readX();
    bool value = false;
    if(val > triggerSensitivity){value = true;}
    return value;
}

bool Joystick::isLeft() {
    float val = readX();
    bool value = false;
    if(val < (-1 * triggerSensitivity)){value = true;}
    return value;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Get the pins
String Joystick::toString() {
    String ret = String("JoystickPins: {");
    ret.concat("pinX=");
    ret.concat(this->pinX);
    ret.concat(", pinY=");
    ret.concat(this->pinY);
    ret.concat(", pinZ=");
    ret.concat(this->pinZ);
    ret.concat("}");
    
    return ret;
}
