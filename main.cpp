#include <QCoreApplication>

#include "lighter.h"
#include "watcher.h"

#include <QFile>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile* f = new QFile("/sys/class/gpio/export");
    f->open(QIODevice::WriteOnly);
    f->write("1017");
    f->close();

    delete f;
    f = new QFile("/sys/class/gpio/gpio1017/direction");
    f->open(QIODevice::WriteOnly);
    f->write("in");
    f->close();

    f = new QFile("/sys/class/gpio/export");
    f->open(QIODevice::WriteOnly);
    f->write("1016");
    f->close();

    delete f;
    f = new QFile("/sys/class/gpio/gpio1016/direction");
    f->open(QIODevice::WriteOnly);
    f->write("out");
    f->close();
    delete f;

    f = new QFile("/sys/class/gpio/gpio1016/value");
    f->open(QIODevice::WriteOnly);
    f->write("0");
    f->close();

    Lighter* l = new Lighter("/sys/class/gpio/gpio1016/value");
    Watcher* w = new Watcher("/sys/class/gpio/gpio1017/value", l);

    w->signalsBlocked();

    return a.exec();
}
