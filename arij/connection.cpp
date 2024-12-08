#include "connection.h"

connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("qtproject_e");
db.setUserName("ADMIN");//inserer nom de l'utilisateur
db.setPassword("ADMIN");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
