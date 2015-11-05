/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SetRegistrationStartDateScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef SETREGISTRATIONSTARTDATESCREEN_H
#define SETREGISTRATIONSTARTDATESCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include "FileStorage.h"
#include "RegistrationStartDate.h"

#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");
#define lOGO cout<<"\t\t\t----Course bid - Shenkar----\n"<<endl;

class SetRegistrationStartDateScreen : public UIScreen {
private:
	string startDate;

public:
	SetRegistrationStartDateScreen();

	//inline methods
	//void setStartDate(string startDate) { this->startDate = startDate;  }
	string getStartDate() { return startDate; }

	bool verifyAndSetStartDate(int ,int ,int );
	void show();
};

#endif SETREGISTRATIONSTARTDATESCREEN_H