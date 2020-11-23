#ifndef APPLICATION_H
#define APPLICATION_H
#include <QMainWindow>
#include "mainwindow.h"
#include <QObject>
#include <QApplication>
#include "database.h"
#include "cardreader.h"
#include "pincontroller.h"
#include <QScrollArea>
#include <QString>
#include <QThread>


class Application : public QObject
{
        Q_OBJECT
public:


        Application();
        void run();

        static void sleep(unsigned long secs){QThread::sleep(secs);}
        void getReturnName();
        void callGetOrReturn();
        void displayScooter_id();
        QString getid()const;
        QString getMyName()const;       
        QString EmpCategory()const;
        QString checkEmpStatus();
        QString getScooter();       
        QString getEmpStatus1();
        QString getEmpStatus2();
        QString getCurrentScooterId()const;
        QString getReturneedScooterId()const;
        QString showReturnSpotId()const;
        QString showGetSpotId()const;
        void setReturnSpotId();
        void setGetSpotId();
        void unLock1();
        void lock1();
        bool checkEmptySpotFirst()const;
        bool checkFullSpotFirst()const;
        bool checkScooterExist()const;
        int countGiScooters()const;
        int countLefkaScooters()const;
        int countMuScooters()const;
        int countGoScooters()const;
        int countGiSpots()const;
        int countLeSpots()const;
        int countMuSpots()const;
        int countGoSpots()const;
        bool chekStatus();
        bool checkSpot1()const;
        bool checkSpot2()const;
        bool checkSpot3()const;
        bool checkSpot4()const;
        bool checkSpot5()const;
        bool checkSpot6()const;
        bool checkSpot7()const;
        bool checkSpot8()const;
        bool checkSpot9()const;
        bool checkSpot10()const;



public slots:
        void getName();
        void setPins();



signals:
      void  call_pin();



private slots:
        void displayData();
        void processNewCardFromDb();
        void unlockgetSpot1();
        void unlockgetSpot2();
        void unlockgetSpot3();
        void unlockgetSpot4();
        void unlockgetSpot5();
        void unlockgetSpot6();
        void unlockgetSpot7();
        void unlockgetSpot8();
        void unlockgetSpot9();
        void unlockgetSpot10();
        void unlockReturnSpot1();
        void unlockReturnSpot2();
        void unlockReturnSpot3();
        void unlockReturnSpot4();
        void unlockReturnSpot5();
        void unlockReturnSpot6();
        void unlockReturnSpot7();
        void unlockReturnSpot8();
        void unlockReturnSpot9();
        void unlockReturnSpot10();
        void unlockReturnScooter();
        void unlockGetScooter();



private:

        Database m_db;
        CardReader m_cardReader;
        PinController m_pinController;
        MainWindow m_ui;
        QTimer *pinDelay;



};

#endif // APPLICATION_H

