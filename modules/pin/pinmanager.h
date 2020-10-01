
#ifndef PINMANAGER_H
#define PINMANAGER_H

#include <QObject>
#include "ipincontroller.h"

namespace Pin {
class PinManager;
}

/// The main class of Pin module. Supports pwm, adc, gpio. Just import this class, change settings
/// on globals.h if it is needed and start using pins.
class Pin::PinManager : public QObject
{
        Q_OBJECT
public:
        PinManager();

        /// All the pins must be enabled before it is used. If the pin cannot be enabled, the
        /// function will return the -1.
        int enablePin(quint8 pinNo);

        /// After pin is disabled, it cannot be used.
        void disablePin(quint8 pinNo);

        /// Pin can be input or output. Used for GPIO now.
        void pinMode(quint8 pinNo, G::PinMode mode);

        /// Duty value should be between 0 - 1000. If pin is 3.3V, 500 duty cycle gives 3.3/2V
        /// output.
        void pwmWriteDuty(quint8 pinNo, quint32 val);

        /// Read current duty cycle value which is enteren by pwmWriteDuty
        quint32 pwmReadDuty(quint8 pinNo);
        void pwmWritePeriod(quint8 pinNo, quint32 val);
        quint32 pwmReadPeriod(quint8 pinNo);

        /// Analog read mostly uses ADC so use ADC-supported pin.
        quint16 analogRead(quint8 pinNo);

        /// Control GPIO pins.
        void digitalWrite(quint8 pinNo, bool val);

        /// Read GPIO pin. Mode should be input.
        bool digitalRead(quint8 pinNo);

private:
        void initPinController();

        // Must be initialized according to OS used.
        // TODO: On the release, choose pin controller hard-coded according to target device.
        IPinController *m_pinController;
};

#endif // PINMANAGER_H
