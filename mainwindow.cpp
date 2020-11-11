#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QColor>
#include <QMovie>
#include <QPixmap>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QString>
#include <QMessageBox>
#include <QLabel>
#include <QLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   this->setWindowFlags(Qt::CustomizeWindowHint);
   returnMain();
   startView();
   connect(&m_timerClock, SIGNAL(timeout()), this, SLOT(updateClock()));
   m_timerClock.start(1000);

}

void MainWindow::displaySpotId(QString spot_id)
{
        qDebug()<<spot_id;
        ui->spot_num->setText(spot_id);
        ui->return_spot_num->setText(spot_id);
}

MainWindow::~MainWindow()
{
        delete ui;
}


void MainWindow::welcomeUser(QString name)
{

    ui->welcomeUser->setText("Welcome " + name);
    welcome_page();
}

void MainWindow::returnScooter(QString name)
{

     ui->lb_welcome_return->setText("Welcome " + name);
     return_scooter();
}

void MainWindow::displayScooterInGirne(int girneScooter, int LefkaScooter, int mugasScooter, int gonyeliScooters , int girneSpots, int lespots, int muspots, int gospots)
{
  ui->lb_GiAvailable_scooters->setText(QString::number(girneScooter) +" Scooters");
  ui->lb_LeAvailable_scooters->setText(QString::number(LefkaScooter) +" Scooters");
  ui->lb_mAvailable_scooters->setText(QString::number(mugasScooter)  +" Scooters");
  ui->lb_GoAvailable_scooter->setText(QString::number(gonyeliScooters) +" Scooters");
  ui->lb_GiAvailable_spot->setText(QString::number(girneSpots) +" Spots");
  ui->lb_LeAvailable_spot->setText(QString::number(lespots) +" Spots");
  ui->lb_mAvailable_spot->setText(QString::number(muspots) +" Spots");
  ui->lb_GoAvailable_spot->setText(QString::number(gospots) +" Spots");

}

void MainWindow::showScooter(QString scooter_id, QString rScooterId)
{

    ui->scooter_num->setText(scooter_id);
    ui->return_scooter_num->setText(rScooterId);

}

