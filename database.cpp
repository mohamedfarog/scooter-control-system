#include "database.h"
#include <QString>
#include <QDebug>

Database::Database()
{

}
int Database::connect(QString host, QString dbuname, QString pwd, QString dbName)
{
        db.setHostName(host);
        db.setUserName(dbuname);
        db.setPassword(pwd);
        db.setDatabaseName(dbName);

        if(!db.open()) {
                qDebug() << "Db is not connected.";
               return 1;
        }
        else {
                qDebug() << "Db is connected.";
                InitializationFuns();
                return 0;
        }
   }

QString Database::getRfid()const
{

        return rfid;

}

QString Database::getUser()const
{
        return name;

}

QString Database::getEmployee_id()const
{
        return employee_id;

}

QString Database::getCategory()const
{
        return emp_category;

}

QString Database::checkStatus(QString employee_id)
{
        bool s;
        bool haves = false;
        QString welcome = "SELECT employee_id FROM gunseldb1.scooters WHERE employee_id ="+employee_id;
        dgqry.exec(welcome);
        while(dgqry.next()){
                   haves = true;
        }

        if(haves == true){              
                s=true;
                setstatus(s);
        }
        else {

                s=false;
                setstatus(s);
        }
return employee_id;
}

void Database::setstatus(bool s)
{

        status = s;
}

bool Database::getstatus()const

{
       return status;
}

QString Database::getUserNameById(QString id)
{
	QString welcome  = "SELECT name,rfid,registry,category FROM employee_iot WHERE rfid ="+id;
	dgqry.exec(welcome);
	dgqry.next();
	try{
		rfid = dgqry.value(1).toString();
		rfid == id ? login = true : login = false;
		if(rfid!=id){
			qDebug()<<"Wrong";
			return 0;
		}
	}
	catch(int e){

	}
	if(login == true)
	{
		name = dgqry.value(0).toString();
		rfid = dgqry.value(1).toString();
		employee_id = dgqry.value(2).toString();
		emp_category = dgqry.value(3).toString();
		checkStatus(employee_id);
		showTakenScooter(emp_category);
		showReturnedScooter(employee_id);
		showTakenSpot();
		showReturnedSpot();
		return id;

    }

}

int Database::setGiAvailableSpots(int girnespots)
{
        QString spotNo = "SELECT COUNT(*) FROM gunseldb1.spots WHERE spot_status = 0";
        dgqry.exec(spotNo);
        dgqry.next();
        int gispotsnum = dgqry.value(0).toInt();
        girnespots = gispotsnum;
        getGirneSpots(gispotsnum);
        return girnespots;
}



void Database::getGirneSpots(int gispotsnum)
{

        girnespots = gispotsnum;

}
int Database::returnGiSpots()const{
        return girnespots;

}

int Database::setLeAvailableSpots(int lespots)
{
        QString spotNo = "SELECT COUNT(*) FROM gunseldb1.lef_spots WHERE spot_status = 0";
        dgqry.exec(spotNo);
        dgqry.next();
        int lespotsnum = dgqry.value(0).toInt();
        getLeSpots(lespotsnum);
        return lespots;
}

