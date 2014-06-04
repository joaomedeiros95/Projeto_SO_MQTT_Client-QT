#include "thread1.h"

Thread1::Thread1(QObject *parent) :
    QThread(parent)
{
}

void Thread1::run () {
    p = new QProcess();
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(update()));
    p->start("mosquitto_sub -t information");

    p->waitForFinished();
}

void Thread1::update() {
    string = p->readAllStandardOutput().data();
    if(string != NULL)
        emit novoTexto(string);
}

void Thread1::quit() {
    p->terminate();
    quit();
}
