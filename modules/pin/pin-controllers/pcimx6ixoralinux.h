#ifndef PCIMX6IXORALINUX_H
#define PCIMX6IXORALINUX_H

#include "../ipclinux.h"

namespace Pin {
class PcImx6IxoraLinux;
}

/// PinController for the following platform;
/// SoM         : Toradex Apalis Imx6
/// CB          : Toradex Ixora
/// OS          : Linux
class Pin::PcImx6IxoraLinux : public IPcLinux
{
public:
        PcImx6IxoraLinux();

        /// Return pin object according to pinNo. If pinNo exceed the PIN_SIZE or if there is no
        /// representation of the pin on Linux, return nullptr.
        const DPin *getPin(quint8 pinNo) override;

private:
        int enablePwmPin(quint8 pinNo) override;

        /// Ixora pins start from 1 but in our pinMap, it starts from 0 so if it is requested to get
        /// pin X, it should be returned pinMap[X-1].
        ///
        /// Odd pins  : In side of the board
        /// Even pins : Out side of the board
        static const quint8 PIN_SIZE = 36;
        DPin m_pins[PIN_SIZE] = {
                {"", G::UNKNOWN_PIN_TYPE}, // 01
                {"", G::UNKNOWN_PIN_TYPE}, // 02
                {"", G::UNKNOWN_PIN_TYPE}, // 03
                {"", G::UNKNOWN_PIN_TYPE}, // 04
                {"", G::UNKNOWN_PIN_TYPE}, // 05
                {"", G::UNKNOWN_PIN_TYPE}, // 06
                {"", G::GND},             // 07
                {"", G::UNKNOWN_PIN_TYPE}, // 08
                {"", G::UNKNOWN_PIN_TYPE}, // 09
                {"", G::UNKNOWN_PIN_TYPE}, // 10
                {"", G::UNKNOWN_PIN_TYPE}, // 11
                {"", G::VCC},             // 12
                {"36", G::GPIO},         // 13
                {"37", G::GPIO},        // 14
                {"38", G::GPIO},       // 15
                {"39", G::GPIO},       // 16
                {"170", G::GPIO},       // 17
                {"169", G::GPIO},        // 18
                {"2", G::GPIO},           // 19
                {"6", G::GPIO},            // 20
                {"", G::GND},               // 21
                {"in_voltage4_raw", G::ADC}, // 22
                {"in_voltage5_raw", G::ADC}, // 23
                {"in_voltage6_raw", G::ADC}, // 24
                {"in_voltage7_raw", G::ADC}, // 25
                {"", G::GND},               // 26
                {"", G::UNKNOWN_PIN_TYPE}, // 27
                {"", G::UNKNOWN_PIN_TYPE}, // 28
                {"", G::VCC},             // 29
                {"", G::UNKNOWN_PIN_TYPE}, // 30
                {"", G::UNKNOWN_PIN_TYPE}, // 31
                {"", G::GND},             // 32
                {"pwmchip0/pwm0", G::PWM}, // 33
                {"pwmchip1/pwm0", G::PWM}, // 34
                {"pwmchip2/pwm0", G::PWM}, // 35
                {"pwmchip3/pwm0", G::PWM}  // 36
        };
};

#endif // PCIMX6IXORALINUX_H
