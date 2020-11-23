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
    m_pinController.Mode(15,OUTPUT);
    m_pinController.Mode(16,OUTPUT);
    m_pinController.Mode(0,OUTPUT);
    m_pinController.Mode(1,OUTPUT);
    m_pinController.Mode(2,OUTPUT);
    m_pinController.Mode(3,OUTPUT);
    m_pinController.Mode(4,OUTPUT);
    m_pinController.Mode(5,OUTPUT);
    m_pinController.Mode(8,OUTPUT);
    m_pinController.Mode(26,OUTPUT);
    m_pinController.Mode(23,OUTPUT);
    m_pinController.Mode(24,OUTPUT);    
    m_pinController.Mode(25,OUTPUT);
    m_pinController.Mode(9,OUTPUT);
    m_pinController.Mode(7,OUTPUT);
    m_pinController.Mode(22,OUTPUT);
    m_pinController.Mode(21,OUTPUT);
    m_pinController.Mode(11,OUTPUT);
    m_pinController.Mode(27,OUTPUT);
    m_pinController.Mode(20,OUTPUT);
    m_pinController.Mode(29,OUTPUT);

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0,LOW);
    m_pinController.Write(1,LOW);
    m_pinController.Write(2,LOW);
    m_pinController.Write(3,LOW);
    m_pinController.Write(4,LOW);
    m_pinController.Write(5,LOW);
    m_pinController.Write(8,LOW);
    m_pinController.Write(26,LOW);
    m_pinController.Write(23,LOW);
    m_pinController.Write(24,LOW);

    m_pinController.Write(25,HIGH);
    m_pinController.Write(9,HIGH);
    m_pinController.Write(7,HIGH);
    m_pinController.Write(22,HIGH);
    m_pinController.Write(21,HIGH);
    m_pinController.Write(11,HIGH);
    m_pinController.Write(27,HIGH);
    m_pinController.Write(20,HIGH);
    m_pinController.Write(29,HIGH);
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
}

void Application::unLock1()
{
    m_pinController.Write(23,LOW);
    m_pinController.Write(24,HIGH);
    sleep(5);
    m_pinController.Write(23,LOW);
    m_pinController.Write(24,LOW);
}
void Application::lock1()
{
    m_pinController.Write(23,HIGH);
    m_pinController.Write(24,LOW);
    sleep(5);
    m_pinController.Write(23,LOW);
    m_pinController.Write(24,LOW);
}
void Application::unlockgetSpot1()
{  
    int check = 0;

    m_pinController.Write(15,HIGH);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(25);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot1();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
 }
}

void Application::unlockgetSpot2()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,HIGH);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1){
        int sensor = m_pinController.Read(9);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot2();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }
}

void Application::unlockgetSpot3()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, HIGH);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1){
        int sensor = m_pinController.Read(7);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot3();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }
}

void Application::unlockgetSpot4()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, HIGH);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1){
        int sensor = m_pinController.Read(22);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot4();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }
}

void Application::unlockgetSpot5()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, HIGH);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1){
        int sensor = m_pinController.Read(21);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot5();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }

}

void Application::unlockgetSpot6(){

    int check=0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, HIGH);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);    
    while(check!=1){
        int sensor = m_pinController.Read(11);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot6();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }
}

void Application::unlockgetSpot7()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, HIGH);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);

    while(check!=1){
        int sensor = m_pinController.Read(27);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot7();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }

}

void Application::unlockgetSpot8()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, HIGH);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);

    while(check!=1){
        int sensor = m_pinController.Read(20);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot8();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }

}

void Application::unlockgetSpot9()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, HIGH);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1){
        int sensor = m_pinController.Read(29);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if (sensor==1)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.getQuery(m_db.getEmployee_id(), m_db.getCategory());
            m_db.updateGetSpot9();
            sleep(2);
            lock1();
            setPins();
            qDebug()<<"SPOT 2 IS UNLOCKED";
            break;
        }
    }

}


void Application::unlockgetSpot10()
{

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,HIGH);
    unLock1();
    sleep(10);
    m_db.updateGetSpot9();
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

}



void Application::unlockReturnSpot1()
{
    int check = 0;
    m_pinController.Write(15,HIGH);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(25);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot1();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot2()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,HIGH);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(9);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot2();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot3()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, HIGH);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(7);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot3();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot4()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, HIGH);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(22);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot4();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot5()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, HIGH);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(21);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot5();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot6()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, HIGH);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(11);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot6();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}

void Application::unlockReturnSpot7()
{
    int check = 0;
    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, HIGH);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(27);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot7();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}

void Application::unlockReturnSpot8()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, HIGH);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(20);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot8();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}

void Application::unlockReturnSpot9()
{
    int check = 0;

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, HIGH);
    m_pinController.Write(26,LOW);
    unLock1();
    sleep(5);
    while(check!=1)
    {
        int sensor = m_pinController.Read(29);
        qDebug()<<"SENSOR IS NOT DETECTED";
        if(sensor==0)
        {
            qDebug()<<"SENSOR IS DETECTED NOW";
            m_db.returnQuery();
            m_db.updateReturnSpot9();
            lock1();
            setPins();
            qDebug()<<"SPOT 1 IS UNLOCKED";
            break;

    }
  }
}
void Application::unlockReturnSpot10()
{

    m_pinController.Write(15,LOW);
    m_pinController.Write(16,LOW);
    m_pinController.Write(0, LOW);
    m_pinController.Write(1, LOW);
    m_pinController.Write(2, LOW);
    m_pinController.Write(3, LOW);
    m_pinController.Write(4, LOW);
    m_pinController.Write(5, LOW);
    m_pinController.Write(8, LOW);
    m_pinController.Write(26,HIGH);
    unLock1();
    sleep(10);
    lock1();
    setPins();
    qDebug()<<"SPOT retuen 10 IS UNLOCKED";
    m_db.updateReturnSpot10();

}
