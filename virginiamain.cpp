#include "virginiamain.h"
#include "ui_virginiamain.h"

extern QString globaldata;

VirginiaMain::VirginiaMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VirginiaMain)
{
    ui->setupUi(this);

}

VirginiaMain::~VirginiaMain()
{
//    delete vaap;
//    delete tw;
//    delete vl;
    delete ui;
    QApplication* app;
         app->exit(0);
//    qApp->exit(1);
}


void VirginiaMain::on_pushButton_clicked()
{
    vaap = new VAAP();
    vaap->setWindowTitle("DLH-Virginia");
    vaap->show();
    vaap->setAttribute(Qt::WA_DeleteOnClose, true);
}

void VirginiaMain::on_pushButton_3_clicked()
{
    tw = new Testwelcome();
    QString title = "DLH-" + globaldata;
    tw->setWindowTitle(title);
    tw->show();
    tw->setAttribute(Qt::WA_DeleteOnClose, true);
}

void VirginiaMain::on_pushButton_2_clicked()
{
    vl = new valearn();
    vl->setWindowTitle("DLH-Virginia");
    vl->show();
    vl->setAttribute(Qt::WA_DeleteOnClose, true);
}