void Database::getLeSpots(int lespotsnum)
{

        lespots = lespotsnum;
}
int Database::returnLeSpots()const
{
        return lespots;

}
int Database::setMuAvailableSpots(int muspots)
{
           QString spotNo = "SELECT COUNT(*) FROM gunseldb1.magusa_spots WHERE spot_status = 0";
            dgqry.exec(spotNo);
            dgqry.next();
            int muspotsnum = dgqry.value(0).toInt();
            getMuSpots(muspotsnum);
            return muspots;


}
void Database::getMuSpots(int muspotsnum)
{
        muspots = muspotsnum;
        qDebug()<<muspots;

}
int Database::returnMuSpots()const
{
        return muspots;

}
int Database::setGoAvailableSpots(int gospots)
{
        QString spotNo = "SELECT COUNT(*) FROM gunseldb1.gonyeli_spots WHERE spot_status = 0";
        dgqry.exec(spotNo);
        dgqry.next();
        int gospotsnum = dgqry.value(0).toInt();
        getGoSpots(gospotsnum);
        return gospots;

}
void Database::getGoSpots(int gospotsnum)
{

 gospots = gospotsnum;
 qDebug()<<gospots;

}
int Database::returnGoSpots()const
{
        return gospots;

}
int Database::setGiAvailableScooters(int girneScooters)
{

        QString scooterNo = "SELECT COUNT(*) FROM gunseldb1.scooters WHERE employee_id = 'Available' AND emp_category = '1'";
        dgqry.exec(scooterNo);
        dgqry.next();
        int gisnum = dgqry.value(0).toInt();
        girneScooters = gisnum;
        getScooterInGi(gisnum);
        return girneScooters;

}

void Database::getScooterInGi(int gisnum)
{
        girneScooters = gisnum;


}

int Database::returnGiScooters()const
{
        return girneScooters;
}

int Database::setLeAvailableScooter(int lefkosaScooters)
{
              QString scooterNo = "SELECT COUNT(*) FROM gunseldb1.scooters WHERE employee_id = 'Available' AND emp_category = '2'";
        dgqry.exec(scooterNo);
        dgqry.next();
        int lefscooter = dgqry.value(0).toInt();
        lefkosaScooters = lefscooter;
        getScooterInLef(lefscooter);
        return lefkosaScooters;
}
void Database::getScooterInLef(int lefscooter)
{
     lefkosaScooters = lefscooter;

}

int Database::returnLefScooter()const
{
        return lefkosaScooters;

}

int Database::setMuAvailableScooters (int mugusaScooters)
{
               QString scooterNo = "SELECT COUNT(*) FROM gunseldb1.scooters WHERE employee_id = 'Available' AND emp_category = '3'";
        dgqry.exec(scooterNo);
        dgqry.next();
        int muscooter = dgqry.value(0).toInt();
        mugusaScooters = muscooter;
        getScooterInMu(muscooter);
        return mugusaScooters;

}

void Database::getScooterInMu(int muscooter)
{

        mugusaScooters = muscooter;

}

int Database::returnMuScooters()const
{
return mugusaScooters;

}

int Database::setGoAvailableScooters(int gonyeliScooter)
{
        QString scooterNo = "SELECT COUNT(*) FROM gunseldb1.scooters WHERE employee_id = 'Available' AND emp_category = '4'";
        dgqry.exec(scooterNo);
        dgqry.next();
        int goscooter = dgqry.value(0).toInt();
        gonyeliScooter = goscooter;
        getScootersInGo(goscooter);
        return gonyeliScooter;
}

void Database::getScootersInGo(int goscooter)
{
        gonyeliScooter = goscooter;

}
int Database::returnGoScooters()const
{
        return gonyeliScooter;

}

QString Database::ReadCard(QString id)
{
          dgqry.exec("SELECT id FROM user WHERE name = 'user'");
          dgqry.next();
          id =  dgqry.value(0).toString();
          dgqry.prepare("UPDATE user SET id = '0' WHERE name = 'user'");
          dgqry.exec();

           if(id !="0"){
               getUserNameById(id);
               InitializationFuns();
          }
        else{

             qDebug()<<"SOrry";

          }
return id;

}

QString Database::AfterLogin(QString name)
{
        QString welcome  = "SELECT name FROM employee_iot WHERE rfid ="+name;
        dgqry.exec(welcome);
        dgqry.next();
        return name;

}

 QString Database::getQuery( QString employee_id, QString emp_category)
 {
     QString gsid;
     gsid =  sid;
     QString taken = "Scooter Taken";
     QString place =  "Girne Station";
     qDebug()<<"getDataIsUpdated";
     QString welcome = QString ("UPDATE gunseldb1.scooters SET status =0, employee_id=%1, emp_category = 0 WHERE employee_id='Available' AND emp_category=1 LIMIT 1").arg(employee_id);
     dgqry.exec(welcome);
     InitializationFuns();
     logInformation(employee_id,  gsid, taken, place);
     return emp_category;

}

