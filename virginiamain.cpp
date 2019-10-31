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
    delete ui;
}

void VirginiaMain::on_pushButton_clicked()
{
    vaap = new VAAP();
    vaap->show();
    vaap->setWindowTitle("VirginiaApplicationProcess");
}
