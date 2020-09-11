#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButtonReset_clicked();
    void on_radioButtonPause_clicked();
    void on_radioButtonFish_clicked();
    void on_radioButtonWork_clicked();

    void radioButtonFish_adding();
    void radioButtonWork_adding();

    void lcdNumberFish_display();
    void lcdNumberWork_display();


private:
    Ui::Dialog *ui;

    bool flagFish,flagWork;
    int totalFishTime,totalWorkTime;
    QTimer *qtimerOneSecond;

};
#endif // DIALOG_H
