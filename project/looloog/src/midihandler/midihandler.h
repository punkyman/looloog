#pragma once

#include <MIDI.h>

// declare external based on what the MIDI_CREATE_DEFAULT_INSTANCE macro does
extern MIDI_NAMESPACE::MidiInterface<MIDI_NAMESPACE::SerialMIDI<HardwareSerial>> MIDI;
