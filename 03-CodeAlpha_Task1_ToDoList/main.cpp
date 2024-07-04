#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <locale>
#include <codecvt>

#define MAX_TASKS       50

using namespace std;

/**********************************Private Macros*******************************************************/

#define USER_INPUT_ADD_TASK                 1
#define USER_INPUT_COMPLETE_TASK            2
#define USER_INPUT_SHOW_TASKS               3
#define USER_INPUT_Inquire_About_TASK       4
#define EXIT                                5

#define MAX_NAME_LENGHT                     15
#define MAX_DESCRIPTION_LENGTH              100 

enum class Task_Status
{
Done = 1,
Not_Finished,
In_Progress
};

enum class Task_Priority
{
NONE = 1,    
LOW,
MID,
HIGH    
};

typedef struct
{
unsigned int  Year;
unsigned char Month;
unsigned char Day;
float Hour;
string Day_Mode; // pm , am //

}Date_t;

class Tasks 
{
public:  

/**********************************Member variables declaration*******************************************/
char ID;
char Display_Order;
Task_Status status;
string Name;
Date_t Due_Date;
Task_Priority Priority;
string Description;

/**********************************Member functions definition********************************************/
Tasks();


};


// ANSI escape codes for colors //
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string WHITE = "\033[37m";

/* Creating an allias to the class Tasks for an easy access */
using Tasks_u = Tasks;


/**********************************Helper functions definition*******************************************/
void Menu_Print_Options(void);
void User_ADD_TASK_Interface();
void User_Complete_TASK_Interface();
void User_Show_TASKS_Interface();
void User_Inquire_TASK_Interface();
void SetColor(const string Color);
void Print_Task(Tasks_u &Task);
string applyStrikethrough(const string& str);
void Arrange_In_Priority_Order();
void Arrange_In_Due_Order();
void Display_Tasks();

/* Creating an array to hold the tasks */
array <Tasks_u,MAX_TASKS>Tasks_Container;

char Task_Tracker = 0;
int User_Integar_Menu_Input = 0;
string User_String_Menu_Input = "NULL";
float User_Float_Menu_Input = 0.0;

int main()
{

while(1)
{
/* Printing the menu options for the user*/
Menu_Print_Options();

/* Taking the user input */
cin >> User_Integar_Menu_Input;

    switch (User_Integar_Menu_Input)
    {
    case USER_INPUT_ADD_TASK:
    {
     /* Taking the user data about the added task */
     User_ADD_TASK_Interface();

     /* Successful task added */
     cout << "Your task is added successfuly\n\n";
     
     Print_Task(Tasks_Container[Task_Tracker]);
     cout << "\n";
    
     /* Updating the array tracking holding variable by moving one element */
     Task_Tracker++;   
     break;
    }
    case USER_INPUT_COMPLETE_TASK:
    {
        
     User_Complete_TASK_Interface();

        break;
    }
    case USER_INPUT_SHOW_TASKS:
    {
        
     User_Show_TASKS_Interface(); 
        break;
    }
    case USER_INPUT_Inquire_About_TASK:
    {

     User_Inquire_TASK_Interface();
        
        break;
    }
    case EXIT:
    break;

    default:
      cout << "Please enter valid data\n";
      break;
    }
    
    if(User_Integar_Menu_Input == EXIT) break;
}

return 0;

}




/**********************************Helper functions implementation*******************************************/
void Menu_Print_Options()
{
cout << "Choose your option by ID:\n";
cout << "1- Add task \n" << "2- Complete task \n" << "3- Show tasks \n" << "4- Inquire about task \n" << "5- Exit\n";
cout << "Choice: ";
}

