#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>


class Stopwatch : public QObject {
    Q_OBJECT
public:
    Stopwatch() {
        seconds = 0;
        seconds_on_diplay = 0;
        minutes = 0;
        counter = 0;
        int previous_seconds_value = 0;
        paused = false;
    };
    void watch_start();
    void watch_stop();
    void watch_clear();

    short int get_seconds();
    short int get_seconds_on_display();
    void set_seconds_on_display(short int value);
    short int increase_seconds();
    short int increase_seconds_on_display();

    short int increase_minutes();
    short int get_minutes();
    void set_minutes(short int value);


    short int increase_counter();
    int get_counter();

    bool get_paused();

    short int get_previous_seconds_value();
    void set_previous_second_value(short int value);
    short int get_previous_minutes_value();
    void set_previous_minutes_value(short int value);


private:
    short int minutes;
    short int seconds;
    short int seconds_on_diplay;
    int counter;
    short int previous_seconds_value;
    short int previous_minutes_value;
    bool paused;
};
#endif // STOPWATCH_H
