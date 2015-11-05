/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** StudentEditScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef STUDENTEDITSCREEN_H
#define STUDENTEDITSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIEditScreen.h"
#include "Student.h"
#include "StudentAddCompletedScreen.h"
#include "StudentRemoveCompletedScreen.h"
#include "StudentAddAssignedCourseScreen.h"
#include "StudentRemoveAssignedCourseScreen.h"
#include "StudentRemoveDesiredCourseScreen.h"
#include "StudentUnlockScreen.h"
#include "StudentResetPassScreen.h"


#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;

class StudentEditScreen : public UIEditScreen {
private:
	long studentId;
	Student * student;
public:
	StudentEditScreen();
	bool saveStudentAndVerify();
	bool deleteStudent();
	bool addCompletedCourse();
	bool removeCompletedCourse();
	void show();
	void editStudentDetailes();
	Course *getChosenCourse(vector<Course*> );
	void PrintSpesificCourse(vector<Course*>);
};



#endif STUDENTEDITSCREEN_H