#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "virginiamain.h"
#include "notavailable.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    VirginiaMain *Virginia;
    NotAvailable *na;
};

#endif // MENU_H
