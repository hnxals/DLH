#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.setWindowTitle("Driver's License Helper");

    QDir::setCurrent(a.applicationDirPath());
    return a.exec();
}
