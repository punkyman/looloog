#include "button.h"
#include "midihandler/midihandler.h"

#define MIDI_HIGH 127
#define MIDI_LOW 0

Button::Button(midi::Channel _channelNumber, midi::DataByte _controlNumber)
        : Control(_channelNumber, _controlNumber)
        , m_previousState(HIGH)
{
}

void Button::Update(int _muxPin)
{
     bool state = digitalRead(_muxPin);

    if(m_previousState != state)
    {   
        // as we are reading value for a resistor pullup setup, reverse the logic
        if(state == HIGH)
            Midihandler::SendCC(m_channelNumber, m_controlNumber, MIDI_LOW);
        else
            Midihandler::SendCC(m_channelNumber, m_controlNumber, MIDI_HIGH);

        m_previousState = state;
    }
}
