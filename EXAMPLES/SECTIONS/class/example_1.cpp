// class example_1.cpp
// Bu dastur juda oddiy classga misolnidir.
// Yana ham yaxshiroq misol uchun example_2.cpp da ko'rsatilgan.
#include <iostream>
using namespace std;
class DayOfYear {
  public:
    void output();
    int month;
    int day;
};

int main() {
    DayOfYear today, birthday;

    cout << "Bugungi kunni kiriting:\n ";
    cout << "Oyni raqam bilan kiriting (1-12): ";
    cin >> today.month;
    cout << "Kunni raqam bilan kiriting (1-31): ";
    cin >> today.day;    

    cout << "Tug'ilgan sanangizni kiriting:\n ";
    cout << "Oyni raqam bilan kiriting (1-12): ";
    cin >> birthday.month;
    cout << "Kunni raqam bilan kiriting (1-31): ";
    cin >> birthday.day;

    cout << "Bugungi kun: ";
    today.output();
    cout << "Sizning tug'ilgan sanangiz: ";    
    today.output();

    if (today.month == birthday.month && today.day == birthday.day) {
        cout << "Tug'ilgan kuningiz muborak bo'lsin!" << endl;
    } else {
        cout << "Kuningiz hayrli bo'lsin!" << endl;
    }

    return 0;
}

// Bu output funksiyasi va u DayOfYear classga tegishlidir.
// iostreamdan foydalaniladi.
void DayOfYear::output() {
    cout  <<"Oy: " << month
          <<", kun: " << day << endl;
}