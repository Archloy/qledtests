#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>

class QFile;
class Lighter;
class QTimer;

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QString gpio, Lighter* light);

private:
    QFile* m_watch;
    Lighter* m_light;
    QTimer* m_timer;
    char data[10];
    char latest;

public slots:
    void check();
};

#endif // WATCHER_H
