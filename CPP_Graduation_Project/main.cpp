#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <vector>


using namespace std;

/***********************Private Macros*******************/
#define Select_Add_Record     1
#define Select_Fetch_Record   2
#define Select_Exit           3

class Employee
{
private:
int ID;
int Age;
string Name;

public:

/* class APIs definition */

/* parametrized Constructor*/
Employee(int Copy_ID ,string Copy_Name,int Copy_Age) { ID = Copy_ID; Age = Copy_Age; Name = Copy_Name; }

/* Getters: */
string Get_Name();
int Get_ID();
int Get_age();

/* Setters: */
void Set_name(string Copy_name);
void Set_ID(int Copy_ID);
void Set_age(int Copy_age);



};


/*******************Library_Dunctions_Defiition****************/
void Print_User_Interface();
void Add_Record_User_Interact();
void Fetch_Record_User_Interact();


/*****************Global_Variables*******************/
string User_name;
int User_Age;
int User_Id;

vector <Employee> Employers_Vector;

int main()
{
/* Local_variables_definition */

int User_Interface_Input = 0;

int Loop_Counter = 0;

while(User_Interface_Input != Select_Exit)
{

Print_User_Interface();
cin >> User_Interface_Input;  cout<<"\n";

switch(User_Interface_Input)
{

case Select_Add_Record: 

Add_Record_User_Interact();
Employers_Vector.push_back(Employee(Loop_Counter,User_name,User_Age));
cout <<"User record added successfly \n\n";

break;

case Select_Fetch_Record: 

Fetch_Record_User_Interact();
cout << "\n";

break;

    
case Select_Exit: 
cout << "Thank you \n";

break;

default: cout<< "Invalid option , Select again\n\n";break;    
    
}


Loop_Counter++;

}




}

/*******************Library_Functions_Implementation****************/
void Print_User_Interface()
{
cout <<"please select an option:\n";
cout <<"1: Add record\n"<<"2: Fetch Record\n" << "3: Quit\n";
cout <<"Enter option: ";
}

void Add_Record_User_Interact()
{
cout << "Add User, Please enter user name and id \n";
cout << "Name : ";
cin >> User_name;
cout << "Age: ";
cin >> User_Age;
cout<< "\n";


}
void Fetch_Record_User_Interact()
{

cout << "Please enter the Id of the refered employer: \n";
cout << "Id: "; 
cin >> User_Id;
cout <<"\n";
cout << "User name: "<< Employers_Vector[User_Id].Get_Name() <<"\n";
cout<<"Age: "<< Employers_Vector[User_Id].Get_age() <<"\n";

}

/* Employe class APIS implementation: */

string Employee::Get_Name()
{
 
 return Name;
}
int Employee::Get_ID()
{
return ID;
}
int Employee::Get_age()
{

return Age;

}

void Employee::Set_name(string Copy_name)
{
Name = Copy_name;

}
void Employee::Set_ID(int Copy_ID)
{
ID = Copy_ID;
}

void Employee::Set_age(int Copy_age)
{

Age = Copy_age;

}
