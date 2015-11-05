/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CourseDataScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COURSEDATASCREEN_H
#define COURSEDATASCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;

#include "UIDataScreen.h"
#include "Course.h"
#include "Student.h"
#include "UITerminal.h"

class CourseDataScreen : public UIDataScreen {
private:
	Course* course;
	Student* student;		//NOTE:may be not in use on Secretary Terminal
	UITerminal* terminal;	//NOTE:may be not in use on Secretary Terminal
public:
	CourseDataScreen() {	}

	void printCourseData();
	void show();
};

#endif COURSEDATASCREEN_H