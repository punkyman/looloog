#pragma once
#include "control/control.h"

class Pot : Control
{
    private:
        int m_previousValue;
    public:
        Pot(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _signalPin);
        void Update();
};
