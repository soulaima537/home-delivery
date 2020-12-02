#ifndef STATI_H
#define STATI_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>

using namespace std;


namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;
    ~statistique();

private slots:
    void on_pushButton_clicked();

private:
    Ui::statistique *ui;
};

#endif // STATI_H
