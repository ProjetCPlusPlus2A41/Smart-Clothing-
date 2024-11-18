#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQueryModel>
#include <QDate>


class commande
{
public:
    commande();
    commande(QString,QDate,QString,double);
    bool ajouter();

        // Getter et Setter pour nomco(getter retourne la valeur actuel et setters change la valeur)
        QString getNomco() const {
            return nomco;
        }

        void setNomco(const QString &newNomco) {
            nomco = newNomco;
        }

        // Getter et Setter pour numco
        QDate getDateco() const {
            return dateco;
        }

        void setDateco(QDate Dateco ) {
            dateco = Dateco;
        }

        // Getter et Setter pour modep
        QString getModep() const {
            return modep;
        }

        void setModep(const QString &newModep) {
            modep = newModep;
        }

        // Getter et Setter pour prixco
        double getPrixco() const {
            return prixco;
        }

        void setPrixco(double newPrixco) {
            prixco = newPrixco;
        }
    QSqlQueryModel* afficher();//aficher tous les commandes a partir du base de donne
    QSqlQueryModel* trier(QString condition, bool ascendant);//trier les commandes selon la condition (par chneya) et decroissant wala croissant)
    void recherche(int id);
    bool supprimer(int);
    bool modifier(int);
    QMap<QString, int> statistiquesParType();//retourne un QMap avec des statistiques
    static QList<QDate> getAllDates();//qui retourne une liste (QList) de toutes les dates de commande enregistrées



    private:
       int id;
       QString nomco;
       QDate dateco;
       QString modep;
       double prixco;


};

#endif // COMMANDE_H
