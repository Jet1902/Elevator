#include "qworld.h"

#include <QTime>
#include <QTimer>
#include <QDebug>


QWorld* g_pWorld = nullptr;

QWorld& world()
{
    if(!g_pWorld)
        g_pWorld = new QWorld;
    return *g_pWorld;
}

QWorld::QWorld(QObject *parent) : QObject(parent)
{
    startTimer(0);
}

void QWorld::calc(int dT)
{
    m_elevator.goTo();
    emit needUpdate();
}

void QWorld::onCall(int floor)
{
    if(!m_elevator.isMoving())
    {
        m_elevator.setIsMoving(true);
        m_elevator.setDestinationFloor(floor);
    }
}

void QWorld::timerEvent(QTimerEvent *event)
{
    int curTick = QTime::currentTime().msecsSinceStartOfDay();
    if(m_iPrevTick != -1 && m_elevator.isMoving())
    {
        int dT = (curTick - m_iPrevTick) * 0.005;
        if(dT < 5)
            return;
        calc(dT);
    }
    m_iPrevTick = curTick;
}
