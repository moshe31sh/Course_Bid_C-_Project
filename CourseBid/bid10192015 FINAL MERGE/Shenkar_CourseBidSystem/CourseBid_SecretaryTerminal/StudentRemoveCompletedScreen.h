/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentRemoveCompletedScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef STUDENTREMOVECOMPLETEDSCREEN_H
#define STUDENTREMOVECOMPLETEDSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Student.h"
#include "Course.h"

class StudentRemoveCompletedScreen : public UIScreen {
private:
	Student * student;
	Course * courseToRemove;
public:
	StudentRemoveCompletedScreen(Student*, Course*);
	bool removeCompletedCourse();
	void show();
};

#endif STUDENTREMOVECOMPLETEDSCREEN_H