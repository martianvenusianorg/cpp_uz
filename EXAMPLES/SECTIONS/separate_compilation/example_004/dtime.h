#ifndef DTIME_H
#define DTIME_H
#include <iostream>
using namespace std;

namespace dtimesavitch{
    class DigitialTime {
    public:
        DigitialTime(int theHour, int theMinute);
        DigitialTime();
        void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);
        friend istream& operator>>(istream& ins, DigitialTime& theObject);
        friend bool operator==(const DigitialTime& time1, const DigitialTime& time2);
        friend ostream& operator<<(ostream& outs, const DigitialTime& theObject);
    private:
        int hour;
        int minute;
    };
}
#endif