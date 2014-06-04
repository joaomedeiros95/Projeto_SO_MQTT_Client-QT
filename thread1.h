#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>
#include <QProcess>

class Thread1 : public QThread
{
    Q_OBJECT
public:
    explicit Thread1(QObject *parent = 0);
    void run();
    QProcess *p;

private:
    QString string;

signals:
    void novoTexto(QString);

public slots:
    void update();

public slots:
    void quit();

};

#endif // THREAD1_H
