/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CourseAddNewScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COURSEADDNEWSCREEN_H
#define COURSEADDNEWSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "Course.h"
#include "UIAddNewScreen.h"

#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");


class CourseAddNewScreen:public UIAddNewScreen {
private:
	long courseId;
	Course * course;
public:
	CourseAddNewScreen()
	{
	}
	void setCourseId(long courseId) { this->courseId = courseId; }
	bool addCourseAndVerify();
	void show();
	~CourseAddNewScreen();
};

#endif COURSEADDNEWSCREEN_H