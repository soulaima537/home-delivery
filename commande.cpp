#include "commande.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMessageBox>
#include<QSqlQueryModel>



commande::commande()
{ commande c;
code=0;
type="";
quantite=0;
prix=0;
}

commande::commande(int code ,QString type,int quantite,float prix)
{
    this->code=code;
    this->type= type;
    this->quantite=quantite;
    this->prix=prix;
}
int commande::getcode(){return code;}
QString commande::gettype(){return  type;}
int commande::getquantite(){return quantite;}
float commande::getprix(){return  prix;}

bool commande::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO COMMANDE (code,type,quantite,prix) "
                      "VALUES (:code,:type,:quantite,:prix)");

        query.bindValue(":code",code);
        query.bindValue(":type",type);
        query.bindValue(":quantite",quantite);
        query.bindValue(":prix",prix);



        return    query.exec();

}
QSqlQueryModel * commande ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));



        return model;
}
QSqlQueryModel *commande ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));

        return model;
}


bool commande :: supprimer(int code)
{
    QSqlQuery query;
    query.prepare("Delete from COMMANDE where code= :code ");
    query.bindValue(":code",code);
    return    query.exec();

}
bool commande::modifier(int code ,QString type,int quantite,float prix)
{

    QSqlQuery query;

    query.prepare("UPDATE COMMANDE SET code= :code,type= :type, quantite= :quantite,prix= :prix where code= :code");
    query.bindValue(":code",code);
    query.bindValue(":type", type);
    query.bindValue(":quantite",quantite);
    query.bindValue(":prix",prix);
       return    query.exec();

}
bool  commande::search(int code )
{
       QSqlQuery query;
           query.prepare("Select * from COMMANDE where code= :code");
           query.bindValue(":code", code);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * commande::tri_par_code()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by CODE DESC");

model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));


    return model;
}
QSqlQueryModel * commande::tri_par_codeASC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE order by CODE ASC");

model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));


    return model;
}
