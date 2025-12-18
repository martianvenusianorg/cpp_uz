#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
#include "dtime.h"
using namespace std;

namespace{

    void readHour(istream& ins, int& theHour);
    
    void readMinute(istream& ins, int& theMinute);
    
    int digitToInt(char ch);
    
} // unnamed namespace

namespace dtimesavitch{

    DigitialTime::DigitialTime(int theHour, int theMinute) {
        if (theHour < 0 || theHour > 23 || theMinute < 0 || theMinute > 59) {
            cout << "Error illegal time input\n";
            exit(1);
        }
        else {
            hour = theHour;
            minute = theMinute;
        }
    }

    DigitialTime::DigitialTime() : hour(0), minute(0) 
    {

    }

    void DigitialTime::advance(int minutesAdded) {
        int grossMinutes = minute + minutesAdded;
        minute = grossMinutes % 60;
        int hourAdjustment = grossMinutes / 60;
        hour = (hour + hourAdjustment) % 24;
    }   

    void DigitialTime::advance(int hoursAdded, int minutesAdded) {
        hour = (hour + hoursAdded) % 24;
        advance(minutesAdded);
    }

    bool operator==(const DigitialTime& time1, const DigitialTime& time2) {
            return (time1.hour == time2.hour) && (time1.minute == time2.minute);
    }
    
    ostream& operator<<(ostream& outs, const DigitialTime& theObject) {
        outs << theObject.hour << ':';
        if (theObject.minute < 10)
            outs << '0';
        outs << theObject.minute;
        return outs;
    }

    istream& operator>>(istream& ins, DigitialTime& theObject) {
        readHour(ins, theObject.hour);
        readMinute(ins, theObject.minute);
        return ins;
    }
} // namespace dtimesavitch

namespace
{
    
    int digitToInt(char ch)
    {
        if (!isdigit(ch)) {
                cout << "Error illegal digit input\n";
                exit(1);
        }
        return ch - '0';
    }

    void readMinute(istream& ins, int& theMinute) {
        char ch1, ch2;
        ins >> ch1 >> ch2;
        if (!isdigit(ch1) && isdigit(ch2)) {
            cout << "Error illegal minute input\n";
            exit(1);
        }
        theMinute = (digitToInt(ch1) * 10) + digitToInt(ch2);

        if (theMinute < 0 || theMinute > 59) {
            cout << "Error illegal minute input\n";
            exit(1);
        }
    }

    void readHour(istream& ins, int& theHour) {
        char ch1, ch2;
        ins >> ch1 >> ch2;
        if (!isdigit(ch1) && isdigit(ch2) || ch2 == ':') {
            cout << "Error illegal hour input\n";
            exit(1);
        }

        if(isdigit(ch1) && (ch2 == ':')) {
            theHour = digitToInt(ch1);
        }
        else
        {
            theHour = (digitToInt(ch1) * 10) + digitToInt(ch2);
            ins >> ch2; // discard the colon
            if(ch2 != ':') {
                cout << "Error illegal hour input\n";
                exit(1);
            }
        }
        
        if (theHour < 0 || theHour > 23) {
            cout << "Error illegal hour input\n";
            exit(1);
        }
    }
} // unnamed namespace