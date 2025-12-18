#include<iostream>
namespace savitch1
{
    void greeting();      
}
namespace savitch2
{
    void greeting();      
}
 void bigGreeting();

 int main()
 {
     {
        using namespace savitch1;
        greeting();
    }
    {
        using namespace savitch2;
        greeting();
    }
    bigGreeting();
    return 0;
 }
void savitch1::greeting()
{
    std::cout << "Hello from savitch1 namespace!" << std::endl;
}
void savitch2::greeting()
{
    std::cout << "Hello from savitch2 namespace!" << std::endl;
}
void bigGreeting()      
{
    std::cout << "Hello from the global namespace!" << std::endl;
}   
