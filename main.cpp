#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w= new MainWindow;
    w->setWindowTitle("Driver's License Helper");
    w->show();
    a.connect( &a,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));
    return a.exec();

}

