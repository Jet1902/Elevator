#ifndef CELEVATOR_H
#define CELEVATOR_H

#include <QtMath>


class CElevator
{
public:
    CElevator();

    void goToFloor(int floor, int dT);
    void openDoors();

    bool isMoving() const
        { return m_isMoving; }

    void setIsMoving(bool isMoving)
        { m_isMoving = isMoving; }

    double currentFloor() const
        { return m_currentFloor; }

private:
    int m_currentFloor = 1;
    int m_destinationFloor = 1;
    int m_elevatorSpeed = 1;
    bool m_isMoving = false;
};

#endif // CELEVATOR_H
