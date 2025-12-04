// class example_1.cpp
// Bu dastur classga misoldir.
#include <iostream>
using namespace std;
class DayOfYear {
  public:
    void input();
    void output();
    void set(int newMonth, int newDay);
    // Dastlabgi shart: newMonth va newDay qo'llash mumkin bo'lgan sanalar bo'lishi kerak.
    // Keyingi shart: Sana argumentlarga asoslangan holda qayta o'rnatiladi.
    int getMonth();
    // Keyingi shart: Oy qiymati qaytariladi. 1 soni Yanvar uchun, 2 soni Fevral uchun va h.k.
    int getDay();
    // Keyingi shart: Kun qiymati qaytariladi.
  private:
    void checkDate(); // Private a'zo funksiya
    int month;        // Private a'zo o'zgaruvchi
    int day;          // Private a'zo o'zgaruvchi 
};

int main() {
  DayOfYear today, birthday;

  cout << "Bugungi kunni kiriting:\n";
  today.input();
  cout << "Bugungi kun: ";
  today.output();
    
  birthday.set(7, 4); // 4-iyulni o'rnatish
  cout << "Sizning tu'gilgan kuningiz: ";
  birthday.output();

  if (today.getMonth() == birthday.getMonth() && today.getDay() == birthday.getDay()) {
    cout << "Tug'ilgan kuningiz muborak bo'lsin!" << endl;
  } else {
    cout << "Kuningiz hayrli bo'lsin!" << endl;
  }

  birthday = today;
  birthday.output();

  if (today.getMonth() == birthday.getMonth() && today.getDay() == birthday.getDay()) {
    cout << "Tug'ilgan kuningiz muborak bo'lsin!" << endl;
  } else {
    cout << "Kuningiz hayrli bo'lsin!" << endl;
  }
  
  return 0;
}

// Bu input funksiyasi va u DayOfYear classga tegishlidir.
// iostreamdan foydalaniladi.
// Private a'zo o'zgaruvchilarga funksiya tanasida to'g'ridan-to'g'ri 
// murojjat qilish mumkin (lekin boshqa joyda emas).
void DayOfYear::input() {
  cout  <<"Oyni raqam bilan kiriting: ";
  cin >> month;
  cout  <<"Kunni raqam bilan kiriting: ";
  cin >> day;
}

// Bu output funksiyasi va u DayOfYear classga tegishlidir.
// iostreamdan foydalaniladi.
void DayOfYear::output() {
    cout  << month <<"-oy, "
          << day << "-kun"<< endl;
}

void DayOfYear::set(int newMonth, int newDay) {
  month = newMonth;
  day = newDay;
  checkDate();
}

void DayOfYear::checkDate() {
  if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
    cout << "Noto'g'ri sana kiritildi. Dastur tugatildi" << endl;
    exit(1);
  }
}  

int DayOfYear::getMonth() {
  return month;
}   

int DayOfYear::getDay() {
  return day;
}