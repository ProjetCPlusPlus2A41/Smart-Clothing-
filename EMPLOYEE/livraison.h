#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QDate>
#include <QString>
#include <QSqlQueryModel>

class Livraison
{
public:
    Livraison();//constructeur non parametrer
    Livraison(QString,QDate,QString,float,QString,QString,QString,int); //constructeur parametrer

//getters pour acceder a un champ
    QString getRef_l();
    QDate getDate_l();
    QString getRef_cmd();
    float getPrix_l();
    QString getStatus_l();
    QString getAddresse_l();
    QString getMode_l();
    int getCin_cl();

//setters pour modifier un champ
void  setRef_l(QString);
void  setDate_l(QDate);
void  setRef_cmd(QString);
void  setPrix_l(float);
void  setStatus_l(QString);
void  setAddresse_l(QString);
void  setMode_l(QString);
void  setCin_cl(int);

//les methodes
bool ajouter();
QSqlQueryModel* afficher();
bool modifier();
bool LivraisonExiste(QString ref);
bool supprimer(QString ref);
   QSqlQueryModel* rechercheParref_l(const QString& ref_l);
private:
    int cin_cl;
    float prix_l;
    QDate date_l;
    QString ref_l,ref_cmd,status_l,addresse_l,mode_l;

};

#endif // LIVRAISON_H
