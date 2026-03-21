#pragma once
#include "control/control.h"

class Button : Control
{
    private:
        bool m_previousState;

    public:
        Button(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxPin);
        virtual void Update(int _muxPin);
};
