#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include "commande.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<iostream>
#include <QApplication>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Wedevapplication");
    ui->tableView->setModel(tabfr.afficher());
       ui->comboBox->setModel(fournisseur::afficher1());
       ui->tableView_2->setModel(tabco.afficher());
       ui->comboBox_3->setModel(commande::afficher1());
       ui->comboBox_4->setModel(commande::afficher1());
       mysysteme=new QSystemTrayIcon(this);
       mysysteme->setIcon(QIcon(":/icon.png"));
       mysysteme->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    fournisseur f (ui->lineEdit->text().toUInt(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_6->text());
      f.ajouter();
        ui->tableView->setModel(tabfr.afficher());
        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    fournisseur f;
    ui->tableView->setModel(f.afficher());

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->comboBox->setModel(fournisseur::afficher1());
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->comboBox->currentText().toUInt();
}

void MainWindow::on_pushButton_7_clicked()
{
    bool    test=tabfr.modifier(ui->comboBox->currentText().toUInt(),ui->lineEdit_7->text(), ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_10->text(),ui->lineEdit_11->text()) ;
       if (test)
       {
             ui->tableView->setModel(tabfr.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_comboBox_2_activated(int index)
{
     ui->comboBox_2->currentText().toUInt();
}

void MainWindow::on_pushButton_10_clicked()
{
    bool    test=tabfr.supprimer( ui->comboBox_2->currentText().toUInt());
        if (test)
        {

              ui->tableView->setModel(tabfr.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
        ui->comboBox_2->setModel(fournisseur::afficher1());
}

void MainWindow::on_pushButton_12_clicked()
{

    bool q=tabfr.search(ui->lineEdit_12->text().toUInt());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! cette Agence existe deja."),
                               QMessageBox::Ok);

       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! cette Agence n'existe pas"),
                                QMessageBox::Ok);
       }
}

void MainWindow::on_pushButton_13_clicked()
{
    fournisseur * f = new fournisseur(ui->lineEdit->text().toUInt(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_6->text());
    if(ui->radioButton_2->isChecked()){
       ui->tableView->setModel(f->tri_par_idASC());
    }
    if(ui->radioButton->isChecked()){
         ui->tableView->setModel(f->tri_par_id());   }
    delete f;
}



void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_16_clicked()
{
    commande c(ui->lineEdit_25->text().toUInt(),ui->lineEdit_26->text(),ui->lineEdit_27->text().toUInt(), ui->lineEdit_28->text().toUInt());
      c.ajouter();
        ui->tableView_2->setModel(tabco.afficher());

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_18_clicked()
{
 ui->tableView_2->setModel(tabco.afficher());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_20_clicked()
{
    bool    test=tabco.modifier(ui->comboBox_3->currentText().toUInt(),ui->lineEdit_13->text(), ui->lineEdit_14->text().toInt(),ui->lineEdit_15->text().toInt()) ;
       if (test)
       {
             ui->tableView_2->setModel(tabco.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}

void MainWindow::on_comboBox_3_activated(int index)
{
    ui->comboBox_3->currentText().toUInt();

}

void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_22_clicked()
{
    bool    test=tabco.supprimer( ui->comboBox_4->currentText().toUInt());
        if (test)
        {

              ui->tableView_2->setModel(tabco.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
       ui->comboBox_4->setModel(commande::afficher1());
}

void MainWindow::on_comboBox_4_activated(int index)
{
    ui->comboBox_4->currentText().toUInt();
}

void MainWindow::on_pushButton_23_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_24_clicked()
{

    bool q=tabco.search(ui->lineEdit_16->text().toUInt());

       if( q == true){
          // ui->found->setText("found!");
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! this commande already exists"),
                                QMessageBox::Ok);
       }else{
           //ui->found->setText("not found!");
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! this commande does not exist"),
                                QMessageBox::Ok);
}
}

void MainWindow::on_pushButton_25_clicked()
{
    commande *c = new commande (ui->lineEdit_25->text().toUInt(),ui->lineEdit_26->text(),ui->lineEdit_27->text().toUInt(), ui->lineEdit_28->text().toUInt());
    if(ui->radioButton_4->isChecked()){
      ui->tableView_2->setModel(c->tri_par_codeASC());
    }
    if(ui->radioButton_3->isChecked()){
     ui->tableView_2->setModel(c->tri_par_code());    }
    delete c;
}





