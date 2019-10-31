#ifndef VAAP_H
#define VAAP_H

#include <QMainWindow>

namespace Ui {
class VAAP;
}

class VAAP : public QMainWindow
{
    Q_OBJECT

public:
    explicit VAAP(QWidget *parent = nullptr);
    ~VAAP();

private slots:
    void on_comboBox_license_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::VAAP *ui;
};

#endif // VAAP_H
