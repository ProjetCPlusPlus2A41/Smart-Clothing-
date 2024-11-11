#ifndef GESTIONEMPLOYEE_H
#define GESTIONEMPLOYEE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


class gestionemployee
{
public:
    gestionemployee();
    gestionemployee(int, QString, QString, int, QString, QString, QString, QString, double, int);
    bool Ajouter();
    QSqlQueryModel* Afficher(bool sortBySalary = false, bool ascending = true); // Updated Afficher function
     QSqlQueryModel* rechercherEmployeParID(const QString& id);
    //QSqlQueryModel* rechercherEmployeParID(const QString& id);
    //QSqlQueryModel* Afficher();
   // QSqlQueryModel* Afficher(bool ascending = true); // Default sorting is ascending
    bool supprimer(int ID);
    bool modifier();
    int getID() { return ID; }
    QString getNom_E() { return Nom_E; }
    QString getPrenom_E() { return Prenom_E; }
    int getNum_Tel_E() { return Num_Tel_E; }
    QString getMail_E() { return Mail_E; }
    QString getSexe() { return Sexe; }
    QString getAdresse_E() { return Adresse_E; }
    QString getRole() { return Role; }
    double getSalaire() { return Salaire; }
    int getPoint_fed_E() { return Point_fed_E; }

    void setID(int id) { ID = id; }
    void setNom_E(QString nom) { Nom_E = nom; }
    void setPrenom_E(QString prenom) { Prenom_E = prenom; }
    void setNum_Tel_E(int tel) { Num_Tel_E = tel; }
    void setMail_E(QString mail) { Mail_E = mail; }
    void setAdresse_E(QString adr) { Adresse_E = adr; }
    void setRole(QString role) { Role = role; }
    void setSexe(QString sexe) { Sexe = sexe; }
    void setSalaire(double s) { Salaire = s; }
    void setPoint_fed_E(int points) { Point_fed_E = points; }
/*public slots:
    void handTableViewActivated();*/
private:
    int ID;
    QString Nom_E;
    QString Prenom_E;
    int Num_Tel_E;
    QString Mail_E;
    QString Sexe;
    QString Adresse_E;
    QString Role;
    double Salaire;
    int Point_fed_E;

};
#endif // GESTIONEMPLOYEE_H
