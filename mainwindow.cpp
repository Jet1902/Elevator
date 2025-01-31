#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qworld.h"
#include <QPushButton>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&world().elevator(), SIGNAL(floorReached(int)), this, SLOT(onFloorReached(int)));
    connect(&m_floorsButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(onButtonClicked(int)));
    connect(this, SIGNAL(callElevator(int)), &world(), SLOT(onCall(int)));

    setButtonsCount(ui->floorsSpin->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_floorsSpin_valueChanged(int value)
{
    setButtonsCount(value);
}

void MainWindow::setButtonsCount(int value)
{
    QFormLayout* layout = qobject_cast<QFormLayout*>(ui->buttonsGroup->layout());
    if(!layout)
        return;
    while(layout->rowCount() != value)
    {
        if(layout->rowCount() < value)
        {
            int floorNumber = layout->rowCount() + 1;

            QPushButton* newButton = new QPushButton(ui->buttonsGroup);
            newButton->setObjectName(QString("newButton_%1").arg(floorNumber));
            newButton->setText(QString::number(floorNumber));
            layout->addRow(newButton);
            m_floorsButtonGroup.addButton(newButton, floorNumber);
        }
        else
            layout->removeRow(value);
    }
}

void MainWindow::onFloorReached(int floor)
{
    ui->floorScreen->display(floor);
}

void MainWindow::onButtonClicked(int id)
{
    emit callElevator(id);
}
