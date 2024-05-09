 
 #include <iostream>
 #include <string>



using namespace std;


int main()
{

string username {"De7ko"};

cout << username << " "<<"Size= " << username.size() << "\n";
cout << username << " " <<"Size= " << username.length() << "\n";
cout << username << " " <<"Size= " << username.max_size() << "\n";


username.clear();
cout << username << " "<<"Size after clear= " << username.size() << "\n";

if(username.empty())
{

cout<<"String is empty"<<"\n";

}
else{

   cout<<"Strin is not empty"<<"\n";
}

username = "linux";

/* Append addes string to the variable*/
username.append(" Academy");
cout<<username<<"\n";

/* push back adds element to string*/
username.push_back('D');
cout<<username<<"\n";

/* pop back deletes the last charachter*/
username.pop_back();
cout << username <<"\n";

}
