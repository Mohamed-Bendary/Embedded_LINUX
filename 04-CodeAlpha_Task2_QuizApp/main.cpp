#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <locale>
#include <codecvt>
#include <map>

using namespace std;


/************************************User_Defined datatypes**********************************************/
class User {
public:
    string User_Name;
    string Password;
    unsigned char Score = 0;
};

struct Question {
    string question;
    vector<string> options;
    int correctAnswer;
};

// ANSI Escape codes for colors //
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string WHITE = "\033[37m";

/**********************************Helper functions definition*******************************************/
void SetColor(const string Color);
void registerUser(map<string, User>& users);
bool loginUser(map<string, User>& users, string& loggedInUser);
void takeQuiz(vector<Question>& questions, User& user);
void displayResult(const User& user, const vector<Question>& questions);
void loadQuestions(vector<Question>& mathQuestions, vector<Question>& programmingQuestions, vector<Question>& sportsQuestions);

int main() {
    map<string, User> users;
    vector<Question> mathQuestions, programmingQuestions, sportsQuestions;
    loadQuestions(mathQuestions, programmingQuestions, sportsQuestions);

    string choice;
    string loggedInUser;
    
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;
        cout << "\n";

        if (choice == "1") {
            registerUser(users);
        } else if (choice == "2") {
            if (loginUser(users, loggedInUser)) {
                int topicChoice;
                cout << "\nChoose a topic: \n1. Math\n2. Programming\n3. Sports\nChoose an option: ";
                cin >> topicChoice;
                cout << "\n";

                switch (topicChoice) {
                    case 1:
                        takeQuiz(mathQuestions, users[loggedInUser]);
                        break;
                    case 2:
                        takeQuiz(programmingQuestions, users[loggedInUser]);
                        break;
                    case 3:
                        takeQuiz(sportsQuestions, users[loggedInUser]);
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }

                if (topicChoice == 1) {
                    displayResult(users[loggedInUser], mathQuestions);
                } else if (topicChoice == 2) {
                    displayResult(users[loggedInUser], programmingQuestions);
                } else if (topicChoice == 3) {
                    displayResult(users[loggedInUser], sportsQuestions);
                }
            }
        } else if (choice == "3") {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

/**********************************Helper functions implementation*******************************************/

void SetColor(const string Color) {
    cout << RESET;
    cout << Color;
}

void registerUser(map<string, User>& users) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose another username.\n";
    } else {
        users[username] = {username, password, 0};
        cout << "Registration successful!\n";
    }
    cout << "\n";
}

bool loginUser(map<string, User>& users, string& loggedInUser) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].Password == password) {
        loggedInUser = username;
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
    cout << "\n";
}

void takeQuiz(vector<Question>& questions, User& user) {
    int answer;
    user.Score = 0;

    // Ensure only 3 questions are presented
    for (int i = 0; i < 3; ++i) {
        const auto& q = questions[i];
        SetColor(RED);
        cout << q.question << endl;
        SetColor(RESET);
        for (int j = 0; j < q.options.size(); ++j) {
            cout << j + 1 << ". " << q.options[j] << endl;
        }
        cout << "Your answer: ";
        cin >> answer;

        if (answer - 1 == q.correctAnswer) {
            user.Score++;
        }
        cout << "\n";
    }
}

void displayResult(const User& user, const vector<Question>& questions) {
    cout << "Quiz Over!\n";
    cout << "Your score: " << static_cast<int>(user.Score) << "/3\n\n";
    cout << "Correct Answers:\n\n";

    for (int i = 0; i < 3; ++i) {
        const auto& q = questions[i];
        SetColor(RED);
        cout << q.question << endl;
        SetColor(RESET);
        cout << "Correct answer: " << q.options[q.correctAnswer] << endl;
    }
    cout << "\n";
}

void loadQuestions(vector<Question>& mathQuestions, vector<Question>& programmingQuestions, vector<Question>& sportsQuestions) {
    mathQuestions.push_back({"What is 2 + 2?", {"3", "4", "5", "6"}, 1});
    mathQuestions.push_back({"What is the square root of 16?", {"2", "3", "4", "5"}, 2});
    mathQuestions.push_back({"What is 5 * 6?", {"30", "31", "32", "33"}, 0});
    
    programmingQuestions.push_back({"What is the keyword to declare a constant in C++?", {"const", "constant", "final", "immutable"}, 0});
    programmingQuestions.push_back({"What does 'HTML' stand for?", {"Hypertext Markup Language", "Hyperlink Markup Language", "Hyper Transfer Markup Language", "Hypertext Transfer Markup Language"}, 0});
    programmingQuestions.push_back({"Which language is used for Android app development?", {"Java", "Python", "C++", "Swift"}, 0});
    
    sportsQuestions.push_back({"How many players are there in a football team?", {"10", "11", "12", "13"}, 1});
    sportsQuestions.push_back({"Which country won the FIFA World Cup in 2018?", {"Brazil", "Germany", "France", "Argentina"}, 2});
    sportsQuestions.push_back({"How many sets are there in a volleyball match?", {"3", "4", "5", "6"}, 2});
}
