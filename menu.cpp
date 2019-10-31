#include "menu.h"
#include "ui_menu.h"
#include <QString>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_pushButton_clicked()
{/*
    QString VA = "Virginia";
    QString St = ui->Statename -> currentText();*/
    if(ui->Statename->currentIndex()==0){
        Virginia = new VirginiaMain(this);
        Virginia->show();
        Virginia->setWindowTitle("Virginia");
        destroy();
    }
    else{
        na = new NotAvailable(this);
        na->show();
        na->setWindowTitle("NotAvailable");
    }



}
