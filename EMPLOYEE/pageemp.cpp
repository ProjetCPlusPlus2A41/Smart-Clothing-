#include "pageemp.h"
#include "ui_pageemp.h"
#include"gestionemployee.h"
#include"connection.h"
#include<QMessageBox>
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
#include <QStackedWidget>
#include"todolist.h"
#include "QDebug"
#include "pageclient.h"
#include "pagelivr.h"
#include "pagepromotion.h"
#include "pagecom.h"
pageemp::pageemp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pageemp),todoListWindow(new TodoList)

{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.Afficher(true, ascending));
    connect(ui->pushButton_17, &QPushButton::clicked, this, &pageemp::on_pushButton_17_clicked);
     connect(ui->pushButton_3, &QPushButton::clicked, this, &pageemp::showTodoList);


    QPixmap pixmap("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-05_à_23.03.56_f9e17b70-removebg-preview.png"); // Remplacez le chemin par l'image souhaitée
    QIcon buttonIcon(pixmap);

    // Définir l'icône du bouton avec l'image
   /* buttonImage->setIcon(buttonIcon);

    // Ajuster la taille du bouton selon l'image
    int iconSize = 80; // Taille de l'icône dans l'image partagée
    buttonImage->setIconSize(QSize(iconSize, iconSize));
    buttonImage->setFixedSize(iconSize + 5, iconSize + 5); // Ajout de 16 pixels pour les bordures

    // Positionner le bouton sur la fenêtre
    int buttonX = 340; // Position X dans l'image partagée
    int buttonY = 78; // Position Y dans l'image partagée
    buttonImage->move(buttonX, buttonY);
    // Définir le style du bouton pour qu'il soit plat
    buttonImage->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonImage, &QPushButton::clicked, this, &pageemp::on_button_Image_clicked);
*/


    // Créer un widget de statistiques
    /* Créez un QLabel pour les statistiques
    m_statisticsLabel = new QLabel(this);
    m_statisticsLabel->setAlignment(Qt::AlignCenter);

    // Ajoutez le QLabel à une page de stackedWidget (par exemple, page_3 pour les statistiques)
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_statisticsLabel);
    ui->page_3->setLayout(layout);*/






/*chargement des images
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.31_1cb58230-removebg-preview.png", ui->label_21);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.31_1cb58230-removebg-preview.png", ui->label);
    loadImage("C:\\Users\\the cast\\Desktop\\image\\WhatsApp Image 2024-11-10 à 18.51.31_e66bd550.jpg", ui->label_8);
    loadImage("C:\\Users\\the cast\\Desktop\\image\\WhatsApp Image 2024-11-10 à 18.51.31_e66bd550.jpg", ui->label_19);
    loadImage("C:\\Users\\ESS\\OneDrive\\Documents\\rapport de stage\\interface\\Capture d’écran 2024-09-29 185850.png", ui->label_9);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.32_aa7ae239-removebg-preview.png",ui->label_12);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.32_aa7ae239-removebg-preview.png",ui->label_34);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.32_06d2d704-removebg-preview.png",ui->label_13);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.32_06d2d704-removebg-preview.png",ui->label_35);
    loadImage("C:\\Users\\ESS\\Downloads\\Capture_d_écran_2024-10-20_141614-removebg-preview.png",ui->label_15);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\A P P  I C O N 💕 _.jpeg",ui->label_16);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\liist or task.png",ui->label_17);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\Capture d’écran 2024-10-20 152058.png",ui->label_18);*/
}

pageemp::~pageemp()
{
    delete ui;
}
void pageemp::loadImage(const QString& imagePath, QLabel* label)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull())
    {
        label->setPixmap(pixmap);
        label->setScaledContents(true);
    }
    else
    {
        qDebug() << "Failed to load image:" << imagePath;
    }
}

