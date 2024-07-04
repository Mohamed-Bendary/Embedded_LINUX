#include <iostream>
#include <string>
#include <array>
#include <bitset>

using namespace std;

class First
{
    private:
    int y = 20;

    public:
    int x= 10;

    protected:
    int z = 20;

}; 

class Second : public First
{


};

int main()
{

Second ob1;
cout << ob1.x<<"\n";


}