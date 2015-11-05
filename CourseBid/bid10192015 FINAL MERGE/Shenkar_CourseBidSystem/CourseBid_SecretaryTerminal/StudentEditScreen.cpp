/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentEditScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "StudentEditScreen.h"

StudentEditScreen::StudentEditScreen()
{
	
}


/*
saveStudentAndVerify. Save changes to DB
*/
bool StudentEditScreen::saveStudentAndVerify()
{

	this->student->save(false);
	return true;
}


void StudentEditScreen::editStudentDetailes()
{
	char choice;
	bool condition = true;
	string buffer;
	bool isChanged = false;
	char answer;
	do { // Activate the menu until the user quits.
		system("cls");
		lOGO
			cout << "\nYour options are:\n\n";
		cout << "Please enter your choice:" << endl;
		cout << "1 - Print student details" << endl;
		cout << "2 - Edit name" << endl;
		cout << "3 - Edit last name" << endl;
		cout << "4 - Edit email" << endl;
		cout << "B - Back" << endl;
		fflush(stdin);
		choice = getchar();
		system("cls");
		switch (choice)
		{
		case '1':
		{
			lOGO
				cout << "Student Details" << endl;
			cout << "Id\t\t" << "Name\t\t" << "LastName\t\t" << "Lock" << endl;
			cout << this->student->getId() << "  \t\t" << this->student->getFirstName() << " \t\t" << this->student->getLastName() << "\t\t\t  " << this->student->getLocked() << endl;
			cout << "\nCompleted  Courses" << endl;

			this->PrintSpesificCourse(this->student->getCompletedCourses());
			cout << "\nAssigned Courses" << endl;
			this->PrintSpesificCourse(this->student->getAssignedCourse());
			cout << "\nDesired Courses" << endl;
			this->PrintSpesificCourse(this->student->getDesiredCourses());
			CLEAN
				break;
		}
		case '2':{
			cout << "\n\n" << this->student->getFirstName() << endl;
			cout << "\nPlease enter new name ";
			cin >> buffer;
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->student->setFirstName(buffer);
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
			cout << "\n\n" << this->student->getLastName() << endl;
			cout << "\nPlease enter new last name ";
			cin >> buffer;
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->student->setLastName(buffer);
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
			cout << "\n\n" << this->student->getEmail() << endl;
			cout << "\nPlease enter new email ";
			cin >> buffer;
			cout << "Save? y/n" << endl;
			fflush(stdin);
			answer = getchar();
			if (answer == 'y'){
				this->student->setEmail(buffer);
				cout << "Email successfully changed" << endl;
				isChanged = true;
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
					this->saveStudentAndVerify();
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
			CLEAN;
			break;
		}
		}
	} while (condition == true);

}


bool StudentEditScreen::deleteStudent()
{
	this->student->deleteMe();

	return true;
}

bool StudentEditScreen::addCompletedCourse()
{


	return true;
}

bool StudentEditScreen::removeCompletedCourse()
{


	return true;
}


/*
PrintSpesificCourse(vector<Course*> courseToPrint. Get specific course vector to print 
*/
void StudentEditScreen::PrintSpesificCourse(vector<Course*> courseToPrint){

	int index = 0;

	if (courseToPrint.size() != 0){
		for each (Course *course in courseToPrint)
		{
			index++;
			cout << "[" << index << "] " << course->getName() << endl;

		}
	}
	else cerr << "No such course" << endl;

}


/*
PrintSpesificCourse(vector<Course*> courseToPrint. return specific course from vector 
*/
Course *StudentEditScreen::getChosenCourse(vector<Course*> courseToPrint){
	vector<Course*> courses = courseToPrint;
	string choice;
	cout << "Courses list" << endl;
	cout << "Id\t" << "Name" << endl;
	for each (Course *course in courses)
	{
		cout << course->getCourseId() << '\t' << course->getName() << endl << endl;

	}
	cout << "Enter course id or 'E' for exit" << endl;
	cin >> choice;
	if (choice == "e" || choice == "E") return NULL;
	else {
		Course * course = Course::getCourseByCourseId(new FileStorage(), atoi(choice.c_str()));
		if (course != NULL){
			return course;
		}
	}
	cerr << "No such course" << endl;
	return NULL;
}



void StudentEditScreen::show()
{
	bool condition = true;
	string choice;
	do { // Activate the menu until the user quits.
		lOGO
			try{
			FileStorage *fs = new FileStorage();
			vector<Student> students = Student::getAllStudents(fs);
			vector<Course > allCourses = Course::getAllCourses(fs);
			vector<Course *> temp;
			temp.resize(allCourses.size());
			for (int i = 0; i < allCourses.size(); i++){
				temp[i] = &allCourses[i];
			}
			cout << "Id\t\t" << "Name\t\t" << "LastName\t\t" << "Lock" << endl;

			for each (Student student in students)
			{
				cout << student.getId() << "  \t\t" << student.getFirstName() << " \t\t" << student.getLastName() << "\t\t\t  " << student.getLocked() << endl;
			}

			cout << "\n\nPlease enter student id or e to exit" << endl;
			cin >> choice;
			if (choice == "e" || choice == "E") condition = false;
			else {
				this->student = Student::getStudentByStudentId(new FileStorage(), atoi(choice.c_str()));
				if (student != NULL){
					long id = atoi(choice.c_str());
					char choice;

					do { // Activate the menu until the user quits.
						system("cls");
						lOGO
							cout << "\nEditing: " << this->student->getFirstName() << " " << this->student->getLastName() << endl;
						if (this->student->getLocked()){
							cout << "\n**** Student is LOCK ****" << endl;
						}
						cout << "\nYour options are:\n\n";
						cout << "Please enter your choice:" << endl;
						cout << "1 - Edit student details" << endl;
						cout << "2 - Delete student" << endl;
						cout << "3 - Add Completed Course" << endl;
						cout << "4 - remove Completed Course" << endl;
						cout << "5 - Add assigned Course" << endl;
						cout << "6 - Remove assigned Course" << endl;
						cout << "7 - Remove Desired Course" << endl;
						cout << "8 - Lock / Unlock student" << endl;
						cout << "9 - Reset password" << endl;
						cout << "B - Back" << endl;
						fflush(stdin);
						choice = getchar();
						system("cls");

						switch (choice)
						{
						case '1':
						{
							this->editStudentDetailes();
							CLEAN
								break;
						}
						case '2':{
							char answer;
							cout << "\nDo you save changes? y/n" << endl;
							fflush(stdin);
							answer = getchar();
							if (answer == 'y'){
								this->deleteStudent();

								condition = false;
								cout << "Student deleted" << endl;
							}
							else{
								cout << "Action canceled" << endl;
							}

							CLEAN
								break;
						}
						case '3':{
							string choice;
							bool condition = true;
							try{
								do { // Activate the menu until the user quits.
									lOGO
										cout << "Add completed course screen" << endl;

									temp.resize(allCourses.size());
									for (int i = 0; i < allCourses.size(); i++){
										temp[i] = &allCourses[i];
									}
									Course * course = this->getChosenCourse(temp);
									if (course != NULL){
										StudentAddCompletedScreen *studentAddCompletedScreen = new StudentAddCompletedScreen(this->student, course);
										if (studentAddCompletedScreen->addCompletedCourse() == true){
											condition = false;
											CLEAN
										}
									}
									else
									{
										condition = false;
									}


									CLEAN


								} while (condition);
							}
							catch (bad_alloc e){
								cerr << e.what() << endl;
							}
							CLEAN
								break;
						}
						case '4':{
							string choice;
							bool condition = true;
							try{
								do { // Activate the menu until the user quits.
									lOGO
										cout << "Remove completed course screen" << endl;

									Course * course = this->getChosenCourse(this->student->getCompletedCourses());
									if (course != NULL){
										StudentRemoveCompletedScreen *studentRemoveCompletedScreen = new StudentRemoveCompletedScreen(this->student, course);
										if (studentRemoveCompletedScreen->removeCompletedCourse() == true){
											condition = false;
											CLEAN
										}
									}
									else
									{
										condition = false;
									}


									CLEAN


								} while (condition);
							}
							catch (bad_alloc e){
								cerr << e.what() << endl;
							}
							CLEAN
								break;

						}
						case '5':{
							string choice;
							bool condition = true;
							try{
								do { // Activate the menu until the user quits.
									lOGO
										cout << "Add assigned course screen" << endl;

									Course * course = this->getChosenCourse(temp);
									if (course != NULL){
										StudentAddAssignedCourseScreen *studentAddAssignedCourseScreen = new StudentAddAssignedCourseScreen(this->student, course);
										if (studentAddAssignedCourseScreen->addAssignedCourse() == true){
											condition = false;
											CLEAN
										}
									}
									else
									{
										condition = false;
									}


									CLEAN


								} while (condition);
							}
							catch (bad_alloc e){
								cerr << e.what() << endl;
							}
							CLEAN
								break;
						}
						case '6':{
							string choice;
							bool condition = true;
							try{
								do { // Activate the menu until the user quits.
									lOGO
										cout << "Remove assigned course screen" << endl;
									Course * course = this->getChosenCourse(student->getAssignedCourse());
									if (course != NULL){
										StudentRemoveAssignedCourseScreen *studentRemoveAssignedCourseScreen = new StudentRemoveAssignedCourseScreen(this->student, course);
										if (studentRemoveAssignedCourseScreen->removeAssignedCourse() == true){
											condition = false;
											CLEAN
										}
									}
									else
									{
										condition = false;
									}


									CLEAN


								} while (condition);
							}
							catch (bad_alloc e){
								cerr << e.what() << endl;
							}
							CLEAN
								break;
						}

						case '7':{
							string choice;
							bool condition = true;
							try{
								do { // Activate the menu until the user quits.
									lOGO
										cout << "Remove desired course screen" << endl;
									Course * course = this->getChosenCourse(this->student->getDesiredCourses());
									if (course != NULL){
										StudentRemoveDesiredCourseScreen *studentRemoveDesiredCourseScreen = new StudentRemoveDesiredCourseScreen(this->student, course);
										if (studentRemoveDesiredCourseScreen->removeDesiredCourse() == true){
											condition = false;
											CLEAN
										}
									}
									else
									{
										condition = false;
									}


									CLEAN


								} while (condition);
							}
							catch (bad_alloc e){
								cerr << e.what() << endl;
							}
							CLEAN
								break;
						}
						case '8':{
							StudentUnlockScreen *studentUnlockScreen = new StudentUnlockScreen(this->student);
							studentUnlockScreen->show();
							CLEAN
								break;
						}
						case '9':{
							StudentResetPassScreen *studentResetPassScreen = new StudentResetPassScreen(this->student);
							studentResetPassScreen->resetStudentPass();
							CLEAN
								break;
						}
						case 'b': { // Set to 'E' and go to case 'E'.
						case 'B':  // End the switch.

							condition = false;
							break;
						}
						default:{
							cerr << "Wrong choice" << endl;
							CLEAN;
							break;
						}
						}
					} while (condition == true);
					system("cls");
				}
				else {
					cout << "No such student , try again" << endl;
					CLEAN
				}
			}
		}
		catch (bad_alloc e){
			cerr << e.what();
		}

	} while (condition);

}





