#include <Arduino.h>
#include "mux.h"

Mux::Mux(Control* _controls, int _numControls, int _s0Pin, int _s1Pin, int _s2Pin, int _s3Pin, int _cableSelectPin)
            : m_controls(_controls), m_numControls(_numControls), m_s0Pin(_s0Pin), m_s1Pin(_s1Pin), m_s2Pin(_s2Pin), m_s3Pin(_s3Pin), m_cableSelectPin(_cableSelectPin)
{
    pinMode(m_s0Pin, OUTPUT);
    pinMode(m_s1Pin, OUTPUT);
    pinMode(m_s2Pin, OUTPUT);
    pinMode(m_s3Pin, OUTPUT);
    pinMode(m_cableSelectPin, OUTPUT);
}

void Mux::Update()
{
    Serial.println("\nupdate mux component on CS pin " + m_cableSelectPin);

    for(int i = 0; i < m_numControls; ++i)
    {
        m_controls[i].Update();
    }
}
