/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UISCREEN_H
#define UISCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UITerminal;

class UIScreen {
protected:
	UITerminal* terminal;
public:
	UIScreen() {	}
	/* NON IMPLEMENTED UISCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UIScreen() {}
};


#endif UISCREEN_H