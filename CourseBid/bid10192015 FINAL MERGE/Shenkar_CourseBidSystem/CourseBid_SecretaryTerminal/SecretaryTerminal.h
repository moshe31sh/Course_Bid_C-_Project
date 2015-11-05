/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SecretaryTerminal.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef SECRETARY_TERMINAL_H
#define SECRETARY_TERMINAL_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <stack>		
using namespace std;

#include "UITerminal.h"

class UIScreen;

class SecretaryTerminal : public UITerminal{
public:
	SecretaryTerminal();

	void getScreenWithParams(long id)
	{
		


	};

	//override parent
	UIScreen& getScreen();
	//override parent
	void pushLastScreen(UIScreen& screen);
	//override parent
	UIScreen& popLastScreen();
	//override parent
	void setCurrentScreen(UIScreen& screen);
	//override parent
	bool releaseTerminals();
};

#endif SECRETARY_TERMINAL_H