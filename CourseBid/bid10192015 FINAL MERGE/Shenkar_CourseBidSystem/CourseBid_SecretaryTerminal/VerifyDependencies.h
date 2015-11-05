/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** VerifyDependencies.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef VERIFYDEPENDENCIES_H
#define VERIFYDEPENDENCIES_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "Course.h"

class VerifyDependencies {
private:

public:
	VerifyDependencies() {	}
	static bool verify(Course* courseToDelete);
};

#endif VERIFYDEPENDENCIES_H