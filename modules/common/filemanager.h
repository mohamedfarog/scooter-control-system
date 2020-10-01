#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class FileManager : public QObject
{
        Q_OBJECT
public:
        static QString read(const QString filePath);
        static bool write(const QString filePath, QString data);
};

#endif // FILEMANAGER_H
