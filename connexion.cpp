#include "connexion.h"
#include<QSqlDatabase>
connexion::connexion()
{

}
bool connexion::cree_connexion(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2a");//inserer le nom de la source de données ODBC
    db.setUserName("SYSTEM");//inserer nom de l'utilisateur
    db.setPassword("SYSTEM");//inserer mot de passe de cet utilisateur

    if(db.open())
        test=true;
    return test;
}
