/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentUnlockScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "StudentUnlockScreen.h"

StudentUnlockScreen::StudentUnlockScreen(Student *stud) :student(stud){}

bool StudentUnlockScreen::releaseStudent()
{


	return true;
}

bool StudentUnlockScreen::lockStudent()
{


	return true;
}

void StudentUnlockScreen::show()
{
	char choice;
	bool condition = true;

	char answer;
	do { // Activate the menu until the user quits.
		system("cls");
		cout << "Lock / Unlock screen" << endl;
		cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Lock student" << endl;
		cout << "2 - Unlock student" << endl;
		cout << "B - Back" << endl;
		fflush(stdin);
		choice = getchar();
		switch (choice)
		{
		case '1':
		{
			this->student->setLocked(true);
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->student->save(false);
				cout << "Student successfully locked" << endl;
				condition = false;
			}
			else{
				cout << "Action canceled" << endl;
			}
			break;
		}
		case '2':{
			this->student->setLocked(false);
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->student->save(false);
				cout << "Student successfully unlocked" << endl;
				condition = false;
			}
			else{
				cout << "Action canceled" << endl;
			}
			break;
		}

		case 'B': { // Set to 'E' and go to case 'E'.
		case 'b':  // End the switch.

			condition = false;

			break;
		}
		default:{
			cerr << "Wrong choice" << endl;
			system("cls");
			break;
		}
		}
	} while (condition == true);
}