#include "ipclinux.h"
#include "../common/filemanager.h"
#include "../common/globals.h"
#include <QDebug>

using namespace Pin;

int
IPcLinux::enablePin(quint8 pinNo)
{
        G::PinType pinType = getPinType(pinNo);
        int res = 0;

        if (pinType == G::PinType::GPIO) {
                res = exportGpioPin(pinNo);
        } else if (pinType == G::PinType::PWM) {
                res = enablePwmPin(pinNo);
        } else if (pinType == G::PinType::ADC) {
                QString dataRead = FileManager::read(getAdcValPath(pinNo));
                if (dataRead.isEmpty()) {
                        res = -1;
                }
        }

        return res;
}

void
IPcLinux::disablePin(quint8 pinNo)
{
        G::PinType pinType = getPinType(pinNo);
        if (pinType == G::PinType::GPIO) {
                unexportGpioPin(pinNo);
        } else if (pinType == G::PinType::PWM) {
                disablePwmPin(pinNo);
        }
}

void
IPcLinux::setMode(quint8 pinNo, G::PinMode mode)
{
        G::PinType pinType = getPinType(pinNo);
        if (pinType == G::PinType::GPIO) {
                setGpioMode(pinNo, mode);
        }
}

void
IPcLinux::setPwmDuty(quint8 pinNo, quint32 val)
{
        QString targetPath = getPwmDutyPath(pinNo);

        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::setPwmDuty"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo <<
                               "|val:" << val;

                return;
        }

        FileManager::write(targetPath, QString::number(val));
}

quint32
IPcLinux::getPwmDuty(quint8 pinNo)
{
        QString targetPath = getPwmDutyPath(pinNo);

        // Check if pinNo is okay
        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::getPwmDuty"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return 0;
        }

        // Get data from the file
        QString dataRead = FileManager::read(targetPath);

        // Convert it to int and check for validity
        bool isConversionOk = false;
        quint16 targetVal = dataRead.toUShort(&isConversionOk);

        if (isConversionOk == false) {
                qCritical() << "IPcLinux::getPwmDuty"
                               "|Data is not numerical."
                               "|pinNo:" << pinNo <<
                               "|dataRead:" << dataRead;
                return 0;
        }

        // Return the value
        return targetVal;
}


void
IPcLinux::setPwmPeriod(quint8 pinNo, quint32 val)
{
        QString targetPath = getPwmPeriodPath(pinNo);

        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::setPwmPeriod"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo <<
                               "|val:" << val;
                return;
        }

        FileManager::write(targetPath, QString::number(val));
}

quint32
IPcLinux::getPwmPeriod(quint8 pinNo)
{
        QString targetPath = getPwmPeriodPath(pinNo);

        // Check if pinNo is okay
        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::getPwmPeriod"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return 0;
        }

        // Get data from the file
        QString dataRead = FileManager::read(targetPath);

        // Convert it to int and check for validity
        bool isConversionOk = false;
        quint16 targetVal = dataRead.toUShort(&isConversionOk);

        if (isConversionOk == false) {
                qCritical() << "IPcLinux::getPwmPeriod"
                               "|Data is not numerical."
                               "|pinNo:" << pinNo <<
                               "|dataRead:" << dataRead;
                return 0;
        }

        // Return the value
        return targetVal;
}

quint16
IPcLinux::getAdcVal(quint8 pinNo)
{
        QString targetPath = getAdcValPath(pinNo);

        // Check if pinNo is okay
        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::getAdcVal"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return 0;
        }

        // Get data from the file
        QString dataRead = FileManager::read(targetPath);

        // Convert it to int and check for validity
        bool isConversionOk = false;
        quint16 targetVal = dataRead.toUShort(&isConversionOk);

        if (isConversionOk == false) {
                qCritical() << "IPcLinux::getAdcVal"
                               "|Data is not numerical."
                               "|pinNo:" << pinNo <<
                               "|dataRead:" << dataRead;
                return 0;
        }

        // Return the value
        return targetVal;
}

bool
IPcLinux::getGpioVal(quint8 pinNo)
{
        QString targetPath = getGpioValPath(pinNo);

        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::getGpioVal"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return false;
        }

        bool targetVal = FileManager::read(targetPath) == "1";

        return targetVal;
}

void
IPcLinux::setGpioVal(quint8 pinNo, bool val)
{
        QString targetPath = getGpioValPath(pinNo);

        if (targetPath.isEmpty()) {
                qCritical() << "IPcLinux::setGpioVal"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo <<
                               "|val:" << val;
                return;
        }

        FileManager::write(targetPath, QString::number(val));
}

void
IPcLinux::disablePwmPin(quint8 pinNo)
{
        QString pwmEnablePath = getPwmEnablePath(pinNo);
        if (pwmEnablePath.isEmpty()) {
                qCritical() << "IPcLinux::disablePwmPin"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return;
        }

        FileManager::write(pwmEnablePath, "0");
}

