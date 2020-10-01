#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql/QtSql>
#include <string>
#include <QString>
#include <mainwindow.h>
#include "modules/pin/pinmanager.h"





class Database : public QObject
{
        Q_OBJECT

public:
        int connect(QString host, QString dbuname, QString pwd, QString dbName);


        Pin::PinManager m_pinManager;





 explicit Database();


       //If connection is successfull, return 0, else 1.
       QString runQuery(QString query);
       int setGiAvailableScooters(int girneScooters);
       int setLeAvailableScooter(int lefkosaScooters);
       int setMuAvailableScooters (int mugusaScooters);
       int setGoAvailableScooters(int gonyeliScooter);
       int setGiAvailableSpots(int girnespots);
       int setLeAvailableSpots(int lespots);
       void getLeSpots(int lespotnum);
       int returnLeSpots()const;
       int setMuAvailableSpots(int muspots);
       void getMuSpots(int muspotsnum);
       int returnMuSpots()const;
       int setGoAvailableSpots(int gospots);
       void getGoSpots(int gospotsnum);
       int returnGoSpots()const;
       QString ReadCard(QString id);
       QString AfterLogin(QString name);
       QString getUserNameById(QString id);
       QString getRfid()const;
       QString getUser()const;
       QString getEmployee_id()const;
       QString getCategory()const;
       QString checkStatus(QString employee_id);
       QString showTakenScooter(QString emp_category);
       QString showReturnedScooter(QString employee_id);
       void showTakenSpot();
       void showReturnedSpot();
       QString returnScooterId()const;
       void getScooterId(QString scooterId);
       void getScooter_id(QString scooter_id);

       QString returnScooter_id()const;
       QString returnFullSpotId()const;
       QString returnEmptySpotId()const;
       void getfullSpotId(QString spotId);
       void getEmptySpotId(QString spotId);
       void getScooterInGi(int gisnum);
       int  returnGiScooters()const;
       void getScooterInLef(int lefscooter);
       int returnLefScooter()const;
       void getScooterInMu(int muscooter);
       int returnMuScooters()const;
       void getScootersInGo(int goscooter);
       int returnGoScooters()const;
       void getGirneSpots(int gispots);
       int returnGiSpots()const;
       void logInformation(QString employee_id, QString gsid, QString taken, QString place);
       void haveEmptySpot(bool emptyspot);
       bool returnEmptySpotResult()const;
       void haveFUllSpot(bool fullspot);
       bool returnFullSpotResult()const;
       void ExistScooter(bool existscooter);
       bool returnExistScooter()const;

       void setstatus(bool s );
       bool getstatus()const;
       void getSpot1();
       void getSpot2();
       void getSpot3();
       void getSpot4();
       void getSpot5();
       void getSpot6();
       void getSpot7();
       void getSpot8();
       void getSpot9();
       void getSpot10();
       void InitializationFuns();
       void updateGetSpot1();
       void updateGetSpot2();
       void updateGetSpot3();
       void updateGetSpot4();
       void updateGetSpot5();
       void updateGetSpot6();
       void updateGetSpot7();
       void updateGetSpot8();
       void updateGetSpot9();
       void updateGetSpot10();
       void updateReturnSpot1();
       void updateReturnSpot2();
       void updateReturnSpot3();
       void updateReturnSpot4();
       void updateReturnSpot5();
       void updateReturnSpot6();
       void updateReturnSpot7();
       void updateReturnSpot8();
       void updateReturnSpot9();
       void updateReturnSpot10();

       void setSpot1Status(bool spot1);
       bool getSpot1Status()const;
       void setSpot2Status(bool spot2);
       bool getSpot2Status()const;
       void setSpot3Status(bool spot3);
       bool getSpot3Status()const;
       void setSpot4Status(bool spot4);
       bool getSpot4Status()const;
       void setSpot5Status(bool spot5);
       bool getSpot5Status()const;
       void setSpot6Status(bool spot6);
       bool getSpot6Status()const;
       void setSpot7Status(bool spot7);
       bool getSpot7Status()const;
       void setSpot8Status(bool spot8);
       bool getSpot8Status()const;
       void setSpot9Status(bool spot9);
       bool getSpot9Status()const;
       void setSpot10Status(bool spot10);
       bool getSpot10Status()const;



       QString getQuery(QString employee_id, QString emp_category);
       void returnQuery();





private:


        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        QString rfid, name ,card_id,id,employee_id,emp_category, sid, rsid, gspotid, rspotid;
        QSqlQuery dgqry;
        bool status,spot1s,spot2s,spot3s,spot4s,spot51,spot6s,spot7s, spot8s, spot9s, spot10s, haveemptyspot, havefullspot, exists;
        int girneScooters,lefkosaScooters,mugusaScooters,gonyeliScooter, girnespots, lespots,muspots,gospots;
        bool login = false;


};

#endif // DATABASE_H
