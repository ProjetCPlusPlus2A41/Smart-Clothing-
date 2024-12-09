#include "pagelivr.h"
#include "ui_pagelivr.h"
#include "pagelivr.h"
#include "ui_pagelivr.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QDebug>
#include<QLabel>
#include<QMessageBox>
#include<QVBoxLayout>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlQueryModel>
#include<QApplication>
#include <iostream>
#include<QIntValidator>
#include<QBoxLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QMessageBox>
#include <QApplication>
#include <QDebug>
#include<QWidget>
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QDesktopServices>
#include <QTextDocumentWriter>
#include <iostream>
#include <fstream>
#include <QSqlTableModel>
#include <QDir>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QDate>
#include <QSqlError>
#include <QtCharts/QChart>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFile>
#include <QSortFilterProxyModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include<QWidget>
#include <QtSvg/QSvgRenderer>
#include <QFileSystemModel>
#include <QTimer>
#include <QtCharts>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include <QtCharts/QChart>
#include <QDesktopServices>
#include <QUrl>
#include "pageclient.h"
#include "pageemp.h"
#include "pagecom.h"
#include "pagepromotion.h"
#include <QPieSeries>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#define file_cin "^[0-9]+$"
#define file_ref_add "^[A-Za-z 0-9]+$"
pagelivr::pagelivr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pagelivr)
{
    ui->setupUi(this);

    QRegularExpression cinRegex("^[0-9]{8}$");  // Regular expression for CIN (8 digits)
      QRegularExpressionValidator *cinValidator = new QRegularExpressionValidator(cinRegex, this);
      ui->le_CINcL->setValidator(cinValidator);

      // Regular expression for address (alphanumeric characters and spaces)
      QRegularExpression addressRegex("^[a-zA-Z0-9 ]+$");
      QRegularExpressionValidator *addressValidator = new QRegularExpressionValidator(addressRegex, this);
      ui->le_addresseL->setValidator(addressValidator);

      // Set the same reference pattern for other line edits
      ui->le_refL->setValidator(addressValidator);
      ui->le_refCMDL->setValidator(addressValidator);
      ui->le_refL->setMaxLength(15);
      ui->le_refCMDL->setMaxLength(15);
      ui->le_dateL->setDate(QDate::currentDate());



    ui->tab_livraison->setModel(L.afficher());
      connect(ui->sortAscButton, &QPushButton::clicked, this, &pagelivr::on_sortAscButton_clicked);
      connect(ui->sortDescButton, &QPushButton::clicked, this, &pagelivr::on_sortDescButton_clicked);

       connect(ui->tab_livraison, &QTableView::clicked, this, &pagelivr::on_tab_livraison_clicked);

      ui->tab_livraison->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->tab_livraison->setSelectionMode(QAbstractItemView::SingleSelection);
                 QSqlTableModel *model = new QSqlTableModel(this);
                  model->setTable("livraison");  // Replace with the actual table name
                  model->select();

  }

pagelivr::~pagelivr()
{
    delete ui;
}

void pagelivr::on_pb_ajouter_clicked()
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

void pagelivr::on_tab_livraison_activated(const QModelIndex &index)
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



void pagelivr::clear()
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



bool pagelivr::controlSaisie() {
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

    // Check if CIN livraison field is empty or zero
    if (ui->le_CINcL->text().isEmpty() || ui->le_CINcL->text().toInt() == 0) {
        QMessageBox::warning(this, "Invalid CIN livraison", "The CIN livraison field cannot be empty or zero.");
        return false;
    }

    // All validations passed
    return true;
}



void pagelivr::on_pb_modifier_clicked()
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


void pagelivr::on_pb_supprimer_clicked()
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



