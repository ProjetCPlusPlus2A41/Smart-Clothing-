#include "clients.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>




clients::clients() {}
clients::clients(int id,QString  nom_c, QString prenom_c, QString genre, QString email, int age, QString adresse, QString ty_peau, double taille, double poids, int point_fed, int telephone)
{
    this->id=id;
    this->nom_c = nom_c;
    this->prenom_c = prenom_c;
    this->genre = genre;
    this->email = email;
    this->age = age;
    this->adresse = adresse;
    this->ty_peau = ty_peau;
    this->taille = taille;
    this->poids = poids;
    this->point_fed = point_fed;
    this->telephone = telephone;
}

bool clients::Ajouter()
{
    QSqlQuery query;



    query.prepare("INSERT INTO CLIENTS (NOM_C,PRENOM_C,GENRE, EMAIL,AGE,ADRESSE,TY_PEAU,TAILLE,POIDS,POINT_FED,TELEPHONE) VALUES (:nom_c,:prenom_c,:genre,:email,:age ,:adresse,:ty_peau,:taille,:poids,:point_fed,:telephone)");
    query.bindValue(":nom_c", nom_c);
    query.bindValue(":prenom_c", prenom_c);
    query.bindValue(":genre", genre);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":adresse", adresse);
    query.bindValue(":ty_peau",ty_peau);
    query.bindValue(":taille",taille);
    query.bindValue(":poids",poids);
    query.bindValue(":point_fed",point_fed);
    query.bindValue(":telephone", telephone);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }

    return true;
}
QSqlQueryModel *clients::afficher(bool sortByFidelity, bool fid) {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Modify the query to sort by POINT_FED if requested
    QString queryStr = "SELECT * FROM CLIENTS";
    if (sortByFidelity) {
        queryStr += " ORDER BY POINT_FED ";
        queryStr += fid ? "ASC" : "DESC";
    }

    // Use queryStr instead of a fixed query
    model->setQuery(queryStr);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de peau"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Taille"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Poids"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Genre"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Point de fidelite"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Age"));

    return model;
}

bool clients::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTS WHERE ID_CL = :id");
    query.bindValue(":id", id);

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

// Modify client information
bool clients::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE clients SET nom_c = :nom_c, prenom_c = :prenom_c, adresse = :adresse, "
                  "genre = :genre, email = :email, age = :age, ty_peau = :ty_peau, "
                  "taille = :taille, poids = :poids, point_fed = :point_fed, telephone = :telephone "
                  "WHERE id_cl = :id_cl");

    query.bindValue(":nom_c", nom_c);
    query.bindValue(":prenom_c", prenom_c);
    query.bindValue(":adresse", adresse);
    query.bindValue(":genre", genre);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":ty_peau", ty_peau);
    query.bindValue(":taille", taille);
    query.bindValue(":poids", poids);
    query.bindValue(":point_fed", point_fed);
    query.bindValue(":telephone", telephone);
    query.bindValue(":id_cl", id);  // Only as a condition, not in the SET clause

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError().text();
        return false;
    }

    return true;
}



QSqlQueryModel* clients::rechercherclientParID(const QString& searchId)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE ID_CL = :searchId");
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

