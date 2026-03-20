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
    Serial.println("updating pot");
    Serial.println("\tchannel: " + m_channelNumber);
    Serial.println("\tcontrol number " + m_controlNumber);
 
    int value = analogRead(m_signalPin);

    if(m_previousValue != value)
    {
        // taken from code sample, not sure about this conversion
        midi::DataByte midiValue = value >> 3;

        MIDI.sendControlChange(m_controlNumber, midiValue, m_channelNumber);
        m_previousValue = value;
    }
}
