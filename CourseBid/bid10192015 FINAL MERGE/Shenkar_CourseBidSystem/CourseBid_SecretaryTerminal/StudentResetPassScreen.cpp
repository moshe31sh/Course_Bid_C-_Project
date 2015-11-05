/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentResetPassScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "StudentResetPassScreen.h"

StudentResetPassScreen::StudentResetPassScreen(Student *stud) :student(stud){}

bool StudentResetPassScreen::resetStudentPass()
{
	cout << "Reset password screen" << endl;
	char answer;
	cout << "\nDo you want reset password? y/n" << endl;
	fflush(stdin);
	answer = getchar();
	if (answer == 'y'){
		system("cls");
		cout << "Password set to 0000" << endl;
		this->student->setPassword("0000");
		this->student->save(false);
		cout << "\nNew password successfully changed" << endl;
	}
	else{
		cout << "Action canceled" << endl;
		return false;
	}

	return true;
}

void StudentResetPassScreen::show()
{

}