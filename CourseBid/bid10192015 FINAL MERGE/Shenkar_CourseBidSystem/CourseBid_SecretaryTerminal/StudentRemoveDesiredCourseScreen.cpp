/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentRemoveCompletedScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/

#include "StudentRemoveDesiredCourseScreen.h"




StudentRemoveDesiredCourseScreen::StudentRemoveDesiredCourseScreen(Student* stud, Course* course) : student(stud), courseToRemove(course)
{
	cout << "StudentRemoveCompletedScreen() called" << endl;
}


bool StudentRemoveDesiredCourseScreen::removeDesiredCourse()
{
	this->student->removeDesiredCourse(this->courseToRemove);
	char answer;
	cout << "\nDo you save changes? y/n" << endl;
	fflush(stdin);
	answer = getchar();
	if (answer == 'y'){
		this->student->save(false);

		cout << "Change successfully saved" << endl;
	}
	else{
		cout << "Action canceled" << endl;
	}
	return true;
}

void StudentRemoveDesiredCourseScreen::show()
{

}