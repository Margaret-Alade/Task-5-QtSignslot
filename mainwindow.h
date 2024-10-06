#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartStopButtonClicked();
    void onResetButtonClicked();
    void onLapButtonClicked();
    void updateTimerDisplay(double time);

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    int lapCount;
    double lastLapTime;
};
#endif // MAINWINDOW_H
