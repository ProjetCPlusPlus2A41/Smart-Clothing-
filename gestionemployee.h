#ifndef GESTIONEMPLOYEE_H
#define GESTIONEMPLOYEE_H

#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class gestionemployee {
public:
    // Default constructor
    gestionemployee();

    // Parameterized constructor with new attributes
    gestionemployee(int ID, QString Nom_E, QString Prenom_E, int Num_Tel_E, QString Mail_E,
                    QString Sexe, QString Adresse_E, QString Role, double Salaire,
                    int Point_fed_E, QString MDP, QString QUESTION, QString REPONSE);

    // Method to add a new employee
    bool Ajouter();

    // Method to display employees with optional sorting
    QSqlQueryModel* Afficher(bool sortBySalary = false, bool ascending = true);

    // Method to search an employee by ID
    QSqlQueryModel* rechercherEmployeParID(const QString& id);

    // Method to delete an employee by ID
    bool supprimer(int ID);

    // Method to modify employee details
    bool modifier(int id, const QString& nom, const QString& prenom, const QString& mail,
                  const QString& adresse, int numTel, double salaire, const QString& role,
                  int pointFidelite, const QString& sexe,
                  const QString& mdp = "", const QString& question = "", const QString& reponse = "");

    // Getters
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

    // Getters for new attributes
    QString getMDP() { return MDP; }
    QString getQUESTION() { return QUESTION; }
    QString getREPONSE() { return REPONSE; }

    // Setters
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

    // Setters for new attributes
    void setMDP(QString mdp) { MDP = mdp; }
    void setQUESTION(QString question) { QUESTION = question; }
    void setREPONSE(QString reponse) { REPONSE = reponse; }

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

    // New attributes
    QString MDP;       // Password
    QString QUESTION;  // Security question
    QString REPONSE;   // Security answer
};

#endif // GESTIONEMPLOYEE_H
 