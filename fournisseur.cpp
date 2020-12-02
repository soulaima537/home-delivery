#include "fournisseur.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMessageBox>
#include<QSqlQueryModel>


fournisseur::fournisseur()
{
  id=0;
  nom="";
  pren="";
  type="";
  adresse="";
  num_tel="";

}

fournisseur::fournisseur(int id, QString nom, QString pren, QString type, QString adresse, QString num_tel)
{
     this->id= id;
    this->nom = nom;
     this->pren = pren;
     this->type= type;
    this->adresse = adresse;
     this->num_tel = num_tel;


}
int fournisseur::getid(){return id;}
QString fournisseur::getnom(){return  nom;}
QString fournisseur::getpren(){return  pren;}
QString fournisseur::gettype(){return  type;}
QString fournisseur::getadresse(){return  adresse;}
QString fournisseur::getnum_tel(){return num_tel;}

bool fournisseur::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO FOURNISSEUR (id,nom,pren,type,adresse,num_tel) "
                      "VALUES (:id,:nom,:pren,:type,:adresse,:num_tel)");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":pren",pren);
        query.bindValue(":type",type);
        query.bindValue(":adresse",adresse);
        query.bindValue(":num_tel",num_tel);



        return    query.exec();

}
QSqlQueryModel * fournisseur ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM_TEL"));



        return model;
}
QSqlQueryModel *fournisseur ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}


bool fournisseur :: supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from FOURNISSEUR where id = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
bool fournisseur::modifier(int id, QString nom, QString pren, QString type, QString adresse, QString num_tel)
{

    QSqlQuery query;

    query.prepare("UPDATE FOURNISSEUR SET nom= :nom,pren= :pren,type= :type,adresse= :adresse, num_tel= :num_tel where id= :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":pren",pren);
    query.bindValue(":type", type);
    query.bindValue(":adresse",adresse);
    query.bindValue(":num_tel",num_tel);
       return    query.exec();

}
bool  fournisseur::search(int id )
{
       QSqlQuery query;
           query.prepare("Select * from FOURNISSEUR where id= :id");
           query.bindValue(":id", id);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * fournisseur::tri_par_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR order by ID DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));

model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_TEL"));


    return model;
}
QSqlQueryModel * fournisseur::tri_par_idASC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR order by ID ASC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));

model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_TEL"));


    return model;
}
