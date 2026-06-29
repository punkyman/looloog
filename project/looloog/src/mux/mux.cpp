#include <Arduino.h>
#include "mux.h"

int Mux::m_s0Pin;
int Mux::m_s1Pin;
int Mux::m_s2Pin;
int Mux::m_s3Pin;

Mux::Mux(Control** _controls, int _numControls, int _cableSelectPin, int _outputPin)
    : m_controls(_controls), m_numControls(_numControls), m_cableSelectPin(_cableSelectPin), m_outputPin(_outputPin)
{
    pinMode(m_cableSelectPin, OUTPUT);
    pinMode(m_outputPin, INPUT);
    // safety first, make sure pullup resistor is disabled on input pin
    digitalWrite(m_outputPin, LOW);

    // default to HIGH as cable select is expected to be low to read address values
    digitalWrite(m_cableSelectPin, HIGH);
}

void Mux::InitMuxBus(int _s0Pin, int _s1Pin, int _s2Pin, int _s3Pin)
{
    m_s0Pin = _s0Pin;
    m_s1Pin = _s1Pin;
    m_s2Pin = _s2Pin;
    m_s3Pin = _s3Pin;

    pinMode(m_s0Pin, OUTPUT);
    pinMode(m_s1Pin, OUTPUT);
    pinMode(m_s2Pin, OUTPUT);
    pinMode(m_s3Pin, OUTPUT);
}

// enable component
// then use the bus to select the used addresses and update existing controls
// 74HC4067 component frequency change is 89mhz, so this code should be safe to execute without additional delay
void Mux::Update()
{
    // Serial.println("\nupdate mux component on CS pin " + m_cableSelectPin);

    digitalWrite(m_cableSelectPin, LOW);

    for (int i = 0; i < m_numControls && i < 16; ++i)
    {
        // predicate : control is plugged at a mux address based relative to its number
        int address = m_controls[i]->GetControlNumber();
        bool s3 = address & 0b1000;
        bool s2 = address & 0b0100;
        bool s1 = address & 0b0010;
        bool s0 = address & 0b0001;

        digitalWrite(m_s0Pin, s0 ? HIGH : LOW);
        digitalWrite(m_s1Pin, s1 ? HIGH : LOW);
        digitalWrite(m_s2Pin, s2 ? HIGH : LOW);
        digitalWrite(m_s3Pin, s3 ? HIGH : LOW);

        //int debugValue = s3 * 0b1000 + s2 * 0b0100 + s1 * 0b0010 + s0 * 0b0001;
        //Serial.println("\nupdate for component number ");
        //Serial.println(debugValue);

        m_controls[i]->Update(m_outputPin);
    }

    digitalWrite(m_cableSelectPin, HIGH);
}
