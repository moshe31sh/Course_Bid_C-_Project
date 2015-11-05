/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** UserLoginScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include <string>
#include "Course.h"
#include "FileStorage.h"
#include "UIErrorScreen.h"
#include "UserLoginScreen.h"
#include "Student.h"
#include "Technician.h"
#include "CoursePair.h"
#include "PointDistributionScreen.h"
#include "AssignmentCalculator.h"
#include "FileStorage.h"
#include "StudentMainScreen.h"

// START OF static functions and fields
int UserLoginScreen::checkIfIdCorrect = 0;

UserLoginScreen::UserLoginScreen()
{
	UserLoginScreen::initcheckIfIdCorrect();
}

void UserLoginScreen::initcheckIfIdCorrect()
{
	UserLoginScreen::checkIfIdCorrect = 0;
}

void UserLoginScreen::increasecheckIfIdCorrect()
{
	UserLoginScreen::checkIfIdCorrect++;
}
// END OF static functions and fields

bool UserLoginScreen::userIdExist(long _userId){

	FileStorage fileStorage;
	vector<Student> students = Student::getAllStudents(&fileStorage);
	//check if the user id is exist
	for each(Student student in students)
	{
		if (student.getId() == _userId){ 

			if (student.getLocked()){ // student.getId() != admin id

				CLEAN
				cout << endl << " This user is Locked please address to the secretary office to unlock it" << endl << endl;
				
				return false;
			}
			return true;
		}
	}
	return false;
}

// admin auth
void UserLoginScreen::technitionLoginRedirect(Technician * technician){
	string adminPass;
	bool flag = false;
		do{
			cout << endl << "Admin Password: ";
			cin >> adminPass;

			if (technician->verifyPassword(adminPass)){
					cout << "Authenticate succeed" << endl;

					CLEAN
						
						TechnicianMainScreen *technicianMainScreen = new TechnicianMainScreen();
						technicianMainScreen->show();
						flag = true;
				}

				else {

					CLEAN

					cout <<endl << "       Wrong Admin Pass enter! try again" << endl;
			}

	} while(!flag);

}

void UserLoginScreen::show()
{//set counter of trys to 0
	UserLoginScreen::initcheckIfIdCorrect();
	bool exist = false;
	try{
		IStorage * fs = new FileStorage();
		string password;
		int userId;

		do { // Activate the menu until the user quits.
			lOGO

			cout << "Please enter the following details" << endl;
			cout << "\nId: ";

			while ((!(cin >> userId) || userId < 0)) // <<< note use of "short circuit" logical operation here
			{
				cout << "Bad input - try again: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
			}
			if (userIdExist(userId)){
				bool conditon = true;
				exist = true;
				do{
					cout << "Password: ";
					cin >> password;

					if (Student * stud = Student::getStudentByStudentId(fs, userId)){

						
						if (stud->verifyPassword(password)){
							cout << "Authenticate succeed" << endl;
							UserLoginScreen::initcheckIfIdCorrect();

							CLEAN
								StudentMainScreen *studentMainScreen = new StudentMainScreen(stud);

							studentMainScreen->setUser(stud);
							studentMainScreen->show();
							conditon = false;
						}

						else {
							cout << "Wrong enter! try again" << endl;
							UserLoginScreen::increasecheckIfIdCorrect();
							if (UserLoginScreen::checkIfIdCorrect >= 3){ //check if the attempts are above 3 times
								stud->setLocked(true);
								stud->save(false);
								conditon = false;
								cout << "\n\n***You enter Wrong password 3 times , user is locked***" << endl;
								CLEAN
							}

						}
					}
				} while (conditon);
			}
			else
			{
				FileStorage fileStorage;
				vector<Technician> technicians = Technician::getAllTechnician(&fileStorage);
				for each(Technician technician in technicians)
				{
					if (technician.getId() == userId)
					{
						exist = true;
						if (!technician.getLocked())
						{
							technitionLoginRedirect(&technician);
						}
						else{
							CLEAN
								cout << endl << " This user is Locked please address to the secretary office to unlock it" << endl << endl;

						}
					}
				}
			}
			 if (!exist){
				cout << "No such user id , try again" << endl;
				CLEAN
			}
		} while (true);
	}
	catch (bad_alloc e)
	{
		cerr << "bad_alloc caught: " << e.what() << '\n';
	}
}

