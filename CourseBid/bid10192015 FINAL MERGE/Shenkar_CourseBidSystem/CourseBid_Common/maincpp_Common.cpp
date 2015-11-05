/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** maincpp.cpp
** <This is Common Library. This main is not in use!>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef COMMON
#define COMMON
#include <iostream>
#include <cstdint>
#include "Student.h"
#include "Course.h"
#include "Formula.h"
#include "TerminalObj.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Common Lib" << endl;

	IStorage * fs;
	fs = new FileStorage();
	TerminalObj * terminal = new TerminalObj(1, fs);
	terminal->setLocked(true);
	terminal->save(false);
	
	vector<TerminalObj> allTerminals = TerminalObj::getAllTerminals(fs);
	for each(TerminalObj terminal in allTerminals)
	{
		cout << terminal.getLocked() << endl;
	}

	terminal->setLocked(false);
	terminal->save(false);

	allTerminals = TerminalObj::getAllTerminals(fs);
	for each(TerminalObj t in allTerminals)
	{
		cout << t.getLocked() << endl;
	}

	terminal->deleteMe();

	allTerminals = TerminalObj::getAllTerminals(fs);
	for each(TerminalObj t in allTerminals)
	{
		cout << t.getLocked() << endl;
	}


	/*
	Course* course = Course::getCourseByCourseId(&fs, 1);

	//cout << "ID: " << student->getId() << endl << "Fname: " << student->getFirstName() << endl;
	cout << course->ToString() << endl;
	if (student->addAssignedCourse(course))
		cout << "Course '" << course->getCourseId() << "' added to user!";
	else
		cout << "Failed to add course";

	cout << endl;
	delete student;
	delete course;
	*/
	system("pause");
}
#endif COMMON