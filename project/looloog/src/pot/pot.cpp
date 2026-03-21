#include "pot.h"
#include "midihandler/midihandler.h"

Pot::Pot(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _signalPin)
        : Control(_controlNumber, _channelNumber, _signalPin)
        , m_previousValue(0)
{
    pinMode(m_signalPin, INPUT);
}

void Pot::Update()
{ 
    int value = analogRead(m_signalPin);

    if(m_previousValue != value)
    {
        Serial.println("\nEvent on pot");
        Serial.println("\tchannel: " + m_channelNumber);
        Serial.println("\tcontrol number " + m_controlNumber);
        Serial.println("\tchannel: " + m_channelNumber);

        // taken from code sample, not sure about this conversion
        midi::DataByte midiValue = value >> 3;
        Serial.println("\tvalue: " + midiValue);

        MIDI.sendControlChange(m_controlNumber, midiValue, m_channelNumber);
        m_previousValue = value;
    }
}
