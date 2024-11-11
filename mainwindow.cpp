#include "mainwindow.h"
#include "ui_mainwindow.h" 
#include"gestionemployee.h"
#include"connection.h"
#include"genderstatisticswidget.h"
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




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.Afficher(true, ascending));
    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_pushButton_17_clicked);

    // Créer un QPushButton et ajouter une image
    QPushButton* buttonImage = new QPushButton(ui->page_2);
    QPixmap pixmap("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-05_à_23.03.56_f9e17b70-removebg-preview.png"); // Remplacez le chemin par l'image souhaitée
    QIcon buttonIcon(pixmap);

    // Définir l'icône du bouton avec l'image
    buttonImage->setIcon(buttonIcon);

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
    connect(buttonImage, &QPushButton::clicked, this, &MainWindow::on_button_Image_clicked);


    // Create PDF QPushButton with image
    QPushButton* buttonpdf = new QPushButton(ui->page_2);
    QPixmap pixmap1("C:\\Users\\the cast\\Downloads\\pdf-removebg-preview.png");
    QIcon buttonIconPdf(pixmap1);

    buttonpdf->setIcon(buttonIconPdf);

    int pdfIconSize = 40;
    buttonpdf->setIconSize(QSize(pdfIconSize, pdfIconSize));
    buttonpdf->setFixedSize(pdfIconSize + 5, pdfIconSize + 5);

    int buttonXpdf = 980;
    int buttonYpdf = 20;
    buttonpdf->move(buttonXpdf, buttonYpdf);

    buttonpdf->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    connect(buttonpdf, &QPushButton::clicked, this, &::MainWindow::on_buttonpdf_clicked);
    // Créer un widget de statistiques
    /* Créez un QLabel pour les statistiques
    m_statisticsLabel = new QLabel(this);
    m_statisticsLabel->setAlignment(Qt::AlignCenter);

    // Ajoutez le QLabel à une page de stackedWidget (par exemple, page_3 pour les statistiques)
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_statisticsLabel);
    ui->page_3->setLayout(layout);*/






//chargement des images
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.31_1cb58230-removebg-preview.png", ui->label_21);
    loadImage("C:\\Users\\the cast\\Downloads\\WhatsApp_Image_2024-11-10_à_18.51.31_1cb58230-removebg-preview.png", ui->label);
    loadImage("C:\\Users\\the cast\\Desktop\\image\\WhatsApp Image 2024-11-10 à 18.51.31_e66bd550.jpg", ui->label_8);
    loadImage("C:\\Users\\the cast\\Desktop\\image\\WhatsApp Image 2024-11-10 à 18.51.31_e66bd550.jpg", ui->label_19);
    loadImage("C:\\Users\\ESS\\OneDrive\\Documents\\rapport de stage\\interface\\Capture d’écran 2024-09-29 185850.png", ui->label_9);
    loadImage("C:\\Users\\ESS\\Downloads\\Capture_d_écran_2024-10-20_063741-removebg-preview.png",ui->label_12);
    loadImage("C:\\Users\\ESS\\Downloads\\add-removebg-preview.png",ui->label_13);
    loadImage("C:\\Users\\ESS\\Downloads\\Capture_d_écran_2024-10-20_141614-removebg-preview.png",ui->label_15);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\A P P  I C O N 💕 _.jpeg",ui->label_16);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\liist or task.png",ui->label_17);
    loadImage("C:\\Users\\ESS\\OneDrive\\Bureau\\icon employee\\Capture d’écran 2024-10-20 152058.png",ui->label_18);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::loadImage(const QString& imagePath, QLabel* label)
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

void MainWindow::on_pushButton_5_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
    int ID = ui->lineEdit_8->text().toInt();
    QString Nom_E=ui->lineEdit_9->text();
    QString Prenom_E=ui->lineEdit_10->text();
    QString Mail_E = ui->lineEdit_11->text();
    QString Adresse_E = ui->lineEdit_13->text();
    int Num_Tel_E = ui->lineEdit_12->text().toInt();
    double Salaire = ui->lineEdit_17->text().toFloat();
    QString Role=ui->comboBox_2->currentText();
    int Point_fed_E = ui->lineEdit_22->text().toInt();
    QString Sexe=ui->comboBox->currentText();

    QString Num_Tel_E_str  = QString::number(Num_Tel_E);
    if (Num_Tel_E >= 0 && Num_Tel_E_str.length() != 8) {
        QMessageBox::warning(this, "Invalid Phone Number", "Phone number must be 8 digits.");
        return;
    }
    if(!Mail_E.contains("@")) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    if (Salaire <= 0 ||Point_fed_E<= 0) {
        QMessageBox::warning(this, "Invalid Salary", "Salary must be a positive value.");
        return;
    }


    gestionemployee  E(ID,Nom_E, Prenom_E, Num_Tel_E, Mail_E, Sexe, Adresse_E, Role, Salaire,Point_fed_E);

    bool test=E.Ajouter();

