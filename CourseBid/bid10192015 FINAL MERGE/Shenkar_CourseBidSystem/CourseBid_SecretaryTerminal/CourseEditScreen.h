/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CourseEditScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COURSEEDITSCREEN_H
#define COURSEEDITSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIEditScreen.h"
#include "Course.h"
#include "CircleDetection.h"
#include "VerifyDependencies.h"
#include "CourseAddPrerequisiteScreen.h"
#include "CourseRemovePrerequisiteScreen.h"


#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;

class CourseEditScreen : public UIEditScreen {
private:
	long courseId;
	Course * course;
	CircleDetection* circleDetection;
	VerifyDependencies* verifyDependencies;
public:
	CourseEditScreen();
	bool saveCourseAndVerify();
	void show();
	void editCourseMenu();
	
};

#endif COURSEEDITSCREEN_H