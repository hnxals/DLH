#include "testsimulator.h"
#include "ui_testsimulator.h"


extern QString globaldata;


Testsimulator::Testsimulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Testsimulator)
{
    ui->setupUi(this);
    choiceGroup = new QButtonGroup(this);
    trueanswer = ui->label_trueanswer;
    analysis = ui->label_analysis;
    youranswer = ui->label_youranswer;
    choiceGroup->addButton(ui->radioButton_A,1);
    choiceGroup->addButton(ui->radioButton_B,2);
    choiceGroup->addButton(ui->radioButton_C,3);
    choiceGroup->addButton(ui->radioButton_D,4);
//    question->setText(); //填入第一题的值
    trueanswer->clear();
    analysis->clear();
    youranswer->clear();
    qnum = 1;
    totalscore = 0;
    score1 = 0;
    score2 = 0;
}

Testsimulator::~Testsimulator()
{
    delete ui;
}



void Testsimulator::on_pushButton_submit_clicked()
{
    int trueanswernum; //这获取答案
    int ans = choiceGroup->checkedId();
    QString trueanswerchar;
    switch (trueanswernum) {
    case 1:
        trueanswer->setText("True answer: A");
        break;
    case 2:
        trueanswer->setText("True answer: B");
        break;
    case 3:
        trueanswer->setText("True answer: C");
        break;
    case 4:
        trueanswer->setText("True answer: D");
        break;
    default:
        break;
    }
    switch (ans) {
    case 1:
        trueanswer->setText("Your answer: A");
        break;
    case 2:
        trueanswer->setText("Your answer: B");
        break;
    case 3:
        trueanswer->setText("Your answer: C");
        break;
    case 4:
        trueanswer->setText("Your answer: D");
        break;
    default:
        break;
    }
    QString analysistext; //题目分析赋值
    analysis->setText(analysistext);
    if(ans==trueanswernum){
        if(qnum<=10)
            score1++;
        else
            score2++;
    }
    ui->pushButton_submit->setDisabled(true);
}

void Testsimulator::on_pushButton_next_clicked()
{
    trueanswer->clear();
    analysis->clear();
    youranswer->clear();
    ui->pushButton_submit->setEnabled(true);
}
