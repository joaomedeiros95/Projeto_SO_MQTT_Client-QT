#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QProcess>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
    void run();
    QProcess *p;

private:
    QString string;

signals:
    void newText(QString);

private slots:
    void update();

public slots:
    void quit();
};

#endif // THREAD_H
