#include "gestionemployee.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>



gestionemployee::gestionemployee() {}
gestionemployee::gestionemployee(int ID, QString Nom_E, QString Prenom_E, int Num_Tel_E, QString Mail_E, QString Sexe, QString Adresse_E, QString Role, double Salaire, int Point_fed_E)
{
    this->ID=ID;
    this->Nom_E = Nom_E;
    this->Prenom_E = Prenom_E;
    this->Num_Tel_E = Num_Tel_E;
    this->Mail_E = Mail_E;
    this->Sexe = Sexe;
    this->Adresse_E = Adresse_E;
    this->Role = Role;
    this->Salaire = Salaire;
    this->Point_fed_E = Point_fed_E;

}

bool gestionemployee::Ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYEE (NOM_E, PRENOM_E, SEXE, MAIL_E, NUM_TEL_E, ADRESSE_E, ROLE, SALAIRE, POINT_FED_E) "
                  "VALUES (:Nom_E, :Prenom_E, :Sexe, :Mail_E, :Num_Tel_E, :Adresse_E, :Role, :Salaire, :Point_fed_E)");

    query.bindValue(":Nom_E", Nom_E);
    query.bindValue(":Prenom_E", Prenom_E);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":Mail_E", Mail_E);
    query.bindValue(":Num_Tel_E", Num_Tel_E);
    query.bindValue(":Adresse_E", Adresse_E);
    query.bindValue(":Role", Role);
    query.bindValue(":Salaire", Salaire);
    query.bindValue(":Point_fed_E", Point_fed_E);
    qDebug() << "Requête préparée :" << query.executedQuery();
    qDebug() << "Paramètres :";
    qDebug() << "Nom_E:" << Nom_E;
    qDebug() << "Prenom_E:" << Prenom_E;
    qDebug() << "Sexe:" << Sexe;
    qDebug() << "Mail_E:" << Mail_E;
    qDebug() << "Num_Tel_E:" << Num_Tel_E;
    qDebug() << "Adresse_E:" << Adresse_E;
    qDebug() << "Role:" << Role;
    qDebug() << "Salaire:" << Salaire;
    qDebug() << "Point_fed_E:" << Point_fed_E;


    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }

    return true;
}
bool gestionemployee::supprimer(int ID) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE CIN_E = :ID");
    query.bindValue(":ID", ID);


    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }


    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucune suppression n'a été effectuée. Assurez-vous que l'ID existe.";
        return false;
    }

    return true;
}
QSqlQueryModel* gestionemployee::Afficher(bool sortBySalary, bool ascending)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Modify the query to sort by salary if requested
    QString queryStr = "SELECT * FROM EMPLOYEE";
    if (sortBySalary) {
        queryStr += " ORDER BY Salaire ";
        queryStr += ascending ? "ASC" : "DESC";
    }

    model->setQuery(queryStr);

    // Set headers as before
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Role"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Point de Fidelite"));

    if (model->lastError().isValid()) {
        qDebug() << "Database error in Afficher:" << model->lastError();
    } else {
        qDebug() << "Affichage completed, row count:" << model->rowCount();
    }

    return model;
}



bool gestionemployee::modifier() {
    QSqlQuery query;

    // Prepare the SQL update query with the attributes for employee management
    query.prepare("UPDATE EMPLOYEE SET "
                  "Nom_E = :Nom_E, "
                  "Prenom_E = :Prenom_E, "
                  "Mail_E = :Mail_E, "
                  "Adresse_E = :Adresse_E, "
                  "Num_Tel_E = :Num_Tel_E, "
                  "Salaire = :Salaire, "
                  "Role = :Role, "
                  "Point_fed_E = :Point_fed_E, "
                  "Sexe = :Sexe "
                  "WHERE CIN_E = :ID");

    // Bind the parameters with the attributes of the class
    query.bindValue(":Nom_E", Nom_E);
    query.bindValue(":Prenom_E", Prenom_E);
    query.bindValue(":Mail_E", Mail_E);
    query.bindValue(":Adresse_E", Adresse_E);
    query.bindValue(":Num_Tel_E", Num_Tel_E);
    query.bindValue(":Salaire", Salaire);
    query.bindValue(":Role", Role);
    query.bindValue(":Point_fed_E", Point_fed_E);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":ID", ID);  // ID for the WHERE clause

    // Execute the query and handle potential errors
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour:" << query.lastError().text();
        return false;
    }

    return true; // Return true if successful
}

QSqlQueryModel* gestionemployee::rechercherEmployeParID(const QString& searchId)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE CIN_E = :searchId");
    query.bindValue(":searchId", searchId);
    if (query.exec())
    {
        model->setQuery(std::move(query));
    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête de recherche : " << query.lastError().text();
    }
    return model;
}

