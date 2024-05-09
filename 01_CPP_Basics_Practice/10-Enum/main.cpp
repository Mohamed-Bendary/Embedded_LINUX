#include <iostream>
#include <string>
#include <array>
#include <bitset>

using namespace std;

/** We are going to write a simple program that provides
 * menu options (Terminal) for a food outlet so the users will detect options from the menu
 * and we will present the price information based on the choice
 * New requirement, when the user press exit(3),the program should calculate the total amout of money to be paid & then  
 * if the amout above 100EGp , the system will giv him a 10% discount
*/


/**Extract nouns: [menu - option - food - user - price]
 * 
 * Extract verbs: Select
 * 
*/


#define MAX_MONEY_TO_ADD_DISCOUNT 100





/***************************************APIS***************************************/
/** Operator overloading
 * This API takes an integar and a string then add them together into one string
 */
string operator+ (int money , string currency);
const int User_select();



/***********************************Enums******************************************/
enum class Menu_Options
{

Fries_Option  = 1,
Burger_Option = 2,
EXIT_Option = 3

};
/***********************************Class******************************************/
class Menu
{
    public:
    //variables: Menu contains..what?
    //funtions:: what do i need from the menu
    void show();
  

};

constexpr int US_TO_EGP = 50;
constexpr int USER_DEFAULT_OPTION = Menu_Options::Fries_Option;

int main()
{

unsigned int User_Selection = 0;
unsigned int Total_money_In_US = 0; 
unsigned int Total_money_In_EGP = 0; 
bool Is_True = true;

//Creatin object from the class::Menu
Menu New_Menu;


while(Is_True == true)
{
    New_Menu.show();
/* The user shoul input his selection*/
User_Selection = User_select();


/* Switch the selection */
switch (User_Selection)
{

case Menu_Options::Fries_Option: 
{
 cout << "The freis price is: 1$ \n ";
 Total_money_In_US += 1;
 break; 
}
case Menu_Options::Burger_Option:
{
cout << "The burger price is: 2$ \n ";
Total_money_In_US +=2;
break;
}
case Menu_Options::EXIT_Option:
{
cout << "Thank you \n ";
Is_True = false;
break;
}
default: cout << "Invalid selection \n";

}

}
Total_money_In_EGP = Total_money_In_US * US_TO_EGP;
cout << "Your total price to pay is : " << Total_money_In_EGP << " EGP \n";

if(Total_money_In_EGP >= MAX_MONEY_TO_ADD_DISCOUNT)
{
Total_money_In_EGP = Total_money_In_EGP - (Total_money_In_EGP/10);
cout << "After discount the price is : " << Total_money_In_EGP <<" EGP \n";
}

}


/********************APIS_Definition**********************/

string operator+ (int money , string currency)
{

   string result = to_string(money).append(currency);
    return result;
}

const int User_select()
{
  int option =USER_DEFAULT_OPTION;
  cin >> option;
  return option;
}

 void Menu::show()
  { 
    cout << "Menu: \n";
    cout << " 1- Fries \n";
    cout << " 2- Burger \n";
    cout << " 3- Exit \n";

  }
