/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** maincpp.cpp
** This is Secretary Terminal main fucntion. It will run when you will enter
** the CourseBid from Secretary Terminal.
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef SECRETARY_TERMINAL
#define SECRETARY_TERMINAL
#include <iostream>
#include <cstdint>

using namespace std;


#include "Course.h"
#include "FileStorage.h"
#include "SecretaryTerminal.h"
#include "UIErrorScreen.h"
#include "SecretaryMainScreen.h"

///SECRETARY TERMINAL
int main(int argc, char* argv[])
{
	//
	try{
		SecretaryMainScreen *SecretaryScreen = new SecretaryMainScreen();
		SecretaryScreen->show();
		delete SecretaryScreen;
	}
	catch (bad_alloc e)
	{
		cerr << e.what() << endl;
	}
}

#endif SECRETARY_TERMINAL