if(test) {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.Afficher(true, ascending));
}else
        QMessageBox:: critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajout non effectué\n"
                                          "click cancel to exit."),QMessageBox::Cancel);


};




void MainWindow::on_pushButton_12_clicked()
{
    int id = ui->lineEdit_8->text().toInt();
    gestionemployee a;
    a.setID(id);
    bool test = a.supprimer(id);

    if(test) {
        // Mettre à jour la vue du tableau
        ui->tableView->setModel(Etmp.Afficher(true, ascending));
        // Afficher un message de confirmation
        QMessageBox::information(this, tr("OK"),
                                 tr("Suppression effectuée\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        // Effacer les champs après la suppression
        ui->lineEdit_8->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_13->clear();
        ui->comboBox_2->clear();
        ui->lineEdit_17->clear();
        ui->comboBox->clear();
        ui->lineEdit_22->clear();
    } else {
        // Afficher un message d'erreur si la suppression a échoué
        QMessageBox::critical(this, tr("NOT OK"),
                              tr("Suppression non effectuée\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

}


void MainWindow::on_tableView_activated(QModelIndex &index)
{
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* page = stackedWidget->widget(2); // Change the index to your page number
    QLineEdit* id = page->findChild<QLineEdit*>("lineEdit_cin"); // Change "id" to the objectName of your id widget

    // Get the ID from the first column of the selected row
    QString value = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    id->setText(value);

    Connection c;
    c.closeConnection();
    QSqlQuery qry;

    qry.prepare("SELECT NOM_E, PRENOM_E, SEXE, MAIL_E, NUM_TEL_E, ADRESSE_E, ROLE, SALAIRE, POINT_FED_E FROM EMPLOYEE WHERE CIN_E = :ID");
    qry.bindValue(":ID", value);

    if(qry.exec())
    {
        if(qry.next())
        {
            ui->lineEdit_9->setText(qry.value(1).toString());
            ui->lineEdit_10->setText(qry.value(2).toString());
            ui->lineEdit_11->setText(qry.value(3).toString());
            ui->lineEdit_12->setText(qry.value(4).toString());
            ui->lineEdit_13->setText(qry.value(5).toString());
            ui->comboBox_2->setCurrentText(qry.value(6).toString());
            ui->lineEdit_17->setText(qry.value(7).toString());
            ui->comboBox->setCurrentText(qry.value(8).toString());
            ui->lineEdit_22->setText(qry.value(9).toString());
        }
    }

}


void MainWindow::on_pushButton_9_clicked()
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


void MainWindow::on_pushButton_13_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0) {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}


void MainWindow::on_pushButton_6_clicked()
{

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



    // Create a gestionemployee object with the updated values
    gestionemployee E(ID, Nom_E, Prenom_E, Num_Tel_E, Mail_E, Sexe, Adresse_E, Role, Salaire, Point_fed_E);

    // Attempt to modify the employee record
    if (E.modifier()) {
        QMessageBox::information(this, tr("OK"), tr("Modification effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        // Update the table view to reflect changes
        ui->tableView->setModel(Etmp.Afficher(true, ascending));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Modification non effectuée\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    static bool ascending = true; // Track the sort order; initially set to ascending

    // Call Afficher with sorting by salary
    ui->tableView->setModel(Etmp.Afficher(true, ascending));

    // Toggle the sort order for the next click
    ascending = !ascending;
}
void MainWindow::on_button_Image_clicked()
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

void MainWindow::on_buttonpdf_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A1);
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

/*void MainWindow::on_pushButton_18_clicked()
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
/*void MainWindow::drawPieChart()
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
void MainWindow::on_pushButton_18_clicked()
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
