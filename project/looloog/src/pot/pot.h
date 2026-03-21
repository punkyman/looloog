#pragma once
#include "control/control.h"

class Pot : public Control
{
    private:
        int m_previousValue;

    public:
        Pot(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxAddress);
        virtual void Update(int _muxPin);
};
