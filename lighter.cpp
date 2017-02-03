#include "lighter.h"

#include <QFile>


Lighter::Lighter(QString gpio)
{
    m_led = new QFile(gpio);
    state = 0;
    connect(this, SIGNAL(toggleSignal()), this, SLOT(toggle()));
}

void Lighter::toggle()
{
    state = state == 48 ? 49 : 48;
    if(m_led->open(QIODevice::WriteOnly))
    {
        m_led->write(&state, 1);
        m_led->close();
    }

}
