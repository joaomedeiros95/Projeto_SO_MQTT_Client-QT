#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "smartphone.h"
#include <QThread>
#include "thread.h"
#include "thread1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Smartphone *smart;
    Thread *mouse;
    Thread1 *information;

private:
    Ui::MainWindow *ui;
    QString string;
    QStringList list;
    QStringList list1;
    bool pegouinfo;
    float valorx;
    float valory;
    float valorz;
    QPoint point;

private slots:
    void update3D(QString string);
    void on_tabWidget_currentChanged(int index);
    void mousemudou(QString);
    void on_actionSobre_triggered();
};

#endif // MAINWINDOW_H
