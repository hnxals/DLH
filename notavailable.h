#ifndef NOTAVAILABLE_H
#define NOTAVAILABLE_H

#include <QDialog>

namespace Ui {
class NotAvailable;
}

class NotAvailable : public QDialog
{
    Q_OBJECT

public:
    explicit NotAvailable(QWidget *parent = nullptr);
    ~NotAvailable();

private:
    Ui::NotAvailable *ui;
};

#endif // NOTAVAILABLE_H
