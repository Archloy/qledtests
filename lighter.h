#ifndef LIGHTER_H
#define LIGHTER_H

#include <QObject>

class QFile;

class Lighter : public QObject
{
    Q_OBJECT

public:
    Lighter(QString gpio);

private:
    QFile* m_led;
    char state;
public slots:
    void toggle();

signals:
    void toggleSignal();
};

#endif // LIGHTER_H
