#include <Arduino.h>
#include "board_utils.h"

#define D6 6
#define D7 7
#define D8 8
#define D9 9

#define BUS_S0_PIN 2
#define BUS_S1_PIN 3
#define BUS_S2_PIN 4
#define BUS_S3_PIN 5

#define MODULE_1_MUX_1_MIDI_CHANNEL 1
#define MODULE_1_MUX_2_MIDI_CHANNEL 2
#define MODULE_2_MUX_1_MIDI_CHANNEL 3
#define MODULE_2_MUX_2_MIDI_CHANNEL 4


DECLARE_MUX(g_module1Mux1, D6, A3, MODULE_1_MUX_1_MIDI_CHANNEL)
DECLARE_MUX(g_module1Mux2, D7, A2, MODULE_1_MUX_2_MIDI_CHANNEL)
DECLARE_MUX(g_module2Mux1, D8, A1, MODULE_2_MUX_1_MIDI_CHANNEL)
DECLARE_MUX(g_module2Mux2, D9, A0, MODULE_2_MUX_2_MIDI_CHANNEL)

void setup() {
  Serial.begin(9600);

  // initialize bus shared by all mux
  Mux::InitMuxBus(BUS_S0_PIN, BUS_S1_PIN, BUS_S2_PIN, BUS_S3_PIN);
}

void loop() {
  unsigned long start = millis();

  g_module1Mux1.Update();
  g_module1Mux2.Update();

  g_module2Mux1.Update();
  g_module2Mux2.Update();

  unsigned long duration = millis() - start;

  // cap refresh rate to 60hz
  delay(16 - duration);
}

