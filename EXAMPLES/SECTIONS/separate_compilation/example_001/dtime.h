#pragma once
// #ifndef DTIME_H
// #define DTIME_H
#include <iostream>
using namespace std;
class DigitialTime {
public:
    friend bool operator==(const DigitialTime& time1, const DigitialTime& time2);
    DigitialTime(int theHour, int theMinute);
    DigitialTime();
    void advance(int minutesAdded);
    void advance(int hoursAdded, int minutesAdded);
    friend istream& operator>>(istream& ins, DigitialTime& theObject);
    friend ostream& operator<<(ostream& outs, const DigitialTime& theObject);
private:
    int hour;
    int minute;
};
// #endif