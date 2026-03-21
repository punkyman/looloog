#pragma once

#include "control/control.h"

class Mux
{
    private:
        static int m_s0Pin;
        static int m_s1Pin;
        static int m_s2Pin;
        static int m_s3Pin;

        Control* m_controls;
        int m_numControls;
        int m_cableSelectPin;
        int m_outputPin;

    public:
        Mux(Control* _controls, int _numControls, int _cableSelectPin, int _outputPin);
        static void InitMuxBus(int _s0Pin, int _s1Pin, int _s2Pin, int _s3Pin);
        void Update();
};
