/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** maincpp.cpp
** This is Registration Terminal main fucntion. It will run when you will enter
** the CourseBid from Registration Terminal.
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef REGISTRATION_TERMINAL
#define REGISTRATION_TERMINAL
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define BUFFER_SIZE 20
#define TRUE '1'
#define FALSE '0'

#include <iostream>
#include <cstdint>
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
#include "TerminalObj.h"
using namespace std;


void AuthenticationMenu();
void LogInMenu(IStorage *);
void Wellcome();


//REGISTRATION TERMINAL
int main(int argc, char* argv[])
{
	if (!TerminalObj::isTerminalLegal())
	{
		LockScreen lockScreen;
		lockScreen.show();
		exit(0);
	}

	Wellcome();
	cout << "\nWelcome to course bid - REGISTRATION TERMINAL Shenkar!!" << endl;
	cout << "\nFinish authentication to proceed\n" << endl;
	CLEAN

	
	UserLoginScreen login;
	login.show();
	

}

void Wellcome(){
	cout << "            #    # ###### #      #       ####  " << endl;
	cout << "            #    # #      #      #      #    # " << endl;
	cout << "            ###### #####  #      #      #    # " << endl;
	cout << "            #    # #      #      #      #    # " << endl;
	cout << "            #    # #      #      #      #    # " << endl;
	cout << "            #    # ###### ###### ######  ####  " << endl;
}

#endif REGISTRATION_TERMINAL