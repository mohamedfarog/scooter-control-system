#include "pinmanager.h"
#include "pin-controllers/pctk1ixoralinux.h"
#include "pin-controllers/pcimx6ixoralinux.h"
#include "pin-controllers/pcrpi3linux.h"
#include "../common/globals.h"
#include <QDebug>

using namespace Pin;

PinManager::PinManager() :
        m_pinController(nullptr)
{
        initPinController();
}

void
PinManager::initPinController()
{
        /// TODO: Make the selection on compilation time by using macro.
        if (G::DEVICE == "tk1") {
                m_pinController = new PcTk1IxoraLinux();
        } else if (G::DEVICE == "imx6") {
                m_pinController = new PcImx6IxoraLinux();
        } else if (G::DEVICE == "rpi3") {
                m_pinController = new PcRpi3Linux();
        } else {
                qCritical() << "PinManager::initPinController"
                               "|Pin controller is not initialized so cannot do pin works.";
        }
}

int
PinManager::enablePin(quint8 pinNo)
{
        int res = 0;
        if (m_pinController == nullptr) {
                return -1;
        }

        res = m_pinController->enablePin(pinNo);

        return res;
}

void
PinManager::disablePin(quint8 pinNo)
{
        if (m_pinController == nullptr) {
                return;
        }

        m_pinController->disablePin(pinNo);
}

void
PinManager::pinMode(quint8 pinNo, G::PinMode mode)
{
        if (m_pinController == nullptr) {
                return;
        }

        m_pinController->setMode(pinNo, mode);
}

void
PinManager::pwmWriteDuty(quint8 pinNo, quint32 val)
{
        if (m_pinController == nullptr) {
                return;
        }

        m_pinController->setPwmDuty(pinNo, val);
}

quint32
PinManager::pwmReadDuty(quint8 pinNo)
{
        if (m_pinController == nullptr) {
                return 0;
        }

        return m_pinController->getPwmDuty(pinNo);
}

void PinManager::pwmWritePeriod(quint8 pinNo, quint32 val)
{
        if (m_pinController == nullptr) {
                return;
        }

        m_pinController->setPwmPeriod(pinNo, val);
}

quint32 PinManager::pwmReadPeriod(quint8 pinNo)
{
        if (m_pinController == nullptr) {
                return 0;
        }

        return m_pinController->getPwmPeriod(pinNo);
}

quint16
PinManager::analogRead(quint8 pinNo)
{
        if (m_pinController == nullptr) {
                return 0;
        }

        return m_pinController->getAdcVal(pinNo);
}

void
PinManager::digitalWrite(quint8 pinNo, bool val)
{
        if (m_pinController == nullptr) {
                return;
        }

        m_pinController->setGpioVal(pinNo, val);
}

bool
PinManager::digitalRead(quint8 pinNo)
{
        if (m_pinController == nullptr) {
                return false;
        }

        return m_pinController->getGpioVal(pinNo);
}
