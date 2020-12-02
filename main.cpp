#include "mainwindow.h"

#include <QApplication>
#include"connexion.h"
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       connexion c;
       bool test=c.cree_connexion();



       if(test){
       QMessageBox::information(nullptr,QObject::tr("database is open"),
                                QObject::tr("connexion etablie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                               QObject::tr("non connecter"),
                               QMessageBox::Cancel);}

       MainWindow w;
       w.show();

       return a.exec();
}
