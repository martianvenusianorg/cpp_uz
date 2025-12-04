#include <iostream>
using namespace std;

typedef int* IntPointer;

void sneaky(IntPointer temp);

int main()
{
    IntPointer p;
    p = new int;
    *p = 77; 
    cout << "*p ning dastlabki qiymati: " << *p << endl;
    sneaky(p);
    cout << "*p ning yangi qiymati: " << *p << endl;
    return 0;
}

void sneaky(IntPointer temp)
{
    *temp = 99;
    cout << "temp ichida qiymat: " << *temp << endl;
}
