#include <Arduino.h>
#include "midihandler/midihandler.h"
#include "pot/pot.h"
#include "button/button.h"
#include "mux/mux.h"

Pot g_pot1(1, 1, 15);
Pot g_pot2(1, 2, 7);
Button g_button1(1, 3, 15);

Mux g_mux1;
Mux g_mux2;

void setup() {
  Serial.begin(9600);
  // midi initialization without any input expected
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  
// update panel values
  g_mux1.Update();
  g_mux2.Update();

// cap refresh rate to 60hz
  delay(16);
  Serial.println("Ping");
}

