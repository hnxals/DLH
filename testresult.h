#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <QMainWindow>

namespace Ui {
class testresult;
}

class testresult : public QMainWindow
{
    Q_OBJECT

public:
    explicit testresult(QWidget *parent = nullptr);
    ~testresult();
    void sendData(QString data1, QString data2);

private:
    Ui::testresult *ui;
};

#endif // TESTRESULT_H
