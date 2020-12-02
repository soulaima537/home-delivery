#ifndef FOURNISSUER_H
#define FOURNISSUER_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class fournisseur
{
public:
     //constructor
    fournisseur();
    fournisseur(int,QString,QString,QString,QString,QString );
    //getters and setters
    int getid();
    QString getnom();
    QString getpren();
    QString gettype();
    QString getadresse();
    QString getnum_tel();
    // methodes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id, QString nom, QString pren, QString type, QString adresse, QString num_tel);
     static QSqlQueryModel * afficher1();
      bool  search(int id );
      QSqlQueryModel *tri_par_id();
      QSqlQueryModel * tri_par_idASC();



    //static QSqlQueryModel * afficher1();
    //static QSqlQueryModel *modi1();
    //void pdf();


 private:
  int id;
  QString nom;
  QString pren;
  QString type;
  QString adresse;
  QString num_tel;



};

#endif // FOURNISSUER_H
