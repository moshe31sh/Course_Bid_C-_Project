/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UILockScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UILOCKSCREEN_H
#define UILOCKSCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UIScreen;
#include "UIScreen.h"

class UILockScreen: public UIScreen {
protected:
	string message;
public:
	UILockScreen() {	}

	UILockScreen(string message) : message(message) { }

	/* NON IMPLEMENTED UILOCKSCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UILockScreen() {}
};

#endif UILOCKSCREEN_H