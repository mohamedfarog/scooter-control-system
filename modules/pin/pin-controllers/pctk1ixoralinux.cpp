#include "pctk1ixoralinux.h"
#include "../../common/filemanager.h"
#include <QDebug>

using namespace Pin;

const DPin *
PcTk1IxoraLinux::getPin(quint8 pinNo)
{
        pinNo--; // pinNo starts from 1, pinMap array starts from 0

        if (pinNo >= PIN_SIZE) {
                return nullptr;
        }

        const DPin *pin = &m_pins[pinNo];

        if (pin->name.isEmpty()) {
                return nullptr;
        }

        return pin;
}

int
PcTk1IxoraLinux::enablePwmPin(quint8 pinNo)
{
        QString pwmExportPath = getPwmDir() + "pwmchip0/export";

        // Export
        bool isOk = FileManager::write(pwmExportPath, QString::number(pinNo-33));
        if (isOk == false) {
                return -1;
        }

        // Enable
        QString pwmEnablePath = getPwmEnablePath(pinNo);
        if (pwmEnablePath.isEmpty()) {
                qCritical() << "PcTk1IxoraLinux::enablePwmPin"
                               "|Error while enabling pwm. Pwm couldn't be enabled."
                               "|pinNo:" << pinNo;
                return -1;
        }

        FileManager::write(pwmEnablePath, "1");

        // Enter default value to period
        QString pwmPeriodPath = getPwmPeriodPath(pinNo);
        if (pwmPeriodPath.isEmpty()) {
                qCritical() << "PcTk1IxoraLinux::enablePwmPin"
                               "|Error while changing pwm period. Pwm couldn't be enabled."
                               "|pinNo:" << pinNo;
                return -1;
        }
        FileManager::write(pwmPeriodPath, QString::number(G::PWM_PERIOD));

        return 0;
}
