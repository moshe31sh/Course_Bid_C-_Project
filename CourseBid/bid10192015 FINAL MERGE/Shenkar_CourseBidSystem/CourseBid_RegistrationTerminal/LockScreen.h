/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** InsertAssignitionFileScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#pragma once
#include "Terminal.h"

class LockScreen :public Terminal
{
private:
	bool isLock;
public:
	LockScreen();
	~LockScreen();
	void show();
	void releaseLock();
};