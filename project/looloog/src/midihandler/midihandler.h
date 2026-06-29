#pragma once

#include <USB-MIDI.h>

class Midihandler
{
    public:
        static void Init();
        static void SendCC(midi::Channel _channel, midi::DataByte _controlNumber, midi::DataByte _controlValue);
};
