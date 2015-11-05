/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentMainScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "StudentMainScreen.h"
#include "PointDistributionScreen.h"
#include "InsertAssignitionFileScreen.h"

#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define BUFFER_SIZE 20
#define TRUE '1'
#define FALSE '0'

void StudentMainScreen::logOut()
{
	this->Log = false;
	
}

void StudentMainScreen::getAssignitionResultsScreen()
{
	CLEAN
		lOGO
		cout << " \t\t\t Assigned Courses" << endl << endl;
	vector<Course *> assCourses = this->student->getAssignedCourse();

	if (assCourses.size() == 0) {
		cout << "There are no assigned courses for you" << endl;
	}
	else
	for each (Course * course in assCourses)
	{
		cout << " NAME " << course->getName() << "  ID " << course->getId() << endl;

	}

}

void StudentMainScreen::getPointDistributionScreen()
{
	try{
		PointDistributionScreen * pointDistributionScreen = new PointDistributionScreen();
		pointDistributionScreen->setStudent(this->student);
		FileStorage fileStorage;
		pointDistributionScreen->setCourses(Course::getAllCourses(&fileStorage));
		CLEAN
			pointDistributionScreen->show();
		if (pointDistributionScreen != NULL) delete pointDistributionScreen;
	}
	catch (bad_alloc e){
		cerr << e.what();
	}
}

//student details
void StudentMainScreen::studentDetails()
{
	vector<Course *> comCourses = this->student->getCompletedCourses();
	vector<Course *> desCourses = this->student->getDesiredCourses();

	cout << " Student details" << endl << endl;
	cout << " Name : " << this->student->getFirstName() << " " << this->student->getLastName() << endl;
	cout << " ID : " << this->student->getId() << endl;
	cout << " Email : " << this->student->getEmail() << endl;
	cout << " Points : " << this->student->getPoints() << endl;
	cout << " Completed Courses : ";
	if (comCourses.size() == 0){
		cout << " No Completed Courses";
	}
	else{
		for each (Course * course in comCourses)
		{
			cout << "  " << course->getName() << " | ";
		}
	}
	cout << endl;
	cout << " Desired Courses : ";
	if (desCourses.size() == 0){
		cout << " No Desired Courses";
	}
	else{
		for each (Course * descourse in desCourses)
		{
			cout << "  " << descourse->getName() << " | ";
		}
	}
	cout << endl;
}

//show
void StudentMainScreen::show()
{
	//switch case for pre/post and registration times - not the same menu in each time
	SystemTime systemtime = SystemTime();
	switch (systemtime.getCourseBidTime())
	{
	case 0:
		cout << "PreRegistration" << endl;
		this->preRegistrationMenu();
		break;
	case 1:
		cout << "Registration" << endl;
		this->registrationMenu();
		
		break;
	case 2:
		cout << "PostRegistration" << endl;
		this->postRegistrationMenu();
		
		break;
	}
	
}

// empty pre 
void StudentMainScreen::preRegistrationMenu(){

}


void StudentMainScreen::registrationMenu(){
	char choice;
	SystemTime systemtime = SystemTime();
	do { // Activate the menu until the user quits.
		this->changeScreen = systemtime.getCourseBidTime();
		cout << "Welcome to course bid - STUDENT TERMINAL Shenkar!!" << endl;
		lOGO
		
		cout << "Hello " << this->student->getFirstName() << " " << this->student->getLastName() << endl;
		cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Print course list" << endl;
		cout << "2 - Assign points to course " << endl;
		cout << "3 - Student Details " << endl;
		cout << "E - Logout" << endl;
		choice = getchar();
		system("cls");
		switch (choice)
		{
		case '1':
		{
					this->printCourseList();
					CLEAN
						break;
		}
		case '2':{
					 this->getPointDistributionScreen();
					 CLEAN
						 break;
		}
		case '3':{
					 this->studentDetails();
					 CLEAN
						 break;
		}


		case 'E': { // Set to 'E' and go to case 'E'.
		case 'e':  // End the switch.


			this->logOut();
			break;
		}
		default:{
					cerr << "Wrong choice" << endl;
					CLEAN;
		}
		}//changes screen if the logged out or time as changed
	} while (this->Log &&  this->changeScreen == SystemTime::CourseBidTime::Registration);
	cout << "HAVE A NICE DAY!\n\n";
	CLEAN
}

//postRegistrationMenu
void StudentMainScreen::postRegistrationMenu(){
	char choice;
	SystemTime systemtime = SystemTime();
	do { // Activate the menu until the user quits.
		this->changeScreen = systemtime.getCourseBidTime();
		cout << "Welcome to course bid - STUDENT TERMINAL Shenkar!!" << endl;
		lOGO
		cout << "Hello " << this->student->getFirstName() << " " << this->student->getLastName() << endl;

		cout << "\nYour options are:\n\n";
		cout << "1 - Student Details " << endl;
		cout << "2 - Assingition Results " << endl;
		cout << "E - Logout" << endl;
		choice = getchar();
		system("cls");
		switch (choice)
		{
		case '1':{
					 this->studentDetails();
					 CLEAN
						 break;
		}
		case '2':{
					 this->getAssignitionResultsScreen();
					 CLEAN
						 break;

		}

		case 'E': { // Set to 'E' and go to case 'E'.
		case 'e':  // End the switch.
			this->logOut();
			break;
		}
		default:{
					cerr << "Wrong choice" << endl;
					CLEAN;
		}
		}
	} while (this->Log && this->changeScreen == SystemTime::CourseBidTime::PostRegistration);
	cout << "HAVE A NICE DAY!\n\n";
	CLEAN
}

//print course list details
void StudentMainScreen::printCourseList(){

	char c;
	string choice;
	bool condition = true;
	FileStorage filestorage;
	vector<Course> courses = Course::getAllCourses(&filestorage);

	lOGO
		cout << "                                Course list\n" << endl;
	cout << " ID\t" << "NAME\t" << "DESCRIPTION\t\t" << "HOURS" << endl;

	for each (Course course in courses)
	{
		cout << " " << course.getCourseId() << "\t" << course.getName() << "\t" << course.getDescription() << "\t" << course.getTeachingHours() << endl;
	}

	do { // Activate the menu until the user quits.

		c = getchar();
		cout << " \n Enter a valid course id  in order to review its prerequisite courses or 'E' for exit" << endl;
		cin >> choice;
		if (choice == "e" || choice == "E") condition = false;
		else {
			//get Preequisite for each course
			for each (Course course in courses)
			{
				if (course.getCourseId() == atoi(choice.c_str())) {
					vector<Course> preCourses = course.getPreequisiteCourses();
					if (preCourses.size() == 0) {
						cout << "There are no Prerequisite Courses for this course " << endl;
					}
					else{
						for each (Course perCourse  in preCourses)
						{
							cout << " Prerequisite Courses : " << "Course Name : " << perCourse.getName() << "\tCourse Id : " << perCourse.getId() << endl;

						}
					}
				}

			}
		}
	} while (condition);
}

