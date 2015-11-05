/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** PointDistributionScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef POINTDISTRIBUTIONSCREEN_H
#define POINTDISTRIBUTIONSCREEN_H

#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "Course.h"
#include "Student.h"
#include "UIListScreen.h"
#include "StudentMainScreen.h"

class PointDistributionScreen : public UIListScreen {
private:
	vector<Course*> courses;
	Student* student;
	FileStorage *filestorage;

public:
	enum ComDes{
		Completed,
		Desired
	};
	PointDistributionScreen();
	~PointDistributionScreen();
	void printCourseListForStudent();
	bool isCoursetaken(long ,ComDes);
	void setDesiredCoursePoints();
	void show();
	void setStudent(Student*);
	void setCourses(vector<Course>);
};

#endif POINTDISTRIBUTIONSCREEN_H