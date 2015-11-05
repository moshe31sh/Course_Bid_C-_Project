/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** PointDistributionScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "PointDistributionScreen.h"
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define BUFFER_SIZE 20
#define TRUE '1'
#define FALSE '0'

PointDistributionScreen::PointDistributionScreen()
{
	filestorage = new FileStorage();
	student = NULL;
}

PointDistributionScreen:: ~PointDistributionScreen()
{
	if (filestorage != NULL) delete filestorage;

}


// check if the course is not in the completed and not in the desired
bool PointDistributionScreen::isCoursetaken(long _courseId , ComDes _ComDes)
{
	int counter = 0;
	bool match = false;
	vector<Course *> courses;
	if (_ComDes == Desired){
		 courses = this->student->getDesiredCourses();
	}
	else if (_ComDes == Completed){
		courses = this->student->getCompletedCourses();
	}
	if (courses.size() == 0)
	{
		return false;
	}
	for each (Course * studentCourse in courses)
	{
		counter++;
		if (studentCourse->getCourseId() == _courseId)
		{
			match = true;
		}
	}
	if (courses.size() <= counter)

		return match;
}


//assign points to desired courses
void PointDistributionScreen::setDesiredCoursePoints()
{
	string courseChoice, pointsChoice;
	bool condition = true;
	vector<Course> courses = Course::getAllCourses(filestorage);
	vector<Course *> completedCourses = this->student->getCompletedCourses();

	do { // Activate the menu until the user quits.
		bool isMatching = false;
		bool vaildCourse = false;

		int preqCounter = 0;
		this->printCourseListForStudent();

		cout << "Enter course id or 'E' for exit" << endl;
		cin >> courseChoice;

		if (courseChoice == "e" || courseChoice == "E")
		{
			condition = false;
		}

		else {
			//check if the preequisite of the desired course is a part of the student completed courses
			if (Course *chosenCourse = Course::getCourseByCourseId(filestorage, atoi(courseChoice.c_str()))){
				vector<Course> preequisiteCoursesForCourse = chosenCourse->getPreequisiteCourses();
				for each (Course prqCourse in preequisiteCoursesForCourse)
				{
					for (int i = 0; i < completedCourses.size(); i++){
						if (prqCourse.getCourseId() == completedCourses[i]->getCourseId())
						{
							preqCounter++;
						}
					}
				}
				// if the student can chose this course according to course preequisite courses
				if ((preequisiteCoursesForCourse.size() == 0) || (preequisiteCoursesForCourse.size() == preqCounter) && vaildCourse)
				{
					isMatching = true;
				}
				if (chosenCourse != NULL && isMatching)
				{
					long id = atoi(courseChoice.c_str());

					if ((isCoursetaken(id, Desired)) || (isCoursetaken(id, Completed)))
					{
						cout << "You cannot choose this course again!" << endl;
						CLEAN
					}
					cout << "You have " << this->student->getPoints() << " amount of points\nPlease enter the amount of point you are willing to allocate from 1 to " << this->student->getPoints() << endl;
					cin >> pointsChoice;
					 
					// check if the the choice is an integer.
					float checkIfWhole = atof(pointsChoice.c_str());
					if (floorf(checkIfWhole) != (checkIfWhole)){
						cout << "Please enter a whole number" << endl;
						CLEAN
					}
					// assign points to course and from 1 to student max points
					else if (atoi(pointsChoice.c_str()) >= 1 && atoi(pointsChoice.c_str()) <= this->student->getPoints())
					{
						this->student->setPoints(this->student->getPoints() - atoi(pointsChoice.c_str()));
						this->student->addDesiredCourse(id, atoi(pointsChoice.c_str()));
						this->student->save(false);
						CLEAN
					}
					else {
						cout << "Wrong enter" << endl;
						CLEAN
					}
				}
				else if (!isMatching)
				{
					cout << "You didnt complete the preequisite courses for the following course " << endl;
					CLEAN
				}
				else if (!vaildCourse)
				{
					cout << "Wrong enter" << endl;
					CLEAN
				}
				else
				{
					cout << "No such course, try again" << endl;
					CLEAN
				}
			}
			else
			{
				cout << "No such course exist" << endl;
				CLEAN
			}
		}
	} while (condition);
}

// show screen
void PointDistributionScreen::show()
{
	fflush(stdin);
	char choice;
	do { // Activate the menu until the user quits.
		lOGO
		cout << "Hello " << this->student->getFirstName() << " " << this->student->getLastName() << endl;
		cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Set Desired Course Points" << endl;
		cout << "B - Back" << endl;
		choice = getchar();
		system("cls");

		switch (choice)
		{
		case '1':
		{
			setDesiredCoursePoints();
			CLEAN
			break;	
		}
		case 'b': { // Set to 'E' and go to case 'E'.
		case 'B':  // End the switch.

			choice = 'B';
			break;
		}
		default:{

			cerr << "Wrong choice" << endl;
			CLEAN;
			break;
		}
		}
	} while (choice != 'B');

}
// set student to the pointDistribution screen
void PointDistributionScreen::setStudent(Student* student){
	if (student != NULL) this->student = student;
	else throw new exception_ptr;
}

// set course to the pointDistribution screen
void PointDistributionScreen::setCourses(vector<Course> courses){
	this->courses.resize(courses.size());
	for (unsigned i = 0; i < courses.size(); i++)
	{
		(this->courses[i]) = &courses[i];
	}
}

//prints only courses that the student hasnt completed
void PointDistributionScreen::printCourseListForStudent() 
{
	lOGO
		vector<Course> allCourses = Course::getAllCourses(filestorage);
	cout << "                                    Course list\n" << endl;
	cout << "Id\t" << "Name" << endl;
	vector<Course*> selectedCourses = student->getDesiredCourses();
	map<long, bool> map_desired_courses;

	//check if the the selcted courses for desired is not in the completed courses!
	for each (Course course in allCourses)
	{
		for each (Course * selected in selectedCourses)
		{
			if (map_desired_courses.find(selected->getCourseId()) == map_desired_courses.end()) // not exist
			{
				map_desired_courses.insert(std::pair<long, bool>(selected->getCourseId(), true));
			}
		}
	}

	for each(Course course in allCourses) {
		if (map_desired_courses.find(course.getCourseId()) == map_desired_courses.end())
		{
			cout << course.getCourseId() << '\t' << course.getName() << endl << endl; // courseList excluding the completed course
		}
	}
}