void pageemp::on_pushButton_5_clicked() {

    int ID = ui->lineEdit_8->text().toInt();
    QString Nom_E = ui->lineEdit_9->text();
    QString Prenom_E = ui->lineEdit_10->text();
    QString Mail_E = ui->lineEdit_11->text();
    QString Adresse_E = ui->lineEdit_13->text();
    int Num_Tel_E = ui->lineEdit_12->text().toInt();
    double Salaire = ui->lineEdit_17->text().toFloat();
    QString Role = ui->comboBox_2->currentText();
    int Point_fed_E = ui->lineEdit_22->text().toInt();
    QString Sexe = ui->comboBox->currentText();

    // New fields
    QString MDP = ui->mdp->text();            // MDP field
    QString QUESTION = ui->rolebox_3->currentText();  // Question field
    QString REPONSE = ui->reponse->text();    // Response field

    QString Num_Tel_E_str = QString::number(Num_Tel_E);
    if (Num_Tel_E >= 0 && Num_Tel_E_str.length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number must be 8 digits.");
        return;
    }
    if (!Mail_E.contains("@")) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }


    // Pass new attributes to the constructor
    gestionemployee E(ID, Nom_E, Prenom_E, Num_Tel_E, Mail_E, Sexe, Adresse_E, Role, Salaire, Point_fed_E, MDP, QUESTION, REPONSE);

    bool test = E.Ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.Afficher(true, ascending));
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void pageemp::on_tableView_activated(QModelIndex &index)
{


}



