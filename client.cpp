#include "clients.h"
#include "historiquedialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>




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



    query.prepare("INSERT INTO CLIENTS (NOM_C,PRENOM_C,EMAIL,TELEPHONE,ADRESSE,TY_PEAU,TAILLE,POIDS,GENRE,POINT_FED,AGE) VALUES (:nom_c,:prenom_c,:email,:telephone ,:adresse,:ty_peau,:taille,:poids,:genre,:point_fed,:age)");
    query.bindValue(":nom_c", nom_c);
    query.bindValue(":prenom_c", prenom_c);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":ty_peau",ty_peau);
    query.bindValue(":taille",taille);
    query.bindValue(":poids",poids);
    query.bindValue(":genre", genre);
    query.bindValue(":point_fed",point_fed);
    query.bindValue(":age", age);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }
    // Obtenir l'ID du dernier client ajouté
    id = query.lastInsertId().toInt();
    enregistrerHistorique("Ajout       ",     nom_c,       id);
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
    enregistrerHistorique("Suppression", nom_c, id);

    return true;
}

bool clients::modifier(int id, const QString& nom, const QString& prenom, const QString& adresse,
                       const QString& genre, const QString& email, int age, const QString& ty_peau,
                       double taille, double poids, int pointFid, int telephone) {
    QSqlQuery query;
    QString sql = "UPDATE clients SET ";
    bool first = true;

    // Construire dynamiquement la requête en ajoutant uniquement les champs non vides
    if (!nom.isEmpty()) {
        sql += "nom_c = :nom_c";
        first = false;
    }
    if (!prenom.isEmpty()) {
        if (!first) sql += ", ";
        sql += "prenom_c = :prenom_c";
        first = false;
    }
    if (!adresse.isEmpty()) {
        if (!first) sql += ", ";
        sql += "adresse = :adresse";
        first = false;
    }
    if (!genre.isEmpty()) {
        if (!first) sql += ", ";
        sql += "genre = :genre";
        first = false;
    }
    if (!email.isEmpty()) {
        if (!first) sql += ", ";
        sql += "email = :email";
        first = false;
    }
    if (age > 0) {
        if (!first) sql += ", ";
        sql += "age = :age";
        first = false;
    }
    if (!ty_peau.isEmpty()) {
        if (!first) sql += ", ";
        sql += "ty_peau = :ty_peau";
        first = false;
    }
    if (taille > 0) {
        if (!first) sql += ", ";
        sql += "taille = :taille";
        first = false;
    }
    if (poids > 0) {
        if (!first) sql += ", ";
        sql += "poids = :poids";
        first = false;
    }
    if (pointFid > 0) {
        if (!first) sql += ", ";
        sql += "point_fed = :point_fed";
        first = false;
    }
    if (telephone > 0) {
        if (!first) sql += ", ";
        sql += "telephone = :telephone";
    }

    sql += " WHERE id_cl = :ID";
    query.prepare(sql);

    // Lier les valeurs aux paramètres uniquement si elles ne sont pas vides ou nulles
    if (!nom.isEmpty()) query.bindValue(":nom_c", nom);
    if (!prenom.isEmpty()) query.bindValue(":prenom_c", prenom);
    if (!adresse.isEmpty()) query.bindValue(":adresse", adresse);
    if (!genre.isEmpty()) query.bindValue(":genre", genre);
    if (!email.isEmpty()) query.bindValue(":email", email);
    if (age > 0) query.bindValue(":age", age);
    if (!ty_peau.isEmpty()) query.bindValue(":ty_peau", ty_peau);
    if (taille > 0) query.bindValue(":taille", taille);
    if (poids > 0) query.bindValue(":poids", poids);
    if (pointFid > 0) query.bindValue(":point_fed", pointFid);
    if (telephone > 0) query.bindValue(":telephone", telephone);
    query.bindValue(":ID", id);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour :" << query.lastError().text();
        return false;
    }
    enregistrerHistorique("Modification   ",    nom_c,     id);


    return true;
}




QSqlQueryModel* clients::rechercherclientParID(int searchId)
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
void clients::enregistrerHistorique(const QString &action, const QString &nomClient, int idClient) {
    QFile file("historique_clients.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        out << action << " - Client ID: " << idClient << ", Nom: " << nomClient << ", Date: " << dateTime << "\n";
        file.close();
    }
}
