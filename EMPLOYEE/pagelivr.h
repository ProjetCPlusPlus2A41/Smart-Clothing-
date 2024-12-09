#ifndef PAGELIVR_H
#define PAGELIVR_H

#include <QMainWindow>
#include "livraison.h"
namespace Ui {
class pagelivr;
}

class pagelivr : public QMainWindow
{
    Q_OBJECT

public:
    explicit pagelivr(QWidget *parent = nullptr);
    ~pagelivr();
private slots:
    void on_pb_ajouter_clicked();
    void clear();
    bool controlSaisie();
    void on_tab_livraison_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();
    void sendMail(const QString &to, const QString &subject, const QString &message);

    void on_sortAscButton_clicked();
void refreshTable(QSqlQueryModel *model);
        void on_sortDescButton_clicked();
    void on_send_clicked();
    void mailSent(QString status);
    void on_radioButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);



void Stat();
    void on_PDF_clicked();

    void on_STAT_clicked();

    void on_tab_livraison_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_client1_clicked();

    void on_emp_clicked();

    void on_ordr_clicked();

    void on_prom_clicked();

private:
      Ui::pagelivr *ui;
    Livraison L;
private:

};

#endif // PAGELIVR_H