void pagelivr::on_send_clicked()
{
QString to = ui->rcpt->text();
QString message = ui->msg->toPlainText();

QString subject = "Rh";
 sendMail(to, subject, message);
sendMail(to, subject, message);
QTime time = ui->timeEdit->time();
int sec = QTime(0, 0).msecsTo(time);
QString messagee = "Email Email envoyé"; // Set the message directly here

QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
trayIcon->setIcon(QIcon("E:/not.png"));
trayIcon->setToolTip("Application");
QTimer::singleShot(sec, trayIcon, [trayIcon,message] {
    trayIcon->showMessage("Rh", message, QSystemTrayIcon::Information, 5000);
});

connect(trayIcon, &QSystemTrayIcon::messageClicked, trayIcon, &QSystemTrayIcon::hide);
connect(trayIcon, &QSystemTrayIcon::activated, trayIcon, &QSystemTrayIcon::hide);
trayIcon->show();


connect(trayIcon, &QSystemTrayIcon::messageClicked, trayIcon, &QSystemTrayIcon::hide);
connect(trayIcon, &QSystemTrayIcon::activated, trayIcon, &QSystemTrayIcon::hide);
trayIcon->show();
}
void pagelivr::sendMail(const QString &to, const QString &subject, const QString &message)
{

    QString user = "culeks.here@gmail.com";
   QString pass = "yijxwnltahibhgyy";
    QString host = "smtp.gmail.com";
    int port = 465;
    int timeout = 30000;

    QString from = "culeks.here@gmail.com";


    Smtp *smtp = new Smtp(user, pass, host, port, timeout);


    smtp->sendMail(from, to, subject, message);
}
void pagelivr::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP livraison" ), tr( "Message sent!\n\n" ) );
}
void pagelivr::on_sortAscButton_clicked()
{
    // Retrieve the original data from the database
    QSqlQueryModel *originalModel = L.afficher();

    // Sort the data by the id_a column in ascending order
    originalModel->setQuery("SELECT * FROM livraison ORDER BY cin_cl ASC");
refreshTable(originalModel);

}


void pagelivr::on_sortDescButton_clicked()
{
    // Retrieve the original data from the database
    QSqlQueryModel *originalModel = L.afficher();

    // Sort the data by the id_a column in descending order
    originalModel->setQuery("SELECT * FROM livraison ORDER BY cin_cl DESC");

 refreshTable(originalModel);

}
void pagelivr::refreshTable(QSqlQueryModel *model)
{

    ui->tab_livraison->setModel(model);


    ui->tab_livraison->resizeColumnsToContents();

    ui->tab_livraison->resizeRowsToContents();
}

void pagelivr::on_radioButton_clicked()
{
    QString ref_l = ui->lineEdit->text().trimmed();  // Get the search text

    // Get the filtered model using the Livraison class
    QSqlQueryModel *filteredModel = L.rechercheParref_l(ref_l);

    // Set the model to the QTableView
    ui->tab_livraison->setModel(filteredModel);
}


void pagelivr::on_lineEdit_textChanged(const QString &arg1)
{
    QString filterText = arg1.trimmed();

    // Determine the filter type based on the selected radio button
    int filterColumn = -1;
    if (ui->radioButton->isChecked()) {
        filterColumn = 0; // Assuming `ref_l` is in column 1
    }

    if (filterColumn == -1) {
        return; // No filter column selected, exit early
    }

    // Get the filtered model using the Livraison class
    QSqlQueryModel *filteredModel = L.rechercheParref_l(filterText);

    // Set the model to the QTableView
    ui->tab_livraison->setModel(filteredModel);
}




void pagelivr::on_PDF_clicked()
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
    QAbstractItemModel *model = ui->tab_livraison->model();
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

