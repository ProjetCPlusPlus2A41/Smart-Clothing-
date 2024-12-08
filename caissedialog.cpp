#include "CaisseDialog.h"
#include "ui_CaisseDialog.h"
#include "ui_caissedialog.h"

CaisseDialog::CaisseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaisseDialog)
{
    ui->setupUi(this);
    // Optionnel : Personnaliser la fenêtre
    setWindowTitle("Passage à la caisse");
}

CaisseDialog::~CaisseDialog()
{
    delete ui;
}

void CaisseDialog::setClientInfo(const QString &nom, const QString &prenom, int id)
{
    // Mettre à jour les champs d'interface avec les informations du client
    ui->labelNom->setText("Nom : " + nom);
    ui->labelPrenom->setText("Prénom : " + prenom);
    ui->labelId->setText("ID : " + QString::number(id));
}
