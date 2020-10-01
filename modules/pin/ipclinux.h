#ifndef IPCLINUX_H
#define IPCLINUX_H

#include "ipincontroller.h"
#include "idpins.h"

namespace Pin {
class IPcLinux;
}

class Pin::IPcLinux : public IPinController, public IDPins
{
public:
        /// Find pin type and trigger suitable functions according to pin type. If the pin cannot be
        /// enabled, return non-zero value.
        int enablePin(quint8 pinNo);
        void disablePin(quint8 pinNo);
        void setMode(quint8 pinNo, G::PinMode mode);
        void setPwmDuty(quint8 pinNo, quint32 val);
        quint32 getPwmDuty(quint8 pinNo);
        void setPwmPeriod(quint8 pinNo, quint32 val);
        quint32 getPwmPeriod(quint8 pinNo);
        quint16 getAdcVal(quint8 pinNo);
        bool getGpioVal(quint8 pinNo);
        void setGpioVal(quint8 pinNo, bool val);

        virtual const DPin *getPin(quint8 pinNo) = 0;

private:
        virtual int enablePwmPin(quint8 = 0) { return -1; }
        virtual void disablePwmPin(quint8 pinNo);
        virtual void setGpioMode(quint8 pinNo, G::PinMode mode);
        virtual int exportGpioPin(quint8 pinNo);
        virtual void unexportGpioPin(quint8 pinNo);

        /// PinName is how Linux see the Pin.
        QString getPinName(quint8 pinNo);
        G::PinType getPinType(quint8 pinNo);

protected:
        /// Linux paths
        QString getPwmDir() { return "/sys/class/pwm/"; }

        /// All other pwm path functions will use this functions so making change here affects all
        /// pwm paths.
        QString getPwmPinDir(quint8 pinNo);
        QString getPwmDutyPath(quint8 pinNo);
        QString getPwmPeriodPath(quint8 pinNo);
        QString getPwmEnablePath(quint8 pinNo);

        QString getAdcDir() { return "/sys/bus/iio/devices/iio:device0/"; }

        /// All other adc path functions will use this functions so making change here affects all
        /// pwm paths.
        QString getAdcPinPath(quint8 pinNo);
        QString getAdcValPath(quint8 pinNo);

        /// All other gpio path functions will use this functions so making change here affects all
        /// pwm paths.
        QString getGpioDir() { return "/sys/class/gpio/"; }
        QString getGpioExportPath() { return getGpioDir() + "export"; }
        QString getGpioUnexportPath() { return getGpioDir() + "unexport"; }
        QString getGpioPinDir(quint8 pinNo);
        QString getGpioValPath(quint8 pinNo);
        QString getGpioDirectionPath(quint8 pinNo);
};

///
/// Model for pin definitions
///
//static const quint8 PIN_SIZE = 40;
//DPin m_pins[PIN_SIZE] = {
//        {"", UNKNOWN_PIN_TYPE}, // 01
//        {"", UNKNOWN_PIN_TYPE}, // 02
//        {"", UNKNOWN_PIN_TYPE}, // 03
//        {"", UNKNOWN_PIN_TYPE}, // 04
//        {"", UNKNOWN_PIN_TYPE}, // 05
//        {"", UNKNOWN_PIN_TYPE}, // 06
//        {"", UNKNOWN_PIN_TYPE}, // 07
//        {"", UNKNOWN_PIN_TYPE}, // 08
//        {"", UNKNOWN_PIN_TYPE}, // 09
//        {"", UNKNOWN_PIN_TYPE}, // 10
//        {"", UNKNOWN_PIN_TYPE}, // 11
//        {"", UNKNOWN_PIN_TYPE}, // 12
//        {"", UNKNOWN_PIN_TYPE}, // 13
//        {"", UNKNOWN_PIN_TYPE}, // 14
//        {"", UNKNOWN_PIN_TYPE}, // 15
//        {"", UNKNOWN_PIN_TYPE}, // 16
//        {"", UNKNOWN_PIN_TYPE}, // 17
//        {"", UNKNOWN_PIN_TYPE}, // 18
//        {"", UNKNOWN_PIN_TYPE}, // 19
//        {"", UNKNOWN_PIN_TYPE}, // 20
//        {"", UNKNOWN_PIN_TYPE}, // 21
//        {"", UNKNOWN_PIN_TYPE}, // 22
//        {"", UNKNOWN_PIN_TYPE}, // 23
//        {"", UNKNOWN_PIN_TYPE}, // 24
//        {"", UNKNOWN_PIN_TYPE}, // 25
//        {"", UNKNOWN_PIN_TYPE}, // 26
//        {"", UNKNOWN_PIN_TYPE}, // 27
//        {"", UNKNOWN_PIN_TYPE}, // 28
//        {"", UNKNOWN_PIN_TYPE}, // 29
//        {"", UNKNOWN_PIN_TYPE}, // 30
//        {"", UNKNOWN_PIN_TYPE}, // 31
//        {"", UNKNOWN_PIN_TYPE}, // 32
//        {"", UNKNOWN_PIN_TYPE}, // 33
//        {"", UNKNOWN_PIN_TYPE}, // 34
//        {"", UNKNOWN_PIN_TYPE}, // 35
//        {"", GPIO}, // 36
//        {"", ADC},  // 37
//        {"", PWM},  // 38
//        {"", VCC},  // 39
//        {"", GND}   // 40
//};

#endif // IPCLINUX_H