void pageemp::on_pushButton_12_clicked() {
    int id = ui->lineEdit_16->text().toInt();
    gestionemployee a;
    a.setID(id);
    bool test = a.supprimer(id);

    if (test) {
        // Update the table view
        ui->tableView->setModel(Etmp.Afficher(true, ascending));

        // Show confirmation message
        QMessageBox::information(this, tr("OK"),
                                 tr("Suppression effectuée\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        // Clear fields after deletion
        ui->lineEdit_16->clear(); // ID field
        ui->lineEdit_10->clear(); // First Name field
        ui->lineEdit_11->clear(); // Last Name field
        ui->lineEdit_12->clear(); // Phone Number field
        ui->lineEdit_13->clear(); // Address field
        ui->comboBox_2->clear();  // Role field
        ui->lineEdit_17->clear();  // Salary field
        ui->comboBox->clear();      // Gender field
        ui->lineEdit_22->clear();  // Points field

        // Clear the new attributes fields
        ui->mdp->clear();     // MDP field
        ui->rolebox_3->clear(); // Security Question field
        ui->reponse->clear();  // Response field
    } else {
        // Show error message if deletion failed
        QMessageBox::critical(this, tr("NOT OK"),
                              tr("Suppression non effectuée\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void pageemp::on_pushButton_6_clicked() {
    // Retrieve updated values from the UI
    int ID = ui->lineEdit_8->text().toInt();
    QString Nom_E = ui->lineEdit_9->text();
    QString Prenom_E = ui->lineEdit_10->text();
    QString Mail_E = ui->lineEdit_11->text();
    QString Adresse_E = ui->lineEdit_13->text();
    int Num_Tel_E = ui->lineEdit_12->text().toInt();
    double Salaire = ui->lineEdit_17->text().toFloat();
    QString Role = ui->comboBox_2->currentText();
    int Point_fed_E = ui->lineEdit_22->text().toInt();
    QString Sexe = ui->comboBox->currentText();

    // New fields
    QString MDP = ui->mdp->text();            // MDP field
    QString QUESTION = ui->rolebox_3->currentText();  // Question field
    QString REPONSE = ui->reponse->text();    // Response field
    gestionemployee E(ID, Nom_E, Prenom_E, Num_Tel_E, Mail_E, Sexe, Adresse_E, Role, Salaire, Point_fed_E, MDP, QUESTION, REPONSE);
    // Attempt to modify the employee record
    if (E.modifier(ID, Nom_E, Prenom_E, Mail_E, Adresse_E, Num_Tel_E, Salaire, Role, Point_fed_E, Sexe, MDP, QUESTION, REPONSE)) {
        QMessageBox::information(this, tr("OK"), tr("Modification effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Update the table view to reflect changes
        ui->tableView->setModel(Etmp.Afficher(true, ascending));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Modification non effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }
}



void pageemp::on_pushButton_9_clicked()
{

}


void pageemp::on_pushButton_16_clicked()
{

}


void pageemp::on_pushButton_13_clicked()
{

}




void pageemp::on_pushButton_17_clicked()
{
    static bool ascending = true; // Track the sort order; initially set to ascending

    // Call Afficher with sorting by salary
    ui->tableView->setModel(Etmp.Afficher(true, ascending));

    // Toggle the sort order for the next click
    ascending = !ascending;
}
void pageemp::on_button_Image_clicked()
{
    QString searchId = ui->SEARCH->text();
    QSqlQueryModel* model = Etmp.rechercherEmployeParID(searchId);

    if (model->rowCount() > 0)
    {
        ui->tableView->setModel(model);
        ui->tableView->selectRow(0); // Sélectionner la première ligne trouvée
    }
    else
    {
        QMessageBox::information(this, "Recherche", "Aucun employé trouvé avec cet ID.");
    }
}

void pageemp::on_buttonpdf_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(filePath);

      // Set the page size to A1
      QPageSize pageSize(QPageSize::A1);  // Create a QPageSize object with the desired size
      pdfWriter.setPageSize(pageSize);
    pdfWriter.setTitle("Employee List");

    QPainter painter(&pdfWriter);
    int yPos = 1000;  // Initial vertical position
    int rowHeight = 1000;  // Row height

    QFont titleFont("Helvetica", 18, QFont::Bold);
    QFont headerFont("Helvetica", 12, QFont::Bold);
    QFont contentFont("Helvetica", 12);

    // Title
    painter.setFont(titleFont);
    painter.drawText(500, 500, "Employee List");

    // Header
    painter.setFont(headerFont);
    painter.drawText(1000, yPos, "ID");
    painter.drawText(3000, yPos, "Nom");
    painter.drawText(5000, yPos, "Prenom");
    painter.drawText(7000, yPos, "Telephone");
    painter.drawText(9000, yPos, "Email");
    painter.drawText(11000, yPos, "Sexe");
    painter.drawText(13000, yPos, "Adresse");
    painter.drawText(15000, yPos, "Role");
    painter.drawText(17000, yPos, "Salary");
    painter.drawText(19000, yPos, "Loyalty Points");
    yPos += rowHeight;

    QSqlQuery query;
    if (!query.prepare("SELECT CIN_E, NOM_E, PRENOM_E, NUM_TEL_E, MAIL_E, SEXE, ADRESSE_E,ROLE, SALAIRE, POINT_FED_E FROM employee")) {
        qDebug() << "SQL Error: " << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to retrieve employee data:\n" + query.lastError().text());
        return;
    }

    if (query.exec()) {
        painter.setFont(contentFont);
        while (query.next()) {
            painter.drawText(1000, yPos, QString::number(query.value("CIN_E").toInt()));  // ID
            painter.drawText(3000, yPos, query.value("NOM_E").toString());  // Nom
            painter.drawText(5000, yPos, query.value("PRENOM_E").toString());  // Prenom
            painter.drawText(7000, yPos, QString::number(query.value("NUM_TEL_E").toInt()));  // Telephone
            painter.drawText(9000, yPos, query.value("MAIL_E").toString());  // Email
            painter.drawText(11000, yPos, query.value("SEXE").toString());  // Sexe
            painter.drawText(13000, yPos, query.value("ADRESSE_E").toString());  // Adresse
            painter.drawText(15000, yPos, query.value("ROLE").toString());
            painter.drawText(17000, yPos, QString::number(query.value("SALAIRE").toDouble(), 'f', 2));
            painter.drawText(19000, yPos, QString::number(query.value("POINT_FED_E").toInt()));
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

/*void pageemp::on_pushButton_18_clicked()
{
    int maleCount = 0;
    int femaleCount = 0;

    QSqlQuery query;
    if (!query.prepare("SELECT SEXE FROM employee")) {
        qDebug() << "SQL Error: " << query.lastError().text();
        QMessageBox::critical(this, "Erreur de base de données", "Échec de la récupération des données des employés:\n" + query.lastError().text());
        return;
    }

    if (query.exec()) {
        while (query.next()) {
            QString sexe = query.value("SEXE").toString();
            if (sexe == "M") {
                maleCount++;
            } else if (sexe == "F") {
                femaleCount++;
            }
        }
    } else {
        qDebug() << "SQL Error: " << query.lastError().text();
        QMessageBox::critical(this, "Erreur de base de données", "Échec de la récupération des données des employés:\n" + query.lastError().text());
        return;
    }

    // Vérifier que m_statisticsLabel est bien initialisé
    if (m_statisticsLabel) {
        m_statisticsLabel->setText("Hommes : " + QString::number(maleCount) + "\nFemmes : " + QString::number(femaleCount));
    } else {
        qDebug() << "m_statisticsLabel n'est pas initialisé !";
    }

    // Afficher la page des statistiques
    ui->stackedWidget->setCurrentIndex(2);
}*/
// Draw the pie chart based on employee sex data
/*void pageemp::drawPieChart()
{
    int maleCount = 0, femaleCount = 0;

    // Execute SQL query to get employee sex information
    QSqlQuery query("SELECT SEXE FROM employee");

    if (query.exec()) {
        while (query.next()) {
            QString sexe = query.value(0).toString();
            if (sexe == "M") {
                maleCount++;
            } else if (sexe == "F") {
                femaleCount++;
            }
        }
    } else {
        qDebug() << "SQL Error:" << query.lastError().text();
        return;
    }

    // Total employees counted
    int total = maleCount + femaleCount;
    if (total == 0) return;  // Avoid division by zero if no employees

    // Create a QPixmap to hold the pie chart image
    QPixmap piePixmap(200, 200);  // Create a pixmap with specified dimensions
    piePixmap.fill(Qt::transparent);  // Fill it with transparency (background)
    QPainter painter(&piePixmap);  // Create a painter to draw on the pixmap
    painter.setRenderHint(QPainter::Antialiasing);  // Enable anti-aliasing for smoother edges

    // Define the rectangle that will bound the pie chart
    QRectF pieRect(10, 10, 180, 180);  // Position and size of the pie chart

    // Draw the male segment (blue)
    painter.setBrush(Qt::blue);
    painter.drawPie(pieRect, 0, 16 * (maleCount * 360 / total));  // Drawing male segment

    // Draw the female segment (magenta)
    painter.setBrush(Qt::magenta);
    painter.drawPie(pieRect, 16 * (maleCount * 360 / total), 16 * (femaleCount * 360 / total));  // Drawing female segment

    // Update QLabel to display the generated pie chart
    ui->label_10->setPixmap(piePixmap);
}

// Example usage of the drawPieChart method*/
/*void pageemp::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Aller à la page où tu veux afficher les stats

    // Exécuter la requête pour récupérer les statistiques de genre
    QSqlQuery query;
    query.prepare("SELECT SEXE, COUNT(*) AS gender_count FROM employee WHERE SEXE IN ('F', 'H') GROUP BY SEXE");

    int femaleCount = 0;
    int maleCount = 0;

    if (query.exec()) {
        while (query.next()) {
            if (query.value("SEXE").toString() == "F") {
                femaleCount = query.value("gender_count").toInt();
            } else if (query.value("SEXE").toString() == "H") {
                maleCount = query.value("gender_count").toInt();
            }
        }
    }

    // Créer un widget pour les statistiques de genre
    GenderStatisticsWidget *statsWidget = new GenderStatisticsWidget(this);
    statsWidget->setStatistics(femaleCount, maleCount);

    // Ajouter le widget de statistiques à la disposition de la page
    // Assure-toi que la page du `stackedWidget` a un layout pour l'ajouter
    QVBoxLayout *layout = new QVBoxLayout(ui->stackedWidget->widget(2));
    layout->addWidget(statsWidget);
}
*/

void pageemp::on_pushButton_3_clicked()
{

}
void pageemp::showTodoList() {
    todoListWindow->show(); // Affiche la fenêtre de Todolist
}

void pageemp::navigateToPage(int pageIndex)
{

}



void pageemp::on_client1_clicked()
{
    pageclient *pc;
    hide();
    pc = new pageclient (this);
    pc->show();
}



void pageemp::on_livr_clicked()
{
    pagelivr *pl;
    hide();
    pl = new pagelivr (this);
    pl->show();
}

void pageemp::on_ord_clicked()
{
    pagecom *po;
    hide();
    po = new pagecom (this);
    po->show();
}

void pageemp::on_prom_clicked()
{
    pagepromotion *pm;
    hide();
    pm= new pagepromotion (this);
    pm->show();
}

void pageemp::on_pushButton_4_clicked()
{

}

void pageemp::on_pdf_clicked(){
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
