/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** AssignitionResultsStudentScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef ASSIGNITIONRESULTSSTUDENTSCREEN_H
#define ASSIGNITIONRESULTSSTUDENTSCREEN_H

#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "UIListScreen.h"
#include "Course.h"
#include "Student.h"

class AssignitionResultsStudentScreen : public UIListScreen{
private:
	Student * student;
	vector<Course*> courses;
public:
	AssignitionResultsStudentScreen();
	void getStudentData(long studentId);
	void show();
};

#endif ASSIGNITIONRESULTSSTUDENTSCREEN_H