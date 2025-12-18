#include<iostream>
#include "dtime.h"
using namespace std;
int main() {
    DigitialTime clock, oldClock;
    cout << "Enter a time in HH:MM format: ";
    cin >> clock;
    oldClock = clock;
    clock.advance(15);   
    if (clock == oldClock)
        cout << "Something is wrong " << clock << endl;
    cout << "You entered: " << oldClock << endl;
    cout << "Time after advancing 15 minutes: " << clock << endl;

    clock.advance(2, 15);
    cout << "Time after advancing 2 hours and 15 minutes: " << clock << endl;


    return 0;
}