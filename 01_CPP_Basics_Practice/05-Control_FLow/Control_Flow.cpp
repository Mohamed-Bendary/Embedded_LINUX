#include <iostream>
#include <string>
#include <array>


using namespace std;

/** We are going to write a simple program that provides
 * menu options (Terminal) for a food outlet so the users will detect options from the menu
 * and we will present the price information based on the choice
*/


/**Extract nouns: [menu - option - food - user - price]
 * 
 * Extract verbs: Select
 * 
*/
#define Fries_Selection   1
#define Burger_Selection  2

int main()
{

unsigned int User_Selection = 0;
cout << "Menu: \n";
cout << " 1- Fries \n";
cout << " 2- Burger \n";

/* The user shoul input his selection*/
cin >> User_Selection;

/* Switch the selection */
switch (User_Selection)
{

case Fries_Selection: 
{
 cout << "The freis price is: 1$ \n ";
 break; 
}
case Burger_Selection:
{
cout << "The burger price is: 2$ \n ";
break;
}
default: cout << "Invalid selection \n";

}


}