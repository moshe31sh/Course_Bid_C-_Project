/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SystmTime.h
**
** Author: Maor Toubian,
** -------------------------------------------------------------------------*/
#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H

#include "RegistrationStartDate.h"
#include "FileStorage.h"
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

class SystemTime{

private:

	int initDay;
	int initMonth;
	int initYear;

public:

	/*
	** Consrtuctor.
	** getting the initial system date from storage and assign it to the SystemTime init date values
	*/
	SystemTime();

	/*
	** enum CourseBidTime.
	** PreRegistration, Registration, PostRegistration
	*/
	enum CourseBidTime{ PreRegistration, Registration, PostRegistration };

	/*
	** courseBidTime.
	** the current CourseBidTime time
	*/
	CourseBidTime courseBidTime;

	/*
	** getCourseBidTime.
	** getting the current time and checking if the day is before/at/after the initial registration date
	*/
	CourseBidTime getCourseBidTime()
	{
		time_t     now = time(0);
		struct tm  tstruct;
		string currentDate;
		localtime_s(&tstruct, &now);

		if ((tstruct.tm_mon+1) == this->initMonth){
			if (tstruct.tm_mday < initDay){ this->courseBidTime = PreRegistration; }
			else if (tstruct.tm_mday == initDay){ this->courseBidTime = Registration; }
			else{ courseBidTime = this->PostRegistration; }
		}
		else if ((tstruct.tm_mon+1) < this->initMonth){
			courseBidTime = this->PreRegistration;
		}
		else{
			courseBidTime = this->PostRegistration;
		}


		return courseBidTime;
	}

};

#endif SYSTEMTIME_H

