#include <iostream>
#include <cstring>
#include <cstddef>
using namespace std;

class StringVar
{
  public:
    StringVar();
    StringVar(int size);
    StringVar(const char a[]);
    StringVar(const StringVar& stringObject);
    ~StringVar();

    int length() const;
    void inputLine(istream& ins);
    //Precondition: If ins is a file input stream, then ins has been
    //connected to a file.
    //Action: The next text in the input stream ins, up to '\n', is copied
    //to the calling object. If there is not sufficient room, then
    //only as much as will fit is copied.

    friend ostream& operator << (ostream& outs, const StringVar& theString);
  private:
  char *value;
  int maxLength;
};


void conversation(int maxNameSize);

int main()
{
    using namespace std;
    conversation(30);
    cout << "Suhbat yakunlandi." << endl;
    return 0;
}

void conversation(int maxNameSize)
{
    using namespace std;
    StringVar yourName(maxNameSize), ourName("Suhbatdosh");
    cout << "Ismingiz nima? \n";
    yourName.inputLine(cin);
    cout << "Salom, " << yourName << "!" << endl;
    cout << "Mening ismim " << ourName << "." << endl;
}

// cstdlib va cstddef kutubxonalarini qo'shish kerak 
StringVar::StringVar() : maxLength(100)
{
    value = new char[maxLength + 1];
    value[0] = '\0';
}

// cstdlib va cstddef kutubxonalarini qo'shish kerak 
StringVar::StringVar(int size): maxLength(size)
{
    value = new char[maxLength + 1];
    value[0] = '\0';
} 

// cstdlib va cstddef kutubxonalarini qo'shish kerak 
StringVar::StringVar(const char a[]): maxLength(strlen(a))
{
    value = new char[maxLength + 1];
    strcpy(value, a);
}

StringVar::StringVar(const StringVar& stringObject): maxLength(stringObject.length())
{
    value = new char[maxLength + 1];
    strcpy(value, stringObject.value);
}

StringVar::~StringVar()
{
    delete [] value;
}

// cstring kutubxonasini qo'shish kerak
int StringVar::length() const
{
    return strlen(value);
}

// iostream kutubxonasini qo'shish kerak
void StringVar::inputLine(istream& ins)
{
    ins.getline(value, maxLength + 1);
}

// iostream kutubxonasini qo'shish kerak
ostream& operator << (ostream& outs, const StringVar& theString)
{
    outs << theString.value;
    return outs;
}