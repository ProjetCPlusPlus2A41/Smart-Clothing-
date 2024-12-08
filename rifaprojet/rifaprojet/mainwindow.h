#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "promotion.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_histo_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_stats_clicked();

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_pushButton_11_clicked();
   void updateLabelFromArduino(const QString &data);
   void searchPromotion(const QString &id);
   void readSerialData();
   void processMessage(const QString &message);
   void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    promotion p;
    QSerialPort *serial;  // Serial port object
       QString enteredCode;
       QString buffer;  // Declare the buffer to store incoming serial data

       Arduino a;
};

#endif // MAINWINDOW_H
