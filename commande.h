#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class commande
{
public:
    commande();
    commande(int,QString,int,float );

    //getters and setters
    int getcode();
    QString gettype();
    int getquantite();
    float getprix();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int code ,QString type,int quantite,float prix);
    static QSqlQueryModel * afficher1();
    bool  search(int code );
    QSqlQueryModel *tri_par_code();
    QSqlQueryModel * tri_par_codeASC();

private:
int code ;
QString type;
int quantite;
float prix;

};

#endif // COMMANDE_H
