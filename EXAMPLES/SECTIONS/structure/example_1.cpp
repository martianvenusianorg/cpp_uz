    // BankAccount structure toifasini ifodalovchi dastur
#include <iostream>
using namespace std;
// Bank omonat daftarchasi uchun structure
struct BankAccount
{
	double	balance;
	double	interestRate;
	int term; // yechib olishga bo'lgan majburiy saqlash muddati
};

void getData(BankAccount& theAccount);
// Keyingi holat: theAccount.balance va theAccount.interestRate
// berilgan qiymatlar foydalanuvchi tomonidan kiritiladi.

int main()
{
	BankAccount account;
	getData(account);

	double rateFraction, interest;
	rateFraction = account.interestRate / 100.0;
	interest = account.balance * rateFraction * (account.term / 12.0);
	account.balance = account.balance + interest;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout 	<< "Sizning omonatingiz "
		<< account.term << " oydan so'ng $" << account.balance << " bo'ladi." << endl;

	return 0;
}

// iostreamdan foydalaniladi.
void getData(BankAccount& theAccount)
{
	cout	<< "Mavjud pul miqdorini kiriting: $";
	cin	>> theAccount.balance;
	cout	<< "Foiz ko'rsatgichini kiriting: ";
	cin	>> theAccount.interestRate;
	cout	<< "Omonatni majburing saqlash muddatini ko'rsating\n"
		<< "(muddat 12 oy yoki undan kichik bo'lishi kerak): ";
	cin	>> theAccount.term;
}