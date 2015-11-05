/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UserLoginScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef USERLOGINSCREEN_H
#define USERLOGINSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;
#define BUFFER_SIZE 20

#include "UIScreen.h"
#include "Terminal.h"
#include "LockScreen.h"
#include "TechnicianMainScreen.h"
//#include "LockScreenUtils.h"
//#include "Student.h"

class UserLoginScreen : public Terminal {
private:

	//void checkLoginCounter();

public:
	UserLoginScreen();
	static int checkIfIdCorrect;
	static void initcheckIfIdCorrect();
	static void increasecheckIfIdCorrect();
	void technitionLoginRedirect(Technician * technician);
	bool userIdExist(long _userId);
	void show();
};

#endif USERLOGINSCREEN_H