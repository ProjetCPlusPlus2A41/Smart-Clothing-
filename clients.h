#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
class clients
{
private:
    int id;
    QString nom_c;
    QString prenom_c;
    QString genre;
    QString email;
    int age;
    QString adresse;
    QString ty_peau;
    float taille;
    float poids;
    int point_fed;
    int telephone;

    void enregistrerHistorique(const QString &action, const QString &nomClient, int idClient);  // Ajoutez cette déclaration

public:

    clients();
    clients(int,QString, QString, QString, QString, int, QString, QString, double, double, int, int);
    bool Ajouter();
    // Declaration of the methods
    QSqlQueryModel* afficher(bool sortByFidelity=false, bool fid=true);
    QSqlQueryModel* rechercherclientParID(int id);
    bool supprimer(int id);
    bool modifier(int id, const QString& nom, const QString& prenom, const QString& adresse,
             const QString& genre, const QString& email, int age, const QString& ty_peau,
             double taille, double poids, int pointFid, int telephone);
    void AjouterClient(const QString &clientID, const QString &clientName);
    //bool modifier();
    // getters
    int getId() { return id; }
    QString getNom_c() { return nom_c; }
    QString getPrenom_c() { return prenom_c; }
    QString getGenre() { return genre; }
    QString getEmail() { return email; }
    int getAge() { return age; }
    QString getAdresse() { return adresse; }
    QString getTy_peau() { return ty_peau; }
    double getTaille() { return taille; }
    double getPoids() { return poids; }
    int getPoint_fed() { return point_fed; }
    int getTelephone() { return telephone; }
    // setters
    void setId(int i) { id = i; }
    void setNom_c(QString nom) { nom_c = nom; }
    void setPrenom_c(QString prenom) { prenom_c = prenom; }
    void setGenre(QString g) { genre = g; }
    void setEmail(QString mail) { email = mail; }
    void setAge(int a) { age = a; }
    void setAdresse(QString adr) { adresse = adr; }
    void setTy_Peau(QString type) { ty_peau = type; }
    void setTaille(double t) { taille = t; }
    void setPoids(double p) { poids = p; }
    void setPointFed(int points) { point_fed = points; }
    void setTelephone(int t) { telephone = t; }
};

#endif // CLIENTS_H
