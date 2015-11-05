/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseRemovePrerequisiteScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "CourseRemovePrerequisiteScreen.h"

CourseRemovePrerequisiteScreen::CourseRemovePrerequisiteScreen(long rootCourseId) :rootCourseId(rootCourseId)
{
}



void CourseRemovePrerequisiteScreen::show()
{
	CLEAN
		bool exist = false;
	string choice;
	bool condition = true;
	try{
		FileStorage *fs = new FileStorage();

		rootCourse = Course::getCourseByCourseId(fs, this->rootCourseId);
		do { // Activate the menu until the user quits.
			vector<Course> courses = rootCourse->getPreequisiteCourses();
			cout << "Course remove prerequisite screen" << endl;
			cout << "Id\t" << "Name" << endl;
			for each (Course course in courses)
			{
				cout << course.getCourseId() << '\t' << course.getName() << endl << endl;

			}
			cout << "Enter leaf course id or 'E' for exit" << endl;
			cin >> choice;
			for each (Course course in courses)
			{
				if (course.getCourseId() == atoi(choice.c_str())) exist = true;
			}

			if (choice == "e" || choice == "E") condition = false;
			else if (!exist){
				cout << "No such course try again" << endl;
				CLEAN;
			}
			else {
				this->leafCourse = Course::getCourseByCourseId(fs, atoi(choice.c_str()));
				if (leafCourse != NULL){
					long id = atoi(choice.c_str());
					this->leafCourse = Course::getCourseByCourseId(fs, atoi(choice.c_str()));
					this->rootCourse->removePrerequisiteCourse(this->leafCourse->getCourseId());
					cout << "Action succeed" << endl;
					condition = false;

				}
				else {
					cout << "Wrong enter" << endl;

				}
				CLEAN
			}
		} while (condition);
		//delete fs;
	}
	catch (bad_alloc e){
		cerr << e.what() << endl;
	}
}