/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UITerminal.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UITERMINAL_H
#define UITERMINAL_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <stack>		
using namespace std;

#include "UIScreen.h"

class UIScreen;

class UITerminal {
protected:
	UIScreen * currentScreen;
	stack<UIScreen> screenStack;
public:
	UITerminal() {	}

	/* IMPLEMENTED UITERMINAL METHODS - CAN BE OVERRIDED */
	virtual bool releaseTerminals()
	{
		return true;
	}

	/* NON IMPLEMENTED UITERMINAL METHODS - NEED OVERRIDE */
	virtual UIScreen& getScreen() = 0;
	virtual void pushLastScreen(UIScreen& screen) = 0;
	virtual UIScreen& popLastScreen() = 0;
	virtual void setCurrentScreen(UIScreen& screen) = 0;
	virtual ~UITerminal() {}
};

#endif UITERMINAL_H