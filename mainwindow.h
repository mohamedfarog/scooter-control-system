#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWindow>
#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QProcess>





namespace Ui {
class MainWindow;
static const int NUM_OF_SCOOTERS = 10;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT
public:
        explicit MainWindow(QWidget *parent = 0);         
        ~MainWindow();






signals:
        void itIsClicked();
        void getIsCalled();
        void returnIsCalled();
        void callDisplayData();
        void dataChanged();
        void rDataChanged();
        void rSpotsChanged();
        void settingPins();



public slots:
        void updateClock();
        void open_get_spot();
        void welcomeUser(QString name);
        void returnScooter(QString name);
        void displayScooterInGirne(int girneScooter, int LefkaScooter, int mugasScooter, int gonyeliScooters, int girneSpots, int lespots, int muspots, int gospots);
        void welcome_page();
        void startView();
        void returnMain();
        void showScooter(QString scooter_id, QString rScooterId);
        void displaySpotId(QString spot_id);
        void on_btn_stationGi_clicked();
        void on_btngi_res_for_me_clicked();      
        void on_btnlef_res_for_me_clicked();
        void on_btn_stationLe_clicked();
        void on_btn_stationM_clicked();
        void on_btnm_res_for_me_clicked();
        void on_btn_stationGo_clicked();
        void on_btngo_res_for_me_clicked();
        void on_un_lock_clicked();
        void on_btn_return_clicked();
        void on_un_lock_2_clicked();
        void on_btnReboot_clicked();


private slots:
        void on_back_2_clicked();

        void on_back_3_clicked();

        void on_back_clicked();

        void on_back_4_clicked();

private:

        Ui::MainWindow *ui;
        QTimer m_timerClock;
        QTimer *mTimer;
        QProcess pyProcess;

        void reserve_spot();
        void reportcall();
        void return_scooter();
        void open_return_sopt();
        int c;


};

#endif // MAINWINDOW_H

