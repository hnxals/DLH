#include "testwelcome.h"
#include "ui_testwelcome.h"

extern QString globaldata;

Testwelcome::Testwelcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Testwelcome)
{
    ui->setupUi(this);
}

Testwelcome::~Testwelcome()
{
    delete ui;
}

void Testwelcome::on_pushButton_clicked()
{
    ts= new Testsimulator();
    QString title = "DLH-" + globaldata;
    ts->setWindowTitle(title);
    ts->show();
    ts->setAttribute(Qt::WA_DeleteOnClose, true);
    destroy();
}
