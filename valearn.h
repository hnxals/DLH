#ifndef VALEARN_H
#define VALEARN_H

#include <QMainWindow>
#include <iostream>
#include <QDesktopServices>
#include <QDir>
#include <QCoreApplication>


namespace Ui {
class valearn;
}

class valearn : public QMainWindow
{
    Q_OBJECT

public:
    explicit valearn(QWidget *parent = nullptr);
    ~valearn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::valearn *ui;
};

#endif // VALEARN_H
