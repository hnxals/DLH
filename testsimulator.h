#ifndef TESTSIMULATOR_H
#define TESTSIMULATOR_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLabel>

namespace Ui {
class Testsimulator;
}

class Testsimulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Testsimulator(QWidget *parent = nullptr);
    ~Testsimulator();

private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::Testsimulator *ui;
    QButtonGroup *choiceGroup;
    QRadioButton *choiceA;
    QRadioButton *choiceB;
    QRadioButton *choiceC;
    QRadioButton *choiceD;
    QLabel *trueanswer;
    QLabel *analysis;
    QLabel *question;
    QLabel *youranswer;
    int totalscore,score1,score2;
    int qnum;

};

#endif // TESTSIMULATOR_H
