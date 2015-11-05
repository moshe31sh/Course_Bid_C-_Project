/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentMainScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef STUDENTMAINSCREEN_H
#define STUDENTMAINSCREEN_H

#include <iostream>
#include <cstdint>	
#include <map>
using namespace std;
#include "UIMainScreen.h"
#include "Student.h"
#include "Terminal.h"
#include "SystemTime.h"

class StudentMainScreen : public Terminal {
private:
	Student* student;
	bool Log;
	SystemTime::CourseBidTime changeScreen;
	void changeSrceenByTime();
	void preRegistrationMenu();
	void registrationMenu();
	void postRegistrationMenu();
public:
	StudentMainScreen(Student * stud) :student(stud)
	{
		this->Log = true;
		this->changeScreen = SystemTime::CourseBidTime::Registration;
	}
	void printCourseList();
	void logOut();
	void getAssignitionResultsScreen();
	void getPointDistributionScreen();
	void studentDetails();
	void show();
};

#endif STUDENTMAINSCREEN_H