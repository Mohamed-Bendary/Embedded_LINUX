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
#define Fries_Selection   1
#define Burger_Selection  2
#define Exit_Selection    3

#define MAX_MONEY_TO_ADD_DISCOUNT 100
#define USER_DEFAULT_OPTION   3

/** Operator overloading
 * This API takes an integar and a string then add them together into one string
*/


/***************************************APIS***************************************/
string operator+ (int money , string currency);
const int User_select();


constexpr int US_TO_EGP = 50;
int main()
{

unsigned int User_Selection = 0;
unsigned int Total_money_In_US = 0; 
unsigned int Total_money_In_EGP = 0; 
bool Is_True = true;

cout << "Menu: \n";
cout << " 1- Fries \n";
cout << " 2- Burger \n";
cout << " 3- Exit \n";

while(Is_True == true)
{
/* The user shoul input his selection*/
User_Selection = User_select();


/* Switch the selection */
switch (User_Selection)
{

case Fries_Selection: 
{
 cout << "The freis price is: 1$ \n ";
 Total_money_In_US += 1;
 break; 
}
case Burger_Selection:
{
cout << "The burger price is: 2$ \n ";
Total_money_In_US +=2;
break;
}
case Exit_Selection:
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

