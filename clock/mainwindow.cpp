#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flagFish = 0;
    flagWork = 0;
    totalFishTime = 0;
    totalWorkTime = 0;
    ui->lcdNumberFish->display("00-00-00");
    ui->lcdNumberWork->display("00-00-00");

    //set qtimer
    QTimer *qtimerOneSecond = new QTimer();
    qtimerOneSecond->start(1000);
    //connect
    connect( qtimerOneSecond, SIGNAL(timeout()), this, SLOT(radioButtonFish_adding()) );
    connect( qtimerOneSecond, SIGNAL(timeout()), this, SLOT(radioButtonWork_adding()) );
    connect( qtimerOneSecond, SIGNAL(timeout()), this, SLOT(lcdNumberFish_display()) );
    connect( qtimerOneSecond, SIGNAL(timeout()), this, SLOT(lcdNumberWork_display()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonReset_clicked()
{
    //reset all
    //all number reset to 0
    flagFish = 0;
    flagWork = 0;
    totalFishTime = 0;
    totalWorkTime = 0;
    ui->lcdNumberFish->display("00-00-00");
    ui->lcdNumberWork->display("00-00-00");

    //radio button reset to choose pause
    ui->radioButtonPause->click();
}



void MainWindow::on_radioButtonPause_clicked()
{
    flagFish = 0;
    flagWork = 0;
}

void MainWindow::on_radioButtonFish_clicked()
{
    if(flagFish == 0)
    {
        flagFish = 1;
        flagWork = 0;
    }
}

void MainWindow::on_radioButtonWork_clicked()
{
    if(flagWork == 0)
    {
        flagFish = 0;
        flagWork = 1;
    }
}

void MainWindow::radioButtonFish_adding()
{
    if( flagFish && !flagWork )
        totalFishTime++;
}

void MainWindow::radioButtonWork_adding()
{
    if( flagWork && !flagFish )
        totalWorkTime++;
}

void MainWindow::lcdNumberFish_display()
{
    int fishSeconds,fishMinutes,fishHours;
    fishSeconds=totalFishTime%60;
    fishMinutes=(totalFishTime/60)%60;
    fishHours=(totalFishTime/3600)%60;
    QString fishTime = QString::number(fishHours, 10)+":"+QString::number(fishMinutes, 10)+":"+QString::number(fishSeconds, 10);

    ui->lcdNumberFish->display(fishTime);
}
void MainWindow::lcdNumberWork_display()
{
    int workSeconds,workMinutes,workHours;
    workSeconds=totalWorkTime%60;
    workMinutes=(totalWorkTime/60)%60;
    workHours=(totalWorkTime/3600)%60;
    QString workTime = QString::number(workHours, 10)+":"+QString::number(workMinutes, 10)+":"+QString::number(workSeconds, 10);

    ui->lcdNumberWork->display(workTime);

}
