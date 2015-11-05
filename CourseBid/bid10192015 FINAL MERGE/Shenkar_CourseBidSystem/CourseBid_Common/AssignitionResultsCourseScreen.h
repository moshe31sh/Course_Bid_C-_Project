/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** AssignitionResultsCourseScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef ASSIGNITIONRESULTSCOURSESCREEN_H
#define ASSIGNITIONRESULTSCOURSESCREEN_H

#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "UIListScreen.h"
#include "Course.h"
#include "Student.h"

class AssignitionResultsCourseScreen : public UIListScreen {
private:
	Course * course;
	vector<Student*> students;
public:
	//! AssignitionResultsCourseScreen class constructor.
	AssignitionResultsCourseScreen();

	//! Shows specific course data
	/*!
	\param courseId - specific course id
	\return - void
	*/
	void getCourseData(long courseId);

	//! Prints screen. This functions is inheritated from UIListScreen, and must be overided.
	/*!
	\return - void
	*/
	void show();
};

#endif ASSIGNITIONRESULTSCOURSESCREEN_H