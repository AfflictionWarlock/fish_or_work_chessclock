#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
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

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_pushButtonReset_clicked()
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



void Dialog::on_radioButtonPause_clicked()
{
    flagFish = 0;
    flagWork = 0;
}

void Dialog::on_radioButtonFish_clicked()
{
    if(flagFish == 0)
    {
        flagFish = 1;
        flagWork = 0;
    }
}

void Dialog::on_radioButtonWork_clicked()
{
    if(flagWork == 0)
    {
        flagFish = 0;
        flagWork = 1;
    }
}

void Dialog::radioButtonFish_adding()
{
    if( flagFish && !flagWork )
        totalFishTime++;
}

void Dialog::radioButtonWork_adding()
{
    if( flagWork && !flagFish )
        totalWorkTime++;
}

void Dialog::lcdNumberFish_display()
{
    int fishSeconds,fishMinutes,fishHours;
    fishSeconds=totalFishTime%60;
    fishMinutes=(totalFishTime/60)%60;
    fishHours=(totalFishTime/3600)%60;
    QString fishTime = QString::number(fishHours, 10)+":"+QString::number(fishMinutes, 10)+":"+QString::number(fishSeconds, 10);

    ui->lcdNumberFish->display(fishTime);
}
void Dialog::lcdNumberWork_display()
{
    int workSeconds,workMinutes,workHours;
    workSeconds=totalWorkTime%60;
    workMinutes=(totalWorkTime/60)%60;
    workHours=(totalWorkTime/3600)%60;
    QString workTime = QString::number(workHours, 10)+":"+QString::number(workMinutes, 10)+":"+QString::number(workSeconds, 10);

    ui->lcdNumberWork->display(workTime);

}

