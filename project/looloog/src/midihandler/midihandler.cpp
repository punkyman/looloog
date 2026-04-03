#include "midihandler.h"

USBMIDI_CREATE_DEFAULT_INSTANCE();

void Midihandler::Init()
{
    // midi initialization without any input expected
    MIDI.begin(MIDI_CHANNEL_OFF);
}

void Midihandler::SendCC(midi::Channel _channel, midi::DataByte _controlNumber, midi::DataByte _controlValue)
{
#ifdef DEBUG_MIDI_THROUGH_SERIAL
    Serial.println("\nMidi Event");
    Serial.println("channel");
    Serial.println(_channel);
    Serial.println("control number");
    Serial.println(_controlNumber);
    Serial.println("value");
    Serial.println(_controlValue);
#else
    MIDI.sendControlChange(_controlNumber, _controlValue, _channel);
#endif
}
