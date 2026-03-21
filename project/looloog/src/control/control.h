#pragma once
#include <MIDI.h>

class Control
{
    protected:
        midi::DataByte m_controlNumber;
        midi::Channel m_channelNumber;

    public:
        Control(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxPin)
                : m_controlNumber(_controlNumber), m_channelNumber(_channelNumber)
        {}
        virtual void Update(int _muxPin) = 0;
};
