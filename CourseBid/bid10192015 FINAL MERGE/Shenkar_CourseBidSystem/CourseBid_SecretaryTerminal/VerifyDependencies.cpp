/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** VerifyDependencies.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "VerifyDependencies.h"

bool VerifyDependencies::verify(Course* course_to_delete) {
	FileStorage fs;
	vector<Course> vec_course = Course::getAllCourses(&fs);

	bool flag = true;
	for (unsigned int i = 0; i < vec_course.size(); i++) {
		vector<Course> vec_prereq = vec_course[i].getPreequisiteCourses();
		for (unsigned int j = 0; j < vec_prereq.size(); j++)
			if (vec_prereq[j].getCourseId() == course_to_delete->getCourseId())
				flag = false;
	}
	return flag;
}