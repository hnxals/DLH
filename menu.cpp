#include "menu.h"
#include "ui_menu.h"
#include <QString>
#include <QDialog>
QString globaldata;

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QApplication::setQuitOnLastWindowClosed(true);
}

Menu::~Menu()
{
    delete Virginia;
    delete na;
    delete ui;
    qApp->quit();
}



void Menu::on_pushButton_clicked()
{
    if(ui->Statename->currentIndex()==0){
        Virginia = new VirginiaMain;
        Virginia->show();
        Virginia->setWindowTitle("Virginia");
        globaldata = "VA";
        destroy();
    }
    else{
        na = new NotAvailable;
        na->show();
        na->setWindowTitle("NotAvailable");
    }




}
