#ifndef TESTWELCOME_H
#define TESTWELCOME_H

#include <QMainWindow>
#include <testsimulator.h>


namespace Ui {
class Testwelcome;
}

class Testwelcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Testwelcome(QWidget *parent = nullptr);
    ~Testwelcome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Testwelcome *ui;
    Testsimulator *ts;
};

#endif // TESTWELCOME_H
