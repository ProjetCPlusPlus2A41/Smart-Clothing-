#ifndef PAGEPROMOTION_H
#define PAGEPROMOTION_H

#include <QMainWindow>
#include "promotion.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <arduino.h>
#include "arduino.h"
namespace Ui {
class Arduino;
class pagepromotion;
}

class pagepromotion : public QMainWindow
{
    Q_OBJECT

public:
    explicit pagepromotion(QWidget *parent = nullptr);
    ~pagepromotion();

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

   void on_clients1_clicked();

   void on_emp_clicked();

   void on_livr_clicked();

   void on_order_clicked();

   void on_promo_clicked();

private:
   Ui::pagepromotion *ui;
    promotion p;
    QSerialPort *serial;  // Serial port object
       QString enteredCode;
       QString buffer;
      arduino a;
};

#endif // PAGEPROMOTION_H


