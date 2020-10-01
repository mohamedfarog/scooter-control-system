#include "filemanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QString
FileManager::read(const QString filePath)
{
        QFile fo(filePath);
        QString data("");

        if (fo.open(QIODevice::ReadOnly)) {
                QTextStream fileStream(&fo);
                data = fileStream.readAll();
                fo.close();
        } else {
                qCritical() << "FileManager::read"
                               "|Error while opening the file."
                               "|filePath:" << filePath;
        }

        return data;
}

bool
FileManager::write(const QString filePath, QString data)
{
        QFile fo(filePath);

        if (fo.open(QIODevice::WriteOnly)) {
                QTextStream fileStream(&fo);
                fileStream << data;
                fo.close();
        } else {
                qCritical() << "FileManager::write"
                               "|Error while opening the file."
                               "|filePath:" << filePath;
                return false;
        }

        return true;
}
