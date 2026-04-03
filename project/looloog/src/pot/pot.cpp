#include "pot.h"
#include "midihandler/midihandler.h"

Pot::Pot(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxAddress)
        : Control(_controlNumber, _channelNumber, _muxAddress)
        , m_previousValue(0)
{
}

void Pot::Update(int _muxPin)
{ 
    int value = analogRead(_muxPin);

    if(m_previousValue != value)
    {
        // as arduino DAC encodes on 10bit (0-1024), reduce range to (0-128)
        midi::DataByte midiValue = value >> 3;

        Midihandler::SendCC(m_channelNumber, m_controlNumber, midiValue);
        m_previousValue = value;
    }
}
