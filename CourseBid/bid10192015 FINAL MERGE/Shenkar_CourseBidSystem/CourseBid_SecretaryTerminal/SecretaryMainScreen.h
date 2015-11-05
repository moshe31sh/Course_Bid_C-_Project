/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SecretaryMainScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef SECRETARYMAINSCREEN_H
#define SECRETARYMAINSCREEN_H

#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "UIMainScreen.h"
#include "Course.h"
#include "Student.h"
#include "SetExpressionScreen.h"
#include "LockRegistrationScreen.h"
#include "TerminalObj.h"
#include "Terminal.h"
#include "CourseEditScreen.h"
#include <time.h>
#include "StudentAddNewScreen.h"
#include "StudentEditScreen.h"
#include "CourseAddNewScreen.h"
#include "AssignmentCalculator.h"
#include "SystemTime.h"
#include "SetRegistrationStartDateScreen.h"

//#include "Expression.h"
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define CLEAN1 cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	

#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;

class SecretaryMainScreen : public UIMainScreen {
private:
	SystemTime::CourseBidTime changeScreen;
	void changeSrceenByTime();
	void preRegistrationMenu(FileStorage *);
	void registrationMenu(FileStorage *);
	void postRegistrationMenu(FileStorage *);
public:
	
	SecretaryMainScreen();
	vector<Course*> getCourseList();
	vector<Student*> getStudentList();
	void getAssignitionResultsCourses();
	void getAssignitionResultsStudents();
	bool	lockTerminal(bool status);
	string getRegistrationStartDate();
	bool releaseTerminalScreen();
	bool studentUnlockScreen();
	bool studentResetPassScreen();
	void show();

	};




#endif SECRETARYMAINSCREEN_H