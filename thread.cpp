#include "thread.h"

Thread::Thread(QObject *parent) :
    QThread(parent)
{
}

void Thread::run () {
    p = new QProcess();
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(update()));
    p->start("mosquitto_sub -t mouse");

    p->waitForFinished();
}

void Thread::update() {
    string = p->readAllStandardOutput().data();
    emit newText(string);
}

void Thread::quit() {
    p->terminate();
    quit();
}
