#pragma once
#include <MIDI.h>

class Control
{
    protected:
        midi::DataByte m_controlNumber;
        midi::Channel m_channelNumber;
        int m_muxAddress;


    public:
        Control(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxAddress)
                : m_controlNumber(_controlNumber), m_channelNumber(_channelNumber), m_muxAddress(_muxAddress)
        {}
        int GetMuxAdress() { return m_muxAddress; }
        virtual void Update(int _muxPin) = 0;
};
