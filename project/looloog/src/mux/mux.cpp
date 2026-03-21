#include <Arduino.h>
#include "mux.h"

int Mux::m_s0Pin;
int Mux::m_s1Pin;
int Mux::m_s2Pin;
int Mux::m_s3Pin;

Mux::Mux(Control *_controls, int _numControls, int _cableSelectPin, int _outputPin)
    : m_controls(_controls), m_numControls(_numControls), m_cableSelectPin(_cableSelectPin), m_outputPin(_outputPin)
{
    pinMode(m_cableSelectPin, OUTPUT);
    pinMode(m_outputPin, INPUT);

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
    Serial.println("\nupdate mux component on CS pin " + m_cableSelectPin);

    digitalWrite(m_cableSelectPin, LOW);

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < m_numControls && j < 16; ++j)
        {
            if (m_controls[j].GetMuxAdress() == i)
            {
                bool s0 = i & 0b1000;
                bool s1 = i & 0b0100;
                bool s2 = i & 0b0010;
                bool s3 = i & 0b0001;

                digitalWrite(m_s0Pin, s0);
                digitalWrite(m_s0Pin, s1);
                digitalWrite(m_s0Pin, s2);
                digitalWrite(m_s0Pin, s3);

                int debugValue = s0 * 0b1000 + s1 * 0b0100 + s2 * 0b0010 + s3 * 0b0001;

                Serial.println("\nupdate for component number " + debugValue);

                m_controls[j].Update(m_outputPin);
            }
        }
    }

    digitalWrite(m_cableSelectPin, HIGH);
}
