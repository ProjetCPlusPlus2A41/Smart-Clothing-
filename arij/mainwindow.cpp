#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QMessageBox>
#include <QDebug>


#define file_cin "^[0-9]+$"
#define file_ref_add "^[A-Za-z 0-9]+$"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_CINcL->setValidator(new QRegExpValidator( QRegExp(file_cin),this));
    ui->le_CINcL->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_addresseL->setValidator(new QRegExpValidator( QRegExp(file_ref_add),this));
    ui->le_refL->setValidator(new QRegExpValidator( QRegExp(file_ref_add),this));
    ui->le_refL->setMaxLength(15);
    ui->le_refCMDL->setValidator(new QRegExpValidator( QRegExp(file_ref_add),this));
    ui->le_refCMDL->setMaxLength(15);
    ui->le_dateL->setDate(QDate::currentDate());


    ui->tab_livraison->setModel(L.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    if(controlSaisie()==1)
{
QString ref_l=ui->le_refL->text();
QDate date_l = ui->le_dateL->date();  // Assuming le_dateL is your QDateEdit widget
QString ref_cmd=ui->le_refCMDL->text();
float prix_l=ui->le_prixL->text().toFloat();
QString status_l=ui->le_statusL->currentText();
QString mode_l=ui->le_modeL->currentText();
QString addresse_l=ui->le_addresseL->text();
int cin_cl=ui->le_CINcL->text().toInt();

 Livraison L(ref_l,date_l,ref_cmd,prix_l,status_l,addresse_l,mode_l,cin_cl);

 bool test1=L.LivraisonExiste(ref_l);
  qDebug() <<test1;
             if(test1==false) //LIVRAISON n'EXISTE pas donc ajout
  {
   bool test=L.ajouter();
      qDebug() <<test;
             QMessageBox msgBox;
             if(test)
             {
                 ui->tab_livraison->setModel(L.afficher());
                  clear();
                 msgBox.setText("Ajout avec Succes.");
                msgBox.exec();
             }

             else
             {
             msgBox.setText("!!Echec d'Ajout!!");
           msgBox.exec();
             }
     }

             else //livraison n'existe pas
             {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Livraison Existe !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }

}


}

void MainWindow::on_tab_livraison_activated(const QModelIndex &index)
{
    // Get the selected reference from the table
    QString val = ui->tab_livraison->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM livraison WHERE ref_l = :ref_l");
    qry.bindValue(":ref_l", val);  // Bind the value safely to avoid SQL injection

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->le_refL->setText(qry.value(0).toString());
            // Get and set the date
            QDate date_l = qry.value(1).toDate();
            ui->le_dateL->setDate(date_l);  // sta3malna setDate() khatir QDateEdit
            // Other fields
            ui->le_refCMDL->setText(qry.value(2).toString());
            ui->le_prixL->setText(qry.value(3).toString());
            ui->le_statusL->setCurrentText(qry.value(4).toString());
            ui->le_modeL->setCurrentText(qry.value(6).toString());
            ui->le_addresseL->setText(qry.value(5).toString());
            ui->le_CINcL->setText(qry.value(7).toString());
            ui->le_REFL_supp->setText(qry.value(0).toString());
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Error::"), qry.lastError().text());
    }
}



void MainWindow::clear()
{
    ui->le_refL->clear();
    ui->le_dateL->setDate(QDate::currentDate());
    ui->le_refCMDL->clear();
    ui->le_prixL->clear();
    // Store the current value of the combo boxes before clearing
    QString currentStatus = ui->le_statusL->currentText();
    QString currentMode = ui->le_modeL->currentText();
    // Optionally reset the combo boxes to the current value
    ui->le_statusL->setCurrentText(currentStatus);
    ui->le_modeL->setCurrentText(currentMode);
    ui->le_addresseL->clear();
    ui->le_CINcL->clear();
    ui->le_REFL_supp->clear();
}



bool MainWindow::controlSaisie() {
    // Retrieve the selected date
    QDate selectedDate = ui->le_dateL->date();

    // Check if the date is today or in the future
    if (selectedDate < QDate::currentDate()) {
        QMessageBox::warning(this, "Invalid Date", "Date must be today or in the future.");
        return false;
    }

    // Check if Ref Command field is empty
    if (ui->le_refCMDL->text().isEmpty() || ui->le_refCMDL->text() == "") {
        QMessageBox::warning(this, "Missing Reference Command", "The Reference Command field cannot be empty.");
        return false;
    }

    // Check if Address field is empty
    if (ui->le_addresseL->text().isEmpty() || ui->le_addresseL->text() == "") {
        QMessageBox::warning(this, "Missing Address", "The Address field cannot be empty.");
        return false;
    }

    // Check if Price field is empty or zero
    if (ui->le_prixL->text().isEmpty() || ui->le_prixL->text().toFloat() == 0.0f) {
        QMessageBox::warning(this, "Invalid Price", "The Price field cannot be empty or zero.");
        return false;
    }

    // Check if CIN Client field is empty or zero
    if (ui->le_CINcL->text().isEmpty() || ui->le_CINcL->text().toInt() == 0) {
        QMessageBox::warning(this, "Invalid CIN Client", "The CIN Client field cannot be empty or zero.");
        return false;
    }

    // All validations passed
    return true;
}



void MainWindow::on_pb_modifier_clicked()
{
    if(controlSaisie()==1)
    {
        QString ref_l=ui->le_refL->text();
        QDate date_l = ui->le_dateL->date();  // Assuming le_dateL is your QDateEdit widget
        QString ref_cmd=ui->le_refCMDL->text();
        float prix_l=ui->le_prixL->text().toFloat();
        QString status_l=ui->le_statusL->currentText();
        QString mode_l=ui->le_modeL->currentText();
        QString addresse_l=ui->le_addresseL->text();
        int cin_cl=ui->le_CINcL->text().toInt();

        Livraison L(ref_l,date_l,ref_cmd,prix_l,status_l,addresse_l,mode_l,cin_cl);
bool test1=L.LivraisonExiste(ref_l);
 qDebug() <<test1;
            if(test1==true) //LIVRAISON EXISTE donc il va modifier
 {
    bool test=L.modifier();
     qDebug() <<test;
            QMessageBox msgBox;
            if(test)
            {
                ui->tab_livraison->setModel(L.afficher());
                 clear();
                msgBox.setText("Modification avec Succes.");
               msgBox.exec();
            }

            else
            {
            msgBox.setText("!!Echec de modification!!");
          msgBox.exec();
            }
    }

            else //livraison n'existe pas
            {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Livraison n'existe pas pour modifier !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }


    }

}


void MainWindow::on_pb_supprimer_clicked()
{
 Livraison L;
 L.setRef_l(ui->le_REFL_supp->text());
 bool test1=L.LivraisonExiste(L.getRef_l());

             if(test1==true)    // si livraison existe donc on supprime
  {
    bool test=L.supprimer(L.getRef_l());
    QMessageBox msgBox;
    if(test)
    {
   msgBox.setText("Suppression avec succes.");
    ui->tab_livraison->setModel(L.afficher());
   clear();
    }
   else
    msgBox.setText("!!Echec de suppression!!");
   msgBox.exec();

  }
             else
             {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Livraison n'existe pas !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }

}
