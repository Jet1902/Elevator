#include "qelevator.h"

QElevator::QElevator(QObject *parent) : QObject(parent)
{

}


void QElevator::goTo()
{
    if(m_currentFloor == m_destinationFloor)
    {
        m_isMoving = false;
    }
    else
    {
        if(m_destinationFloor > m_currentFloor)
            m_currentFloor += 1;
        if(m_destinationFloor < m_currentFloor)
            m_currentFloor -= 1;
        emit floorReached(m_currentFloor);
    }
}

bool QElevator::isMoving() const
{
    return m_isMoving;
}

void QElevator::setIsMoving(bool isMoving)
{
    m_isMoving = isMoving;
}

void QElevator::setDestinationFloor(int destinationFloor)
{
    m_destinationFloor = destinationFloor;
}
