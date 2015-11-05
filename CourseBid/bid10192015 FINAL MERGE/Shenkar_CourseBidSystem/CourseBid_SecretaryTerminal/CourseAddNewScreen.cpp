/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseAddNewScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "CourseAddNewScreen.h"

bool CourseAddNewScreen::addCourseAndVerify()
{
	vector<Course> courses = Course::getAllCourses(new FileStorage());
	for each (Course course in courses)
	{
		if (this->courseId == course.getId()) return true;
	}

	return false;
}


CourseAddNewScreen::~CourseAddNewScreen(){

}

/*
show. User menu.
*/
void CourseAddNewScreen::show()//user menu
{
	lOGO
		try{
		cout << "Add course screen" << endl;
		cout << "Please enter the following details\n" << endl;
		cout << "Course id: ";

		while (!(cin >> this->courseId) || this->courseId < 0) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
		cout << endl;
		if (this->addCourseAndVerify() == false){
			FileStorage * fs = new FileStorage();
			Course * course = new Course(courseId, fs, true);
			string str;
			cout << "Course name: ";
			cin >> str;
			course->setName(str);
			cout << endl;
			cout << "Course description: ";
			cin >> str;
			course->setDescription(str);
			cout << endl;
			cout << "Course capacity: ";
			cin >> str;
			course->setMaxStudents(atoi(str.c_str()));
			cout << endl;
			fflush(stdin);
			cout << "Course teaching hours: ";
			char buffer[250];
			fflush(stdin);
			gets(buffer);
			course->setTeachingHours(buffer);
			cout << endl;
			course->save(false);
			//delete (course, fs);
		}
		else {
			cout << "Course is already exist" << endl;

		}
	}
	catch (bad_alloc e){
		cerr << e.what() << endl;
	}

}