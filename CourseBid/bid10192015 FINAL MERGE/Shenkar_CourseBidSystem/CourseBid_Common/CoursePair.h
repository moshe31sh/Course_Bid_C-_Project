/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CoursePair.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COURSEPAIR_H
#define COURSEPAIR_H

#include <iostream>
#include <cstdint>	
using namespace std;

#include "Course.h"

class Course;
class CoursePair {
private:
	Course * srcCourse;
	Course * destCourse;
public:
	CoursePair(Course * srcCourse, Course* destCourse) 
		: srcCourse(srcCourse), destCourse(destCourse) {	}

};

#endif COURSEPAIR_H