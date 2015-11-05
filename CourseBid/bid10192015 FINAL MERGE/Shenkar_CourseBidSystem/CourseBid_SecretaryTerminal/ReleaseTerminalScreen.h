/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** ReleaseTerminalScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef RELEASETERMINALSCREEN_H
#define RELEASETERMINALSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"

class ReleaseTerminalScreen : public UIScreen {
private:

public:
	ReleaseTerminalScreen() {	}

	bool releaseTerminals();
	void show();
};

#endif RELEASETERMINALSCREEN_H