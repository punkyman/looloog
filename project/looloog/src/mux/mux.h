#pragma once

#include "control/control.h"

class Mux
{
    private:
        Control* m_controls;
        int m_numControls;
        int m_s0Pin;
        int m_s1Pin;
        int m_s2Pin;
        int m_s3Pin;
        int m_cableSelectPin;

    public:
        Mux(Control* _controls, int _numControls, int _s0Pin, int _s1Pin, int _s2Pin, int _s3Pin, int _cableSelectPin);
        void Update();
};
