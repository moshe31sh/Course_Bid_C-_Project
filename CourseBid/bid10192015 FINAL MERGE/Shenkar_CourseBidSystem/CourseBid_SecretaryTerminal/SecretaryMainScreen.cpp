/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** SecretaryMainScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "SecretaryMainScreen.h"
#include "LockScreen.h"



SecretaryMainScreen::SecretaryMainScreen()
{

	this->changeScreen = SystemTime::CourseBidTime::PreRegistration;

}

vector<Course*> SecretaryMainScreen::getCourseList()
{

	return vector<Course*>();
}

vector<Student*> SecretaryMainScreen::getStudentList()
{


	return vector<Student*>();
}

void SecretaryMainScreen::getAssignitionResultsCourses()
{

}

void SecretaryMainScreen::getAssignitionResultsStudents()
{

}

string SecretaryMainScreen::getRegistrationStartDate()
{

	return string();
}

bool SecretaryMainScreen::releaseTerminalScreen()
{


	return true;
}

bool SecretaryMainScreen::studentUnlockScreen()
{


	return true;
}

bool SecretaryMainScreen::studentResetPassScreen()
{


	return true;
}

/*
lockTerminal . Secretary lock screen 
*/
bool SecretaryMainScreen::lockTerminal(bool status)
{
	FileStorage storage;
	vector<TerminalObj> terminals = TerminalObj::getAllTerminals(&storage);

	if (status == LOCK) {
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
		exit(0);
	}
	else if (status == UNLOCK){
		for each (TerminalObj terminal in terminals)
		{
			if (terminal.getId() == TerminalObj::getTerminalConfiguration())
			{
				terminal.setLocked(false);
				terminal.save(false);
			}
		}
	}
}

/*
show . show secretary option by season
*/

void SecretaryMainScreen::show()
{
	FileStorage * fs = new FileStorage();
	SystemTime systemtime = SystemTime();//running by time



	switch (systemtime.getCourseBidTime()) // enter to switch by enum value
	{

	case 0:
		cout << "PreRegistration" << endl;
		this->preRegistrationMenu(fs);
		break;
	case 1:
		cout << "Registration" << endl;
		this->registrationMenu(fs);
		break;
	case 2:
		cout << "PostRegistration" << endl;
		this->registrationMenu(fs);
		break;
	}

}





void SecretaryMainScreen::preRegistrationMenu(FileStorage *fs){
	char choice = '0';
	SystemTime systemtime = SystemTime();
	do { // Activate the menu until the user quits.
		this->changeScreen = systemtime.getCourseBidTime();
		cout << "Welcome to course bid - SECRETARY TERMINAL Shenkar!!" << endl;
		lOGO
			cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Lock registration screen" << endl;
		cout << "2 - Unlock registration screen" << endl;
		cout << "3 - Course edit " << endl;
		cout << "4 - Add new student " << endl;
		cout << "5 - Edit student " << endl;
		cout << "6 - Add new Course " << endl;

		choice = getchar();
		system("cls");
		switch (choice)
		{

		case '1':{
		

		lockTerminal(LOCK);

			CLEAN

				break;

		}
		case '2':{
lockTerminal(UNLOCK);
				
			CLEAN
				break;

		}
		case '3':{
			try{
				CourseEditScreen * editScreen = new CourseEditScreen();
				editScreen->show();
				delete editScreen;
			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}
		case '4':{
			try{
				StudentAddNewScreen * studentAddNewScreen = new StudentAddNewScreen();
				studentAddNewScreen->show();
				delete studentAddNewScreen;
			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}
		case '5':{
			try{
				StudentEditScreen * studentEditScreen = new StudentEditScreen();
				studentEditScreen->show();
				delete studentEditScreen;

			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}
		case '6':{
			try{
				CourseAddNewScreen *courseAddNewScreen = new CourseAddNewScreen();
				courseAddNewScreen->show();
				delete courseAddNewScreen;

			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}

		default:{
			cerr << "Wrong choice" << endl;
			
			CLEAN;
			break;
		}
		}
	} while (this->changeScreen == SystemTime::CourseBidTime::PreRegistration);

	cout << "Set expression" << endl;
	bool is_error = false;
	do{
		try{
			string exp;
			SetExpressionScreen *expressionScreen = new SetExpressionScreen();
			cout << "Please enter expression: ";
			cin >> exp;
			vector<Student> students = Student::getAllStudents(fs);
			for each(Student student in students){
				if (!expressionScreen->verifyAndSetExpression(exp, &student)) {
					is_error = true;
				}
			}

		}
		catch (bad_alloc e){
			cerr << e.what();
		}
		if (!is_error)	 {
			cout << "Action succeeded" << endl;
		}
		else{
			cout << "Action failed ,wrong input" << endl;
		}
	} while (is_error);

	CLEAN
}


void SecretaryMainScreen::registrationMenu(FileStorage *fs){
	char choice = '0';
	SystemTime systemtime = SystemTime();
	try{
		cout << "assign student to courses by points...." << endl;
		AssignmentCalculator *assignmentCalculator = new AssignmentCalculator();
		assignmentCalculator->compute();
		delete assignmentCalculator;
		CLEAN1
		cout << "Done.\n" << endl;
		CLEAN
	}
	catch (bad_alloc e){
		cerr << e.what();
	}
	do { // Activate the menu until the user quits.
		this->changeScreen = systemtime.getCourseBidTime();
		cout << "Welcome to course bid - SECRETARY TERMINAL Shenkar!!" << endl;
		lOGO
			cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Lock registration screen" << endl;
		cout << "2 - Unlock registration screen" << endl;
		cout << "3 - Course edit " << endl;
		cout << "4 - Edit student " << endl;
		choice = getchar();
		system("cls");
		switch (choice)
		{
		case '1':{

				lockTerminal(LOCK);
				
			CLEAN

				break;

		}
		case '2':{
			
				lockTerminal(UNLOCK);
				
			CLEAN
				break;

		}
		case '3':{
			try{
				CourseEditScreen * editScreen = new CourseEditScreen();
				editScreen->show();
				delete editScreen;
			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}

		case '4':{
			try{
				StudentEditScreen * studentEditScreen = new StudentEditScreen();
				studentEditScreen->show();
				delete studentEditScreen;

			}
			catch (bad_alloc e){
				cerr << e.what();
			}
			CLEAN
				break;
		}
		default:{
			cerr << "Wrong choice" << endl;
			
			CLEAN;
			break;

		}
		}
	} while (this->changeScreen == SystemTime::CourseBidTime::Registration || this->changeScreen == SystemTime::CourseBidTime::PostRegistration);


	CLEAN
}
