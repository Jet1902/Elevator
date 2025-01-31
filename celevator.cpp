#include "celevator.h"
#include "celevator.h"

#include <QDebug>

CElevator::CElevator()
{

}

void CElevator::goToFloor(int floor, int dT)
{
    if(m_currentFloor > floor)
        m_currentFloor -= m_elevatorSpeed * dT / 1000;

    if(m_currentFloor < floor)
        m_currentFloor += m_elevatorSpeed * dT / 1000;

    if(m_currentFloor - floor < 0.001)
    {
        m_isMoving = false;
        openDoors();
    }
}

void CElevator::openDoors()
{
    qDebug() << "Doors opened";
}






