#include "Arduino.h"
#include "button.cpp"
#include "MIDI.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial, midi_out);

bool bank = 0;

void setup()
{
    Serial.begin(31250);

    button_1.setup();
    button_2.setup();
    button_3.setup();
    button_4.setup();
}

void loop()
{
    if (button_1.read())
    {
        midi_out.sendControlChange(11, 127, 1);
        midi_out.sendControlChange(16, 127, 1);
    }
    if (button_2.read())
    {
        midi_out.sendControlChange(18, 127, 1);
        midi_out.sendControlChange(19, 127, 1);
        midi_out.sendControlChange(20, 127, 1);
    }
    if (button_3.read())
    {
        midi_out.sendProgramChange(bank, 1);

        if (bank == 0)
        {
            bank = 1;
        }
        else
        {
            bank = 0;
        }
    }
    if (button_4.read())
    {
        midi_out.sendControlChange(22, 127, 1);
    }
}