#include "watcher.h"

#include <QTimer>
#include <QFile>
#include "lighter.h"

#include <QDebug>


Watcher::Watcher(QString gpio, Lighter *light) : QObject()
{
   m_watch = new QFile(gpio);
   m_timer = new QTimer(this);
   m_light = light;

   m_timer->start(200);

   latest = '0';
   connect(m_timer, SIGNAL(timeout()), this, SLOT(check()));
}

void Watcher::check()
{
    m_watch->open(QIODevice::ReadOnly);
    m_watch->read(data, 1);
    if(data[0] != latest)
    {
        latest = data[0];
        emit m_light->toggleSignal();
    }
    m_watch->close();
}
