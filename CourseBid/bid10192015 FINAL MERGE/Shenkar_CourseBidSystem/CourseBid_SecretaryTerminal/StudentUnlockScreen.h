/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentUnlockScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef STUDENTUNLOCKSCREEN_H
#define STUDENTUNLOCKSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Student.h"

class StudentUnlockScreen : public UIScreen {
private:
	Student *student;
public:
	StudentUnlockScreen(Student *);
	bool releaseStudent();
	bool lockStudent();
	void show();
};

#endif STUDENTUNLOCKSCREEN_H