void User_ADD_TASK_Interface()
{
bool Data_Success =false;

/* Entering task name */  
cout << "Enter the task name: ";
cin.ignore(); // To ignore the leftover newline character from previous input //
getline(cin, User_String_Menu_Input);

Tasks_Container[Task_Tracker].Name = User_String_Menu_Input;

/* Entering the new task due date */
while(Data_Success == false)
{
cout << "Enter task year due date: ";
cin >> User_Integar_Menu_Input;
    if(User_Integar_Menu_Input < 2024)
    {
        cout << "Please enter valid data \n";
    }
    else
    {
    Tasks_Container[Task_Tracker].Due_Date.Year = User_Integar_Menu_Input;
    Data_Success = true;
    }

}
/* Reseting the data success tracker variable */
Data_Success = false;

while (Data_Success == false)
{
cout << "Enter task month due date: ";
cin >> User_Integar_Menu_Input;
    if((User_Integar_Menu_Input < 0) || (User_Integar_Menu_Input > 12))
    {
        cout << "Please enter valid data \n";
    }
    else
    {

    Tasks_Container[Task_Tracker].Due_Date.Month = User_Integar_Menu_Input;
    Data_Success = true;
    
    }
}

/* Reseting the data success tracker variable */
Data_Success = false;

while(Data_Success == false)
{

cout << "Enter task day due date: ";
cin >> User_Integar_Menu_Input;
    if((User_Integar_Menu_Input < 0) || (User_Integar_Menu_Input > 31))
    {
        cout << "Please enter valid data \n";
    }
    else
    {

    Tasks_Container[Task_Tracker].Due_Date.Day = User_Integar_Menu_Input;
    Data_Success = true;
    
    }
}
/* Reseting the data success tracker variable */
Data_Success = false;



while(Data_Success == false)
{    
cout << "Enter task hour due date : ";
cin >> User_Float_Menu_Input;
    if((User_Float_Menu_Input > 12.59) || (User_Float_Menu_Input < 0.0))
    {
        cout << "Please enter valid data \n";
    }
    else
    {
        Tasks_Container[Task_Tracker].Due_Date.Hour = User_Float_Menu_Input;
        Data_Success = true;
    
    }
}

/* Reseting the data success tracker variable */
Data_Success = false;

while(Data_Success == false)
{    
cout << "Enter task Day mode due date by ID:\n" << "1- pm       2- am\n";
cout << "Choice: ";
cin >> User_Integar_Menu_Input;
    if((User_Integar_Menu_Input != 1) && (User_Integar_Menu_Input != 2))
    {
        cout << "Please enter valid data \n";
    }
    else
    {
    if(User_Integar_Menu_Input == 1)  Tasks_Container[Task_Tracker].Due_Date.Day_Mode = "PM";
    else Tasks_Container[Task_Tracker].Due_Date.Day_Mode = "AM";
    Data_Success = true;
    
    }
}

/* Reseting the data success tracker variable */
Data_Success = false;

/* Entering the task priority */

while(Data_Success == false)
{    
cout << "Enter task priority by ID:\n" << "1- High  2-Mid  3-Low \n";
cout << "Choice: ";
cin >> User_Integar_Menu_Input;
    if((User_Integar_Menu_Input != 1) && (User_Integar_Menu_Input != 2) && (User_Integar_Menu_Input != 3))
    {
        cout << "Please enter valid data \n";
    }
    else
    {

    if(User_Integar_Menu_Input == 1) Tasks_Container[Task_Tracker].Priority = Task_Priority::HIGH;
    else if (User_Integar_Menu_Input == 2) Tasks_Container[Task_Tracker].Priority = Task_Priority::MID;
    else Tasks_Container[Task_Tracker].Priority = Task_Priority::LOW;
    Data_Success = true;

    }
}

/* Reseting the data success tracker variable */
Data_Success = false;

/* Entering the task description */
cout << "Enter short decription for the task:\n";
cin.ignore(); // To ignore the leftover newline character from previous input //
getline(cin, User_String_Menu_Input);

Tasks_Container[Task_Tracker].Description = User_String_Menu_Input;

/* Automatic allocation of some task parameters */
// ID is the same its location in the array + 1 //
Tasks_Container[Task_Tracker].ID = Task_Tracker + 1;

// Status in any new task by default is not completed //
Tasks_Container[Task_Tracker].status = Task_Status::Not_Finished;


}

