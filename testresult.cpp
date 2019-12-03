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
        if(data2>=24)
            ui->label_state->setText("Congratulations! You have passed the test similation!");
        else
            ui->label_state->setText("Sorry, You failed because you have made too many mistakes in the general knowledge test!");
    }
    else
        ui->label_state->setText("Sorry, You failed because you have made too many mistakes in the traffic sign test!");
    ui->label_score1->setText(data1);
    ui->label_score2->setText(data2);
}
