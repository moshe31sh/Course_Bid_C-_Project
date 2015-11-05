/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentListScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef STUDENTLISTSCREEN_H
#define STUDENTLISTSCREEN_H

#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "UIListScreen.h"
#include "Student.h"

class StudentListScreen : public UIListScreen {
private:
	vector<Student*> students;
public:
	StudentListScreen();
	void getStudentData();
	void setStudentData();
	void deleteStudent();
	void show();
};

#endif STUDENTLISTSCREEN_H