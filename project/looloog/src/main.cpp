#include <Arduino.h>
#include "midihandler/midihandler.h"
#include "control/control.h"
#include "pot/pot.h"
#include "button/button.h"
#include "mux/mux.h"

#define D6 6
#define D7 7

#define BUS_S0_PIN 2
#define BUS_S1_PIN 3
#define BUS_S2_PIN 4
#define BUS_S3_PIN 5

Control g_mux1Controls[] = {
 Pot(1, 1, 15)
};

Control g_mux2Controls[] = {
  Pot(1, 2, 7),
  Button(1, 3, 15),
};

Mux g_mux1(g_mux1Controls, 1, D6, A3);
Mux g_mux2(g_mux2Controls, 2, D7, A2);

void setup() {
  Serial.begin(9600);

  // initialize bus shared by all mux
  Mux::InitMuxBus(BUS_S0_PIN, BUS_S1_PIN, BUS_S2_PIN, BUS_S3_PIN);

  // midi initialization without any input expected
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  unsigned long start = millis();

  // update each mux to send midi packets
  g_mux1.Update();
  g_mux2.Update();

  unsigned long duration = millis() - start;

  // cap refresh rate to 60hz
  delay(16 - duration);
}

