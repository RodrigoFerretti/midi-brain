#include "Arduino.h"
#include "button.cpp"
#include "MIDI.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial, midi_out);

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
        midi_out.sendControlChange(22, 127, 1);
    }
    if (button_2.read())
    {
        midi_out.sendProgramChange(0, 1);
    }
    if (button_3.read())
    {
        midi_out.sendProgramChange(1, 1);
    }
    if (button_4.read())
    {
        midi_out.sendProgramChange(2, 1);
    }
}