void MainWindow::startView()
{

    QPixmap bkgnd("/home/pi/scooter-control-system/images/baground1.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    QPixmap logo_ico("/home/pi/scooter-control-system/images/gunsel_logo.png");
    ui->gunsel_logo->setPixmap(logo_ico.scaled(900,700,Qt::KeepAspectRatio));
    QPixmap dg("/home/pi/scooter-control-system/images/station5.png");
    QIcon S0Ico(dg);
    ui->btn_station1->setIcon(S0Ico);
    QIcon S1Ico(dg);
    ui->btn_station2->setIcon(S1Ico);
    QIcon S2Icon(dg);
    ui->btn_station3->setIcon(S2Icon);
    QIcon S3Ico(dg);
    ui->btn_station4->setIcon(S3Ico);
    QPixmap dg6("/home/pi/scooter-control-system/images/R.png");
    QIcon Reboot(dg6);
    ui->btnReboot->setIcon(Reboot);
    ui->btnReboot->setIconSize(QSize(35,35));
    ui->lb_station1->setText("Girne");
    ui->lb_station1->setStyleSheet("color: white; font-family: Roboto condensed; Font: 15pt");
    ui->lb_station2->setText("Lefkoşa");
    ui->lb_station2->setStyleSheet("color: white; font-family: Roboto condensed; Font: 15pt");
    ui->lb_station3->setText("Mağusa");
    ui->lb_station3->setStyleSheet("color: white; font-family: Roboto condensed; Font: 15pt");
    ui->lb_station4->setText("Güzelyurt");
    ui->lb_station4->setStyleSheet("color: white; font-family: Roboto condensed; Font: 15pt");
    ui->lb_GiAvailable_spot->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_GiAvailable_scooters->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_LeAvailable_spot->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_LeAvailable_scooters->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_mAvailable_spot->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_mAvailable_scooters->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_GoAvailable_spot->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->lb_GoAvailable_scooter->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 10pt");
    ui->get_spot->setVisible(false);
    ui->scs_Welcome->setVisible(false);
    ui->scs_return->setVisible(false);
    ui->return_spot->setVisible(false);
    ui->scs_mainMenu->setVisible(true);

}

void MainWindow::updateClock()
{
    QTime time  = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->time->setStyleSheet("color: white; font-family: Roboto condensed" );

    if ((time.second() % 2) == 0){
            time_text[3] = ' ';
            time_text[8] = ' ';
    }
    ui->time->setText(time_text);

}

void MainWindow::welcome_page()
{

    ui->get_spot->setVisible(false);
    ui->scs_Welcome->setVisible(true);
    ui->scs_return->setVisible(false);
    ui->return_spot->setVisible(false);
    ui->scs_mainMenu->setVisible(false);

    QPixmap bkgnd("/home/pi/scooter-control-system/images/background5.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    ui->welcomeUser->setStyleSheet("color: white; font-family: Roboto condensed; Font : 60pt;");
    ui->welcomeUser->setAlignment(Qt::AlignCenter);

    QPixmap dg("/home/pi/scooter-control-system/images/GİRNE.png");
    QPixmap dg1("/home/pi/scooter-control-system/images/LEFKOŞA.png");
    QPixmap dg2("/home/pi/scooter-control-system/images/MAĞUSA.png");
    QPixmap dg3("/home/pi/scooter-control-system/images/GÜZELYURT.png");

    QIcon S0Ico(dg);
    ui->btn_stationGi->setIcon(S0Ico);
    QIcon S1Ico(dg1);
    ui->btn_stationGi->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->btn_stationLe->setIcon(S1Ico);
    QIcon S2Icon(dg2);
    ui->btn_stationM->setIcon(S2Icon);
    QIcon S3Ico(dg3);
    ui->btn_stationGo->setIcon(S3Ico);

    ui->w_current_station->setText("Lefkosa Station");
    ui->w_current_station->setStyleSheet("font-family:  Roboto condensed; Font: 20pt; color: white;");

    ui->lb_gi_spot_num->setText("4 Spot");
    ui->lb_gi_spot_num->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 11pt");

    ui->lb_le_spot_num->setText("2 Spot");
    ui->lb_le_spot_num->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 11pt");

    ui->lb_m_spot_num->setText("0 Spot");
    ui->lb_m_spot_num->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 11pt");

    ui->lb_go_spot_num->setText("8 Spot");
    ui->lb_go_spot_num->setStyleSheet("color: #C4CCCD; font-family: Roboto condensed; Font: 11pt");

}

void MainWindow::returnMain()
{
    ui->btn_stationGi->setStyleSheet("border: 0px solid #0086FF;");
    ui->btn_stationLe->setStyleSheet("border: 0px solid #0086FF;");
    ui->btn_stationM->setStyleSheet("border: 0px solid #0086FF;");
    ui->btn_stationGo->setStyleSheet("border: 0px solid #0086FF;");      
    ui->btnlef_res_for_me->setVisible(false);
    ui->btnlef_5min_res->setVisible(false);
    startView();
}

void MainWindow::reserve_spot()
{
        qDebug()<<"Your spot is reserved";
}

void MainWindow::return_scooter()
{

    QPixmap bkgnd("/home/pi/scooter-control-system/images/background5.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);

    QPixmap d43("/home/pi/scooter-control-system/images/returnScootere.png");
    QIcon locker(d43);
    ui->btn_return->setIcon(locker);
    ui->btn_return->setIconSize(QSize(750,220));

    ui->lb_welcome_return->setStyleSheet("color: white; font-family: Roboto condensed; Font : 60pt;");
    ui->lb_welcome_return->setAlignment(Qt::AlignCenter);

    ui->return_current_station->setText("Lefkosa Station");
    ui->return_current_station->setStyleSheet("color: white; font-family: Roboto condensed; Font : 18pt;");

    ui->get_spot->setVisible(false);
    ui->scs_Welcome->setVisible(false);
    ui->scs_return->setVisible(true);
    ui->return_spot->setVisible(false);
    ui->scs_mainMenu->setVisible(false);
//        QTimer::singleShot(30000, [=](){
//                 startView();

//});

}

void MainWindow::open_get_spot()
{

    QPixmap bkgnd("/home/pi/scooter-control-system/images/background5.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);

    QPixmap dq1("/home/pi/scooter-control-system/images/lock.png");
    QIcon locker(dq1);
    ui->un_lock->setIcon(locker);
    ui->un_lock->setIconSize(QSize(450,350));
    ui->spot_num->setAlignment(Qt::AlignCenter);
    ui->spot_num->setStyleSheet("font-family:  Roboto condensed; Font: 28pt; color: white; font-weight: bold");
    ui->scooter_num->setAlignment(Qt::AlignCenter);
    ui->scooter_num->setStyleSheet("font-family:  Roboto condensed; Font: 20pt; color: white");
    ui->current_station->setText("Lefkosa Station");
    ui->current_station->setStyleSheet("font-family:  Roboto condensed; Font: 20pt; color: white;");
    ui->get_spot->setVisible(true);
    ui->scs_Welcome->setVisible(false);
    ui->scs_return->setVisible(false);
    ui->return_spot->setVisible(false);
    ui->scs_mainMenu->setVisible(false);
}

void MainWindow::open_return_sopt()
{
    QPixmap bkgnd("/home/pi/scooter-control-system/images/background5.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    ui->un_lock_2->setIconSize(QSize(450,350));

    QPixmap dq5("/home/pi/scooter-control-system/images/lock.png");
    QIcon locker(dq5);
    ui->un_lock_2->setIcon(locker);
    ui->return_spot_num->setAlignment(Qt::AlignCenter);
    ui->return_spot_num->setStyleSheet("font-family:  Roboto condensed; Font: 28pt; color: white; font-weight: bold");
    ui->return_scooter_num->setAlignment(Qt::AlignCenter);
    ui->return_scooter_num->setStyleSheet("font-family:  Roboto condensed; Font: 20pt; color: white");
    ui->current_station_2->setText("Lefkosa Station");
    ui->current_station_2->setStyleSheet("font-family:  Roboto condensed; Font: 20pt; color: white;");
    qDebug()<<"reurn spot is opening";
    ui->get_spot->setVisible(false);
    ui->scs_Welcome->setVisible(false);
    ui->scs_return->setVisible(false);
    ui->return_spot->setVisible(true);
    ui->scs_mainMenu->setVisible(false);

}

void MainWindow::on_btn_stationLe_clicked()
{

    emit itIsClicked();
    ui->btnlef_res_for_me->setVisible(true);
    ui->btnlef_res_for_me->setText("Reserve for me");
    ui->btnlef_res_for_me->setStyleSheet("background-color: #44484B; color:white; font-family: Roboto condensed; Font: 12pt");
    ui->btn_stationLe->setStyleSheet("border: 10px solid #0086FF;");
}

void MainWindow::on_btnlef_res_for_me_clicked()
{
    ui->btnlef_res_for_me->setText("Reserved");
    ui->btnlef_res_for_me->setStyleSheet("background-color: #44484B; color:white; font-family: Roboto condensed; Font: 12pt");
    ui->btnlef_res_for_me->setVisible(false);
    ui->btnlef_res_for_me->setVisible(true);
    QTimer::singleShot(2000, [=](){
    ui->btnlef_res_for_me->setVisible(false);
    ui->btnlef_res_for_me->setVisible(false);
    ui->btn_stationLe->setStyleSheet("border: 0px solid #0086FF;");
    reserve_spot();
    open_get_spot();

    });

}

void MainWindow::on_un_lock_clicked()
{
    open_get_spot();
    auto movie = new QMovie(this);
    movie->setFileName("/home/pi/scooter-control-system/images/unlock1.gif");
    connect(movie, &QMovie::frameChanged, [=]{
        ui->un_lock->setIcon(movie->currentPixmap());
    });
    movie->start();
    QTimer::singleShot(1000, [=](){
        emit settingPins();
        emit getIsCalled();
        emit dataChanged();
        emit rSpotsChanged();
        ui->get_spot->setVisible(false);
        ui->scs_Welcome->setVisible(false);
        ui->scs_return->setVisible(false);
        ui->return_spot->setVisible(false);
        ui->scs_mainMenu->setVisible(true);      
        startView();
        movie->stop();


    });

}

void MainWindow::on_btn_return_clicked()
{

    reserve_spot();
    open_return_sopt();
}

void MainWindow::on_un_lock_2_clicked()
{
        open_return_sopt();
        auto movie = new QMovie(this);
        movie->setFileName("/home/pi/scooter-control-system/images/unlock1.gif");
        connect(movie, &QMovie::frameChanged, [=]{
            ui->un_lock_2->setIcon(movie->currentPixmap());
        });
        movie->start();
       QTimer::singleShot(1000, [=](){
           emit settingPins();
           emit returnIsCalled();
           emit rDataChanged();
           emit rSpotsChanged();
            ui->get_spot->setVisible(false);
            ui->scs_Welcome->setVisible(false);
            ui->scs_return->setVisible(false);
            ui->return_spot->setVisible(false);
            ui->scs_mainMenu->setVisible(true);
            startView();
            movie->stop();

      });
}
void MainWindow::on_btnReboot_clicked()
{

   QProcess::execute("reboot");
}

void MainWindow::on_back_2_clicked()
{
    returnMain();
    startView();
}

void MainWindow::on_back_3_clicked()
{
    returnMain();
    startView();
}

void MainWindow::on_back_clicked()
{
    returnMain();
    startView();
}

void MainWindow::on_back_4_clicked()
{
    returnMain();
    startView();
}