#include "cardreader.h"
#include <QDebug>

CardReader::CardReader() : pyScript("python3 /home/pi/scooter-control-system/read.py")
{
        connect(&pyProcess, SIGNAL(finished(int)), this, SLOT(pyProcessFinished(int)));
}

void CardReader::run()
{
        pyProcess.start(pyScript);
}

void CardReader::pyProcessFinished(int)
{
        emit newCardAvailableOnDb();
        pyProcess.start(pyScript);
}
