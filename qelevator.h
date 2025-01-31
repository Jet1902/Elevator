#ifndef QELEVATOR_H
#define QELEVATOR_H

#include <QObject>
#include <QDebug>

class QElevator : public QObject
{
    Q_OBJECT
public:
    explicit QElevator(QObject *parent = nullptr);

    void setDestinationFloor(int destinationFloor);

    void setIsMoving(bool isMoving);

    void goTo();

    bool isMoving() const;

signals:
    void floorReached(int floor);

private:
    int m_currentFloor = 1;
    int m_destinationFloor = 1;
//    int m_elevatorSpeed = 1;
    bool m_isMoving = false;
};

#endif // QELEVATOR_H
