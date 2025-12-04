#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_LIST_SIZE = 50;

class TemperatureList
{
  public:
    TemperatureList();
    void addTemperature(double temperature);
    bool isFull() const;
    friend ostream& operator <<(ostream& outs, const TemperatureList& tempList);
  private:
    double list[MAX_LIST_SIZE];
    int size;
};
TemperatureList::TemperatureList() : size(0)
{

}

void TemperatureList::addTemperature(double temperature)
{
    if (isFull())
    {
        cout << "Xato: ro'yxat to'la. Yana harorat qo'shib bo'lmaydi." << endl;
        exit(1);
    }
    else
    {
        list[size] = temperature;
        size++;
    }
}

bool TemperatureList::isFull() const
{
    return (size == MAX_LIST_SIZE);
}   

ostream& operator <<(ostream& outs, const TemperatureList& tempList)
{
    for (int i = 0; i < tempList.size; i++)
    {
        outs << tempList.list[i] << " ";
    }
    return outs;
}