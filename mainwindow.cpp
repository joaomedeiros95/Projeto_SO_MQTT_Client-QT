#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ip.h"
#include "sobre.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    smart = new Smartphone();
    ui->tabWidget->removeTab(1);
    ui->tab->setWindowTitle("Informações");
    ui->tabWidget->addTab(smart,"Celular 3D");

    pegouinfo = false;

    information = new Thread1();
    connect(information, SIGNAL(novoTexto(QString)), this, SLOT(update3D(QString)));
    information->start();

    mouse = new Thread();
    connect(mouse, SIGNAL(newText(QString)), this, SLOT(mousemudou(QString)));
    mouse->start();

    point = QCursor::pos();

    IP ip;
    ip.setModal(true);
    ip.exec();
}

MainWindow::~MainWindow()
{
    information->quit();
    mouse->quit();
    information->terminate();
    mouse->terminate();
    delete information;
    delete mouse;
    delete ui;
}

void MainWindow::update3D(QString string) {
    list = string.split(" ");

    valorx = list.value(1).toFloat(0) + 180;
    valory = list.value(0).toFloat(0) + 180;
    valorz = list.value(2).toFloat(0) + 180;
    smart->setX(valorx);
    smart->setY(valory);
    smart->setZ(valorz);
    smart->updateGL();

    if(list.value(3) == "true") {
        ui->carregando->setText("Carregando");
        ui->carregando->setStyleSheet("QLabel { color : green; }");
    }
    else
        ui->carregando->setText("Não Carregando");
    if(list.value(3) != "true" && ((list.value(4).toFloat()) * 100) <= 20) {
        ui->carregando->setText("Coloque para carregar!");
        ui->carregando->setStyleSheet("QLabel { color : red; }");
    }
    ui->quantbat->setValue(((list.value(4).toFloat()) * 100));
    if(!pegouinfo) {
        ui->OS->setText(ui->OS->text() + list.value(5));
        ui->Resolucao->setText(ui->Resolucao->text() + list.value(6) + "x" + list.value(7));
        ui->pais->setText(ui->pais->text() + list.value(8).toUpper());
        ui->IMEI->setText(ui->IMEI->text() + list.value(9));
        ui->IMSI->setText(ui->IMSI->text() + list.value(10));
    }
    if(list.value(11) == "true")
        ui->Internet->setText("Conexão com Internet: Conectado");
    else
        ui->Internet->setText("Conexão com Internet: Desconectado");
    if(list.value(12) == "true")
        ui->WiFI->setStyleSheet("QLabel { color : green; }");
    else
        ui->WiFI->setStyleSheet("QLabel { color : red; }");
    if(list.value(11) == "true" && list.value(12) == "false")
        ui->tresg->setStyleSheet("QLabel { color : green; }");
    if(list.value(11) == "false" && list.value(12) == "false")
        ui->tresg->setStyleSheet("QLabel { color : red; }");

    pegouinfo = true;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 1 && pegouinfo) {
        ui->statusBar->showMessage("X: " + QString::number(valorx, 'g', 0) + " Y: " +
                                   QString::number(valory, 'g', 0) + " Z: " + QString::number(valorz, 'g', 0));
    }
    else
        ui->statusBar->clearMessage();
}

void MainWindow::mousemudou(QString stringf) {
    list1 = stringf.split(" ");
    if(list1.value(0).contains("true")) {
        point.setY(point.y() - 10);
        QCursor::setPos(point.x(), point.y());
    }
    if(list1.value(1).contains("true")) {
        point.setX(point.x() + 10);
        QCursor::setPos(point.x(), point.y());
    }
    if(list1.value(2).contains("true")) {
        point.setY(point.y() + 10);
        QCursor::setPos(point.x(), point.y());
    }
    if(list1.value(3).contains("true")) {
        std::cout << "Entrou " << std::endl;
        point.setX(point.x() - 10);
        QCursor::setPos(point.x(), point.y());
    }
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
