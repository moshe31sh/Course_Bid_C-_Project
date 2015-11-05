/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** TechnicianMainScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "TechnicianMainScreen.h"
#include "PointDistributionScreen.h"
#include "InsertAssignitionFileScreen.h"

TechnicianMainScreen::TechnicianMainScreen()
{
	this->Log = true;
}

void TechnicianMainScreen::logOut()
{
	this->Log = false;
}

//technicain is locking the terminal if the test went bad
 void TechnicianMainScreen::lockTerminal(bool status)
{
	if (status == LOCK) { 
		FileStorage storage;
		vector<TerminalObj> terminals = TerminalObj::getAllTerminals(&storage);
		for each (TerminalObj terminal in terminals)
		{
			if (terminal.getId() == TerminalObj::getTerminalConfiguration())
			{
				terminal.setLocked(true);
				terminal.save(false);
			}
		}
		LockScreen lockScreen;
		lockScreen.show();
		exit(0); // exit !
	}
}

void TechnicianMainScreen::show()
{
	char choice;
	do { // Activate the menu until the user quits.
		lOGO

		cout << "Hello Admin" << endl;
		cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - System test" << endl; // insert insertAssignitionFileScreen 
		cout << "2 - Lock registration screen" << endl;
		cout << "E - Logout" << endl;
		choice = getchar();
		system("cls");
		switch (choice)
		{
			case '1':
			{//insert test file screen
					InsertAssignitionFileScreen insertAssignitionFileScreen = InsertAssignitionFileScreen();
					insertAssignitionFileScreen.show();
					CLEAN
					break;
			}
			case '2':{
					 
					this->lockTerminal(LOCK);
					CLEAN
					break;
			}
			case 'E': { // Set to 'E' and go to case 'E'.
			case 'e':  // End the switch.

					this->logOut();
					break;
			}
			default:{
						cerr << "Wrong choice" << endl;
						CLEAN;
						break;
			}
		}
	} while (this->Log);
	cout << "HAVE A NICE DAY!\n\n";
	CLEAN
	
}