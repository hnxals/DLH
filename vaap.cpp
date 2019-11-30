#include "vaap.h"
#include "ui_vaap.h"
#include <QMessageBox>
VAAP::VAAP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VAAP)
{
    ui->setupUi(this);
}

VAAP::~VAAP()
{
    delete ui;
}


void VAAP::on_comboBox_license_activated(const QString &arg1)
{
    if(arg1=="Yes"){
        ui->label_2->setText("Where are you from?");
        ui->comboBox_2 ->clear();
        ui->comboBox_2 ->addItem("Other states of US");
        ui->comboBox_2 ->addItem("Canada, France, Germany, or South Korea");
    }
    else if(arg1 == "No"){
        ui->label_2->setText("How old are you?");
        ui->comboBox_2 ->clear();
        ui->comboBox_2 ->addItem("Under age 18");
        ui->comboBox_2 ->addItem("age 18 or older");
    }


}

void VAAP::on_pushButton_clicked()
{
    QImage *img=new QImage;
    if(ui->comboBox_license->currentIndex()==0 && ui->comboBox_2->currentIndex()==0){
        img->load(":/new/pic/yes-in.png");
        img->scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label_3->setScaledContents(true);
        ui->label_3->clear();
        ui->label_3 ->setPixmap(QPixmap::fromImage(*img));
    }
    else if(ui->comboBox_license->currentIndex()==0 && ui->comboBox_2->currentIndex()==1){
        img->load(":/new/pic/yes-out.png");
        img->scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label_3->setScaledContents(true);
        ui->label_3->clear();
        ui->label_3 ->setPixmap(QPixmap::fromImage(*img));
    }
    else if(ui->comboBox_license->currentIndex()==1 && ui->comboBox_2->currentIndex()==0){
        img->load(":/new/pic/no-under18.png");
        img->scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label_3->setScaledContents(true);
        ui->label_3->clear();
        ui->label_3 ->setPixmap(QPixmap::fromImage(*img));
    }
    else if(ui->comboBox_license->currentIndex()==1 && ui->comboBox_2->currentIndex()==1){
        img->load(":/new/pic/no-18.png");
        img->scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label_3->setScaledContents(true);
        ui->label_3->clear();
        ui->label_3 ->setPixmap(QPixmap::fromImage(*img));
    }
    else{
        QMessageBox *error = new QMessageBox();
        error -> setText("Please choose the choice!");
        error->setIcon(QMessageBox::Warning);
        error ->exec();
        delete error;
    }
    delete img;

}
