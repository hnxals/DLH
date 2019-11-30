#include "testsimulator.h"
#include "ui_testsimulator.h"

#include <QtDebug>
#include <QMessageBox>


extern QString globaldata;



Testsimulator::Testsimulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Testsimulator)
{
    ui->setupUi(this);
    ui->state_label->setText(globaldata);
    choiceGroup = new QButtonGroup(this);
    trueanswer = ui->label_trueanswer;
    analysis = ui->label_analysis;
    youranswer = ui->label_youranswer;
    picture = ui->label_pic;
    question = ui->label_Question;
    trueanswer->clear();
    analysis->clear();
    youranswer->clear();
    picture->clear();
    choiceGroup->addButton(ui->radioButton_A,1);
    choiceGroup->addButton(ui->radioButton_B,2);
    choiceGroup->addButton(ui->radioButton_C,3);
    choiceGroup->addButton(ui->radioButton_D,4);
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbfile = QDir::currentPath() + "/test.db";
    db.setDatabaseName(dbfile);
    db.open();
    QSqlQuery query(db);
    query.exec("SELECT * FROM aquestion order By RANDOM() LIMIT 1");
    query.next();
    question->setText(query.value(1).toString());
    img.loadFromData(query.value(2).toByteArray());
    img.scaled(ui->label->size(), Qt::KeepAspectRatio);
    picture->setScaledContents(true);
    picture->setPixmap(img);
    ui->radioButton_A->setText(query.value(3).toString());
    ui->radioButton_B->setText(query.value(4).toString());
    ui->radioButton_C->setText(query.value(5).toString());
    ui->radioButton_D->setText(query.value(6).toString());
    trueanswernum=query.value(7).toInt();
    qanalysis = query.value(8).toString();
    qnum = 1;
    ui->label_qnum->setText("This is question No." + QString::number(qnum, 10));
    score1 = 0;
    score2 = 0;

}

Testsimulator::~Testsimulator()
{
    delete choiceGroup;
    delete choiceA;
    delete choiceB;
    delete choiceC;
    delete choiceD;
    delete trueanswer;
    delete analysis;
    delete question;
    delete youranswer;
    delete picture;
    delete ui;
}



void Testsimulator::on_pushButton_submit_clicked()
{
    int ans = choiceGroup->checkedId();
    qDebug()<<trueanswernum;
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
        youranswer->setText("Your answer: A");
        break;
    case 2:
        youranswer->setText("Your answer: B");
        break;
    case 3:
        youranswer->setText("Your answer: C");
        break;
    case 4:
        youranswer->setText("Your answer: D");
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
    if(qnum==5){
        testresult *tr = new testresult;
        tr->sendData(QString::number(score1, 10), QString::number(score2, 10));
        tr->show();
        destroy();
    }
    trueanswer->clear();
    analysis->clear();
    youranswer->clear();
    ui->pushButton_submit->setEnabled(true);
    QAbstractButton* checked = choiceGroup->checkedButton();
    choiceGroup->setExclusive(false);
    checked->setChecked(false);
    choiceGroup->setExclusive(true);
    ui->label_qnum->setText("This is question No." + QString::number(++qnum, 10));
    if(qnum<=10){
        QSqlQuery query(db);
        query.exec("SELECT * FROM aquestion order By RANDOM() LIMIT 1");
        query.next();
        question->setText(query.value(1).toString());
        img.loadFromData(query.value(2).toByteArray());
        img.scaled(ui->label->size(), Qt::KeepAspectRatio);
        picture->setScaledContents(true);
        picture->setPixmap(img);
        ui->radioButton_A->setText(query.value(3).toString());
        ui->radioButton_B->setText(query.value(4).toString());
        ui->radioButton_C->setText(query.value(5).toString());
        ui->radioButton_D->setText(query.value(6).toString());
        trueanswernum=query.value(7).toInt();
        qanalysis = query.value(8).toString();
    }
    else{
        QSqlQuery query(db);
        query.exec("SELECT * FROM bquestion order By RANDOM() LIMIT 1");
        query.next();
        question->setText(query.value(1).toString());
        img.loadFromData(query.value(2).toByteArray());
        img.scaled(ui->label->size(), Qt::KeepAspectRatio);
        picture->setScaledContents(true);
        picture->setPixmap(img);
        ui->radioButton_A->setText(query.value(3).toString());
        ui->radioButton_B->setText(query.value(4).toString());
        ui->radioButton_C->setText(query.value(5).toString());
        ui->radioButton_D->setText(query.value(6).toString());
        trueanswernum=query.value(7).toInt();
        qanalysis = query.value(8).toString();
    }
}