void User_Complete_TASK_Interface()
{
bool Data_Success = false;

 while(Data_Success == false)
 {
    cout << "Choose the task you completed by ID: \n";
    
    Arrange_In_Priority_Order();
    Arrange_In_Due_Order();

    /* Printing all tasks in order of ID */
    Display_Tasks();

    cout << "Choice: ";
    cin >> User_Integar_Menu_Input;
    if( (User_Integar_Menu_Input < 0) || (User_Integar_Menu_Input > Task_Tracker))
    {
     cout << "Please enter valid data\n";
    }
    else
    {
      Tasks_Container[User_Integar_Menu_Input - 1].status = Task_Status::Done;
      Tasks_Container[User_Integar_Menu_Input - 1].Priority = Task_Priority::NONE;
      Data_Success = true;
    }

 }
 cout << "Good job you completed: \n";
 Print_Task(Tasks_Container[User_Integar_Menu_Input - 1]);
}

void User_Inquire_TASK_Interface()
{
 bool Data_Success = false;
 string String_Part_Priority;

 while(Data_Success == false)
 {
    cout << "Choose the task you want to inquire about by ID: \n";

    /* Printing all tasks in order of ID */
    for(char i = 0;i < Task_Tracker;i++)
    {

    Print_Task(Tasks_Container[i]);

    }

    cout << "Choice: ";
    cin >> User_Integar_Menu_Input;
    if( (User_Integar_Menu_Input < 0) || (User_Integar_Menu_Input > Task_Tracker))
    {
     cout << "Please enter valid data\n";
    }
    else
    {
      if(Tasks_Container[User_Integar_Menu_Input - 1].Priority == Task_Priority::HIGH) String_Part_Priority = "HIGH";
      else if(Tasks_Container[User_Integar_Menu_Input - 1].Priority == Task_Priority::MID) String_Part_Priority = "MID";
      else if(Tasks_Container[User_Integar_Menu_Input - 1].Priority == Task_Priority::LOW) String_Part_Priority = "LOW";
      else String_Part_Priority = "NONE";

      Print_Task(Tasks_Container[User_Integar_Menu_Input - 1]);
      cout << "Description: " << Tasks_Container[User_Integar_Menu_Input - 1].Description << "\nPriority: "
      << String_Part_Priority << "\n\n";
      Data_Success = true;
    }

 }

}

void User_Show_TASKS_Interface()
{
Arrange_In_Priority_Order();
Arrange_In_Due_Order();

Display_Tasks();
}

void Print_Task(Tasks_u &Task)
{
 string Full_Task_Message = "NULL";
 string State_String_Part = "NULL";
 bool Completed_task = false;

 switch (Task.Priority)
 {
  case Task_Priority::HIGH :
 {
    SetColor(RED);
    break;
 }
 case Task_Priority::MID :
 {
    SetColor(YELLOW);
    break;
 }
   
 case Task_Priority::LOW :
 {
    SetColor(GREEN);
    break;
 }
   
 
 default:
    break;
 }   

 if(Task.status == Task_Status::Not_Finished) State_String_Part = "InCompleted";
 else if (Task.status == Task_Status::Done) 
 {
 State_String_Part = "Done";
 SetColor(CYAN);
 Completed_task = true;
 
 }
    /* Printing the task integrated full message showing its all details */
    ostringstream oss;
    oss << static_cast<int>(Task.ID) << ". " << Task.Name << "          State: " << State_String_Part <<"      Due: "<< static_cast<int>(Task.Due_Date.Day) << "/" << static_cast<int>(Task.Due_Date.Month) << "/"
        << static_cast<int>(Task.Due_Date.Year) << " " << static_cast<float>(Task.Due_Date.Hour) << " " << Task.Due_Date.Day_Mode;
    
     if(Completed_task == true)
     {
        Full_Task_Message = applyStrikethrough(oss.str());
        Completed_task = false;
     }
     else Full_Task_Message = oss.str();   
     cout << Full_Task_Message << "\n";

     /* Returning the color back to default */
     SetColor(RESET);  


}

void SetColor(const string Color)
{
cout << RESET;
cout << Color;

}
string applyStrikethrough(const string& str)
{
    // Use combining character U+0336 for strikethrough
    string result;
    for (char ch : str)
    {
        result += ch;
        result += u8"\u0336";
    }
    return result;
}

