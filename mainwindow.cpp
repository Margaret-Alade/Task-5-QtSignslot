#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stopwatch = new QTimer(this);
    seconds = 0;
    paused = false;
    connect(stopwatch, SIGNAL(timeout()), this, SLOT(process()));

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
    seconds = seconds + 1;
    ui->seconds->display(seconds);
}

void MainWindow::pb_startstop_clicked(bool checked) {

    if (paused == false) {
        stopwatch->start(100);
        paused = true;
        ui->pb_startstop->setText("Cтоп");
    } else {
        paused = false;
        stopwatch->stop();
        ui->pb_startstop->setText("Cтарт");

    }

}


void MainWindow::pb_clear_clicked(bool checked) {
    if(ui->pb_startstop->text() == "Cтарт") {
    seconds = 0;
    counter = 0;
    previous_seconds_value = 0;
    paused = false;
    ui->seconds->display(seconds);
    ui->textBrowser->clear();
    stopwatch->stop();
    }
}

void MainWindow::pb_circle_clicked(bool checked) {

    if(stopwatch->isActive()) {
        counter = counter + 1;
        auto counter_ = QString::number(counter);
        int sec_value = ui->seconds->intValue();
        QString text_sec;
        if(previous_seconds_value == 0) {
            text_sec = QString::number(sec_value);
        } else {
            text_sec = QString::number(sec_value - previous_seconds_value);
        }
        ui->textBrowser->append("Circle " + counter_ + ": " + text_sec + "seconds" + "\n");
        previous_seconds_value = sec_value;
    }


}


