#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>

using namespace std;

// A "mini-class" to manage and store the users information
struct User
{
	string firstName;
	string lastName;
	string userName;
	string password;
	string occupation;
	string subject;
	vector<string> students = {};
	vector<string> courses = {};
	vector<int> courseID = {};
};

//Dynamic arrays handling the users in data base
vector<User> users = {};
vector<User> students = {};

//This is a 2d array/list which lists the available courses
string availableCourses[6][4] = {
	{"Algebra I Adv", "Geometry Adv ", "Algebra II Adv", "AP Pre-Calculus"}, //Math
	{"English I Adv", "English II Adv", "GT Humanities I", "GT Humanities II"}, //English
	{"Biology Adv", "Chemistry Adv", "Physics", "AP Physics"}, //Science
	{"World Geography", "AP Human", "World History", "AP World History"}, //History
	{"Computer Science I Adv", "AP Computer Science Principles", "AP Computer Science A", "Computer Science III Adv"}, //Computer Science
	{"Art I Adv", "Band", "Orchestra", "3D Modeling & Animation"} //Fine Art

};

string course[24] = {"Algebra I Adv", "Geometry Adv ", "Algebra II Adv", "AP Pre-Calculus", "English I Adv", "English II Adv", "GT Humanities I", "GT Humanities II", "Biology Adv", "Chemistry Adv", "Physics", "AP Physics", "World Geography", "AP Human", "World History", "AP World History", "Computer Science I Adv", "AP Computer Science Principles", "AP Computer Science A", "Computer Science III Adv", "Art I Adv", "Band", "Orchestra", "3D Modeling & Animation"};

//This is a 2d array/list which lists the available courses GPA scale
double GPA[6][4] = {
	{5.5, 5.5, 5.5, 6.0},
	{5.5, 5.5, 5.5, 5.5},
	{5.5, 5.5, 5.0, 6.0},
	{5.0, 6.0, 5.0, 6.0},
	{5.5, 6.0, 6.0, 6.0},
	{5.5, 5.0, 5.0, 5.0}
};

//Function Prototypes
char portal();
void info();
User signUp();
int login();
char manage(int);


int checkCourses(int);
void selectCourses(int);
void removeCourses(int);


int main ()
{
	int countUsers = 0;
	int userID;
	char choice;

	do
	{
		choice = portal();

		switch (choice)
		{
		case '1':
			info();
			break;

		case '2':
			users.push_back(signUp()); //Adds Element to Vector, dynamic array
			break;

		case '3':
			userID = login();
			if (userID != -2)
			{
				manage(userID);
			}

			break;
		}
	} while (choice != '4');


	return 0;
}



