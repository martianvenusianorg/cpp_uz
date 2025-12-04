// BankAccount uchun classni ifodalovchi dastur
#include <iostream>
using namespace std;
// Bank omonat daftarchasi uchun class
class BankAccount
{
    public:
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
	BankAccount account1, account2;
	cout << "Testni boshlash:\n";
    account1.set(123, 99, 3.0);
    cout << "Birinchi hisob:\n";
    account1.output(cout);
    account1.set(100, 5.0);
    cout << "Birinchi hisob yangilandi:\n";
    account1.output(cout);
    account1.update();
    cout << "Yangilashlardan keyin birinch hisob:\n";
    account1.output(cout);

    account2 = account1;
    cout << "Ikkinchi hisob:\n";
    account2.output(cout);
	return 0;
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