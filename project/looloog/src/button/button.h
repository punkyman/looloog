#pragma once
#include "control/control.h"

class Button : public Control
{
    private:
        bool m_previousState;

    public:
        Button(midi::DataByte _controlNumber, midi::Channel _channelNumber, int _muxAddress);
        virtual void Update(int _muxPin);
};
