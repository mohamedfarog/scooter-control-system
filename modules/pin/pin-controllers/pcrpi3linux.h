#ifndef PCRPI3LINUX_H
#define PCRPI3LINUX_H

#include "../ipclinux.h"

namespace Pin {
class PcRpi3Linux;
}

/// PinController for the following platform;
/// SoM         : Raspberry Pi 3
/// OS          : Linux
class Pin::PcRpi3Linux : public IPcLinux
{
public:
        /// Return pin object according to pinNo. If pinNo exceed the PIN_SIZE or if there is no
        /// representation of the pin on Linux, return nullptr.
        const DPin *getPin(quint8 pinNo) override;

private:
        /// RPI3 pins start from 1 but in our m_pins, it starts from 0 so if it is requested to get
        /// pin X, it should be returned m_pins[X-1].
        ///
        /// Odd1 pins  : In side of the board
        /// Even2 pins : Out side of the board
        static const quint8 PIN_SIZE = 40;
        DPin m_pins[PIN_SIZE] = {
                {"", G::VCC},      // 01
                {"", G::VCC},      // 02
                {"2", G::GPIO},    // 03
                {"", G::VCC},      // 04
                {"3", G::GPIO},    // 05
                {"", G::GND},      // 06
                {"4", G::GPIO},    // 07
                {"14", G::GPIO},   // 08
                {"", G::GND},      // 09
                {"15", G::GPIO},   // 10
                {"17", G::GPIO},   // 11
                {"18", G::GPIO},   // 12
                {"27", G::GPIO},   // 13
                {"", G::GND},      // 14
                {"22", G::GPIO},   // 15
                {"23", G::GPIO},   // 16
                {"", G::VCC},      // 17
                {"24", G::GPIO},   // 18
                {"10", G::GPIO},   // 19
                {"", G::GND},      // 20
                {"9", G::GPIO},    // 21
                {"25", G::GPIO},   // 22
                {"11", G::GPIO},   // 23
                {"8", G::GPIO},    // 24
                {"", G::GND},      // 25
                {"7", G::GPIO},    // 26
                {"", G::UNKNOWN_PIN_TYPE}, // 27
                {"", G::UNKNOWN_PIN_TYPE}, // 28
                {"5", G::GPIO},    // 29
                {"", G::GND},      // 30
                {"6", G::GPIO},    // 31
                {"12", G::GPIO},   // 32
                {"13", G::GPIO},   // 33
                {"", G::GND},      // 34
                {"19", G::GPIO},   // 35
                {"16", G::GPIO},   // 36
                {"26", G::GPIO},   // 37
                {"20", G::GPIO},   // 38
                {"", G::GND},      // 39
                {"21", G::GPIO}    // 40
        };
};

#endif // PCRPI3LINUX_H