QString Database::showTakenScooter(QString emp_category)
{
    bool existscooter;

        QString welcome = "SELECT scooter_id FROM gunseldb1.scooters WHERE employee_id ='Available' AND emp_category= '1' LIMIT 1";
           dgqry.exec(welcome);

         if  (dgqry.next()){
               QString scooter_id = dgqry.value(0).toString();
               getScooter_id(scooter_id);
               existscooter = true;
               ExistScooter(existscooter);
         }
         else{
             existscooter = false;
             ExistScooter(existscooter);
         }

         return emp_category;
}

void Database::ExistScooter(bool existscooter)
{
   exists = existscooter;
}
bool Database::returnExistScooter()const
{
    return exists;
}

void Database::getScooter_id(QString scooter_id)
{
        sid = scooter_id;
}

QString Database::returnScooter_id()const{
        return sid;

}

QString Database::showReturnedScooter(QString employee_id)
{
        QString welcome = "SELECT scooter_id FROM gunseldb1.scooters WHERE employee_id = "+employee_id;
        dgqry.exec(welcome);
        dgqry.next();
        QString scooterId = dgqry.value(0).toString();
        qDebug()<<scooterId;
        getScooterId(scooterId);
        return employee_id;
}

void Database::getScooterId(QString scooterId)
{
        rsid = scooterId;
}

QString Database::returnScooterId()const
{
        return rsid;
}

void Database::showTakenSpot()
{
    bool fullspot;

        QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE spot_status = 1";
        dgqry.exec(welcome);
        if (dgqry.next()){
            fullspot = true;
            QString spotId =dgqry.value(1).toString();
            haveFUllSpot(fullspot);
            getfullSpotId(spotId);
        }
        else {
            fullspot = false;
            haveFUllSpot(fullspot);

        }

}

void Database::haveFUllSpot(bool fullspot)
{

 havefullspot = fullspot;
}
bool Database::returnFullSpotResult()const
{
    return havefullspot;


}

void Database::getfullSpotId(QString spotId)
{
        gspotid = spotId;


}
QString Database::returnFullSpotId()const
{
        return gspotid;

}

void Database::showReturnedSpot()
{
    bool emptyspot;
        QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE spot_status = 0";
        dgqry.exec(welcome);
        if (dgqry.next()){
            emptyspot = true;
            QString spotIdr = dgqry.value(1).toString();
            getEmptySpotId(spotIdr);
            haveEmptySpot(emptyspot);

        }
        else {

            emptyspot = false;
            haveEmptySpot(emptyspot);
        }

}
void Database::haveEmptySpot(bool emptyspot){
    haveemptyspot = emptyspot;

}

bool Database::returnEmptySpotResult()const{
    return haveemptyspot;

}

void Database::getEmptySpotId(QString spotIdr)
{

        rspotid = spotIdr;
}
QString Database::returnEmptySpotId()const
{
        return rspotid;

}

void Database::returnQuery()
 {
     QString gsid;
     gsid =  rsid;
     QString taken = "Scooter Returned";
     QString place =  "Girne Station";
     QString welcome = QString("UPDATE gunseldb1.scooters SET status = 1,  employee_id = 'Available', emp_category = 1 WHERE status = 0 AND employee_id = %1 AND emp_category = 0 LIMIT 1").arg(employee_id);
     dgqry.exec(welcome);
     qDebug()<<"ReturnDataIsUpdated";
     InitializationFuns();
     logInformation(employee_id,  gsid, taken, place);
 }

