/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** RegistrationTerminal.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef REGISTRATIONTERMINAL_H
#define REGISTRATIONTERMINAL_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UITerminal.h"
#include "UIScreen.h"
#include "User.h"

class RegistrationTerminal : UITerminal {
private:
	User * user;
	bool isLocked;
public:
	RegistrationTerminal() { }

	//void setCurrentUser(User * user); <<-do not forget
	void logOutUser();
	void lockTerminal();
	
	/*OVERRIDE FROM PARRENT*/
	UIScreen& getScreen();
	void pushLastScreen(UIScreen& screen);
	UIScreen& popLastScreen();
	void setCurrentScreen(UIScreen& screen);
};

#endif REGISTRATIONTERMINAL_H