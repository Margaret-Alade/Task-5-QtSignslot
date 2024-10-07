#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0.0),lapCount(0),lastLapTime(0.0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::start() {
    if (!timer->isActive()) {
        timer->start(100); // Обновление каждую 0.1 секунды
    }
}

void Stopwatch::stop() {
    if (timer->isActive()) {
        timer->stop();
    }
}

void Stopwatch::reset() {
    elapsedTime = 0.0;
    lapCount = 0;
    lastLapTime = 0.0;
    emit timeUpdated(elapsedTime);
}

QString Stopwatch::lap() {
    double elapsed = elapsedMilliseconds();
    double laptime = elapsed - lastLapTime;
    lastLapTime = elapsed;
    lapCount++;
    return QString("Круг %1, время: %2 секунд")
                                  .arg(lapCount)
                                   .arg(laptime / 1000);
}


bool Stopwatch::isRunning() const {
    return timer->isActive();
}

double Stopwatch::elapsedMilliseconds() const {
    return elapsedTime;
}

void Stopwatch::updateTime() {
    elapsedTime += 100; // Увеличиваем время на 100 миллисекунд
    emit timeUpdated(elapsedTime);
}

