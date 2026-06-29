#pragma once
#include "control/control.h"

class Button : public Control
{
    private:
        bool m_previousState;

    public:
        Button(midi::Channel _channelNumber, midi::DataByte _controlNumber);
        virtual void Update(int _muxPin) override;
};
