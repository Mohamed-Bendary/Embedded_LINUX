#include <iostream>
#include <string>
#include <array>


using namespace std;

/* Create a new container that can contain: array of usernames,max number of usernames = 10*/

constexpr int MAX_Users = 10;
int main()
{
string username; 
short int counter;
array <string,10> usernames;

for(counter=0;counter<MAX_Users;counter++)
{
 cout << "Please enter the username" << "\n";
 cin >> username;
 usernames[counter] =username;

}

 cout << "The usernames are: " << "\n";
for(counter=0;counter<MAX_Users;counter++)
cout << usernames[counter] << "\n";


}