#include "ip.h"
#include "ui_ip.h"
#include <QHostInfo>
#include <QNetworkInterface>

IP::IP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IP)
{
    ui->setupUi(this);
    QList <QHostAddress> hostaddr = QNetworkInterface::allAddresses();
    ui->label_2->setText(hostaddr.at(2).toString());
}

IP::~IP()
{
    delete ui;
}
