#include "pagepromotion.h"
#include "ui_pagepromotion.h"
#include "pagepromotion.h"
#include "ui_pagepromotion.h"
#include "pageclient.h"
#include "pagecom.h"
#include "pageemp.h"
#include "pagelivr.h"
#include "promotion.h"
#include <QMessageBox>
#include <QtCharts>
#include <QSqlQuery>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "qrcode.h"
#include "arduino.h"
pagepromotion::pagepromotion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pagepromotion),
  a()
{
    ui->setupUi(this);


       int ret = a.connect_arduino(); // Connect to Arduino
       switch (ret) {
       case 0:
           qDebug() << "Arduino is available and connected to:" << a.getarduino_port_name();
           break;
       case 1:
           qDebug() << "Arduino is available but not connected to:" << a.getarduino_port_name();
           break;
       case -1:
           qDebug() << "Arduino is not available";
           break;
       }


       QObject::connect(a.getserial(), SIGNAL(readyRead()), this, SLOT(readSerialData()));


   }

   pagepromotion::~pagepromotion()
   {
       if (serial->isOpen()) {
             serial->close();
         }
       delete ui;
   }



void pagepromotion::on_pushButton_5_clicked()
{
    QString Id=ui->lineEdit_8->text();
    QString Nom=ui->lineEdit_9->text();
    QString Pourcentage=ui->lineEdit_10->text();
    QString dateD=ui->dateEdit->date().toString();
    QString dateF=ui->dateEdit_2->date().toString();
    QString Code=ui->lineEdit_13->text();
    QString Category=ui->lineEdit_16->text();
    QString statut=ui->lineEdit_20->text();
    promotion p(Id,Nom,Pourcentage,dateD,dateF,Code,Category,statut);

    if(Id=="" || Nom=="" || Pourcentage=="" || dateD=="" || dateF=="" || Code=="" || Category=="" || statut=="")
    {
         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" veuillez remplir tous les champs."),QMessageBox::Ok);
    }
    else{
    p.ajouter();
    ui->tableView->setModel(p.afficher());
    QFile file("C:/Users/zied/Desktop/fichier.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier.";
        return;
    }
    // Obtenir la date et l'heure actuelles
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
    QTextStream out(&file);
    out << "<font color=\"green\">Le promotion a ete ajoute a " << formattedDateTime << "</font>\n";
    // endl ajoute un saut de ligne
    file.close();

        QMessageBox::information(0,qApp->tr("reussie"),qApp->tr(" la promotion a ete bien ajouteee."),QMessageBox::Ok);
    }
}

void pagepromotion::on_pushButton_6_clicked()
{
    QString Id=ui->lineEdit_8->text();
    QString Nom=ui->lineEdit_9->text();
    QString Pourcentage=ui->lineEdit_10->text();
    QString dateD=ui->dateEdit->date().toString();
    QString dateF=ui->dateEdit_2->date().toString();
    QString Code=ui->lineEdit_13->text();
    QString Category=ui->lineEdit_16->text();
    QString statut=ui->lineEdit_20->text();
    promotion p(Id,Nom,Pourcentage,dateD,dateF,Code,Category,statut);
    if(Id=="" || Nom=="" || Pourcentage=="" || dateD=="" || dateF=="" || Code=="" || Category=="" || statut=="")
    {
         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" veuillez remplir tous les champs."),QMessageBox::Ok);
    }
    else{
    p.modifier();
        QFile file("C:/Users/zied/Desktop/fichier.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Impossible d'ouvrir le fichier.";
            return;
        }
        // Obtenir la date et l'heure actuelles
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

        // Écrire la date et l'heure actuelles suivies du texte dans le fichier
        QTextStream out(&file);
        out << "<font color=\"blue\">La promotion a ete modifiee a " << formattedDateTime << "</font>\n";
        // endl ajoute un saut de ligne
        file.close();
    ui->tableView->setModel(p.afficher());
    QMessageBox::information(0,qApp->tr("reussie"),qApp->tr(" la promotion a ete bien ajouteee."),QMessageBox::Ok);
    }
}

void pagepromotion::on_pushButton_8_clicked()
{
    QString Id = ui->lineEdit_8->text();
    promotion p;

    // Assuming supprimer() returns a bool indicating success or failure
    bool isDeleted = p.supprimer(Id);

    if (isDeleted) {
        // Show a message box to inform the user
        QMessageBox::information(this, "Success", "The promotion has been successfully deleted.");

        // Open the file and write the log entry
        QFile file("C:/Users/zied/Desktop/fichier.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Unable to open the file.";
            return;
        }

        // Get the current date and time
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

        // Write the log entry
        QTextStream out(&file);
        out << " <font color=\"red\">La promotion a ete supprimee a " << formattedDateTime << "\n";
       // endl adds a newline
        file.close();

        // Refresh the table view
        ui->tableView->setModel(p.afficher());
    } else {
        // Show an error message box if deletion fails
        QMessageBox::warning(this, "Error", "Failed to delete the promotion. Please check the ID and try again.");
    }
}


