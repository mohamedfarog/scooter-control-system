#include "pcrpi3linux.h"

using namespace Pin;

const DPin *
PcRpi3Linux::getPin(quint8 pinNo)
{
        pinNo--; // pinNo starts from 1, pinMap array starts from 0

        if (pinNo >= PIN_SIZE) {
                return nullptr;
        }

        const DPin *pin = &m_pins[pinNo];

        if (pin->name.isEmpty()) {
                return nullptr;
        }

        return pin;
}
