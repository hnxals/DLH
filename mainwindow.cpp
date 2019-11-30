#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete menu;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    menu = new Menu;
    menu->setAttribute(Qt::WA_DeleteOnClose, true);
    menu->setWindowTitle("Driver's License Helper");
    menu->show();
    destroy();

}
