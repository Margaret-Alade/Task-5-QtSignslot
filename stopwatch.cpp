#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0.0) {
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
    stop();
    elapsedTime = 0.0;
    emit timeUpdated(elapsedTime);
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

