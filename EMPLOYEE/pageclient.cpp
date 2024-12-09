#include "pageclient.h"
#include "ui_pageclient.h"
#include "QMainWindow"
#include "pageclient.h"
#include "ui_pageclient.h"
#include "clients.h"
#include"connection.h"
#include "HistoriqueDialog.h"
#include <QMessageBox>
#include<QString>
#include <QFrame>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QPixmap>
#include <QDir>
#include <QItemSelectionModel>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPageSize>
#include <QPainter>
#include "messagerie.h"
#include "pageemp.h"
#include "pagelivr.h"
#include "pagecom.h"
#include "pagepromotion.h"
#include "CaisseDialog.h"
pageclient::pageclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pageclient)
{
    ui->setupUi(this);
    messagerieWidget = new Messagerie(this); // Create Messagerie instance
    ui->stackedWidget->addWidget(messagerieWidget); // Add the Messagerie widget to the stackedWidget

    // Appel de la fonction afficher() de l’objet `clients ctmp` pour initialiser la vue tableView
    ui->tableView->setModel(ctmp.afficher());
    ui->tableView->setModel(ctmp.afficher(true, fid));
    connect(ui->modifier_2, &QPushButton::clicked, this, &pageclient::on_modifier_2_clicked);
    // Créer un QPushButton et ajouter une image
    QPushButton* buttonsearch = new QPushButton(ui->page_2);
    QPixmap pixmap("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-05_à_23.03.56_f9e17b70-removebg-preview.png"); // Remplacez le chemin par l'image souhaitée
    QIcon buttonIcon(pixmap);

    // Définir l'icône du bouton avec l'image
    buttonsearch->setIcon(buttonIcon);

    // Ajuster la taille du bouton selon l'image
    int iconSize = 80; // Taille de l'icône dans l'image partagée
    buttonsearch->setIconSize(QSize(iconSize, iconSize));
    buttonsearch->setFixedSize(iconSize + 5, iconSize + 5); // Ajout de 16 pixels pour les bordures

    // Positionner le bouton sur la fenêtre
    int buttonX = 200; // Position X dans l'image partagée
    int buttonY = 78; // Position Y dans l'image partagée
    buttonsearch->move(buttonX, buttonY);
    // Définir le style du bouton pour qu'il soit plat
    buttonsearch->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonsearch, &QPushButton::clicked, this, &::pageclient::on_buttonsearch_clicked);
    //pdf button
    QPushButton* buttonpdff = new QPushButton(ui->page_2);
    QPixmap pixmap1("C:\\Users\\the cast\\Downloads\\pdf-removebg-preview.png");
    QIcon buttonIconPdf(pixmap1);

    buttonpdff->setIcon(buttonIconPdf);

    int pdfIconSize = 40;
    buttonpdff->setIconSize(QSize(pdfIconSize, pdfIconSize));
    buttonpdff->setFixedSize(pdfIconSize + 5, pdfIconSize + 5);

    int buttonXpdf = 930;
    int buttonYpdf = 20;
    buttonpdff->move(buttonXpdf, buttonYpdf);

    buttonpdff->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonpdff, &QPushButton::clicked, this, &::pageclient::on_buttonpdff_clicked);
    connect(ui->historiqueButton, &QPushButton::clicked, this, &pageclient::on_historiqueButton_clicked);
    // Connexion du bouton historique
    connect(ui->historiqueButton, &QPushButton::clicked, this, [this]() {
        HistoriqueDialog dialog(this);
        dialog.exec();
    });


   connect(ui->pushButton_45, &QPushButton::clicked, this, [this]() { navigateToPage(0); });
    connect(ui->pushButton_46, &QPushButton::clicked, this, [this]() { navigateToPage(3); });
    connect(ui->pushButton_49, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->pushButton_64, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
   connect(ui->pushButton_28, &QPushButton::clicked, this, [this]() { navigateToPage(0); });
    connect(ui->pushButton_19, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
   connect(ui->pushButton_68, &QPushButton::clicked, this, [this]() { navigateToPage(4); });


   if (A.connect_arduino() == 0) {
       qDebug() << "Arduino connecté sur le port:" << A.getarduino_port_name();
       QMessageBox::information(nullptr,QObject::tr("Arduino connecté sur le port:"),
                                A.getarduino_port_name() ,QMessageBox::Cancel);
   } else {
       qDebug() << "Échec de la connexion à l'Arduino.";
       QMessageBox::warning(nullptr,QObject::tr(""),"Échec de la connexion à l'Arduino.",QMessageBox::Cancel);
   }
     connect(A.get_serial(), &QSerialPort::readyRead, this, &pageclient::readFromArduino);

}
pageclient::~pageclient()
{
    delete ui;
}







void pageclient::readFromArduino()
{
    QByteArray data = A.read_from_arduino();
    QString ab = QString::fromUtf8(data).trimmed(); // Convertir les données reçues en chaîne de caractères

    qDebug() << "Code reçu:" << ab;

    // Vérifiez si le code reçu correspond à "C"
    if (ab == "C")
    {
        QSqlQuery query;
        // Récupérer les informations du client avec ID 4
        query.prepare("SELECT NOM_C, PRENOM_C FROM CLIENTS WHERE ID_CL = 4");
        if (query.exec() && query.next())
        {
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();

            // Ouvrir la fenêtre modale pour afficher les informations du client
            CaisseDialog dialog(this);
            dialog.setClientInfo(nom, prenom, 4);
            dialog.exec(); // Affiche la fenêtre en mode bloquant

            // Mettre à jour la disponibilité du client
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE CLIENTS SET DISPONIBILITE = 'PRESENT' WHERE ID_CL = 4");
            if (!updateQuery.exec())
            {
                QMessageBox::warning(this, "Erreur", "Échec de la mise à jour de la disponibilité du client.");
            }
        }
        else
        {
            QMessageBox::warning(this, "Erreur", "Impossible de récupérer les informations du client.");
        }
    }
    else
    {
        // Si le code reçu n'est pas "C", mettre le client en "ABSENT"
        QSqlQuery query;
        query.prepare("UPDATE CLIENTS SET DISPONIBILITE = 'ABSENT' WHERE ID_CL = 4");
        if (!query.exec())
        {
            QMessageBox::warning(this, "Erreur", "Échec de la mise à jour de la disponibilité du client.");
        }
    }

    // Mettre à jour la vue table
    ui->tableView->setModel(ctmp.afficher());
}




/*void pageclient::on_ajouter_clicked()
{
    // 1. Récupérer les valeurs depuis l'interface utilisateur
    QString nom_c = ui->lineEdit_30->text();
    QString prenom_c = ui->lineEdit_31->text();
    QString genre = ui->lineEdit_37->text();
    QString email = ui->lineEdit_32->text();
    int age = ui->lineEdit_47->text().toInt();
    QString adresse = ui->lineEdit_34->text();
    QString ty_peau = ui->lineEdit_38->text();
    double taille = ui->lineEdit_41->text().toDouble();
    double poids = ui->lineEdit_45->text().toDouble();
    int point_fed = ui->lineEdit_43->text().toInt();
    int telephone = ui->lineEdit_33->text().toInt();

    clients c(nom_c, prenom_c, genre, email, age, adresse, ty_peau, taille, poids, point_fed,telephone);




    if(c.Ajouter())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
        // Mettre à jour la tableView pour refléter l'ajout du nouveau client
        //ui->tableView->setModel(ctmp.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Ajout non effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }

}*/

void pageclient::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    int id=ui->lineEdit_29->text().toInt();
    QString nom_c = ui->lineEdit_30->text();
    QString prenom_c = ui->lineEdit_31->text();
    QString genre = ui->comboBox->currentText();
    QString email = ui->lineEdit_32->text();
    int age = ui->lineEdit_47->text().toInt();
    QString adresse = ui->lineEdit_34->text();
    QString ty_peau = ui->comboBox_2->currentText();
    double taille = ui->lineEdit_41->text().toDouble();
    double poids = ui->lineEdit_45->text().toDouble();
    int point_fed = ui->lineEdit_43->text().toInt();
    int telephone = ui->lineEdit_33->text().toInt();


    /*QString telephone_str  = QString::number(telephone);
    if (telephone >= 0 && telephone_str.length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number must be 8 digits.");
    return;
    }
    if (!email.contains("@")) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    if (age <= 0 ||point_fed<= 0) {
        QMessageBox::warning(this, "Invalid fidelity point", "fidelity point must be a positive value.");
        return;
    }*/


    clients c(id,nom_c, prenom_c, genre, email, age, adresse, ty_peau, taille, poids, point_fed,telephone);




    if(c.Ajouter())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        ui->tableView->setModel(c.afficher(true, fid));
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Ajout non effectué\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }




}



