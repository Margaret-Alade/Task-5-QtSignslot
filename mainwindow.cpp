#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    stopwatch = new Stopwatch;
    connect(timer, &QTimer::timeout, this, &MainWindow::process);

    ui->pb_startstop->setCheckable(true);
    connect(ui->pb_startstop, &QPushButton::clicked, this, &MainWindow::pb_startstop_clicked);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::pb_clear_clicked);
    connect(ui->pb_circle, &QPushButton::clicked, this, &MainWindow::pb_circle_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::process() {
    stopwatch->increase_seconds();
    stopwatch->increase_seconds_on_display();

    if(stopwatch->get_seconds_on_display() == 60) {
        stopwatch->set_seconds_on_display(0);
        stopwatch->increase_minutes();
    } else {
        ui->seconds->display(stopwatch->get_seconds_on_display());
        ui->minutes->display(stopwatch->get_minutes());

    }
}

void MainWindow::pb_startstop_clicked(bool checked) {

    if (stopwatch->get_paused() == false) {
        timer->start(100);
        stopwatch->watch_start(); // меняем значаение при старте
        ui->pb_startstop->setText("Cтоп");
    } else {
        stopwatch->watch_stop(); // меняем значение при стопе
        timer->stop();
        ui->pb_startstop->setText("Cтарт");

    }

}


void MainWindow::pb_clear_clicked(bool checked) {
    if(ui->pb_startstop->text() == "Cтарт") {
        stopwatch->watch_clear();
        ui->seconds->display(stopwatch->get_seconds_on_display());
        ui->minutes->display(stopwatch->get_minutes());
        ui->textBrowser->clear();
        stopwatch->watch_stop();
    }
}

void MainWindow::pb_circle_clicked(bool checked) {

    if(timer->isActive() && ui->pb_startstop->text() == "Cтоп") {
        auto counter_ = QString::number(stopwatch->increase_counter());
        short int sec_value = stopwatch->get_seconds();
        short int min_value = stopwatch->get_minutes();
        QString text_sec;
        QString text_min;
        if(stopwatch->get_previous_seconds_value() == 0) {
            text_sec = QString::number(sec_value);
        } else {
            text_sec = QString::number(sec_value - stopwatch->get_previous_seconds_value());
        }

        if(stopwatch->get_previous_minutes_value() == 0) {
            text_min = QString::number(min_value);
        } else {
            text_min = QString::number(min_value - stopwatch->get_previous_minutes_value());
        }




        ui->textBrowser->append("Circle " + counter_ + ": " + text_min + "minutes " +  text_sec + "seconds" + "\n");
        stopwatch->set_previous_second_value(sec_value);
        stopwatch->set_previous_minutes_value(min_value);
    }


}


