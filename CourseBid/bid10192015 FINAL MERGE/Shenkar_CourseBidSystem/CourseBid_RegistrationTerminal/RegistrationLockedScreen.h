/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** RegistrationLockedScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef REGISTRATIONLOCKEDSCREEN_H
#define REGISTRATIONLOCKEDSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;

#include "UILockScreen.h"

class RegistrationLockedScreen : public UILockScreen {
public:
	RegistrationLockedScreen(string message) :UILockScreen(message) {	}
	void show()
	{


	}
};

#endif REGISTRATIONLOCKEDSCREEN_H