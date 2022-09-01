#include "Arduino.h"

struct button_t
{
    int pin;
    int debounce_time;
    bool state;
    int state_time;

    void setup()
    {
        pinMode(pin, INPUT_PULLUP);
    }

    bool read()
    {
        bool read = digitalRead(pin);
        bool is_not_boucing = millis() - state_time > debounce_time;

        if ((read < state) & is_not_boucing)
        {
            state = read;
            state_time = millis();

            return 1;
        }

        if ((read > state) & is_not_boucing)
        {
            state = read;
            state_time = millis();

            return 0;
        }

        state = read;

        return 0;
    }
};

button_t button_1 = {
    .pin = 14,
    .debounce_time = 20,
};

button_t button_2 = {
    .pin = 27,
    .debounce_time = 20,
};

button_t button_3 = {
    .pin = 26,
    .debounce_time = 20,
};

button_t button_4 = {
    .pin = 25,
    .debounce_time = 20,
};
