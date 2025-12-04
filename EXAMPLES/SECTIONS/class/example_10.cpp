#include <iostream>
#include "cstdlib"
#include "cctype"
using namespace std;

class Money
{
  public:
    friend Money add(const Money& money1, const Money& money2);
    friend bool equal(const Money& money1, const Money& money2);

    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double getValue() const;
    void input(istream& in);
    void output(ostream& out) const;
    Money add(Money otherMoney);
    Money subtract(Money otherMoney);
    bool equal(Money otherMoney);
  private:
    long allCents;
    int digitToInt(char c);
};

int main()
{
    Money yourAmount, myAmount(10, 9), ourAmount;
    cout << "Birinchi pul miqdorini kiriting (masalan, $45.67): ";
    yourAmount.input(cin);
    cout << "Siz kiritgan pul miqdori: ";
    yourAmount.output(cout);
    cout << endl;
    cout << "Mening pul miqdorim: ";
    myAmount.output(cout);
    cout << endl;

    if (equal(yourAmount, myAmount))
    {
        cout << "Sizning va mening pul miqdorim teng." << endl;
    }
    else
    {
        cout << "Sizning va mening pul miqdorim teng emas." << endl;
    }

    ourAmount = add(yourAmount, myAmount);
    cout << "Bizning umumiy pul miqdorimiz: ";
    yourAmount.output(cout);
    cout << " + ";
    myAmount.output(cout);
    cout << " = ";
    ourAmount.output(cout);
    cout<< endl;
    return 0;       
}

Money add(const Money& money1, const Money& money2)
{
    Money temp;
    temp.allCents = money1.allCents + money2.allCents;
    return temp;
}

bool equal(const Money& money1, const Money& money2)
{
    return (money1.allCents == money2.allCents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)
    {
        cout << "Xato: dollar va sent qiymatlari turlicha ishora qilishi mumkin emas." << endl;
        exit(1);
    }
    allCents = dollars * 100 + cents;
}
Money::Money(long dollars) : allCents(dollars * 100)
{
    
}
Money::Money() : allCents(0)
{

}
double Money::getValue() const
{
    return allCents * 0.01;
}
int Money::digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

void Money::input(istream& ins)
{
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative;
    ins >> oneChar;
    if (oneChar == ' ')
    {
        negative = true;
        ins >> oneChar; // '$' belgisi o'qiladi
    }
    else 
    {
        negative = false;
    }

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if (oneChar != '$' || decimalPoint != '.' ||
        !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Noto'g'ri pul miqdori kiritildi." << endl;
        exit(1);
    }
    
    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    allCents = dollars * 100 + cents;
    if (negative)
        allCents = -allCents;
}

void Money::output(ostream& outs) const
{
    long positiveCents, dollars, cents;
    positiveCents = labs(allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}   