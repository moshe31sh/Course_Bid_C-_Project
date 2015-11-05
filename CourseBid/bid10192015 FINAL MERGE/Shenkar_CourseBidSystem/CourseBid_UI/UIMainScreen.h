/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** UIMainScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UIMAINSCREEN_H
#define UIMAINSCREEN_H
#define CLEAN cout<<"\nPlease press any key to continue"<<endl;	fflush(stdin);	getchar();	system("cls");

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class UIScreen;
#include "UIScreen.h"

class UIMainScreen : public UIScreen {
public:
	UIMainScreen() {	}
	/* NON IMPLEMENTED UILOCKSCREEN METHODS - NEED OVERRIDE */
	virtual void show() = 0;
	virtual ~UIMainScreen() {}
};

#endif UIMAINSCREEN_H