void pagelivr::on_STAT_clicked()
{
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    pagelivr *dialogStats = new pagelivr();
    dialogStats->Stat();

    // Add the chart view to the layout
    layout->addWidget(dialogStats->ui->lab_chart);

    dialog->setWindowTitle("Service Counts");
    dialog->resize(800, 600);

    // Show the dialog
    dialog->exec();
}
void pagelivr::Stat()
{
    QSqlQuery q1;
    qreal total = 0, enCours = 0, livre = 0, retarde = 0;

    // Execute query to get count of 'En cours'
    if (!q1.exec("SELECT COUNT(*) FROM livraison WHERE status_l = 'En cours'")) {
        qDebug() << "Error executing query for 'En cours':" << q1.lastError().text();
        return;
    }
    if (q1.next()) {
        enCours = q1.value(0).toDouble();
        total += enCours;
    }

    // Execute query to get count of 'Livre'
    if (!q1.exec("SELECT COUNT(*) FROM livraison WHERE status_l = 'Livre'")) {
        qDebug() << "Error executing query for 'Livre':" << q1.lastError().text();
        return;
    }
    if (q1.next()) {
        livre = q1.value(0).toDouble();
        total += livre;
    }

    // Execute query to get count of 'Retarde'
    if (!q1.exec("SELECT COUNT(*) FROM livraison WHERE status_l = 'Retarde'")) {
        qDebug() << "Error executing query for 'Retarde':" << q1.lastError().text();
        return;
    }
    if (q1.next()) {
        retarde = q1.value(0).toDouble();
        total += retarde;
    }

    // Calculate percentages
    qreal percentageEnCours = (total != 0) ? enCours / total : 0;
    qreal percentageLivre = (total != 0) ? livre / total : 0;
    qreal percentageRetarde = (total != 0) ? retarde / total : 0;

    // Create series for the pie chart
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);

    // Append slices
    QPieSlice *sliceEnCours = series->append("En cours", percentageEnCours);
    QPieSlice *sliceLivre = series->append("Livre", percentageLivre);
    QPieSlice *sliceRetarde = series->append("Retarde", percentageRetarde);

    // Set colors for each slice
    sliceEnCours->setBrush(QColor("#0072BB"));   // Blue for 'En cours'
    sliceLivre->setBrush(QColor(Qt::green));     // Green for 'Livre'
    sliceRetarde->setBrush(QColor(Qt::red));     // Red for 'Retarde'

    // Set up chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Status Distribution");

    // Set up chart view
    QChartView *chartview = new QChartView(chart, ui->lab_chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(600, 600);
    chartview->show();
}

void pagelivr::on_tab_livraison_clicked(const QModelIndex &index)
{
    // Get the selected row number
    int row = index.row();

    // Assuming the 'addresse_l' data is in column 5 (adjust if necessary)
    QString address = ui->tab_livraison->model()->data(ui->tab_livraison->model()->index(row, 5)).toString();

    // Set the address in the 'saveadd' line edit
    ui->saveaddr->setText(address);

    // Optionally, print the value for debugging
    qDebug() << "Selected address: " << address;
}

void pagelivr::on_pushButton_clicked()
{
    // Get the value entered in the saveaddr line edit (assuming it's a name or part of the address)
    QString searchValue = ui->saveaddr->text();

    QString address;
    QSqlQuery query;

    // Assuming you're searching for the address based on a value like the client's name or part of the address
    // If it's based on the address itself, replace the 'ref_l' with the column name you're querying on
    query.prepare("SELECT ADDRESSE_L FROM livraison WHERE ADDRESSE_L LIKE ?");
    query.bindValue(0, "%" + searchValue + "%"); // Using LIKE for partial matches

    // Execute the query and check if a result is found
    if(query.exec() && query.next()) {
        address = query.value(0).toString(); // Retrieve the address value
    } else {
        qDebug() << "Failed to retrieve address from the database.";
        return; // Exit if no matching address is found
    }

    // Construct the Google Maps URL using the retrieved address
    QString googleMapsUrl = QString("https://www.google.com/maps?q=%1").arg(address);

    // Open the Google Maps URL in the default web browser
    QDesktopServices::openUrl(QUrl(googleMapsUrl));
}

void pagelivr::on_client1_clicked()
{
    pageclient *pc;
    hide();
    pc = new pageclient (this);
    pc->show();
}

void pagelivr::on_emp_clicked()
{
    pageemp *pe;
    hide();
    pe = new pageemp (this);
    pe->show();
}

void pagelivr::on_ordr_clicked()
{
    pagecom *po;
    hide();
    po = new pagecom (this);
    po->show();
}

void pagelivr::on_prom_clicked()
{
    pagepromotion *pm;
    hide();
    pm= new pagepromotion (this);
    pm->show();
}
