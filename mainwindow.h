#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void callElevator(int floor);

private slots:
    void on_floorsSpin_valueChanged(int arg1);
    void setButtonsCount(int value);

    void onFloorReached(int floor);

    void onButtonClicked(int id);

private:
    Ui::MainWindow *ui;
    QButtonGroup m_floorsButtonGroup;
};

#endif // MAINWINDOW_H
