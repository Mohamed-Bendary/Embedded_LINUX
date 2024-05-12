
#include <iostream>
#include <string>
#include <array>
#include <bitset>

using namespace std;

class Person
{

    private:
    string name;
    int age;
    string email;


    public:
    Person()
    {
        name = "xx";
        age = 5;
        email = "NULL";
        cout<<"Constructor of person\n";
    }
    void SetValues(string n , int a ,string em)
    {

        name =n;
    }
    void print()
    {
    cout << name << " " << age << " "<< email << "\n";   
    }

};

class Student : public Person
{

    private:
    int grade;

    public:
    Student()
    {

    grade = 0;
    cout << "Constructor of the Student\n";
    }
    void SetGrade (int G)
    {

    grade = G ;  
    }

    void Display()
    {

        cout << "Your grade is: "<< grade << "\n";
    }

};

int main()
{


Student ob1;
ob1.SetValues("ben" , 22 , "gg");
ob1.print();

ob1.SetGrade(50);
ob1.Display();

}