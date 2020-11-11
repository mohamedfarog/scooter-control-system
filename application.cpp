#include "application.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QSocketNotifier>


Application::Application()
{

        m_db.connect("10.69.1.16", "dg1", "gunsel2", "gunseldb1" );
        connect(&m_cardReader,SIGNAL(newCardAvailableOnDb()),this,SLOT(processNewCardFromDb()));
        connect(&m_ui,SIGNAL(getIsCalled()),this, SLOT(unlockGetScooter()));
        connect(&m_ui,SIGNAL(settingPins()),this, SLOT(setPins()));
        connect(&m_ui, SIGNAL(returnIsCalled()),this, SLOT(unlockReturnScooter()));
        pinDelay =  new QTimer(this);
        connect(&m_ui, SIGNAL(dataChanged()), this,SLOT(displayData()));
        connect(&m_ui, SIGNAL(rDataChanged()), this,SLOT(displayData()));
        m_cardReader.run();
        setPins();

}


void Application::run()
{
 m_ui.show();
 displayData();



}



void Application::displayData()
{


        m_ui.displayScooterInGirne(m_db.returnGiScooters(), m_db.returnLefScooter(),
        m_db.returnMuScooters(), m_db.returnGoScooters(),m_db.returnGiSpots(), m_db.returnLeSpots(),m_db.returnMuSpots(),m_db.returnGoSpots());


}

void Application::setPins()
{

    wiringPiSetup();
    pinMode(15,OUTPUT);
    pinMode(16,OUTPUT);
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(23,OUTPUT);
    pinMode(24,OUTPUT);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);

    qDebug()<<"PIN SET EMITED";


}
void Application::displayScooter_id()
{

   m_ui.showScooter(m_db.returnScooter_id(), m_db.returnScooterId());

}

void Application::processNewCardFromDb()
{
    setPins();



 QString id;
   id = m_db.ReadCard(id);



  if(id!=m_db.getRfid()){
      m_cardReader.run();


    }
   else{
      callGetOrReturn();
   }


 }
void Application::setGetSpotId()
{
        m_ui.displaySpotId(m_db.returnFullSpotId());

}

void Application::setReturnSpotId()
{
     m_ui.displaySpotId(m_db.returnEmptySpotId());
}


void Application::callGetOrReturn()
{

      qDebug()<<m_db.getSpot2Status();
      qDebug()<<m_db.returnScooterId();

      displayScooter_id();
   if (m_db.getstatus() == true){
           getReturnName();
           setReturnSpotId();

           qDebug()<<"Yep";
 }
  else{

           getName();         
           setGetSpotId();
           qDebug()<<"Nope";
 }

}

bool Application::checkScooterExist()const
{
    return m_db.returnExistScooter();
}
bool Application::checkEmptySpotFirst()const{
    return m_db.returnEmptySpotResult();

}
bool Application::checkFullSpotFirst()const{
    return m_db.returnFullSpotResult();

}

void Application::getName()

{

    if (m_db.returnFullSpotResult() == true && m_db.returnExistScooter()== true){
          m_ui.welcomeUser(m_db.getUser());
    }
    else {
      qDebug()<<"Sorry No full Spot";
    }



}

void Application::getReturnName()
{
    if (m_db.returnEmptySpotResult()==true ){
     m_ui.returnScooter(m_db.getUser());
}
    else {
        qDebug()<<"Sorry No empty Spot";
    }

}


QString Application::getCurrentScooterId()const
{
        return m_db.returnScooter_id();

}

QString Application::getReturneedScooterId()const
{
        return m_db.returnScooterId();

}

QString Application::showReturnSpotId()const
{

        return m_db.returnEmptySpotId();

}
QString Application::showGetSpotId()const
{
       return m_db.returnFullSpotId();
}
QString Application::getid()const
{
         return m_db.getRfid();

}
int Application::countGiSpots()const
{
        return m_db.returnGiSpots();
}
int Application::countMuSpots()const
{
        return m_db.returnMuSpots();

}

int Application::countGoSpots()const
{
        return m_db.returnGoSpots();

}

int Application::countLeSpots()const
{
        return m_db.returnLeSpots();
}
int Application::countGiScooters()const
{
      return m_db.returnGiScooters();

}

int Application::countLefkaScooters()const
{
        return m_db.returnLefScooter();

}
int Application::countMuScooters()const
{
      return m_db.returnMuScooters();

}

int Application::countGoScooters()const
{

       return m_db.returnGoScooters();

}
QString Application::EmpCategory()const
{
        return m_db.getCategory();

}
QString Application::getMyName()const
{
        return m_db.getUser();
}

bool Application::chekStatus()
{


      return m_db.getstatus();

}


bool Application::checkSpot1()const
{
        return m_db.getSpot1Status();

}
bool Application::checkSpot2()const
{
         return m_db.getSpot2Status();

}
bool Application::checkSpot3()const
{
          return m_db.getSpot3Status();

}
bool Application::checkSpot4()const
{
          return m_db.getSpot4Status();

}
bool Application::checkSpot5()const
{
        return m_db.getSpot5Status();

}
bool Application::checkSpot6()const
{
         return m_db.getSpot6Status();

}
bool Application::checkSpot7()const{
         return m_db.getSpot7Status();

}
bool Application::checkSpot8()const
{
         return m_db.getSpot8Status();

}
bool Application::checkSpot9()const
{
         return m_db.getSpot9Status();

}
bool Application::checkSpot10()const
{
         return m_db.getSpot10Status();

}



