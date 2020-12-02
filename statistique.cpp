#include "statistique.h"
#include "ui_statistique.h"


statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}


int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE where QUANTITE BETWEEN '1' AND '20'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE where QUANTITE BETWEEN '21' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int statistique::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE where QUANTITE BETWEEN '51' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void statistique::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("10-40") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("32-43") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("44-55") ;

}

void statistique::on_pushButton_clicked()
{
    hide();
}
