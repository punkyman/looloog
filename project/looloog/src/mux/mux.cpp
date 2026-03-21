#include <Arduino.h>
#include "mux.h"

Mux::Mux(Control* _controls, int _numControls, int _s0Pin, int _s1Pin, int _s2Pin, int _s3Pin, int _cableSelectPin, int _outputPin)
            : m_controls(_controls), m_numControls(_numControls), m_s0Pin(_s0Pin), m_s1Pin(_s1Pin), m_s2Pin(_s2Pin), m_s3Pin(_s3Pin), m_cableSelectPin(_cableSelectPin), m_outputPin(_outputPin)
{
    pinMode(m_s0Pin, OUTPUT);
    pinMode(m_s1Pin, OUTPUT);
    pinMode(m_s2Pin, OUTPUT);
    pinMode(m_s3Pin, OUTPUT);
    pinMode(m_cableSelectPin, OUTPUT);
    pinMode(m_outputPin, INPUT);
}

void Mux::Update()
{
    Serial.println("\nupdate mux component on CS pin " + m_cableSelectPin);

    for(int i = 0; i < m_numControls && i < 16; ++i)
    {
        bool s0 = m_numControls & 0b1000;
        bool s1 = m_numControls & 0b0100;
        bool s2 = m_numControls & 0b0010;
        bool s3 = m_numControls & 0b0001;

        digitalWrite(m_s0Pin, s0);
        digitalWrite(m_s0Pin, s1);
        digitalWrite(m_s0Pin, s2);
        digitalWrite(m_s0Pin, s3);

        int debugValue = s0 * 0b1000 + s1 * 0b0100 + s2 * 0b0010 + s3 * 0b0001;

        Serial.println("\nupdate for component number " + debugValue);

        m_controls[i].Update(m_outputPin);
    }
}
