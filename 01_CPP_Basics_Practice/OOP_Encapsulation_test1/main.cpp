#include <iostream>
#include <string>
#include <array>
#include <bitset>

// Constructor

using namespace std;


class Company
{

    private:
        string name;
        int id;
        int salary;

    public:
        void add_parameters(string n , int i, int sal)
        {
        name = n;
        id = i;
        salary = sal;

        }
        string getName()
        {
        return name;

        }
        unsigned int getSalary()
        {
        return salary;

        }
        unsigned int getid()
        {
        return id;

        }
        void print()
        {
        cout << "Your name is " << name <<"\n";
        cout << "Your salary is " << salary <<"\n";
        cout << "Your ID is " << id <<"\n";
     
            
        }
};
int main()
{

Company ob1;
Company ob2;

ob1.add_parameters("ahmed",5,4000);
ob2.add_parameters("Bendary",6,7000);

ob1.print();
ob2.print();


cout<< ob1.getSalary()+ob2.getSalary()<< "\n";

}