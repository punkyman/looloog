#include <Arduino.h>
#include "midihandler/midihandler.h"

void setup() {
  Serial.begin(9600);
  // midi initialization without any input expected
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
// update panel values

// cap refresh rate to 60hz
  delay(16);
  Serial.println("Ping");
}