void Database::getSpot1(){
         bool spot1;
         QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 1";
         dgqry.exec(welcome);
         while(dgqry.next()){

                 int spotN = dgqry.value(2).toInt();
                 if (spotN==0){
                         spot1 = false;
                            setSpot1Status(spot1);

                 }
                 else if (spotN == 1) {
                            spot1 = true;
                            setSpot1Status(spot1);

                 }


                 }

         }

void Database::setSpot1Status(bool spot1){
         spot1s = spot1;


}

bool Database::getSpot1Status()const{
        return spot1s;

}

void Database::getSpot2(){
	bool spot2;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 2";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot2 = false;
			setSpot2Status(spot2);
		}
		else if (spotN == 1) {
			spot2 = true;
			setSpot2Status(spot2);
		}
	}
}

void Database::setSpot2Status(bool spot2)
{
         spot2s = spot2;
}

bool Database::getSpot2Status()const
{
        return spot2s;

}

void Database::getSpot3(){
	bool spot3;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 3";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot3 = false;
			setSpot3Status(spot3);
		}
		else if (spotN == 1) {
			spot3 = true;
			setSpot3Status(spot3);
		}
	}
}

void Database::setSpot3Status(bool spot3)
{
         spot3s = spot3;
}

bool Database::getSpot3Status()const
{
        return spot3s;

}

void Database::getSpot4(){
	bool spot4;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 4";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot4 = false;
			setSpot4Status(spot4);
		}
		else if (spotN == 1) {
			spot4 = true;
			setSpot4Status(spot4);
		}
	}
}

void Database::setSpot4Status(bool spot4)
{
         spot4s = spot4;

}

bool Database::getSpot4Status()const
{
        return spot4s;
}

void Database::getSpot5(){
	bool spot5;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 5";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot5 = false;
			setSpot5Status(spot5);
		}
		else if (spotN == 1) {
			spot5 = true;
			setSpot5Status(spot5);
		}
	}
}

void Database::setSpot5Status(bool spot5){
          spot51 = spot5;

}

bool Database::getSpot5Status()const
{
        return spot51;
}

void Database::getSpot6()
{
	bool spot6;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 6";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot6 = false;
			setSpot6Status(spot6);
		}
		else if (spotN == 1) {
			spot6 = true;
			setSpot6Status(spot6);
		}
	}
}

void Database::setSpot6Status(bool spot6)
{
         spot6s = spot6;
}

bool Database::getSpot6Status()const
{
        return spot6s;
}

void Database::getSpot7()
{
	bool spot7;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 7";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot7 = false;
			setSpot7Status(spot7);
		}
		else if (spotN == 1){
			spot7 = true;
			setSpot7Status(spot7);
		}
	}
}

void Database::setSpot7Status(bool spot7)
{
         spot7s = spot7;
}

bool Database::getSpot7Status()const
{
        return spot7s;
}

void Database::getSpot8()
{
	bool spot8;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id  = 8";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot8 = false;
			setSpot8Status(spot8);
		}
		else if (spotN == 1) {
			spot8 = true;
			setSpot8Status(spot8);
		}
	}
}

void Database::setSpot8Status(bool spot8)
{
         spot8s = spot8;
}

bool Database::getSpot8Status()const
{
        return spot8s;
}

void Database::getSpot9()
{
	bool spot9;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 9";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot9 = false;
			setSpot9Status(spot9);
		}
		else if (spotN == 1) {
			spot9 = true;
			setSpot9Status(spot9);
		}
	}
}

void Database::setSpot9Status(bool spot9)
{
         spot9s = spot9;
}

bool Database::getSpot9Status()const
{
        return spot9s;
}

void Database::getSpot10()
{
	bool spot10;
	QString welcome = "SELECT * FROM gunseldb1.lef_spots WHERE id = 10";
	dgqry.exec(welcome);
	while(dgqry.next()){
		int spotN = dgqry.value(2).toInt();
		if (spotN==0){
			spot10 = false;
			setSpot10Status(spot10);
		}
		else if (spotN == 1) {
			spot10 = true;
			setSpot10Status(spot10);
		}
	}
}

