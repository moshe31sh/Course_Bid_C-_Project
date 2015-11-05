/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIListScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UILISTSCREEN_H
#define UILISTSCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UIScreen;
#include "UIScreen.h"

class UIListScreen : public UIScreen {
public:
	UIListScreen() { }
	/* NON IMPLEMENTED UILOCKSCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UIListScreen() {}
};

#endif UILISTSCREEN_H