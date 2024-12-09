#include "pagecom.h"
#include "ui_pagecom.h"
#include "pagecom.h"
#include "ui_pagecom.h"
#include "commande.h"
#include "arduino.h"
#include "pageclient.h"
#include "pagepromotion.h"
#include "pagelivr.h"
#include "pageemp.h"
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
#include<qrcode.h>>
#include"generateurpdf.h"
#include <QFileDialog>
#include<emailsender.h>
pagecom::pagecom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pagecom)
{
    ui->setupUi(this);
    connect(ui->tableView, &QTableView::clicked, this, &pagecom::onTabCommandeClicked);

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

pagecom::~pagecom()
{
    delete ui;
}




void pagecom::on_pushButton_5_clicked()
{

    arduino A;

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





void pagecom::on_pushButton_7_clicked()
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


void pagecom::on_pushButton_8_clicked()
{
    ui->frame_3->hide();
    ui->frame_2->show();
    ui->frame_4->hide();
    ui->layoutGraph->hide();

}

void pagecom::on_pushButton_11_clicked()
{
    ui->frame_3->hide();
    ui->frame_2->hide();
    ui->frame_4->show();
    ui->layoutGraph->hide();

}

void pagecom::on_pushButton_12_clicked()
{
    ui->frame_3->hide();
    ui->frame_2->hide();
    ui->frame_4->hide();
    ui->layoutGraph->show();

    commande com;
        QMap<QString, int> stats = com.statistiquesParType();

        QPieSeries *series = new QPieSeries();
        for (auto it = stats.begin(); it != stats.end(); ++it) {
            series->append(it.key(), it.value());
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des Réservations par Mode payment");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setFixedSize(700, 400);

        QGraphicsScene *scene = new QGraphicsScene(this);
        scene->addWidget(chartView);
        ui->layoutGraph->setScene(scene);

}


void pagecom::on_RBdtdebut_2_toggled(bool checked)
{
    if(checked){this->etattrie="nom";
    ui->TBtrie_2->setText("Affichage trier selon Nom par ordre");
}
}


void pagecom::on_RBdf_2_toggled(bool checked)
{
    if(checked){this->etattrie="date";
    ui->TBtrie_2->setText("Affichage trier selon Date par ordre");
}
}

void pagecom::on_RBnom_2_toggled(bool checked)
{
    if(checked){this->etattrie="prix";
    ui->TBtrie_2->setText("Affichage trier selon Prix par ordre");
}
}

void pagecom::on_RBC_2_clicked()
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


void pagecom::on_RBdc_2_clicked()
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



void pagecom::on_pushButton_15_clicked()
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


void pagecom::on_pushButton_6_clicked()
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


void pagecom::on_pushButton_14_clicked()
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
void pagecom::onTabCommandeClicked(const QModelIndex &index) {
    if (index.isValid()) {
            QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->tableView->model());

            if (model) {
                // Collect the data from the selected row in the table
                QStringList donneesLigne;
                for (int col = 0; col < model->columnCount(); ++col) {
                    QModelIndex cellIndex = model->index(index.row(), col);
                    donneesLigne << model->data(cellIndex).toString();
                }

                // Join the data into a single string
                QString donnees = donneesLigne.join(" ");

                // Use qrcode.h to generate the QR code
                qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(donnees.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);  // Encode with low error correction

                // Get the size of the QR code
                int size = qr.getSize();
                QImage qrCodeImage(size, size, QImage::Format_RGB888);

                // Convert QR code matrix to image pixels
                for (int y = 0; y < size; ++y) {
                    for (int x = 0; x < size; ++x) {
                        if (qr.getModule(x, y)) {
                            qrCodeImage.setPixel(x, y, QColor(Qt::black).rgb());
                        } else {
                            qrCodeImage.setPixel(x, y, QColor(Qt::white).rgb());
                        }
                    }
                }

                // Show the QR code in a message box
                QMessageBox msgBox;
                msgBox.setIconPixmap(QPixmap::fromImage(qrCodeImage));
                msgBox.exec();
            }
        }
    }


void pagecom::on_pdfbt_clicked()
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


void pagecom::on_mailbtn_clicked()
{
    qDebug() <<"ccccccccccccccccccccccc";
       EmailSender *emailSender = new EmailSender("yasminehmila2@gmail.com", ui->mailedit->text(), "helloo  ", "helloo");
           emailSender->sendMail();

}


void pagecom::on_label_3_linkActivated(const QString &link)
{

}


void pagecom::on_prom_clicked()
{
    pagepromotion *pm;
    hide();
    pm= new pagepromotion (this);
    pm->show();
}


void pagecom::on_livr_clicked()
{
    pagelivr *pl;
    hide();
    pl = new pagelivr (this);
    pl->show();
}


void pagecom::on_emp_clicked()
{
    pageemp *pe;
    hide();
    pe = new pageemp (this);
    pe->show();
}


void pagecom::on_client_clicked()
{
    pageclient *pc;
    hide();
    pc = new pageclient (this);
    pc->show();
}