void
IPcLinux::setGpioMode(quint8 pinNo, G::PinMode mode)
{
        QString gpioDirectionPath = getGpioDirectionPath(pinNo);

        if (gpioDirectionPath.isEmpty()) {
                qCritical() << "IPcLinux::setGpioMode"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo <<
                               "|mode:" << mode;
                return;
        }

        QString gpioMode = "out";
        if (mode == G::INPUT) {
                gpioMode = "in";
        }

        FileManager::write(gpioDirectionPath, gpioMode);
}

int
IPcLinux::exportGpioPin(quint8 pinNo)
{
        QString pinName = getPinName(pinNo);
        bool isOk = false;

        if (pinName.isEmpty()) {
                qCritical() << "IPcLinux::exportGpioPin"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return -1;
        }

        isOk = FileManager::write(getGpioExportPath(), pinName);

        if (isOk == false) {
                return -1;
        }

        return 0;
}

void
IPcLinux::unexportGpioPin(quint8 pinNo)
{
        QString pinName = getPinName(pinNo);

        if (pinName.isEmpty()) {
                qCritical() << "IPcLinux::unexportGpioPin"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return;
        }

        FileManager::write(getGpioUnexportPath(), pinName);
}

QString
IPcLinux::getPinName(quint8 pinNo)
{
        const DPin *pin = getPin(pinNo);

        if (pin == nullptr) {
                qCritical() << "IPcLinux::getPinName"
                               "|No 'pinNo' found."
                               "|pinNo:" << pinNo;
                return "";
        }

        return pin->name;
}

G::PinType
IPcLinux::getPinType(quint8 pinNo)
{
        const DPin *pin = getPin(pinNo);

        if (pin == nullptr) {
                return G::UNKNOWN_PIN_TYPE;
        }

        return pin->type;
}

QString
IPcLinux::getPwmPinDir(quint8 pinNo)
{
        QString pinName = getPinName(pinNo);
        G::PinType pinType = getPinType(pinNo);

        if (pinName.isEmpty()) {
                return "";
        }

        if (pinType != G::PinType::PWM) {
                qCritical() << "IPcLinux::getPwmPinDir"
                               "|Type of 'pinNo' is not PWM."
                               "|pinNo:" << pinNo <<
                               "|pinType:" << pinType;
                return "";
        }

        QString targetDir= getPwmDir() + pinName + "/";
        return targetDir;
}

QString
IPcLinux::getPwmDutyPath(quint8 pinNo)
{
        QString targetPath = getPwmPinDir(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        targetPath += "duty_cycle";
        return targetPath;
}

QString
IPcLinux::getPwmPeriodPath(quint8 pinNo)
{
        QString targetPath = getPwmPinDir(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        targetPath += "period";
        return targetPath;
}

QString
IPcLinux::getPwmEnablePath(quint8 pinNo)
{
        QString targetPath = getPwmPinDir(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        targetPath += "enable";
        return targetPath;
}

QString
IPcLinux::getAdcPinPath(quint8 pinNo)
{
        QString pinName = getPinName(pinNo);
        G::PinType pinType = getPinType(pinNo);

        if (pinName.isEmpty()) {
                return "";
        }

        if (pinType != G::PinType::ADC) {
                qCritical() << "IPcLinux::getAdcPinPath"
                               "|Type of 'pinNo' is not ADC."
                               "|pinNo:" << pinNo <<
                               "|pinType:" << pinType;
                return "";
        }

        QString targetPath = getAdcDir() + pinName;
        return targetPath;
}

QString
IPcLinux::getAdcValPath(quint8 pinNo)
{
        QString targetPath = getAdcPinPath(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        return targetPath;
}

QString
IPcLinux::getGpioPinDir(quint8 pinNo)
{
        QString pinName = getPinName(pinNo);
        G::PinType pinType = getPinType(pinNo);

        if (pinName.isEmpty()) {
                return "";
        }

        if (pinType != G::PinType::GPIO) {
                qCritical() << "IPcLinux::getGpioPinDir"
                               "|Type of 'pinNo' is not ADC."
                               "|pinNo:" << pinNo <<
                               "|pinType:" << pinType;
                return "";
        }

        QString targetDir = getGpioDir() + "gpio" + pinName + "/";
        return targetDir;
}

QString
IPcLinux::getGpioValPath(quint8 pinNo)
{
        QString targetPath = getGpioPinDir(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        targetPath += "value";
        return targetPath;
}

QString
IPcLinux::getGpioDirectionPath(quint8 pinNo)
{
        QString targetPath = getGpioPinDir(pinNo);

        if (targetPath.isEmpty()) {
                return "";
        }

        targetPath += "direction";
        return targetPath;
}
