/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIErrorScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UIERRORSCREEN_H
#define UIERRORSCREEN_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
using namespace std;

class UIScreen;
#include "UIScreen.h"

class UIErrorScreen : public UIScreen {
private:
	string message;
public:
	UIErrorScreen() {	}
	UIErrorScreen(string message) : message(message) { }

	void show() 
	{
		system("CLS");
		cout << "************************************************************" << endl;
		cout << "************************ERROR SCREEN************************" << endl;
		cout << "************************************************************" << endl;
		cout << endl;
		cout << message <<endl;
		cout << endl;
		cout << "**********************************************************" << endl;
	};
};

#endif UIERRORSCREEN_H