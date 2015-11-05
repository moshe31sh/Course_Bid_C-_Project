#pragma once
/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentAddCompletedScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/


#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Student.h"
#include "Course.h"

class StudentAddAssignedCourseScreen : public UIScreen {
private:
	Student* student;
	Course* courseToAdd;
public:
	StudentAddAssignedCourseScreen(Student*, Course*);
	bool addAssignedCourse();
	void show();
};
