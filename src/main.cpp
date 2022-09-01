#include "Arduino.h"
#include "button.cpp"

void setup()
{
    Serial.begin(115200);
    button_1.setup();
    button_2.setup();
    button_3.setup();
    button_4.setup();
}

void loop()
{
    if (button_1.read())
    {
        Serial.println("pressed button 1");
    }
    if (button_2.read())
    {
        Serial.println("pressed button 2");
    }
    if (button_3.read())
    {
        Serial.println("pressed button 3");
    }
    if (button_4.read())
    {
        Serial.println("pressed button 4");
    }
}