#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QObject>
#include <QTimer>
#include <QTime>


class Stopwatch : public QObject {
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();
    QString lap();
    bool isRunning() const;
    double elapsedMilliseconds() const;

signals:
    void timeUpdated(double milliseconds);

private slots:
    void updateTime();

private:
    QTimer *timer;
    double elapsedTime;
    int lapCount;
    double lastLapTime;
};

#endif // STOPWATCH_H