void pagepromotion::on_histo_clicked()
{

    QDialog *dialog = new QDialog(this);
    dialog->resize(600, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/zied/Desktop/fichier.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();
}

void pagepromotion::on_pushButton_10_clicked()
{
    using namespace qrcodegen;

    QString value = ui->qr_code_bar->text();

    if (value.isEmpty()) {
        // Display an error message if the QR code field is empty
        QMessageBox::warning(this, "Error", "QR Code cannot be empty!");
    } else {
        int id = value.toInt();  // Assuming the ID is an integer

        // Check if the ID exists using the idExists function
        if (!p.idExists(id)) {
            // Display an error message if the ID does not exist in the GS_SERVICE table
            QMessageBox::warning(this, "Error", "Service ID does not exist!");
        } else {
            // Format the QR code content in the required format
            QString text = "Service ID: " + value + " is valid in GS_SERVICE.";

            // Create the QR Code object
            QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

            // Get the size of the QR code
            qint32 sz = qr.getSize();

            // Create a QImage object for rendering the QR code
            QImage im(sz, sz, QImage::Format_RGB32);
            QRgb black = qRgb(9, 13, 12);  // QR code black color
            QRgb white = qRgb(255, 255, 255);  // QR code white color

            // Iterate over each pixel in the QR code and set its color
            for (int y = 0; y < sz; y++) {
                for (int x = 0; x < sz; x++) {
                    im.setPixel(x, y, qr.getModule(x, y) ? black : white);
                }
            }

            // Set the generated QR code as a pixmap in the UI, scaled to a reasonable size
            ui->qrcode_label->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
        }
    }
}

void pagepromotion::on_pushButton_7_clicked()
{
    promotion p;
    ui->tableView->setModel(p.tri());

}

void pagepromotion::on_stats_clicked()
{
    QLayoutItem* item;
    while ((item = ui->verticalLayout->layout()->takeAt(0)) != nullptr) {
          delete item->widget();
         delete item;
     }





   QChartView *chartView = nullptr;


     // Create the pie chart based on 'etat'
       chartView = p.createPieChartByStatut();



   // Add the chart view to the layout if it was successfully created
   if (chartView != nullptr) {
       ui->verticalLayout->layout()->addWidget(chartView);
   }

}

void pagepromotion::on_lineEdit_11_textChanged(const QString &arg1)
{


    if (arg1.isEmpty() && ui->lineEdit_11->hasFocus() && !ui->lineEdit_11->hasSelectedText()) {
        ui->tableView->setModel(p.afficher());
        ui->lineEdit_11->setToolTip("Entrez un critère de recherche");
        return; // Exit early if there's no input
    }

    // Call the rechercher function with the selected option and input value
    ui->tableView->setModel(p.rechercher(arg1));
    ui->tableView->clearSelection();
}

void pagepromotion::on_pushButton_11_clicked()
{
p.exportPromotionToPDF();
}
void pagepromotion::updateLabelFromArduino(const QString &data)
{
    // Assuming you have a QLabel in your UI to display Arduino data
    ui->label->setText(data);  // Replace 'arduinoDataLabel' with the actual label name in your UI
}
void pagepromotion::readSerialData()
{
    // Check if data is available from Arduino
    if (a.getserial()->bytesAvailable() > 0) {
        QByteArray data = a.read_from_arduino();  // Read available data
        QString strData = QString(data);         // Convert QByteArray to QString

        qDebug() << "Received data from Arduino: " << strData;  // Debugging

        ui->label->setText("code promo : " + strData);

        // Check if the data contains '#'
        if (strData.contains("#")) {
            // Remove the '#' character
            strData.remove("#");

            qDebug() << "Processed data: " << strData;  // Debugging

            // Process the ID (e.g., search promotion)
            processMessage(strData);
        }
    } else {
        qDebug() << "No data available in the serial buffer.";
    }
}




void pagepromotion::processMessage(const QString &message)
{
    // Process the received message (e.g., search for promotion by ID)
    qDebug() << "Processing message: " << message;

    // Example: If the message is an ID, search for the promotion
    QString id = message.trimmed();
    searchPromotion(id);
}


void pagepromotion::searchPromotion(const QString &id)
{
    // Perform the database search with the received ID (example using QSqlQuery)
    QSqlQuery query;
    query.prepare("SELECT * FROM promotion WHERE id_promo = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        // Assuming the promotion details are in the query result
        QString promoName = query.value("STATUT").toString();
        //QString promoDiscount = query.value("discount").toString();
        // Update the UI with the promo details
        ui->lab->setText("Promotion: " + promoName);
      //  ui->promoDiscountLabel->setText("Discount: " + promoDiscount);
    } else {
        QMessageBox::warning(this, "Error", "Promotion ID not found.");
    }
}

void pagepromotion::on_pushButton_9_clicked()
{
    ui->tableView->setModel(p.afficher());

}

void pagepromotion::on_clients1_clicked()
{
    pageclient *pc;
    hide();
    pc = new pageclient (this);
    pc->show();
}

void pagepromotion::on_emp_clicked()
{
    pageemp *pe;
    hide();
    pe = new pageemp (this);
    pe->show();
}

void pagepromotion::on_livr_clicked()
{
    pagelivr *pl;
    hide();
    pl = new pagelivr (this);
    pl->show();
}

void pagepromotion::on_order_clicked()
{
    pagecom *po;
    hide();
    po = new pagecom (this);
    po->show();
}

void pagepromotion::on_promo_clicked()
{
    pagepromotion *pm;
    hide();
    pm = new pagepromotion (this);
    pm->show();
}
