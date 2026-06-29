#include "pot.h"
#include "midihandler/midihandler.h"

#define JITTER_MARGIN 4

Pot::Pot(midi::Channel _channelNumber, midi::DataByte _controlNumber)
        : Control(_channelNumber, _controlNumber)
        , m_previousValue(0)
{
}

void Pot::Update(int _muxPin)
{ 
    int value = analogRead(_muxPin);

    if(value >= (m_previousValue + JITTER_MARGIN) || value <= ( m_previousValue - JITTER_MARGIN))
    {
        // as arduino DAC encodes on 10bit (0-1024), reduce range to (0-128)
        midi::DataByte midiValue = value >> 3;

        Midihandler::SendCC(m_channelNumber, m_controlNumber, midiValue);
        m_previousValue = value;
    }
}