void Application::unlockGetScooter()
{


        if (m_db.getSpot1Status()==true)
        {
                 unlockgetSpot1();
        }
        else if (m_db.getSpot2Status()==true)
        {
                unlockgetSpot2();
        }
        else if (m_db.getSpot3Status()==true)
        {
                unlockgetSpot3();
        }
        else if (m_db.getSpot4Status()==true)
        {
                unlockgetSpot4();

        }
        else if (m_db.getSpot5Status()==true)
        {
                unlockgetSpot5();

        }
        else if (m_db.getSpot6Status()==true)
        {
                  unlockgetSpot6();

        }
        else if (m_db.getSpot7Status()==true)
        {
                 unlockgetSpot7();
        }
        else if (m_db.getSpot8Status()==true)
        {
                  unlockgetSpot8();

        }
        else if (m_db.getSpot9Status()==true)
        {
                  unlockgetSpot9();

        }
        else if (m_db.getSpot10Status()==true)
        {
                 unlockgetSpot10();
        }
        else {
                qDebug()<<"NO Spot is full";
        }



      m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());


}

void Application::unLock1()
{
    digitalWrite(23,LOW);
    digitalWrite(24,HIGH);
    sleep(5);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
}
void Application::lock1()
{
    digitalWrite(23,HIGH);
    digitalWrite(24,LOW);
    sleep(5);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
}
void Application::unlockgetSpot1()
{

    digitalWrite(15,HIGH);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 1 IS UNLOCKED";
    m_db.updateGetSpot1();


}
void Application::unlockgetSpot2()
{

    digitalWrite(15,LOW);
    digitalWrite(16,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 2 IS UNLOCKED";
    m_db.updateGetSpot2();

}

void Application::unlockgetSpot3()
{


    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 3 IS UNLOCKED";
    m_db.updateGetSpot3();
}

void Application::unlockgetSpot4()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 4 IS UNLOCKED";
    m_db.updateGetSpot4();
}

void Application::unlockgetSpot5()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 5 IS UNLOCKED";
    m_db.updateGetSpot5();


}

void Application::unlockgetSpot6(){


    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 6 IS UNLOCKED";
    m_db.updateGetSpot6();
}

void Application::unlockgetSpot7()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 7 IS UNLOCKED";
    m_db.updateGetSpot7();

}

void Application::unlockgetSpot8()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 8 IS UNLOCKED";
    m_db.updateGetSpot8();
}

void Application::unlockgetSpot9()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 9 IS UNLOCKED";
    m_db.updateGetSpot9();


}

void Application::unlockgetSpot10()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,HIGH);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT 10 IS UNLOCKED";
    m_db.updateGetSpot10();
}




void Application::unlockReturnScooter()
{

        if (m_db.getSpot1Status()==false)
        {
                unlockReturnSpot1();

        }
        else if (m_db.getSpot2Status()==false)
        {
                  unlockReturnSpot2();

        }
        else if (m_db.getSpot3Status()==false)
        {
                 unlockReturnSpot3();
        }
        else if (m_db.getSpot4Status()==false)
        {
                 unlockReturnSpot4();

        }
        else if (m_db.getSpot5Status()==false)
        {
                 unlockReturnSpot5();

        }
        else if (m_db.getSpot6Status()==false)
        {
                unlockReturnSpot6();

        }
        else if (m_db.getSpot7Status()==false)
        {
                unlockReturnSpot7();


        }
        else if (m_db.getSpot8Status()==false)
        {
                unlockReturnSpot8();


        }
        else if (m_db.getSpot9Status()==false)
        {
                unlockReturnSpot9();


        }
        else if (m_db.getSpot10Status()==false)
        {
                unlockReturnSpot10();

        }
        else {

                qDebug()<<"NO Spot is empty";
        }

                qDebug()<<"returnPinHasGoneHigh";
                m_db.returnQuery();


}



void Application::unlockReturnSpot1()
{

    digitalWrite(15,HIGH);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 1 IS UNLOCKED";
    m_db.updateReturnSpot1();

}
void Application::unlockReturnSpot2()
{

    digitalWrite(15,LOW);
    digitalWrite(16,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 2 IS UNLOCKED";
    m_db.updateReturnSpot2();

}
void Application::unlockReturnSpot3()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    m_db.updateReturnSpot3();

}
void Application::unlockReturnSpot4()
{


    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 4 IS UNLOCKED";
    m_db.updateReturnSpot4();
}
void Application::unlockReturnSpot5()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 5 IS UNLOCKED";
    m_db.updateReturnSpot5();

}
void Application::unlockReturnSpot6()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 6 IS UNLOCKED";
    m_db.updateReturnSpot6();

}
void Application::unlockReturnSpot7()
{
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 7 IS UNLOCKED";
    m_db.updateReturnSpot7();

}
void Application::unlockReturnSpot8()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 8 IS UNLOCKED";
    m_db.updateReturnSpot8();

}
void Application::unlockReturnSpot9()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(26,LOW);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 9 IS UNLOCKED";
    m_db.updateReturnSpot9();

}
void Application::unlockReturnSpot10()
{

    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(26,HIGH);
    unLock1();
    sleep(5);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 10 IS UNLOCKED";
    m_db.updateReturnSpot10();

}
