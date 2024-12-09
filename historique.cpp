#include "historiquedialog.h"
#include "ui_historiquedialog.h"
#include "QStringList"
#include "QStringListModel"
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QtSql/QSqlQuery>
#include <QDebug>
HistoriqueDialog::HistoriqueDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoriqueDialog)
{
    ui->setupUi(this);
    loadImage("C:\\Users\\the cast\\Downloads\\aesthetic template 02.jpeg", ui->label);


    chargerHistorique();
}

HistoriqueDialog::~HistoriqueDialog()
{
    delete ui;
}
void HistoriqueDialog::loadImage(const QString& imagePath, QLabel* label)
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
void HistoriqueDialog::chargerHistorique() {
    QFile file("historique_clients.txt");
    QStringList historiqueEntries;  // Liste pour stocker les entrées

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            historiqueEntries << line;  // Ajoute chaque ligne du fichier à la liste
        }
        file.close();
    } else {
        qDebug() << "Impossible d'ouvrir le fichier d'historique.";
    }

    // Créez un modèle basé sur QStringList et liez-le à la vue
    QStringListModel *model = new QStringListModel();
    model->setStringList(historiqueEntries);  // Associez la liste au modèle

    // Appliquez le modèle à votre QListView
    ui->historiqueList->setModel(model);  // Assurez-vous que c'est un QListView dans le .ui
}
