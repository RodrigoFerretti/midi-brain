#include "Arduino.h"

struct button_t
{
    int pin;
    bool state;

    void setup()
    {
        pinMode(pin, INPUT_PULLUP);
    }

    bool read()
    {
        bool press = 0;
        bool read = digitalRead(pin);

        if (read < state)
        {
            press = 1;
        }

        state = read;

        return press;
    }
};

button_t button = {
    .pin = 27,
};
