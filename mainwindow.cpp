#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include"connection.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Appel de la fonction afficher() de l’objet `clients ctmp` pour initialiser la vue tableView
    ui->tableView->setModel(ctmp.afficher());
    ui->tableView->setModel(ctmp.afficher(true, fid));
    connect(ui->modifier_2, &QPushButton::clicked, this, &MainWindow::on_modifier_2_clicked);
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
    int buttonX = 340; // Position X dans l'image partagée
    int buttonY = 78; // Position Y dans l'image partagée
    buttonsearch->move(buttonX, buttonY);
    // Définir le style du bouton pour qu'il soit plat
    buttonsearch->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonsearch, &QPushButton::clicked, this, &::MainWindow::on_buttonsearch_clicked);
    //pdf button
    QPushButton* buttonpdff = new QPushButton(ui->page_2);
    QPixmap pixmap1("C:\\Users\\the cast\\Downloads\\pdf-removebg-preview.png");
    QIcon buttonIconPdf(pixmap1);

    buttonpdff->setIcon(buttonIconPdf);

    int pdfIconSize = 40;
    buttonpdff->setIconSize(QSize(pdfIconSize, pdfIconSize));
    buttonpdff->setFixedSize(pdfIconSize + 5, pdfIconSize + 5);

    int buttonXpdf = 1080;
    int buttonYpdf = 20;
    buttonpdff->move(buttonXpdf, buttonYpdf);

    buttonpdff->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonpdff, &QPushButton::clicked, this, &::MainWindow::on_buttonpdff_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_ajouter_clicked()
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

void MainWindow::on_pushButton_9_clicked()
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


    QString telephone_str  = QString::number(telephone);
    if (telephone >= 0 && telephone_str.length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number must be 8 digits.");
    return;
    }
    if (!email.contains("@")) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    if (age <= 0 ||point_fed<= 0) {
        QMessageBox::warning(this, "Invalid Salary", "Salary must be a positive value.");
        return;
    }


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



void MainWindow::on_pushButton_12_clicked()
{
    int id = ui->lineEdit_29->text().toInt();
    clients a;
    a.setId(id);
    bool test = a.supprimer(id);

    if(test) {

        ui->tableView->setModel(a.afficher(true, fid));

        QMessageBox::information(this, tr("OK"),
                                 tr("Suppression effectuée\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

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
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* page = stackedWidget->widget(2); // Change the index to your page number
    QLineEdit* id = page->findChild<QLineEdit*>("lineEdit_29"); // Change "id" to the objectName of your id widget


    QString value = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    id->setText(value);

    Connection c;
    c.closeConnect();
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



void MainWindow::on_pushButton_13_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0) {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_18_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0) {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}


void MainWindow::on_modifier_clicked()
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
    if (c.modifier()) {
        QMessageBox::information(this, tr("OK"), tr("Modification effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Update the table view to reflect changes
        ui->tableView->setModel(c.afficher(true,fid));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Modification non effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }
}


    void MainWindow::on_modifier_2_clicked() {
        static bool fid = true;  // Track the sort order; initially set to ascending

        // Call afficher with sorting by POINT_FED
        ui->tableView->setModel(ctmp.afficher(true, fid));

        // Toggle the sort order for the next click
        fid = !fid;
    }

    void MainWindow::on_buttonsearch_clicked()
    {
        QString searchid = ui->SEARCH->text();
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

    void MainWindow::on_buttonpdff_clicked() {
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
        if (filePath.isEmpty()) {
            return;
        }

        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize::A1);
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

