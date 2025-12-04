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

class SavingAccount : public BankAccount {
    public:
        SavingAccount(int dollars, int cents, double rate);

        void deposit(int dollars, int cents);
        void withdraw(int dollars, int cents);

    private:
}; 

class CDAccount : public SavingAccount {
    public:
        CDAccount(int dollars, int cents, double rate, int daysToMaturity);

        void getDaysToMaturity();
        void decrementDaysToMaturity();

    private:
        int daysToMaturity;
};

int main() {
    SavingAccount account(100, 50, 5.5);
    account.output(cout);
    cout << endl;
    cout << "Deposit $10.25. " << endl;
    account.deposit(10, 25);
    account.output(cout);
    cout << endl;
    cout << "Withdraw $11.80. " << endl;
    account.withdraw(11, 80);
    account.output(cout);
    cout << endl;
    return 0;
}

SavingAccount::SavingAccount(int dollars, int cents, double rate)
    : BankAccount(dollars, cents, rate) 
{

}

void SavingAccount::deposit(int dollars, int cents) 
{
    double balance = getBalance();
    balance += dollars;
    balance += (static_cast<double>(cents)/100);
    int newDollars = static_cast<int>(balance);
    int newCents = static_cast<int>((balance - newDollars) * 100);
    set(balance, newCents, getRate());
    
}

void SavingAccount::withdraw(int dollars, int cents)
{
    double balance = getBalance();
    balance -= dollars;
    balance -= (static_cast<double>(cents) / 100);
    int newDollars = static_cast<int>(balance);
    int newCents = static_cast<int>((balance - newDollars) * 100);
    set(newDollars, newCents, getRate());
}