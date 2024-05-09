#include <iostream>
#include <string>
#include <array>
#include <bitset>

// Destructor

using namespace std;

class Sample
{

private:
int x;
int y;

public:

    Sample() //Constructor
    {

    x=10;
    y=20;

    }
    ~Sample() //Destructor
    {
  
    cout << "Destructor excuted \n";

    }


};

int i=0;
int main()
{
do
{
    --i;
    cout<<i<<endl;
    i++;

}while(i>=0);

}