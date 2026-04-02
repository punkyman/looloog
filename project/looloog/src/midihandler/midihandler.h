#pragma once

#include <USB-MIDI.h>

// declare external based on what the MIDI_CREATE_DEFAULT_INSTANCE macro does
extern MIDI_NAMESPACE::MidiInterface<USBMIDI_NAMESPACE::usbMidiTransport> MIDI;
