#include "pagecommand.h"
#include "ui_pagecommand.h"
#include "pagecommand.h"
#include "ui_pagecommand.h"
#include "commande.h"
#include "arduino.h"
#include "pageclient.h"
#include "pageemp.h"
#include "pagelivr.h"
#include "pagepromotion.h"
#include"connection.h"
#include <QMessageBox>
#include<QString>
#include <QFrame>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QPixmap>
#include <QDir>
#include<commande.h>
#include <QThread>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include<generateurqrcode.h>
#include"generateurpdf.h"
#include <QFileDialog>
#include<emailsender.h>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include "qrcode.h"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
pagecommand::pagecommand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pagecommand)
{

    ui->setupUi(this);
    connect(ui->tableView, &QTableView::clicked, this, &pagecommand::onTabCommandeClicked);

    ui->tableView->setModel(ctmp.afficher());
   ui->frame_4->hide();
   ui->frame_2->hide();
   ui->layoutGraph->hide();
   ui->CM_modep->addItem("En ligne");
   ui->CM_modep->addItem("Espece");
   ui->CM_modep_2->addItem("En ligne");
   ui->CM_modep_2->addItem("Espece");

   QList<QDate> reservationDates = commande::getAllDates();

   QTextCharFormat highlightFormat;
   highlightFormat.setBackground(Qt::green);

   for (const QDate &date : reservationDates) {
       ui->calendarWidget1->setDateTextFormat(date, highlightFormat);
   }

}

pagecommand::~pagecommand()
{
    delete ui;
}



void pagecommand::on_pushButton_5_clicked()
{
    arduino A;  // Use the correct class name with lowercase 'a'

    // 1. Récupérer les valeurs depuis l'interface utilisateur
    QString nomco = ui->lineEdit_9->text();
    QDate dateco = ui->dateEdit->date();
    QString modep = ui->CM_modep->currentText();
    double prixco = ui->doubleSpinBox_1->value();

    commande c(nomco, dateco, modep, prixco);

    QByteArray dataToSend;

    if (c.ajouter()) // Si l'ajout est réussi
    {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Mettre à jour la tableView pour refléter l'ajout du nouveau client et calendrier
        ui->tableView->setModel(ctmp.afficher());
        QList<QDate> reservationDates = commande::getAllDates();

        QTextCharFormat highlightFormat;
        highlightFormat.setBackground(Qt::green);

        for (const QDate &date : reservationDates) {
            ui->calendarWidget1->setDateTextFormat(date, highlightFormat);
        }

        // Envoyer '1' à l'Arduino
        dataToSend = "1";
    }
    else // Si l'ajout échoue
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Ajout non effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Envoyer '0' à l'Arduino
        dataToSend = "0";
    }

    // Envoyer les données à l'Arduino
    A.write_to_arduino(dataToSend);
}





void pagecommand::on_pushButton_7_clicked()
{
    QList<QDate> reservationDates = commande::getAllDates();

    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(Qt::green);

    for (const QDate &date : reservationDates) {
        ui->calendarWidget1->setDateTextFormat(date, highlightFormat);
    }
    ui->frame_3->show();
    ui->frame_2->hide();
    ui->frame_4->hide();
    ui->layoutGraph->hide();

}


void pagecommand::on_pushButton_8_clicked()
{
    ui->frame_3->hide();
    ui->frame_2->show();
    ui->frame_4->hide();
    ui->layoutGraph->hide();

}

void pagecommand::on_pushButton_11_clicked()
{
    ui->frame_3->hide();
    ui->frame_2->hide();
    ui->frame_4->show();
    ui->layoutGraph->hide();

}

void pagecommand::on_pushButton_12_clicked()
{

}


void pagecommand::on_RBdtdebut_2_toggled(bool checked)
{
    if(checked){this->etattrie="nom";
    ui->TBtrie_2->setText("Affichage trier selon Nom par ordre");
}
}


void pagecommand::on_RBdf_2_toggled(bool checked)
{
    if(checked){this->etattrie="date";
    ui->TBtrie_2->setText("Affichage trier selon Date par ordre");
}
}

void pagecommand::on_RBnom_2_toggled(bool checked)
{
    if(checked){this->etattrie="prix";
    ui->TBtrie_2->setText("Affichage trier selon Prix par ordre");
}
}

void pagecommand::on_RBC_2_clicked()
{
    if(this->etattrie==""){
       QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Valier choisir une option pour trier \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   }
    else {

        ui->tableView->setModel(ctmp.trier(this->etattrie,true));
    }
}


void pagecommand::on_RBdc_2_clicked()
{
    if(this->etattrie==""){
       QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Valier choisir une option pour trier \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   }
    else {

        ui->tableView->setModel(ctmp.trier(this->etattrie,false));
    }
}



