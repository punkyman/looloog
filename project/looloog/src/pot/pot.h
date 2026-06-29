#pragma once
#include "control/control.h"

class Pot : public Control
{
    private:
        int m_previousValue;

    public:
        Pot(midi::Channel _channelNumber, midi::DataByte _controlNumber);
        virtual void Update(int _muxPin) override;
};
