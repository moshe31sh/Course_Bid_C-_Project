/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** TechnitianAssignitionResultsScreen.h
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#ifndef TECHNICIANASSIGNITIONRESULTSSCREEN_H
#define TECHNICIANASSIGNITIONRESULTSSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "Technician.h"
#include "UIListScreen.h"
#define checkFile "../checkfile.txt"

class TechnitianAssignitionResultsScreen : public UIListScreen {
private:
	Technician* technician;
	int** result;
	int _row, _col;
public:
	TechnitianAssignitionResultsScreen(int** result, int row, int col);
	void getMainTechnicianScreen();
	bool getResultFile();
	void show();
};

#endif TECHNICIANASSIGNITIONRESULTSSCREEN_H