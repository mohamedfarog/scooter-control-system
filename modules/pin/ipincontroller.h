#ifndef IPINCONTROLLER_H
#define IPINCONTROLLER_H

#include <QString>
#include "../common/globals.h"

namespace Pin {
class IPinController;
}

/// Pin controlling changes according to OS, Device etc. so for each device, create new class by
/// using this interface. When the functions below run, necessary actions should be written under
/// the concrete class.
class Pin::IPinController
{
public:
        virtual ~IPinController() = default;

        // General
        virtual int enablePin(quint8 pinNo) = 0;
        virtual void disablePin(quint8 pinNo) = 0;
        virtual void setMode(quint8 pinNo, G::PinMode mode) = 0;

        // PWM
        virtual void setPwmDuty(quint8 pinNo, quint32 val) = 0;
        virtual quint32 getPwmDuty(quint8 pinNo) = 0;
        virtual void setPwmPeriod(quint8 pinNo, quint32 val) = 0;
        virtual quint32 getPwmPeriod(quint8 pinNo) = 0;

        // ADC
        virtual quint16 getAdcVal(quint8 pinNo) = 0;

        // GPIO
        virtual bool getGpioVal(quint8 pinNo) = 0;
        virtual void setGpioVal(quint8 pinNo, bool val) = 0;
};

#endif // IPINCONTROLLER_H
