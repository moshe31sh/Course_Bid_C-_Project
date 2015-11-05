/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseAddPrerequisiteScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "CourseAddPrerequisiteScreen.h"

CourseAddPrerequisiteScreen::CourseAddPrerequisiteScreen(long rootCourseId) :rootCourseId(rootCourseId)
{

}

/*
show. User menu.
*/
void CourseAddPrerequisiteScreen::show()
{
	CLEAN
		bool exist = false;
	string choice;
	bool condition = true;
	try{
		FileStorage *fs = new FileStorage();
		rootCourse = Course::getCourseByCourseId(fs, this->rootCourseId);
		do { /// Activate the menu until the user quits.
			vector<Course> courses = Course::getAllCourses(fs);
			cout << "Course add prerequisite screen" << endl;
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
				if (this->rootCourse->getName() == this->leafCourse->getName()){//check self assign
					cout << "Error,can't do self assign" << endl;
					CLEAN
				}
				else
					if (this->checkIfCourseLreadyAdded() == false){ // check if course is already exist in DB
						if (leafCourse != NULL){
							long id = atoi(choice.c_str());
							this->leafCourse = Course::getCourseByCourseId(fs, atoi(choice.c_str()));
							if (this->rootCourse->setPrerequisiteCourse(this->leafCourse->getCourseId())){
								cout << "Course successfully added" << endl;
								condition = false;
							}
							else{
								cout << "Action failed circle detect" << endl;
								condition = false;
							}
							CLEAN
						}
						else {
							cout << "Wrong enter" << endl;
							CLEAN
						}
					}
					else{
						cout << "Course already in prerequisite list" << endl;
						condition = false;
					}
			}
		} while (condition);
		//delete fs;
	}
	catch (bad_alloc e){
		cerr << e.what() << endl;
	}
}



/*
checkIfCourseLreadyAdded. Check if course already assigned
*/
bool CourseAddPrerequisiteScreen::checkIfCourseLreadyAdded(){//n
	vector<Course> coursePrerequisite = this->rootCourse->getPreequisiteCourses();
	for each (Course course in coursePrerequisite)
	{
		if ((course.getName() == this->leafCourse->getName())){
			return true;
		}
	}
	return false;
}