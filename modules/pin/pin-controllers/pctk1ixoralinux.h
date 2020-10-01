#ifndef PCTK1IXORALINUX_H
#define PCTK1IXORALINUX_H

#include "../ipclinux.h"

namespace Pin {
class PcTk1IxoraLinux;
}

/// PinController for the following platform;
/// SoM         : Toradex Apalis TK1
/// CB          : Toradex Ixora
/// OS          : Linux
class Pin::PcTk1IxoraLinux : public IPcLinux
{
public:
        /// Return pin object according to pinNo. If pinNo exceed the PIN_SIZE or if there is no
        /// representation of the pin on Linux, return nullptr.
        const DPin *getPin(quint8 pinNo) override;

private:
        int enablePwmPin(quint8 pinNo) override;

        /// Ixora pins start from 1 but in our m_pins, it starts from 0 so if it is requested to get
        /// pin X, it should be returned m_pins[X-1].
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
                {"250", G::GPIO},        // 13
                {"248", G::GPIO},       // 14
                {"108", G::GPIO},      // 15
                {"109", G::GPIO},      // 16
                {"237", G::GPIO},       // 17
                {"238", G::GPIO},        // 18
                {"233", G::GPIO},         // 19
                {"234", G::GPIO},          // 20
                {"", G::GND},               // 21
                {"in_voltage0_raw", G::ADC}, // 22
                {"in_voltage1_raw", G::ADC}, // 23
                {"in_voltage2_raw", G::ADC}, // 24
                {"in_voltage3_raw", G::ADC}, // 25
                {"", G::GND},               // 26
                {"", G::UNKNOWN_PIN_TYPE}, // 27
                {"", G::UNKNOWN_PIN_TYPE}, // 28
                {"", G::VCC},             // 29
                {"", G::UNKNOWN_PIN_TYPE}, // 30
                {"", G::UNKNOWN_PIN_TYPE}, // 31
                {"", G::GND},             // 32
                {"pwmchip0/pwm0", G::PWM}, // 33
                {"pwmchip0/pwm1", G::PWM}, // 34
                {"pwmchip0/pwm2", G::PWM}, // 35
                {"pwmchip0/pwm3", G::PWM}  // 36
        };
};

#endif // PCTK1IXORALINUX_H
