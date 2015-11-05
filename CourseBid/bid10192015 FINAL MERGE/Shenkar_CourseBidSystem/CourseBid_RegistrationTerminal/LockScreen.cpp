/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** InsertAssignitionFileScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "LockScreen.h"


LockScreen::LockScreen()
{
	this->isLock = true;
}


LockScreen::~LockScreen()
{
}


void LockScreen::releaseLock(){
	this->isLock = false;
}

void LockScreen::show(){
	cout << "		 #####" << endl;
	cout << "		 #     #  ####  #####  ###### ###### #    #" << endl;
	cout << "		 #       #    # #    # #      #      ##   #" << endl;
	cout << "		  #####  #      #    # #####  #####  # #  #" << endl;
	cout << "		      #  #      #####  #      #      #  # #" << endl;
	cout << "		 #    #  #    # #   #  #      #      #   ##" << endl;
	cout << "		 #####    ####  #    # ###### ###### #    #" << endl;
	cout << endl;
	cout << "                         ### " << endl;
	cout << "                          #   ####     " << endl;
	cout << "                          #  #            " << endl;
	cout << "                          #   ####         " << endl;
	cout << "                          #       #        " << endl;
	cout << "                          #  #    #        " << endl;
	cout << "                         ###  ####          " << endl;

	cout << "		 #                                          " << endl;
	cout << "		 #        ####   ####  #    # ###### #####  " << endl;
	cout << "		 #       #    # #    # #   #  #      #    # " << endl;
	cout << "		 #       #    # #      ####   #####  #    # " << endl;
	cout << "		 #       #    # #      #  #   #      #    # " << endl;
	cout << "		 #       #    # #    # #   #  #      #    # " << endl;
	cout << "		 #######  ####   ####  #    # ###### #####  " << endl;

	do{

	} while (isLock == true);
}