#ifndef IDPINS_H
#define IDPINS_H

#include "../common/globals.h"

namespace Pin {
class DPin;
class IDPins;
}

/// A specific pin is represented by the class.
class Pin::DPin
{
public:
        DPin(QString pinName, G::PinType pinType) : name(pinName), type(pinType) {}
        const QString name;
        const G::PinType type;
};

/// Pins are represented by the class wih multiple DPin. IDPins is basically changes according to
/// carier board and SoC combination. Ex: IxoraImx6, IxoraTk1, ApalisImx8
class Pin::IDPins
{
public:
        virtual ~IDPins() = default;
        virtual const DPin *getPin(quint8 pinNo) = 0;
private:
};

#endif // IDPINS_H
