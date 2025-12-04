#include <iostream>
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
        double balance;
        double interestRate;
        double fraction(double percent);
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

BankAccount::BankAccount() : balance(0), interestRate(0.0) {} // Default konstruktor

BankAccount::BankAccount(int dollars, double rate): balance(dollars), interestRate(rate) // Parametrli konstruktor
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
    balance = dollars + 0.01 * cents;
    interestRate = rate;
}


void BankAccount::set(int dollars, int cents, double rate)
{
    if (dollars < 0 || cents < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        return;
    }
    balance = dollars + cents / 100.0;
    interestRate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if (dollars < 0 || rate < 0)
    {
        cout << "Pul miqdori yoki foiz ko'rsatgi'chi xato kiritildi.\n";
        return;
    }
    balance = dollars;
    interestRate = rate;
}  

void BankAccount::update()
{
    balance += fraction(interestRate) * balance;
}

double BankAccount::fraction(double percent)
{
    return percent / 100.0;
}

double BankAccount::getBalance()
{
    return balance;
}

double BankAccount::getRate()
{
    return interestRate;
}

// iostream kutubxonasidan foydalaniladi.
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Hisobdagi pul miqdori: $" << balance << endl;
    outs << "Foiz ko'rsatgichi: " << interestRate << "%" << endl;
}