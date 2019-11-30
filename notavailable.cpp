#include "notavailable.h"
#include "ui_notavailable.h"

NotAvailable::NotAvailable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotAvailable)
{
    ui->setupUi(this);
}

NotAvailable::~NotAvailable()
{

    delete ui;

}
