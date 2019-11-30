#include "virginiamain.h"
#include "ui_virginiamain.h"


VirginiaMain::VirginiaMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VirginiaMain)
{
    ui->setupUi(this);
}

VirginiaMain::~VirginiaMain()
{
    delete vaap;
    delete tw;
    delete vl;
    delete ui;
    qApp->quit();
}

void VirginiaMain::on_pushButton_clicked()
{
    vaap = new VAAP();
    vaap->show();
    vaap->setWindowTitle("VirginiaApplicationProcess");
}

void VirginiaMain::on_pushButton_3_clicked()
{
    tw = new Testwelcome();
    tw->show();
}

void VirginiaMain::on_pushButton_2_clicked()
{
    vl = new valearn();
    vl->show();
}
