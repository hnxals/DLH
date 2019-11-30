#include "testwelcome.h"
#include "ui_testwelcome.h"


Testwelcome::Testwelcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Testwelcome)
{
    ui->setupUi(this);
}

Testwelcome::~Testwelcome()
{
    delete ts;
    delete ui;
}

void Testwelcome::on_pushButton_clicked()
{
    ts= new Testsimulator();
    ts->show();
    destroy();
}
