#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("base");//inserer le nom de la source de données
db.setUserName("issam");//inserer nom de l'utilisateur
db.setPassword("issam");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