void Database::setSpot10Status(bool spot10)
{
         spot10s = spot10;

}

bool Database::getSpot10Status()const
{
        return spot10s;

}

void Database::InitializationFuns()
{
        getSpot1();
        getSpot2();
        getSpot3();
        getSpot4();
        getSpot5();
        getSpot6();
        getSpot7();
        getSpot8();
        getSpot9();
        getSpot10();
        setGiAvailableScooters(girneScooters);
        setLeAvailableScooter(lefkosaScooters);
        setMuAvailableScooters(mugusaScooters);
        setGoAvailableScooters(gonyeliScooter);
        setGiAvailableSpots(girnespots);
        setLeAvailableSpots(lespots);
        setMuAvailableSpots(muspots);
        setGoAvailableSpots(gospots);
}

void Database::updateGetSpot1()
{
        qDebug()<<"get spot 1 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 1");
        dgqry.exec(welcome);
}

void Database::updateGetSpot2()
{
        qDebug()<<"get spot 2 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 2");
        dgqry.exec(welcome);
}

void Database::updateGetSpot3()
{
        qDebug()<<"get spot 3 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 3");
        dgqry.exec(welcome);
}

void Database::updateGetSpot4()
{
        qDebug()<<"get spot 4 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 4");
        dgqry.exec(welcome);
}

void Database::updateGetSpot5()
{
        qDebug()<<"get spot 5 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 5");
        dgqry.exec(welcome);
}

void Database::updateGetSpot6()
{
        qDebug()<<"get spot 6 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 6");
        dgqry.exec(welcome);
}

void Database::updateGetSpot7()
{
     qDebug()<<"get spot 7 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 7");
        dgqry.exec(welcome);
}

void Database::updateGetSpot8()
{
        qDebug()<<"get spot 8 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 8");
        dgqry.exec(welcome);
}

void Database::updateGetSpot9()
{
        qDebug()<<"get spot 9 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 9");
        dgqry.exec(welcome);
}

void Database::updateGetSpot10()
{
        qDebug()<<"get spot 10 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 0  WHERE id = 10");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot1()
{
        qDebug()<<"return spot 1 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 1");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot2()
{
        qDebug()<<"return spot 2 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 2");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot3()
{

        qDebug()<<"return spot 3 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 3");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot4()
{
        qDebug()<<"return spot 4 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 4");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot5()
{
        qDebug()<<"return spot 5 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 5");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot6()
{
        qDebug()<<"return spot 6 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 6");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot7()
{
        qDebug()<<"return spot 7 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 7");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot8()
{
        qDebug()<<"return spot 8 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 8");
        dgqry.exec(welcome);
}

void Database::updateReturnSpot9()
{
     qDebug()<<"return spot 9 dataUpdated";
     QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 9");
     dgqry.exec(welcome);
}

void Database::updateReturnSpot10()
{
        qDebug()<<"return spot 10 dataUpdated";
        QString welcome = QString("UPDATE gunseldb1.lef_spots SET spot_status = 1  WHERE id = 10");
        dgqry.exec(welcome);
}

void Database::logInformation(QString employee_id, QString gsid, QString taken, QString place ){
    QDate date = QDate::currentDate();
    QLocale locale = QLocale(QLocale::Turkish);
    QString new_date = locale.toString(date,"dd/MM/yyyy");
    QTime time = QTime::currentTime();
    QString hour = time.toString("hh:mm:ss");
    QString welcome = QString("INSERT INTO gunseldb1.scooter_log(employee_id,scooter_name,date,hour,operation, location)VALUES(%1, '%2', '%3','%4','%5','%6')").arg(employee_id).arg(gsid).arg(new_date).arg(hour).arg(taken).arg(place);
    dgqry.exec(welcome);
    qDebug()<<"LogInfoInserte";
}