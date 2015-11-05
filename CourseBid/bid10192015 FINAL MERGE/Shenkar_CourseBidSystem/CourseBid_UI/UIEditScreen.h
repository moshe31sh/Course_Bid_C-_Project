/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIEditScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UIEDITSCREEN_H
#define UIEDITSCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UIScreen;
#include "UIScreen.h"

//NOTE: ABSTRACT CLASS
class UIEditScreen : public UIScreen {
public:
	UIEditScreen() {	}
	/* NON IMPLEMENTED UILOCKSCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UIEditScreen() {}
};

#endif UIEDITSCREEN_H