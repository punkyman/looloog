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
        Serial.println("\nEvent on pot");
        Serial.println("\tchannel: " + m_channelNumber);
        Serial.println("\tcontrol number " + m_controlNumber);
        Serial.println("\tchannel: " + m_channelNumber);

        // as arduino DAC encodes on 10bit (0-1024), reduce range to (0-128)
        midi::DataByte midiValue = value >> 3;
        // reverse reading do correspond to the expected rotation of the pot
        midiValue = 127 - midiValue;
        Serial.println("\tvalue: ");
        Serial.println(midiValue);

        MIDI.sendControlChange(m_controlNumber, midiValue, m_channelNumber);
        m_previousValue = value;
    }
}
