#include "valearn.h"
#include "ui_valearn.h"
#include <QUrl>

valearn::valearn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::valearn)
{
    ui->setupUi(this);
}

valearn::~valearn()
{
    delete ui;
}

void valearn::on_pushButton_clicked()
{
    QString File = QDir::currentPath() +"/dmv39.pdf";
    QDesktopServices::openUrl(QUrl::fromLocalFile(File));
}

void valearn::on_pushButton_2_clicked()
{
    QString URL = "https://www.dmv.virginia.gov/webdoc/pdf/dmv39.pdf";
    QDesktopServices::openUrl(QUrl(URL.toLatin1()));
}
