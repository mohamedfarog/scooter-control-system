#include "pcimx6ixoralinux.h"
#include "../../common/filemanager.h"
#include <QDebug>

using namespace Pin;

PcImx6IxoraLinux::PcImx6IxoraLinux()
{
}

const DPin *
PcImx6IxoraLinux::getPin(quint8 pinNo)
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
PcImx6IxoraLinux::enablePwmPin(quint8 pinNo)
{
        // Export 0
        QString pwmExportPath = getPwmDir() + "pwmchip" + QString::number(pinNo-33) + "/export";

        if (pwmExportPath.isEmpty()) {
                qCritical() << "PcImx6IxoraLinux::enablePwmPin"
                               "|Error while exporting. Pwm couldn't be enabled."
                               "|pinNo:" << pinNo;
                return -1;
        }

        bool isOk = FileManager::write(pwmExportPath, "0");
        if (isOk == false) {
                return -1;
        }

        // Make duty 0
        setPwmDuty(pinNo, 0);

        // Enter default value to period
        QString pwmPeriodPath = getPwmPeriodPath(pinNo);
        if (pwmPeriodPath.isEmpty()) {
                qCritical() << "PcImx6IxoraLinux::enablePwmPin"
                               "|Error while changing pwm period. Pwm couldn't be enabled."
                               "|pinNo:" << pinNo;
                return -1;
        }
        FileManager::write(pwmPeriodPath, QString::number(G::PWM_PERIOD));

        // Enable pwm
        QString pwmEnablePath = getPwmEnablePath(pinNo);
        if (pwmEnablePath.isEmpty()) {
                qCritical() << "PcImx6IxoraLinux::enablePwmPin"
                               "|Error while enabling pwm. Pwm couldn't be enabled."
                               "|pinNo:" << pinNo;
                return -1;
        }
        FileManager::write(pwmEnablePath, "1");

        return 0;
}