void pageclient::on_pushButton_12_clicked()
{
    int id = ui->lineEdit_36->text().toInt();
    clients a;
    a.setId(id);
    bool test = a.supprimer(id);

    if(test) {

        ui->tableView->setModel(a.afficher(true, fid));

        QMessageBox::information(this, tr("OK"),
                                 tr("Suppression effectuée\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_36->clear();
        ui->lineEdit_30->clear();
        ui->lineEdit_31->clear();
        ui->lineEdit_32->clear();
        ui->lineEdit_33->clear();
        ui->lineEdit_34->clear();
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->lineEdit_41->clear();
        ui->lineEdit_45->clear();
        ui->lineEdit_47->clear();
        ui->lineEdit_43->clear();
    } else {

        QMessageBox::critical(this, tr("NOT OK"),
                              tr("Suppression non effectuée\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
void pageclient::on_tableView_activated(const QModelIndex &index)
{
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* page = stackedWidget->widget(2); // Change the index to your page number
    QLineEdit* id = page->findChild<QLineEdit*>("lineEdit_29"); // Change "id" to the objectName of your id widget


    QString value = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    id->setText(value);


    QSqlQuery qry;

    qry.prepare("SELECT NOM_C,PRENOM_C,GENRE, EMAIL,AGE,ADRESSE,TY_PEAU,TAILLE,POIDS,POINT_FED,TELEPHONE FROM CLIENTS WHERE ID_CL = :ID");
    qry.bindValue(":ID", value);

    if(qry.exec())
    {
        if(qry.next())
        {
            ui->lineEdit_30->setText(qry.value(1).toString());
            ui->lineEdit_31->setText(qry.value(2).toString());
            ui->lineEdit_32->setText(qry.value(3).toString());
            ui->lineEdit_33->setText(qry.value(4).toString());
            ui->lineEdit_34->setText(qry.value(5).toString());
            ui->comboBox->setCurrentText(qry.value(6).toString());
            ui->comboBox_2->setCurrentText(qry.value(7).toString());
            ui->lineEdit_41->setText(qry.value(8).toString());
            ui->lineEdit_45->setText(qry.value(9).toString());
            ui->lineEdit_47->setText(qry.value(10).toString());
            ui->lineEdit_43->setText(qry.value(11).toString());
        }
    }

}



void pageclient::on_pushButton_13_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0) {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}


void pageclient::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void pageclient::on_pushButton_18_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0) {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}


void pageclient::on_modifier_clicked()
{
    // Retrieve updated values from UI
    int id = ui->lineEdit_29->text().toInt();
    QString nom_c = ui->lineEdit_30->text();
    QString prenom_c = ui->lineEdit_31->text();
    QString genre = ui->comboBox->currentText();
    QString email = ui->lineEdit_32->text();
    int age = ui->lineEdit_47->text().toInt();
    QString adresse = ui->lineEdit_34->text();
    QString ty_peau = ui->comboBox_2->currentText();
    double taille = ui->lineEdit_41->text().toDouble();
    double poids = ui->lineEdit_45->text().toDouble();
    int point_fed = ui->lineEdit_43->text().toInt();
    int telephone = ui->lineEdit_33->text().toInt();

    // Create a client object with the updated values
    clients c(id, nom_c, prenom_c, genre, email, age, adresse, ty_peau, taille, poids, point_fed, telephone);

    // Attempt to modify the client record
    if (c.modifier(id, nom_c, prenom_c, adresse, genre, email, age, ty_peau, taille, poids, point_fed, telephone)) {
        QMessageBox::information(this, tr("OK"), tr("Modification effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Update the table view to reflect changes
        ui->tableView->setModel(c.afficher(true,fid));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Modification non effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }
}


    void pageclient::on_modifier_2_clicked() {
        static bool fid = true;  // Track the sort order; initially set to ascending

        // Call afficher with sorting by POINT_FED
        ui->tableView->setModel(ctmp.afficher(true, fid));

        // Toggle the sort order for the next click
        fid = !fid;
    }

    void pageclient::on_buttonsearch_clicked()
    {

        int searchid = ui->SEARCH->text().toInt();
        QSqlQueryModel* model = ctmp.rechercherclientParID(searchid);

        if (model->rowCount() > 0)
        {
            ui->tableView->setModel(model);
            ui->tableView->selectRow(0); // Sélectionner la première ligne trouvée
        }
        else
        {
            QMessageBox::information(this, "Recherche", "Aucun client trouvé avec cet ID.");
        }
    }

    void pageclient::on_buttonpdff_clicked() {
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
        if (filePath.isEmpty()) {
            return;
        }

        QPdfWriter pdfWriter(filePath);

            QPageSize pageSize(QPageSize::A1);
            pdfWriter.setPageSize(pageSize);
        pdfWriter.setTitle("Client List");

        QPainter painter(&pdfWriter);
        int yPos = 1000;  // Initial vertical position
        int rowHeight = 1000;  // Row height

        QFont titleFont("Helvetica", 18, QFont::Bold);
        QFont headerFont("Helvetica", 12, QFont::Bold);
        QFont contentFont("Helvetica", 12);

        // Title
        painter.setFont(titleFont);
        painter.drawText(500, 500, "Client List");

        // Header
        painter.setFont(headerFont);
        painter.drawText(1000, yPos, "ID");
        painter.drawText(3000, yPos, "Nom");
        painter.drawText(5000, yPos, "Prenom");
        painter.drawText(7000, yPos, "EMAIL");
        painter.drawText(9000, yPos, "TELEPHONE");
        painter.drawText(11000, yPos, "ADRESSE");
        painter.drawText(13000, yPos, "type de peau");
        painter.drawText(15000, yPos, "taille");
        painter.drawText(17000, yPos, "poids");
        painter.drawText(19000, yPos, "Genre");
        painter.drawText(21000, yPos, "POINT DE FIDELITE");
        painter.drawText(25000, yPos, "AGE");
        yPos += rowHeight;

        QSqlQuery query;
        if (!query.prepare("SELECT ID_CL, NOM_C, PRENOM_C,EMAIL,TELEPHONE,ADRESSE,TY_PEAU,TAILLE,POIDS,GENRE,POINT_FED,AGE FROM CLIENTS ")) {
            qDebug() << "SQL Error: " << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to retrieve CLIENT data:\n" + query.lastError().text());
            return;
        }

        if (query.exec()) {
            painter.setFont(contentFont);
            while (query.next()) {
                painter.drawText(1000, yPos, QString::number(query.value("ID_CL").toInt()));
                painter.drawText(3000, yPos, query.value("NOM_C").toString());
                painter.drawText(5000, yPos, query.value("PRENOM_C").toString());
                painter.drawText(7000, yPos, (query.value("EMAIL").toString()));
                painter.drawText(9000, yPos, QString::number(query.value("TELEPHONE").toInt()));
                painter.drawText(11000, yPos, query.value("ADRESSE").toString());
                painter.drawText(13000, yPos, query.value("TY_PEAU").toString());
                painter.drawText(15000, yPos, QString::number(query.value("TAILLE").toDouble()));
                painter.drawText(17000, yPos, QString::number(query.value("POIDS").toDouble(), 'f', 2));
                painter.drawText(19000, yPos, (query.value("GENRE").toString()));
                painter.drawText(21000, yPos, QString::number(query.value("POINT_FED").toInt()));
                painter.drawText(25000, yPos, QString::number(query.value("AGE").toInt()));

                yPos += rowHeight;

                if (yPos > pdfWriter.height() - 100) {  // Create a new page if necessary
                    pdfWriter.newPage();
                    yPos = 100;
                }
            }
        } else {
            qDebug() << "SQL Error: " << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to retrieve employee data:\n" + query.lastError().text());
        }

        painter.end();
        QMessageBox::information(this, tr("PDF Export"), tr("PDF file created successfully!"));
    }

    void pageclient::on_historiqueButton_clicked() {
        HistoriqueDialog dialog(this);
        dialog.exec();  // Ouvre la boîte de dialogue en mode modal
    }
    void pageclient::navigateToPage(int pageIndex)
    {
        ui->stackedWidget->setCurrentIndex(pageIndex);
    }

void pageclient::on_emp_clicked()
{
    pageemp *pe;
    hide();
    pe = new pageemp (this);
    pe->show();
}

void pageclient::on_livr_clicked()
{
    pagelivr *pl;
    hide();
    pl = new pagelivr (this);
    pl->show();
}

void pageclient::on_order_clicked()
{
    pagecom *po;
    hide();
    po = new pagecom (this);
    po->show();
}



void pageclient::on_prom_2_clicked()
{
    pagepromotion *pm;
    hide();
    pm= new pagepromotion (this);
    pm->show();
}

void pageclient::on_PDF_clicked()
{
// Open the dialog to choose where to save the PDF
QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", QString(), "PDF Files (*.pdf)");
if (fileName.isEmpty()) {
    return;
}

// Create the PDF writer and painter
QPdfWriter writer(fileName);
writer.setPageSize(QPageSize(QPageSize::A4)); // A4 page size
writer.setResolution(300); // High-quality resolution for better output

QPainter painter(&writer);
painter.setRenderHint(QPainter::Antialiasing);
painter.setRenderHint(QPainter::TextAntialiasing);

// Get the model from the table view
QAbstractItemModel *model = ui->tableView->model();
if (!model) {
    QMessageBox::warning(this, "Warning", "Failed to retrieve table model.");
    return;
}

// Set up font and metrics for the PDF content
QFont font = painter.font();
font.setPointSize(10); // Font size for the text in the PDF
painter.setFont(font);
QFontMetrics fontMetrics(font);

// Calculate cell width and height for the table
int cellWidth = 1996 / model->columnCount(); // Dynamically adjust based on column count
int cellHeight = fontMetrics.height() + 5;   // Adjust height for readability
int margin = 10; // Margin for the content

// Draw table headers
for (int column = 0; column < model->columnCount(); ++column) {
    QRect headerRect(margin + column * cellWidth, margin, cellWidth, cellHeight);
    painter.drawRect(headerRect);
    QString headerText = model->headerData(column, Qt::Horizontal).toString();
    painter.drawText(headerRect, Qt::AlignCenter, headerText);
}

// Draw table content
for (int row = 0; row < model->rowCount(); ++row) {
    for (int column = 0; column < model->columnCount(); ++column) {
        QModelIndex index = model->index(row, column);
        QString text = model->data(index, Qt::DisplayRole).toString();

        QRect cellRect(margin + column * cellWidth, margin + (row + 1) * cellHeight, cellWidth, cellHeight);
        painter.drawRect(cellRect); // Draw the border of the cell
        painter.drawText(cellRect, Qt::AlignLeft | Qt::AlignVCenter, text); // Draw the content of the cell
    }
}

// Draw the footer
QRect footer(margin, margin + (model->rowCount() + 1) * cellHeight, model->columnCount() * cellWidth, cellHeight);
painter.drawRect(footer);
painter.drawText(footer, Qt::AlignCenter, "Fin du document");

// End the painting process
painter.end();

// Notify the user that the PDF was created successfully
QMessageBox::information(this, "PDF Created", "PDF file has been successfully created.");
}



void pageclient::on_SEARCH_cursorPositionChanged(int arg1, int arg2)
{

}


void pageclient::on_SEARCH_textChanged(const QString &arg1)
{
    // Trim the input text and check if it's not empty
    QString filterText = arg1.trimmed();

    // Create a new model to store the query results
    QSqlQueryModel *filteredModel = new QSqlQueryModel();

    if (filterText.isEmpty()) {
        // If the filter text is empty, load all records (no filter)
        QSqlQuery query;
        query.prepare("SELECT * FROM clients");  // Query to select all clients

        if (query.exec()) {
            filteredModel->setQuery(query);  // Set the query result to the model
        } else {
            qDebug() << "Query failed: " << query.lastError();
        }
    } else {
        // If the filter text is not empty, apply the filter by id_cl
        QSqlQuery query;
        query.prepare("SELECT * FROM clients WHERE id_cl = :id_cl");
        query.bindValue(":id_cl", filterText);  // Bind the filtered text (which is the id_cl)

        if (query.exec()) {
            filteredModel->setQuery(query);  // Set the query result to the model
        } else {
            qDebug() << "Query failed: " << query.lastError();
        }
    }

    // Set the model to the QTableView, either filtered or full model
    ui->tableView->setModel(filteredModel);
}
