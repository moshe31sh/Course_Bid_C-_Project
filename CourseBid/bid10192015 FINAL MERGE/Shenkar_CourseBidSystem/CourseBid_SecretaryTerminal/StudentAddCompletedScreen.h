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
#ifndef STUDENTADDCOMPLETEDSCREEN_H
#define STUDENTADDCOMPLETEDSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Student.h"
#include "Course.h"

class StudentAddCompletedScreen : public UIScreen {
private:
	Student* student;
	Course* courseToAdd;
public:
	StudentAddCompletedScreen(Student*, Course*);
	bool addCompletedCourse();
	void show();
};

#endif STUDENTADDCOMPLETEDSCREEN_H