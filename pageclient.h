#ifndef PAGECLIENT_H
#define PAGECLIENT_H

#include <QMainWindow>
#include "clients.h"
#include "messagerie.h" // Include the Messagerie header
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include "arduino.h"

namespace Ui {
class pageclient;
}

class pageclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit pageclient(QWidget *parent = nullptr);
    ~pageclient();
private slots:

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_modifier_clicked();

    void on_modifier_2_clicked();
    void on_buttonsearch_clicked();
    void on_buttonpdff_clicked();
    void on_historiqueButton_clicked();
    void navigateToPage(int pageIndex);
    void readFromArduino();


    void on_order_clicked();

private:
   Ui::pageclient *ui;
    Messagerie *messagerieWidget; // Add this member variable
    clients ctmp;
    bool fid;
    bool sortByFidelity;
    QSqlQueryModel *model;
    Arduino A;
};


#endif // PAGECLIENT_H




