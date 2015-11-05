/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** RegistrationStartDate.h
** Registration date class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef REGISTRATIONSTARTDATE_H
#define REGISTRATIONSTARTDATE_H

#include <iostream>
#include <cstdint>	
#include <sstream>
#include <string>
using namespace std;

#include "IdObj.h"
class RegistrationStartDate : public IdObj {
private:
	//serial number for all objects RegistrationStartDate
	static const int SERIAL = 4;
	string date;
public:
	/*
	**STORAGE TAGS
	*/
	static const string TAG_DATE;

	/*
	** Consrtuctor.
	*/
	RegistrationStartDate(int id, IStorage * storage) : IdObj(id, storage) {}

	/*
	** Consrtuctor.
	*/
	RegistrationStartDate(string dateString, IStorage * storage);

	/*
	** Static Method - Returns a vector of all courses.
	*/
	vector<RegistrationStartDate> getAllRegistrationStartDates(IStorage * storage);

	/*
	** get/set inline methods
	*/
	void setDate(string date)	{ this->date = date; }
	string getDate()			{ return date; }

	/*(Storage override)
	** Creates record and saves to DB using IStorage from base IdObj.
	** Recursiveness not works for this class, no matter if true or false - here only for inheritance.
	*/
	virtual void save(bool recursive);

	/*(Storage override)
	Delete record and save DB using IStorage from base IdObj.
	*/
	virtual void deleteMe();

	/*
	** Converts a RegistrationStartDate to String.
	** Used for Debug purposes only!
	*/
	string ToString();
};

#endif REGISTRATIONSTARTDATE_H