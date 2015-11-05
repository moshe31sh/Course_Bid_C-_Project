/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SystmTime.cpp
**
** Author: Maor Toubian,
** -------------------------------------------------------------------------*/
#include "SystemTime.h"

/*
** Consrtuctor.
** getting the initial system date from storage and assign it to the SystemTime init date values
*/
SystemTime::SystemTime()
{
	this->courseBidTime = PreRegistration;

	// for real time use of db init date
	//FileStorage * fs = new FileStorage();
	//RegistrationStartDate rsd(4, fs);
	//vector<RegistrationStartDate> vec = rsd.getAllRegistrationStartDates(fs);
	//string date = vec[0].getDate();

	//----for simulation times----//

	//postregistration time
	string date = "01102015";

	//registration time
	//string date = "18102015";

	//preregistration time
	//string date = "31102015";

	this->initDay = atoi(date.substr(0, 2).c_str());
	this->initMonth = atoi(date.substr(2, 2).c_str());
	this->initYear = atoi(date.substr(4).c_str());
}
