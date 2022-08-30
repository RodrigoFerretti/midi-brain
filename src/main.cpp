#include "Arduino.h"
#include "button.cpp"

void setup()
{
    Serial.begin(115200);
    button.setup();
}

void loop()
{
    button.read();
}