#pragma once
#include <MIDI.h>

 class Control
{
    protected:
        midi::DataByte m_controlNumber;
        midi::Channel m_channelNumber;

    public:
        Control(midi::Channel _channelNumber, midi::DataByte _controlNumber)
                : m_controlNumber(_controlNumber), m_channelNumber(_channelNumber)
        {}
        int GetControlNumber() { return m_controlNumber; }
        virtual void Update(int _muxPin) {}
};
