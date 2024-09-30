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
    void pb_startstop_clicked(bool checked = false);
    void pb_clear_clicked(bool checked = false);
    void pb_circle_clicked(bool checked = false);
    void process();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    QTimer *timer;
};
#endif // MAINWINDOW_H
