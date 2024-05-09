#include <iostream>
#include <string>
#include <array>
#include <bitset>

using namespace std;

class Student
{

public:
    int age;
    string name;
    int grade;
    void print(Student x)
    {
    
    cout <<"Your data is :" << x.age << "  "<< x.name << "  " << x.grade << "\n";
    }
};

int main()
{
Student ob1;
Student ob2;
Student ob3;


ob1.age=20;
ob1.name="ahmed";
ob1.grade=70;

ob2.age=22;
ob2.name="Bendary";
ob2.grade=99;



ob1.print(ob2);

    return 0;
}