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
#ifndef INSERTASSIGNITIONFILESCREEN_H
#define INSERTASSIGNITIONFILESCREEN_H

#include <iostream>
#include <cstdint>	
#include <string>

using namespace std;

#include "UIScreen.h"
#include "Technician.h"
#define fname "../systemTest.txt"

class InsertAssignitionFileScreen :public UIScreen {
private:
	Technician * technician;
	int** result;
	int _row, _col;

public:
	InsertAssignitionFileScreen()	{ }
	void insertDistributionFile();
	void getDistributionResults();
	void show();
};

#endif INSERTASSIGNITIONFILESCREEN_H