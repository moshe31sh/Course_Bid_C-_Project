/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** TechnicianMainScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef TECHNICIANMAINSCREEN_H
#define TECHNICIANMAINSCREEN_H

#include <iostream>
#include <cstdint>	
#include <string.h>
using namespace std;
#include "UIMainScreen.h"
#include "Technician.h"
#include "Student.h"
#include "Terminal.h"
#include "TerminalObj.h"
#include "LockScreen.h"
#define LOCK true
#define UNLOCK false

class TechnicianMainScreen :public Terminal {
private:

	bool Log;

public:
	TechnicianMainScreen();
	void logOut();
	void lockTerminal(bool);
	void show();

};

#endif TECHNICIANMAINSCREEN_H