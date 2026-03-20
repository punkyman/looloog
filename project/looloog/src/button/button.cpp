#include "button.h"
#include "midihandler/midihandler.h"

#define MIDI_HIGH 127
#define MIDI_LOW 0

Button::Button(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _signalPin)
        : Control(_controlNumber, _channelNumber, _signalPin)
        , m_previousState(false)
{
    pinMode(m_signalPin, INPUT);
}

void Button::Update()
{
    Serial.println("updating button");
    Serial.println("\tchannel: " + m_channelNumber);
    Serial.println("\tcontrol number " + m_controlNumber);
 
    bool state = digitalRead(m_signalPin);

    if(m_previousState != state)
    {
        // as we are reading value for a resistor pullup setup, reverse the logic
        if(state == HIGH)
            MIDI.sendControlChange(m_controlNumber, MIDI_LOW, m_channelNumber);
        else
            MIDI.sendControlChange(m_controlNumber, MIDI_HIGH, m_channelNumber);

        m_previousState = state;
    }
}