void Arrange_In_Priority_Order()
{
   
    Tasks_u Temp;

    /* Applying sorting algorithm on priority */
    for(char i =0 ; i < Task_Tracker ;i++)
    {
        for(char j = 0 ; j < Task_Tracker - i - 1 ;j++)
        {
            if(Tasks_Container[j+1].Priority > Tasks_Container[j].Priority)
            {
               Temp =  Tasks_Container[j];
               Tasks_Container[j] = Tasks_Container[j+1];
               Tasks_Container[j+1] = Temp;
            }
            else
            {

            }
        }

    }


}
void Arrange_In_Due_Order()
{
    Tasks_u Temp;

    /* Applying sorting algorithm on due date */
    for (char i = 0; i < Task_Tracker; i++)
    {
        for (char j = 0; j < Task_Tracker - i - 1; j++)
        {
            if(Tasks_Container[j + 1].Priority != Tasks_Container[j].Priority)
            {
                /* Skipping the iteration of different priorities to avoid rearanging based on due date
                   if it is already sorted by priority */
                   continue;
            }
            if (Tasks_Container[j + 1].Due_Date.Year < Tasks_Container[j].Due_Date.Year)
            {
                Temp = Tasks_Container[j];
                Tasks_Container[j] = Tasks_Container[j + 1];
                Tasks_Container[j + 1] = Temp;
            }
            else if (Tasks_Container[j + 1].Due_Date.Year == Tasks_Container[j].Due_Date.Year)
            {
                if (Tasks_Container[j + 1].Due_Date.Month < Tasks_Container[j].Due_Date.Month)
                {
                    Temp = Tasks_Container[j];
                    Tasks_Container[j] = Tasks_Container[j + 1];
                    Tasks_Container[j + 1] = Temp;
                }
                else if (Tasks_Container[j + 1].Due_Date.Month == Tasks_Container[j].Due_Date.Month)
                {
                    if (Tasks_Container[j + 1].Due_Date.Day < Tasks_Container[j].Due_Date.Day)
                    {
                        Temp = Tasks_Container[j];
                        Tasks_Container[j] = Tasks_Container[j + 1];
                        Tasks_Container[j + 1] = Temp;
                    }
                    else if (Tasks_Container[j + 1].Due_Date.Day == Tasks_Container[j].Due_Date.Day)
                    {
                        /* Convert AM/PM time to 24-hour format for comparison */
                        float hour1 = Tasks_Container[j].Due_Date.Hour;
                        float hour2 = Tasks_Container[j + 1].Due_Date.Hour;

                        if (Tasks_Container[j].Due_Date.Day_Mode == "PM" && hour1 < 12) hour1 += 12;
                        if (Tasks_Container[j].Due_Date.Day_Mode == "AM" && hour1 == 12) hour1 = 0;
                        if (Tasks_Container[j + 1].Due_Date.Day_Mode == "PM" && hour2 < 12) hour2 += 12;
                        if (Tasks_Container[j + 1].Due_Date.Day_Mode == "AM" && hour2 == 12) hour2 = 0;

                        if (hour2 < hour1)
                        {
                            Temp = Tasks_Container[j];
                            Tasks_Container[j] = Tasks_Container[j + 1];
                            Tasks_Container[j + 1] = Temp;
                        }
                    }
                }
            }
        }
    }
}


void Display_Tasks()
{

    for(char L_Counter = 0 ; L_Counter<Task_Tracker ; L_Counter++)
    {
        Tasks_Container[L_Counter].ID = L_Counter + 1;
        Print_Task(Tasks_Container[L_Counter]);
    }
}


/**********************************Member functions Implementation********************************************/
/* Constructor implementation */
 Tasks_u::Tasks()
 {
  Name = "NULL";
  Due_Date.Year = 2024;
  Due_Date.Month = 8;
  Due_Date.Day = 30;
  Due_Date.Hour = 8.55;
  Due_Date.Day_Mode = "pm";
  Priority = Task_Priority::HIGH;
  Description = "NULL";  

 }
