void pagecommand::on_pushButton_15_clicked()
{
    int id=ui->lineEdit_34->text().toInt();
    if(id!=NULL){
        ctmp.recherche(id);
        if(ctmp.getNomco().isNull()){
            QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                       QObject::tr("Valier saisir une id valid \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else{
                ui->lineEdit_23->setText(ctmp.getNomco());
                ui->dateEdit_3->setDate(ctmp.getDateco());
                ui->doubleSpinBox->setValue(ctmp.getPrixco());
                ui->CM_modep_2->setCurrentText(ctmp.getModep());


        }
    }
}


void pagecommand::on_pushButton_6_clicked()
{
    int id=ui->lineEdit_34->text().toInt();
    QString nomco=ui->lineEdit_23->text();
    QDate dateco=ui->dateEdit_3->date();
    double prixco=ui->doubleSpinBox->value();
    QString modep=ui->CM_modep_2->currentText();
     QMessageBox::StandardButton Confirmation;
     Confirmation = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment modifier cette commande?" ,
                                     QMessageBox::Yes | QMessageBox::No);
     if (Confirmation == QMessageBox::Yes) {
         commande c(nomco,dateco,modep,prixco);

        bool test=c.modifier(id);

        if(test){

            ui->tableView->setModel(ctmp.afficher());
            QMessageBox::information (nullptr, QObject::tr("OK"),
                                       QObject::tr("Modification effectué \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::information (nullptr, QObject::tr("Not OK"),
                                       QObject::tr("Modification non effectué \n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
     }
}


void pagecommand::on_pushButton_14_clicked()
{
    int id=ui->lineEdit_34->text().toInt();
    QMessageBox::StandardButton Confirmation;
    Confirmation = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette commande?" ,
                                    QMessageBox::Yes | QMessageBox::No);
    if (Confirmation == QMessageBox::Yes) {
    bool test = ctmp.supprimer(id);
    if (test) {
        ui->tableView->setModel(ctmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuée"), QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectuée"), QMessageBox::Cancel);
    }
    }
}


//QR CODE
void pagecommand::onTabCommandeClicked(const QModelIndex &index) {

}



void pagecommand::on_pdfbt_clicked()
{
    QString nomFichierPDF = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "Fichiers PDF (*.pdf)");

            if (!nomFichierPDF.isEmpty()) {
                QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());

                if (model) {
                    GenerateurPDF::genererPDF(model, nomFichierPDF);
                } else {
                    QMessageBox::warning(this, "Erreur", "Le modèle n'est pas de type QSqlQueryModel.");
                }
            }
}


void pagecommand::on_mailbtn_clicked()
{
    qDebug() <<"ccccccccccccccccccccccc";
       EmailSender *emailSender = new EmailSender("yasminehmila2@gmail.com", ui->mailedit->text(), "helloo  ", "helloo");
           emailSender->sendMail();

}


void pagecommand::on_client1_clicked()
{
    pageclient *pc;
    hide();
    pc = new pageclient (this);
    pc->show();
}

void pagecommand::on_emp_clicked()
{
    pageemp *pe;
    hide();
    pe = new pageemp (this);
    pe->show();
}

void pagecommand::on_livr_clicked()
{
    pagelivr *pl;
    hide();
    pl = new pagelivr (this);
    pl->show();
}

void pagecommand::on_prom_clicked()
{
    pagepromotion *pm;
    hide();
    pm= new pagepromotion (this);
    pm->show();
}



void pagecommand::on_pushButton_3_clicked()
{

}

void pagecommand::on_pushButton_10_clicked()
{
using namespace qrcodegen;

QString value = ui->qr_code_bar_3->text();

// Check if the value is empty
if (value.isEmpty()) {
    QMessageBox::warning(this, "Error", "QR Code cannot be empty!");
} else {
    int id = value.toInt();  // Assuming the ID is an integer

    // Check if the ID exists in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GS_SERVICE WHERE id_service = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Database query failed!");
        return;
    }

    if (query.next() && query.value(0).toInt() > 0) {
        // Format the QR code content
        QString text = "Service ID: " + value + " is valid in GS_SERVICE.";

        // Create the QR Code object
        QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

        // Get the size of the QR code
        int sz = qr.getSize();

        // Create a QImage object for rendering the QR code
        QImage im(sz, sz, QImage::Format_RGB32);
        QRgb black = qRgb(9, 13, 12);  // QR code black color
        QRgb white = qRgb(255, 255, 255);  // QR code white color

        // Iterate over each pixel and set its color based on the QR code modules
        for (int y = 0; y < sz; y++) {
            for (int x = 0; x < sz; x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? black : white);
            }
        }

        // Set the generated QR code as a pixmap in the UI, scaled to a reasonable size
        ui->qrcode_label_3->setPixmap(QPixmap::fromImage(im).scaled(200, 200, Qt::KeepAspectRatio));
    } else {
        // If ID does not exist
        QMessageBox::warning(this, "Error", "Service ID does not exist!");
    }
}
}
