#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<commande.h>
#include <QMainWindow>
#include "generateurqrcode.h"
//définir des éléments relatifs à l'interface utilisateur générée automatiquement par Qt Designer
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //Elle permet à Qt de gérer l'envoi de signaux et la connexion avec des slots.
    Q_OBJECT

public:
    // constructeur de la classe MainWindow
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_order_clicked();

    void on_clients_clicked();

private:
    Ui::MainWindow *ui;
   commande ctmp;
   //variable bech nestaamlou mbaad f main
   QString etattrie;
};

#endif // MAINWINDOW_H