char portal ()
{
	char choice;

	do
	{
		system("CLS");

		cout << "Welcome to the Student Managment Center" << endl;
		cout << "----------------------------------------" << endl;
		cout << "What would you like to do?" << endl << endl;;
		cout << "\t1. See More Information" << endl;
		cout << "\t2. Sign Up" << endl;
		cout << "\t3. Log In" << endl;
		cout << "\t4. Exit" << endl << endl;

		choice = getch(); //Handles Input

	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');

	return choice;
}

void info ()
{
	system("CLS");
	cout << "Information Screen" << endl;
	cout << "-------------------" << endl << endl;
	cout << "\tThe Student Managment Center is a tool used by staff and students alike," << endl;
	cout << "designed to provide an efficient experience in selecting and checking courses" << endl;
	cout << "for students." << endl << endl;

	system("pause");

}

User signUp ()
{
	User p;
	char choice = '2';
	char occupationChoice;
	bool taken = false;

	do
	{
		do
		{
			system("CLS");

			cout << "Sign Up" << endl;
			cout << "--------" << endl << endl;

			cout << "\tEnter Your First Name: ";
			cin >> p.firstName;
			cout << endl;

			cout << "\tEnter Your Last Name: ";
			cin >> p.lastName;
			cout << endl;

			cout << "\tEnter Your Username or Email: ";
			cin >> p.userName;
			cout << endl;

			cout << "\tEnter Your Password: ";
			cin >> p.password;
			cout << endl;


			for (int i = 0; i < users.size() ; i++) // Finds Vector Size
			{
				if (p.userName == users[i].userName)
				{
					taken = true;
					break;
				}
				else
				{
					taken = false;
				}
			}

			if (taken)
			{
				system("CLS");
				cout << "Sign Up" << endl;
				cout << "--------" << endl << endl;

				cout << "\tUsername is taken, please enter a different username" << endl << endl;
				system("pause");
			}
		} while (taken);


		do
		{
			system("CLS");

			cout << "Is this you? " << endl << endl;
			cout << "\tName: " << p.firstName << " " << p.lastName << endl;
			cout << "\tUsername/Email: " << p.userName << endl;
			cout << "\tPassword: " <<  p.password << endl << endl;

			cout << "1. Yes" << endl;
			cout << "2. No" << endl;

			choice = getch();

		} while (choice != '1' && choice != '2');

	} while (choice == '2');



			p.occupation = "Student";
			students.push_back(p);

	return p;
}

int login()
{
	string username;
	string password;
	int userID = -1;
	char choice;

	do
	{
		system("CLS");
		cout << "Log In" << endl;
		cout << "-------" << endl << endl;


		cout << "\tUsername/Email: ";
		cin >> username;
		cout << endl;

		cout << "\tPassword: ";

		cin >> password;
		cout << endl;


		for (int i = 0; i < users.size(); i++)
		{
			if (username == users[i].userName && password == users[i].password)
			{
				userID = i;
				break;
			}
		}

		if (userID == -1)
		{
			do
			{
				system("CLS");
				cout << "Log In" << endl;
				cout << "-------" << endl << endl;

				cout << "\tUsername/Email: " << username << endl;

				cout << "\tPassword: " << password << endl << endl;

				for (int i = 0; i < users.size(); i++)
				{
					if (username == users[i].userName && password == users[i].password)
					{
						userID = i;
						break;
					}
				}

				cout << "Either Username or Passcode is Incorrect." << endl;
				cout << "Would you like to go back to portal (Press 1), or retry login (Press 2)?";

				choice = getch();
			} while (choice != '1' && choice != '2');

			if (choice == '1')
			{
				return -2;
			}

		}
	} while (choice == '2');

	return userID;
}

//Manages The Program After Logging In

char manage (int userID)
{
	char choice;
	int checkTrapping;
	
	do
	{
		

	if (users[userID].occupation == "Student")
	{
		do
		{
			system("CLS");
			cout << "Welcome " << users[userID].firstName << " " << users[userID].lastName << ", what would you like to do today?" << endl << endl;
			cout << "\t1. Select Courses" << endl;
			cout << "\t2. Check Selected Courses" << endl;
			cout << "\t3. Remove Courses" << endl;
			cout << "\t4. Log Out" << endl;
			choice = getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
	}
	
	
	if (users[userID].occupation == "Student")
	{
		switch (choice)
		{
			case '1':
				selectCourses(userID);
				break;
			
			case '2':
				checkTrapping = checkCourses(userID);
				if (checkTrapping != 1)
				{
					system("pause");
				}
				break;
			case '3':
				removeCourses(userID);
				break;
		}
	}

	
	} while (choice != '4');

	
	return choice;
}

//Selects Courses
void selectCourses(int userID)
{
	
	if (users[userID].courses.size() >= 8)
	{
		system("CLS");
		cout << "You Have Too Many Courses!" << endl << endl;
		system("pause");
		return;
	}
	
	int choice;
	bool errorTrap = false;
	
	do
	{
	
	
	system("CLS");
	
	string subjects[6] = {
		"Math", "English", "Science", "History", "Computer Science", "Fine Arts"
	};

	int optionNumber = 1;

	for (int i = 0; i < 6; i++) 
	{
		cout << "=== " << subjects[i] << " ===" << endl;
		for (int j = 0; j < 4; j++) 
		{
			cout << optionNumber << ". " << availableCourses[i][j]
			     << " (GPA: " << GPA[i][j] << ")" << endl;
			optionNumber++;
		}
		cout << endl;
	}
	
	cout << endl;
		
		cout << "Please Enter the Number of the Course You Want to Select: ";
		cin >> choice;
		cout << endl;
		cin.ignore();
		
		errorTrap = false;
		
		for (int i = 0; i < users[userID].courseID.size(); i++)
		{
			if (users[userID].courseID[i] == choice)
			{
				system("CLS");
				errorTrap = true;
				cout << "You have already chosen this course, please choose another course." << endl;
				system("pause");
				break;
			}
		}
		
		if (choice < 1 || choice > 24) 
		{
			system("CLS");
			cout << "Invalid option. Please choose a number between 1 and 24." << endl;
			system("pause");
		}
	} while (choice < 1 || choice > 24 || errorTrap);
	
	users[userID].courseID.push_back(choice);
	users[userID].courses.push_back(course[choice - 1]);
}

//Checks for courses

int checkCourses(int userID) 
{
	system("CLS");
	
	cout << "Courses for " << users[userID].firstName << ", " << users[userID].lastName << ":\n\n";
	if (users[userID].courses.size() == 0)
	{
		cout << "\tNo Courses Being Taken Currently" << endl << endl;
		system("pause");
		return 1;
	}
	for (int i = 0; i < users[userID].courses.size(); i++)
	{
		cout << "\t" << i + 1 << ". " << users[userID].courses[i] << endl;
	}
	cout << endl;
	
	
	return 0; 
}

void removeCourses(int userID)
{
	int choice;
	
	do
	{
		int checking = checkCourses(userID);
		if (checking == 1)
		{
			return;
		}
	
	
		cout << "Please Enter the Number of the Course You Want to Select: ";
		cin >> choice;
		cout << endl;
	} while (choice < 1 || choice > users[userID].courses.size());
	
	users[userID].courses.erase(users[userID].courses.begin() + (choice - 1)); 
	users[userID].courseID.erase(users[userID].courseID.begin() + (choice - 1)); //Removes Element From Array
	
	
	
}
