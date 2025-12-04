#include <iostream>
#include "cstdlib"
#include "cctype"
using namespace std;

class Money
{
  public:
    friend Money operator +(const Money& money1, const Money& money2);
    friend Money operator -(const Money& money1, const Money& money2);
    friend Money operator -(const Money& money);
    friend bool operator ==(const Money& money1, const Money& money2);
    friend ostream& operator <<(ostream& outs, const Money& money);
    friend istream& operator >>(istream& ins, Money& money);

    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double getValue() const;
    void input(istream& ins);
    void output(ostream& outs) const;
  private:
    long allCents;
    int digitToInt(char c);
};

int main()
{
    Money amount1(1, 50), amount2(0, 15), amount3;
    amount3 = amount1 - amount2;
    cout << "amount3: " << amount3 << endl;
    amount3 = -amount3;
    cout << "amount3 after negation: " << amount3 << endl;
    
    return 0;       
}

Money operator +(const Money& money1, const Money& money2)
{
    Money temp;
    temp.allCents = money1.allCents + money2.allCents;
    return temp;
}

Money operator -(const Money& money1, const Money& money2)
{
    Money temp;
    temp.allCents = money1.allCents - money2.allCents;
    return temp;
}

Money operator -(const Money& money)
{
    Money temp;
    temp.allCents = -money.allCents;
    return temp;
}

bool operator ==(const Money& money1, const Money& money2)
{
    return (money1.allCents == money2.allCents);
}

ostream& operator <<(ostream& outs, const Money& money)
{
    money.output(outs);
    return outs;
}

istream& operator >>(istream& ins, Money& money)
{
    money.input(ins);
    return ins;
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