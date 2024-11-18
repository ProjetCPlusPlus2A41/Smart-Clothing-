#include "commande.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

commande::commande()
{

}
commande::commande(QString nomco,QDate dateco,QString modep,double prixco){

    this->nomco=nomco;
    this->dateco=dateco;
    this->modep=modep;
    this->prixco=prixco;
}
bool commande::ajouter(){
    //Crée un objet QSqlQuery qui sera utilisé pour préparer et exécuter la requête SQL.
    QSqlQuery query;



     query.prepare("INSERT INTO COMMANDE (NOMCO,DATECO,MODE_P,PRIXCO) VALUES (:nomco,:dateco,:modep,:prixco)");

     query.bindValue(":nomco", nomco);
     query.bindValue(":dateco", dateco);
     query.bindValue(":modep", modep);
     query.bindValue(":prixco", prixco);


     if (!query.exec()) {
         qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
         return false;
     }

     return true;
 }
QSqlQueryModel* commande::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODE_P"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}

QSqlQueryModel* commande::trier(QString condition, bool ascendant) {
    QSqlQueryModel* model = new QSqlQueryModel(); //stocker les résultats de la requête SQL.
    QString order = ascendant ? "ASC" : "DESC"; //amalna variable ordre bech narfou croissant wala decroisant "ASC" pour un tri ascendant.

    if (condition == "nom") {
        model->setQuery("SELECT * FROM COMMANDE ORDER BY NOMCO " + order);//tri bnom
    } else if (condition == "date") {
        model->setQuery("SELECT * FROM COMMANDE ORDER BY DATECO " + order);//tri bdate
    } else if (condition == "prix") {
        model->setQuery("SELECT * FROM COMMANDE ORDER BY PRIXCO " + order);//tribprix
    }
    //Ces lignes définissent les en-têtes pour chaque colonne dans le modèle model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODE_P"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    return model; //Retourne le modèle model contenant les données triées et prêtes à être affichées.
}

void commande::recherche(int id) {
    //creer un objet
    QSqlQuery query;
    //récupérer toutes les colonnes de la table COMMANDE
    query.prepare("SELECT * FROM COMMANDE WHERE ID = :ID");
    query.bindValue(":ID", id);//l id tethat f blaset l:ID

    if (query.exec() && query.next()) {
        this->nomco = query.value("NOMCO").toString();//Récupère la valeur de la colonne NOMCO de l'enregistrement retourné.ne5thou valeur mel colonne w nconvertiwha lchainedecaractere
        this->dateco = query.value("DATECO").toDate();
        this-> modep= query.value("MODE_P").toString();
        this->prixco = query.value("PRIXCO").toDouble();
    }
}
bool commande::modifier(int idr) {
    QSqlQuery query;

    query.prepare("UPDATE COMMANDE SET NOMCO = :NOMCO, DATECO = :DATECO, MODE_P = :MODE_P, PRIXCO = :PRIXCO "
                  "WHERE ID = :ID");
    query.bindValue(":ID", idr);
    query.bindValue(":NOMCO", nomco);
    query.bindValue(":DATECO", dateco);
    query.bindValue(":MODE_P", modep);
    query.bindValue(":PRIXCO", prixco);
    return query.exec();
}

bool commande::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM COMMANDE WHERE ID = :ID");
    query.bindValue(":ID", id);
    return query.exec();
}

QMap<QString, int> commande::statistiquesParType() {
    QMap<QString, int> stats;
    QSqlQuery query("SELECT MODE_P, COUNT(*) FROM COMMANDE GROUP BY MODE_P");
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats[type] = count;
    }
    return stats;

}

QList<QDate> commande::getAllDates() {
    QList<QDate> dates;
    QSqlQuery query("SELECT DATECO FROM COMMANDE");

    while (query.next()) {
        dates.append(query.value(0).toDate());
    }
    return dates;
}
