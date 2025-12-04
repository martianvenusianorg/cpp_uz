#include <iostream>
using namespace std;

class DayOfYear
{
    public:
        friend bool equal(DayOfYear date1, DayOfYear date2); // Sana tengligini tekshirish funksiyasi
        // Old shart: date1 va date2 sanalarni ifodalovchi qiymatl
        // Qaytaradi: agar date1 va date2 teng bo'lsa true, aks holda false
        DayOfYear(int month, int day); // Parametrli konstruktor
        DayOfYear(); // Default konstruktor
        void input(); // Sana kiritish funksiyasi
        void output(); // Sana chiqarish funksiyasi

        int getMonth(); 
        // Oyni olish funksiyasi, 1 yanvar, 2 fevral, ..., 12 dekabr
        int getDay();
        // Kunni olish funksiyasi, 1 dan 31 gacha

    private:
        void checkDate(); // Sana tekshirish funksiyasi
        int month;
        int day;
};

bool equal(DayOfYear date1, DayOfYear date2); // Sana tengligini tekshirish funksiyasi
// Old shart: date1 va date2 sanalarni ifodalovchi qiymatlarga ega 
// Qaytaradi: agar date1 va date2 teng bo'lsa true, aks holda false

int main() {
    DayOfYear birthday(3, 31); // Parametrli konstruktor chaqiriladi
    DayOfYear today; // Default konstruktor chaqiriladi

    cout << "Bugungi sanani kiriting." << endl;
    today.input();
    cout << "Bugungi sana: ";
    today.output();
    cout << endl;

    cout << "Sizning tug'ilgan kuningiz: ";
    birthday.output();
    cout << endl;

    if (equal(today, birthday))
        cout << "Tug'ilgan kuningiz muborak!" << endl;
    else
        cout << "Bugun sizning tug'ilgan kuningiz emas." << endl;

    return 0;
}

bool equal(DayOfYear date1, DayOfYear date2)
{
    return (date1.month == date2.month &&
            date1.day == date2.day);
}

DayOfYear::DayOfYear(int month, int day): month(month), day(day)
{
    checkDate();
}

DayOfYear::DayOfYear():month(1),day(1)
{
    
}

void DayOfYear::checkDate() {
  if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
    cout << "Noto'g'ri sana kiritildi. Dastur tugatildi" << endl;
    exit(1);
  }
}

int DayOfYear::getMonth()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

// iostream dan foydalaniladi
void DayOfYear::input()
{
    cout << "Oyni raqam bilan kiriting: ";
    cin >> month;
    cout << "Kuni raqam bilan kiriting: ";
    cin >> day;
}

// iostream dan foydalaniladi
void DayOfYear::output()
{
    cout << "month = " << month
        << ", day = " << day << endl;
}