#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), stopwatch(new Stopwatch(this)){
    ui->setupUi(this);

    connect(ui->pb_startstop, &QPushButton::clicked, this, &MainWindow::onStartStopButtonClicked);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::onResetButtonClicked);
    connect(ui->pb_circle, &QPushButton::clicked, this, &MainWindow::onLapButtonClicked);
    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTimerDisplay);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartStopButtonClicked() {
    if (stopwatch->isRunning()) {
        stopwatch->stop();
        ui->pb_startstop->setText("Старт");
        ui->pb_circle->setEnabled(false); // Деактивируем кнопку Круг
    } else {
        stopwatch->start();
        ui->pb_startstop->setText("Стоп");
        ui->pb_circle->setEnabled(true); // Активируем кнопку Круг
    }
}

void MainWindow::onResetButtonClicked() {
    stopwatch->reset();
    ui->timelabel->setText("00.000 с");
    ui->textBrowser->clear();
}

void MainWindow::onLapButtonClicked() {
    ui->textBrowser->append(stopwatch->lap());
}

void MainWindow::updateTimerDisplay(double time) {
    int seconds = static_cast<int>(time / 1000);
    int milliseconds = static_cast<int>(time) % 1000;
    ui->timelabel->setText(QString("%1.%2 с")
                         .arg(seconds, 2, 10, QChar('0'))
                               .arg(milliseconds, 3, 10, QChar('0')));

}



