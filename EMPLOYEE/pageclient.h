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
      Ui::pageclient *ui;
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


    void on_emp_clicked();

    void on_livr_clicked();

    void on_order_clicked();



    void on_prom_2_clicked();

    void on_PDF_clicked();



    void on_SEARCH_cursorPositionChanged(int arg1, int arg2);

    void on_SEARCH_textChanged(const QString &arg1);

private:

    Messagerie *messagerieWidget; // Add this member variable
    clients ctmp;
    bool fid;
    bool sortByFidelity;
    QSqlQueryModel *model;
    arduino A;
};


#endif // PAGECLIENT_H








