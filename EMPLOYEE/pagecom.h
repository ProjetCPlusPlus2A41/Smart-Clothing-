#ifndef PAGECOM_H
#define PAGECOM_H

#include <QMainWindow>
#include<commande.h>
#include <QMainWindow>
#include "generateurqrcode.h"
namespace Ui {
class pagecom;
}

class pagecom : public QMainWindow
{
    Q_OBJECT

public:
    explicit pagecom(QWidget *parent = nullptr);
    ~pagecom();


private slots:

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();
    //tri radio boutons
    void on_RBdtdebut_2_toggled(bool checked);

    void on_RBdf_2_toggled(bool checked);

    void on_RBnom_2_toggled(bool checked);
    //bouton bech ta5tar croissant wala decroissant
    void on_RBC_2_clicked();

    void on_RBdc_2_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void onTabCommandeClicked(const QModelIndex &index);


    void on_pdfbt_clicked();

    void on_mailbtn_clicked();

    void on_label_3_linkActivated(const QString &link);

    void on_prom_clicked();

    void on_livr_clicked();

    void on_emp_clicked();

    void on_client_clicked();

private:
       Ui::pagecom *ui;
   commande ctmp;
   //variable bech nestaamlou mbaad f main
   QString etattrie;
};



#endif // PAGECOM_H
