#include "button.h"
#include "midihandler/midihandler.h"

#define MIDI_HIGH 127
#define MIDI_LOW 0

Button::Button(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxPin)
        : Control(_controlNumber, _channelNumber, _muxPin)
        , m_previousState(false)
{
}

void Button::Update(int _muxPin)
{
     bool state = digitalRead(_muxPin);

    if(m_previousState != state)
    {
        Serial.println("\nEvent on button");
        Serial.println("\tchannel: " + m_channelNumber);
        Serial.println("\tcontrol number " + m_controlNumber);
        Serial.println("\tvalue: " + !state);
        
        // as we are reading value for a resistor pullup setup, reverse the logic
        if(state == HIGH)
            MIDI.sendControlChange(m_controlNumber, MIDI_LOW, m_channelNumber);
        else
            MIDI.sendControlChange(m_controlNumber, MIDI_HIGH, m_channelNumber);

        m_previousState = state;
    }
}
