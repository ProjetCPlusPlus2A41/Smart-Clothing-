#include "gestionemployee.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

gestionemployee::gestionemployee() {}

gestionemployee::gestionemployee(int ID, QString Nom_E, QString Prenom_E, int Num_Tel_E,
                                 QString Mail_E, QString Sexe, QString Adresse_E, QString Role,
                                 double Salaire, int Point_fed_E, QString MDP, QString QUESTION, QString REPONSE)
{
    this->ID = ID;
    this->Nom_E = Nom_E;
    this->Prenom_E = Prenom_E;
    this->Num_Tel_E = Num_Tel_E;
    this->Mail_E = Mail_E;
    this->Sexe = Sexe;
    this->Adresse_E = Adresse_E;
    this->Role = Role;
    this->Salaire = Salaire;
    this->Point_fed_E = Point_fed_E;

    // Initialize new attributes
    this->MDP = MDP;
    this->QUESTION = QUESTION;
    this->REPONSE = REPONSE;
}

bool gestionemployee::Ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYEE (NOM_E, PRENOM_E, SEXE, MAIL_E, NUM_TEL_E, ADRESSE_E, ROLE, SALAIRE, POINT_FED_E, MDP, QUESTION, REPONSE) "
                  "VALUES (:Nom_E, :Prenom_E, :Sexe, :Mail_E, :Num_Tel_E, :Adresse_E, :Role, :Salaire, :Point_fed_E, :MDP, :QUESTION, :REPONSE)");

    query.bindValue(":Nom_E", Nom_E);
    query.bindValue(":Prenom_E", Prenom_E);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":Mail_E", Mail_E);
    query.bindValue(":Num_Tel_E", Num_Tel_E);
    query.bindValue(":Adresse_E", Adresse_E);
    query.bindValue(":Role", Role);
    query.bindValue(":Salaire", Salaire);
    query.bindValue(":Point_fed_E", Point_fed_E);
    query.bindValue(":MDP", MDP);             // Bind new attribute
    query.bindValue(":QUESTION", QUESTION);     // Bind new attribute
    query.bindValue(":REPONSE", REPONSE);       // Bind new attribute

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

QSqlQueryModel* gestionemployee::Afficher(bool sortBySalary, bool ascending) {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Select statement should match the column order in the database
    QString queryStr = "SELECT * FROM EMPLOYEE"; // Consider selecting specific columns for clarity
    if (sortBySalary) {
        queryStr += " ORDER BY Salaire ";
        queryStr += ascending ? "ASC" : "DESC";
    }

    model->setQuery(queryStr);

    // Set headers for the model
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


bool gestionemployee::modifier(int id, const QString& nom, const QString& prenom, const QString& mail,
                               const QString& adresse, int numTel, double salaire, const QString& role,
                               int pointFidelite, const QString& sexe, const QString& mdp,
                               const QString& question, const QString& reponse) {
    QSqlQuery query;
    QString sql = "UPDATE EMPLOYEE SET ";
    bool first = true;

    // Construct the query dynamically based on non-empty fields
    if (!nom.isEmpty()) {
        sql += "Nom_E = :Nom_E";
        first = false;
    }
    if (!prenom.isEmpty()) {
        if (!first) sql += ", ";
        sql += "Prenom_E = :Prenom_E";
        first = false;
    }
    if (!mail.isEmpty()) {
        if (!first) sql += ", ";
        sql += "Mail_E = :Mail_E";
        first = false;
    }
    if (!adresse.isEmpty()) {
        if (!first) sql += ", ";
        sql += "Adresse_E = :Adresse_E";
        first = false;
    }
    if (numTel > 0) {
        if (!first) sql += ", ";
        sql += "Num_Tel_E = :Num_Tel_E";
        first = false;
    }
    if (salaire > 0) {
        if (!first) sql += ", ";
        sql += "Salaire = :Salaire";
        first = false;
    }
    if (!role.isEmpty()) {
        if (!first) sql += ", ";
        sql += "Role = :Role";
        first = false;
    }
    if (pointFidelite > 0) {
        if (!first) sql += ", ";
        sql += "Point_fed_E = :Point_fed_E";
        first = false;
    }
    if (!sexe.isEmpty()) {
        if (!first) sql += ", ";
        sql += "Sexe = :Sexe";
        first = false;
    }
    if (!mdp.isEmpty()) {
        if (!first) sql += ", ";
        sql += "MDP = :MDP";  // Update password if provided
        first = false;
    }
    if (!question.isEmpty()) {
        if (!first) sql += ", ";
        sql += "QUESTION = :QUESTION";  // Update security question if provided
    }
    if (!reponse.isEmpty()) {
        if (!first) sql += ", ";
        sql += "REPONSE = :REPONSE";  // Update security answer if provided
    }

    sql += " WHERE CIN_E = :ID";
    query.prepare(sql);

    // Bind values only for non-empty fields
    if (!nom.isEmpty()) query.bindValue(":Nom_E", nom);
    if (!prenom.isEmpty()) query.bindValue(":Prenom_E", prenom);
    if (!mail.isEmpty()) query.bindValue(":Mail_E", mail);
    if (!adresse.isEmpty()) query.bindValue(":Adresse_E", adresse);
    if (numTel > 0) query.bindValue(":Num_Tel_E", numTel);
    if (salaire > 0) query.bindValue(":Salaire", salaire);
    if (!role.isEmpty()) query.bindValue(":Role", role);
    if (pointFidelite > 0) query.bindValue(":Point_fed_E", pointFidelite);
    if (!sexe.isEmpty()) query.bindValue(":Sexe", sexe);
    if (!mdp.isEmpty()) query.bindValue(":MDP", mdp);                   // Bind new attribute
    if (!question.isEmpty()) query.bindValue(":QUESTION", question);    // Bind new attribute
    if (!reponse.isEmpty()) query.bindValue(":REPONSE", reponse);       // Bind new attribute
    query.bindValue(":ID", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour :" << query.lastError().text();
        return false;
    }

    return true;
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

