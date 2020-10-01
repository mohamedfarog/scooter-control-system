#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>

//////////////////////////////////////////////////////
/// PIN
//////////////////////////////////////////////////////
namespace Pin {
namespace G {
const static QString DEVICE = "rpi3";
enum PinType {
        PWM,
        GPIO,
        ADC,
        GND,
        VCC,
        UNKNOWN_PIN_TYPE = -1
};
enum PinMode {
        OUTPUT = 0,
        INPUT = 1
};
enum DefinedPins {
        GPIO_LCD_POWER = 14,
        GPIO_LCD_BACKLIGHT_POWER = 20,
        ADC_LCD_TEMP = 22,
        PWM_LCD_BRIGHTNESS = 36
};
const static quint16 PWM_PERIOD = 1000; // So duty 500 means Voltage * 0.5
}
}

#endif // GLOBALS_H
