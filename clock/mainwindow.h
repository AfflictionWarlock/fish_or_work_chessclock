#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;


    bool flagFish,flagWork;
    int totalFishTime,totalWorkTime;
    QTimer *qtimerOneSecond;



};
#endif // MAINWINDOW_H
