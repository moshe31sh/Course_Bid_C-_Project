/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentAddCompletedScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "StudentAddCompletedScreen.h"

StudentAddCompletedScreen::StudentAddCompletedScreen(Student* stud, Course* course) : student(stud), courseToAdd(course)
{
}

/*
addCompletedCourse. Assign Completed Course to student
*/
bool StudentAddCompletedScreen::addCompletedCourse()
{

	this->student->addCompletedCourse(this->courseToAdd);
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

void StudentAddCompletedScreen::show()
{

}