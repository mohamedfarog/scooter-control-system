#ifndef PINCONTROLLE_H
#define PINCONTROLLE_H

#include <QObject>
#include "wiringPi.h"

class PinController : public QObject
{
    Q_OBJECT
public:
    explicit PinController();
    int Read(int pin);
    void Write(int pin, int value);
    void Mode(int pin, int mode);
signals:

public slots:
};

#endif // PINCONTROLLE_H
