/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseEditScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "CourseEditScreen.h"

CourseEditScreen::CourseEditScreen()
{
}




bool CourseEditScreen::saveCourseAndVerify()
{

	this->course->save(false);
	return true;
}


/*
editCourseMenu. Edit all course fields
*/

void CourseEditScreen::editCourseMenu(){
	char choice;
	bool condition = true;
	string buffer;
	bool isChanged = false;
	char answer;
	do { // Activate the menu until the user quits.
		system("cls");
		lOGO
			cout << "Editing course " << this->course->getName() << endl;;
		cout << "\nYour options are:" << endl;
		cout << "Please enter your choice:" << endl;
		cout << "1 - Print course details" << endl;
		cout << "2 - Edit course name" << endl;
		cout << "3 - Edit course description" << endl;
		cout << "4 - Edit max student" << endl;
		cout << "5 - Add course Prerequisite" << endl;
		cout << "6 - Remove course Prerequisite" << endl;
		cout << "7 - Edit teaching hours" << endl;
		cout << "8 - Delete course" << endl;
		cout << "B - Back" << endl;
		fflush(stdin);
		choice = getchar();
		system("cls");
		switch (choice)
		{
		case '1':
		{
			cout << "Course details:\n" << endl;
			cout << "Names\t\t\t" << "Id\t" << "Capacity\t" << "Description\t\t" << "Teaching hours" << endl;
			cout << this->course->getName() << " \t" << this->course->getCourseId() << " \t" << this->course->getMaxStudents() << "\t\t" << this->course->getDescription() << "\t" << this->course->getTeachingHours() << endl;
			cout << "\nCourse Prerequisite list:\n" << endl;
			if (this->course->getPreequisiteCourses().size() > 0){
				vector<Course> coursePrerequisite = this->course->getPreequisiteCourses();
				for each (Course course in coursePrerequisite)
				{
					cout << course.getName() << endl;
				}
			}
			else{
				cout << "No prerequisite courses" << endl;
			}

			CLEAN
				break;
		}
		case '2':{
			cout << "\n\n" << this->course->getName() << endl;
			cout << "\nPlease enter course new name ";
			cin >> buffer;
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->course->setName(buffer);
				cout << "Name successfully changed" << endl;
				isChanged = true;
			}
			else{
				cout << "Action canceled" << endl;
			}
			CLEAN
				break;
		}
		case '3':{
			char str[250];
			cout << "\n\n" << this->course->getDescription() << endl;
			cout << "\nPlease enter new course new description ";
			fflush(stdin);
			gets(str);
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->course->setDescription(str);
				cout << "Name successfully changed" << endl;
				isChanged = true;
			}
			else{
				cout << "Action canceled" << endl;
			}
			CLEAN
				break;
		}
		case '4':{
			cout << "\n\n" << this->course->getMaxStudents() << endl;
			cout << "\nPlease enter max student ";
			cin >> buffer;
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->course->setMaxStudents(atoi(buffer.c_str()));
				cout << "Email successfully changed" << endl;
				isChanged = true;
			}
			else{
				cout << "Action canceled" << endl;
			}
			CLEAN
				break;

		}

		case '5':{
			CourseAddPrerequisiteScreen * addPrerequisiteScreen = new CourseAddPrerequisiteScreen(this->course->getCourseId());
			addPrerequisiteScreen->show();
			//delete addPrerequisiteScreen;
			CLEAN
				break;

		}
		case '6':{
			CourseRemovePrerequisiteScreen *removePrerequisiteScreen = new CourseRemovePrerequisiteScreen(this->course->getCourseId());
			removePrerequisiteScreen->show();
			//delete removePrerequisiteScreen;
			CLEAN
				break;

		}
		case '7':{
			char str[250];
			cout << "\n\n" << this->course->getTeachingHours() << endl;
			cout << "\nPlease enter teaching hours ";
			fflush(stdin);
			gets(str);
			cout << "Save? y/n" << endl;
			answer = getchar();
			if (answer == 'y'){
				this->course->setTeachingHours(str);
				cout << "teaching hours successfully changed" << endl;
				isChanged = true;
			}
			else{
				cout << "Action canceled" << endl;
			}
			CLEAN
				break;

		}
		case '8':{
			char answer;
			cout << "Delete course " << this->course->getName() << endl;
			cout << "Are you sure? y/n" << endl;
			fflush(stdin);
			answer = getchar();

			if (answer == 'y'){
				this->course->deleteMe();
				cout << "Course deleted" << endl;
				condition = false;
			}
			else{
				cout << "Action canceled" << endl;
			}
			CLEAN
				break;

		}
		case 'B': { // Set to 'E' and go to case 'E'.
		case 'b':  // End the switch.

			condition = false;
			if (isChanged == true){
				cout << "\nDo you save changes? y/n" << endl;
				fflush(stdin);
				answer = getchar();
				if (answer == 'y'){
					this->saveCourseAndVerify();
					cout << "Change successfully changed" << endl;
				}
				else{
					cout << "Action canceled" << endl;
				}
			}
			break;
		}
		default:{
			cerr << "Wrong choice" << endl;

			break;
		}
				CLEAN;
		}
	} while (condition == true);
}


void CourseEditScreen::show()
{
	string choice;
	FileStorage *fs;
	bool condition = true;
	try{
		fs = new FileStorage();
		do { // Activate the menu until the user quits.
			lOGO
				vector<Course> courses = Course::getAllCourses(fs);
			cout << "Edit course screen" << endl;
			cout << "Courses list" << endl;
			cout << "Id\t" << "Name" << endl;
			for each (Course course in courses)
			{
				cout << course.getCourseId() << '\t' << course.getName() << endl << endl;

			}
			cout << "Enter course id or 'E' for exit" << endl;
			cin >> choice;
			if (choice == "e" || choice == "E") condition = false;
			else {
				this->course = Course::getCourseByCourseId(fs, atoi(choice.c_str()));
				if (course != NULL){
					this->editCourseMenu();

				}
				else {

					cerr << "No such course" << endl;
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



