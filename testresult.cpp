#include "testresult.h"
#include "ui_testresult.h"

testresult::testresult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testresult)
{
    ui->setupUi(this);

}

testresult::~testresult()
{
    delete ui;
}

void testresult::sendData(QString data1, QString data2)
{
    if(data1==10){
        if(data2>=20)
            ui->label_state->setText("Congratulations! You have passed the test similator!");
        else
            ui->label_state->setText("Sorry, You failed because the your general knowledge questions wrong too much!");
    }
    else
        ui->label_state->setText("Sorry, You failed because the your traffoc sign questions wrong too much!");
    ui->label_score1->setText(data1);
    ui->label_score2->setText(data2);
}
