#include<iostream>
#include "dtime.h"

void readHour(int& theHour);
int main() {
    using namespace std;
    using namespace dtimesavitch;

    int theHour;
    readHour(theHour);

    DigitialTime clock(theHour, 0), oldClock;
    
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
void readHour(int& theHour) {
    using namespace std;
    cout << "Let's play a time game. \n"
         << "Let's pretend the hour has just changed. \n"
         << "You may write midnight as either 0 or 24.\n"
         << "but I will always write it as 0.\n"
         << "Enter the hour as a number (0 to 24): ";
    cin >> theHour;
    if (theHour == 24) {
        theHour = 0;
    }
}   