/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIAddNewScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UIADDNEWSCREEN_H
#define UIADDNEWSCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UIScreen;
#include "UIScreen.h"

//NOTE: ABSTRACT CLASS
class UIAddNewScreen : public UIScreen {
public:
	UIAddNewScreen() {	}
	/* NON IMPLEMENTED UILOCKSCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UIAddNewScreen() {}
};

#endif UIADDNEWSCREEN_H