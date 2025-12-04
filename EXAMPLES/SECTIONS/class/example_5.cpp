#include <iostream>
#include <cmath>
using namespace std;

class BankAccount
{
    public:
        BankAccount(); // Default konstruktor

        BankAccount(int dollars, double rate); // Parametrli konstruktor

        BankAccount(int dollars, int cents, double rate); // Parametrli konstruktor

        void set(int dollars, int cents, double rate);
        
        void set(int dollars, double rate);

        void update();

        double getBalance();

        double getRate();

        void output(ostream& outs);
    
    private:
        int dollarsPart;
        int centsPart;
        double interestRate;
        double fraction(double percent);
        double percent(double fractionValue);
};

int main()
{
	BankAccount account1(100, 2.3), account2;
    cout << "Birinchi hisob:\n";
    account1.output(cout);
    
    cout << "Ikkinchi hisob:\n";
    account2.output(cout);
    
    account1 = BankAccount(999, 99, 5.5);
    cout << "Qayta o'rnatishdan keyin birinchi hisob:\n";
    account1.output(cout);
	return 0;
}

BankAccount::BankAccount() : dollarsPart(0), centsPart(0),interestRate(0.0) {} // Default konstruktor

BankAccount::BankAccount(int dollars, double rate): dollarsPart(dollars), centsPart(0), interestRate(fraction(rate)) // Parametrli konstruktor
{
    if (dollars < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        exit(1);
    }
}

BankAccount::BankAccount(int dollars, int cents, double rate) // Parametrli konstruktor
{
    if (dollars < 0 || cents < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        return;
    }
    dollarsPart = dollars;
    centsPart = cents;
    interestRate = fraction(rate);
}


void BankAccount::set(int dollars, int cents, double rate)
{
    if (dollars < 0 || cents < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        return;
    }
    dollarsPart = dollars;
    centsPart = cents;
    interestRate = fraction(rate);
}

void BankAccount::set(int dollars, double rate)
{
    if (dollars < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        return;
    }
    dollarsPart = dollars;
    interestRate = fraction(rate);
}  

void BankAccount::update()
{
    double balance = getBalance();
    balance += interestRate * balance;
    dollarsPart = static_cast<int>(floor(balance));
    centsPart = static_cast<int>(floor((balance - dollarsPart) * 100)); 
}

double BankAccount::fraction(double percent)
{
    return (percent / 100.0);
}

double BankAccount::getBalance()
{
    return dollarsPart + 0.01 * centsPart;
}

double BankAccount::percent(double fractionValue)
{
    return (fractionValue * 100.0);
}

double BankAccount::getRate()
{
    return percent(interestRate);
}

// iostream kutubxonasidan foydalaniladi.
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Hisobdagi pul miqdori: $" << getBalance() << endl;
    outs << "Foiz ko'rsatgichi: " << getRate() << "%" << endl;
}