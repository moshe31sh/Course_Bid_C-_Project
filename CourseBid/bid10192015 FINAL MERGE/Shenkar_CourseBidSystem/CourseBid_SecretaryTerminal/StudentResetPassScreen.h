/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentResetPassScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef STUDENTRESETPASSSCREEN_H
#define STUDENTRESETPASSSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Student.h"

class StudentResetPassScreen : public UIScreen {
private:
	Student *student;
public:
	StudentResetPassScreen(Student *);
	bool resetStudentPass();
	void show();
};

#endif STUDENTRESETPASSSCREEN_H