#include "livraison.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlError>

Livraison::Livraison()
{
    cin_cl = 0;
    prix_l = 0.0f;
    date_l = QDate::currentDate(); //use QDate::currentDate() if you want today's date
    ref_l = "";
    ref_cmd = "";
    status_l = "En Cours";
    addresse_l = "";
    mode_l = "";
}
Livraison::Livraison(QString ref_l,QDate date_l,QString ref_cmd ,float prix_l,QString status_l,QString addresse_l,QString mode_l,int cin_cl)
{
    this->ref_l=ref_l;
    this->date_l=date_l;
    this->ref_cmd=ref_cmd;
    this->prix_l=prix_l;
    this->status_l=status_l;
    this->addresse_l=addresse_l;
    this->mode_l=mode_l;
    this->cin_cl=cin_cl;
}


// Getters
QString Livraison::getRef_l() {
    return ref_l;
}

QDate Livraison::getDate_l() {
    return date_l;
}

QString Livraison::getRef_cmd() {
    return ref_cmd;
}

float Livraison::getPrix_l() {
    return prix_l;
}

QString Livraison::getStatus_l() {
    return status_l;
}

QString Livraison::getAddresse_l() {
    return addresse_l;
}

QString Livraison::getMode_l() {
    return mode_l;
}

int Livraison::getCin_cl() {
    return cin_cl;
}



// Setters
void Livraison::setRef_l(QString ref) {
    ref_l = ref;
}

void Livraison::setDate_l(QDate date) {
    if (date.isValid()) {
        date_l = date;
    }
}

void Livraison::setRef_cmd(QString refCmd) {
    ref_cmd = refCmd;
}

void Livraison::setPrix_l(float prix) {
    prix_l = prix;
}

void Livraison::setStatus_l(QString status) {
    status_l = status;
}

void Livraison::setAddresse_l(QString addresse) {
    addresse_l = addresse;
}

void Livraison::setMode_l(QString mode) {
    mode_l = mode;
}

void Livraison::setCin_cl(int cin) {
    cin_cl = cin;
}


bool Livraison::ajouter()
{
   QSqlQuery query;

   QString cin_cl_string = QString::number(cin_cl);
   QString date_l_string = date_l.toString("dd-MMM-yy");
   QString prix_l_string = QString::number(prix_l, 'f', 3);  // 'f' is for fixed-point notation, 3 CHIFFRE APRES LA VIRGULE

   query.prepare("INSERT INTO livraison (ref_l, date_l, ref_cmd, prix_l, status_l, addresse_l, mode_l, cin_cl) "
                 "VALUES (:ref_l, :date_l, :ref_cmd, :prix_l, :status_l, :addresse_l, :mode_l, :cin_cl)");

   // Bind values using named placeholders
   query.bindValue(":ref_l", ref_l);
   query.bindValue(":date_l", date_l_string);
   query.bindValue(":ref_cmd", ref_cmd);
   query.bindValue(":prix_l", prix_l_string);
   query.bindValue(":status_l", status_l);
   query.bindValue(":addresse_l", addresse_l);
   query.bindValue(":mode_l", mode_l);
   query.bindValue(":cin_cl", cin_cl_string);

   return query.exec();
}

QSqlQueryModel* Livraison::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT ref_l, TO_CHAR(date_l, 'DD-Mon-YY') AS date_l, ref_cmd, prix_l, status_l, addresse_l, mode_l, cin_cl FROM livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ref Commande"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Status"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Addresse"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Mode"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN Client"));

return model;
}

bool Livraison::modifier()
{
   QSqlQuery query;

   QString cin_cl_string = QString::number(cin_cl);
   QString date_l_string = date_l.toString("dd-MMM-yy");
   QString prix_l_string = QString::number(prix_l, 'f', 3);  // 'f' is for fixed-point notation, 3 decimal places

   query.prepare("UPDATE livraison SET ref_l = :ref_l, date_l = :date_l, ref_cmd = :ref_cmd, prix_l = :prix_l, "
                 "status_l = :status_l, addresse_l = :addresse_l, mode_l = :mode_l, cin_cl = :cin_cl "
                 "WHERE ref_l = :ref_l");  // Assuming ref_l is the unique identifier for the update

   query.bindValue(":ref_l", ref_l);
   query.bindValue(":date_l", date_l_string);
   query.bindValue(":ref_cmd", ref_cmd);
   query.bindValue(":prix_l", prix_l_string);
   query.bindValue(":status_l", status_l);
   query.bindValue(":addresse_l", addresse_l);
   query.bindValue(":mode_l", mode_l);
   query.bindValue(":cin_cl", cin_cl_string);

   if (!query.exec()) {
       qDebug() << "Error: " << query.lastError().text();
       return false;  // Return false if execution failed
   }

   return true;
}


bool Livraison:: LivraisonExiste(  QString ref)
{
   bool exists = false;

   QSqlQuery checkQuery;
   checkQuery.prepare("SELECT ref_l FROM livraison WHERE ref_l=:ref");
   checkQuery.bindValue(":ref", ref);

   if (checkQuery.exec())
   {
       if (checkQuery.next())
       {
           exists = true;
       }
   }
   else
   {
       qDebug() << "Delivery not found:" << checkQuery.lastError();
   }

   return exists;
}

bool Livraison::supprimer(QString ref)
{
   QSqlQuery query;
        query.prepare("Delete from livraison where ref_l=:ref");
        query.bindValue(0,ref);

   return query.exec();
}



