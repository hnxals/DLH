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
    delete ui;
}



void Menu::on_pushButton_clicked()
{
    if(ui->Statename->currentIndex()==0){
        Virginia = new VirginiaMain;
        Virginia->setWindowTitle("Virginia");
        Virginia->show();
        Virginia->setAttribute(Qt::WA_DeleteOnClose, true);
        globaldata = "VA";
        destroy();
    }
    else{
        na = new NotAvailable;
        na->setWindowTitle("NotAvailable");
        na->show();
    }




}
