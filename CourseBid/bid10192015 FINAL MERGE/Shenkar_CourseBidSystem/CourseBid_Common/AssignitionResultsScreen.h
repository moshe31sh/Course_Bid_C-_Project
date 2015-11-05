/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** AssignitionResultScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef ASSIGNITIONRESULTSCREEN_H
#define ASSIGNITIONRESULTSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;

#include "UIListScreen.h"
#include "Course.h"
#include "Student.h"

class AssignitionResultScreen: public UIListScreen {
private:
	Course * course;
	Student * student;
public:
	AssignitionResultScreen() {	}
	void getCouseData();
	virtual void show();

};

#endif ASSIGNITIONRESULTSCREEN_H