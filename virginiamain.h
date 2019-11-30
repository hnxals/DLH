#ifndef VIRGINIAMAIN_H
#define VIRGINIAMAIN_H

#include <QMainWindow>
#include "vaap.h"
#include "testwelcome.h"
#include <valearn.h>

namespace Ui {
class VirginiaMain;
}

class VirginiaMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit VirginiaMain(QWidget *parent = nullptr);
    ~VirginiaMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::VirginiaMain *ui;
    VAAP *vaap;
    Testwelcome *tw;
    valearn *vl;

};

#endif // VIRGINIAMAIN_H
