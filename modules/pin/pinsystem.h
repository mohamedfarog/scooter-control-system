/// TODO: NOT IMPLEMENTED YET
#ifndef PINSYSTEM_H
#define PINSYSTEM_H

#include "pinmanager.h"

namespace Pin {
class PinSystem;
}

class Pin::PinSystem
{
public:
        PinManager *getPinManager();

private:
        PinManager m_pinManager;
};

#endif // PINSYSTEM_H
