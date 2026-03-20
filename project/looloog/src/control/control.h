#pragma once
#include <MIDI.h>

class Control
{
    protected:
        midi::DataByte m_controlNumber;
        midi::Channel m_channelNumber;
        int m_signalPin;

    public:
        Control(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _signalPin)
                : m_controlNumber(_controlNumber), m_channelNumber(_channelNumber), m_signalPin(_signalPin)
        {}
        
        virtual void Update() = 0;
};
