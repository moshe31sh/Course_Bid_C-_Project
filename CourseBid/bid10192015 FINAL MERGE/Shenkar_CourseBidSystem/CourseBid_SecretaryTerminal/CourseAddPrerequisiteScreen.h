/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CourseAddPrerequisiteScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COURSEADDPREREQUISITESCREEN_H
#define COURSEADDPREREQUISITESCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Course.h"
#include "CircleDetection.h"
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");

class CourseAddPrerequisiteScreen : public UIScreen {
private:
	long rootCourseId;
	long leafCourseId;
	Course * rootCourse;
	Course * leafCourse;

public:
	CourseAddPrerequisiteScreen(long rootCourseId);
	bool checkIfCourseLreadyAdded();
	void show();
};

#endif COURSEADDPREREQUISITESCREEN_H