#ifndef QWORLD_H
#define QWORLD_H

#include <QObject>
#include "qelevator.h"

class QWorld : public QObject
{
    Q_OBJECT
public:
    explicit QWorld(QObject *parent = nullptr);

    const QElevator& elevator() const
        { return m_elevator; }

signals:
    void needUpdate();
    void updateScreen(int floor);

public slots:
    void calc(int dT);

    void onCall(int floor);

private:
    QElevator m_elevator;
    int m_iPrevTick = -1;

protected:
    virtual void timerEvent(QTimerEvent *event) Q_DECL_FINAL;
};

QWorld& world();

#endif // QWORLD_H
