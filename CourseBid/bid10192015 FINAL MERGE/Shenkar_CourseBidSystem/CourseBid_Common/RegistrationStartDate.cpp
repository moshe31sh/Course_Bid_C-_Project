/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** RegistrationStartDate.cpp
** Registration date class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "RegistrationStartDate.h"

const string RegistrationStartDate::TAG_DATE = "date";

/*
** Consrtuctor.
*/
RegistrationStartDate::RegistrationStartDate(string dateString, IStorage * storage) : IdObj(0, storage)
{
	long serialS = storage->getNumberFromStringByTag(dateString, storage->TAG_SERIAL);
	if (serialS != this->SERIAL)
	{
		throw new exception(); //wrong serial
	}
	this->id = storage->getNumberFromStringByTag(dateString, storage->TAG_ID);
	this->date = storage->getStringFromStringByTag(dateString, TAG_DATE);
}

/*(Storage override)
** Creates record and saves to DB using IStorage from base IdObj.
** Recursiveness not works for this class, no matter if true or false - here only for inheritance.
*/
void RegistrationStartDate::save(bool recursive)
{
	//create the record
	string record = string("<" + storage->TAG_OBJ + ">");
	record += string("<" + storage->TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
	record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
	record += string("<" + TAG_DATE + "=\"" + date + "\">");
	record += string("<\\" + storage->TAG_OBJ + ">");
	storage->save(record);
}

/*(Storage override)
Delete record and save DB using IStorage from base IdObj.
*/
void RegistrationStartDate::deleteMe()
{
	storage->deleteObj(this->SERIAL, this->id);
	storage->save();
}

/*
** Static Method - Returns a vector of all RegistrationStartDates.
*/
vector<RegistrationStartDate> RegistrationStartDate::getAllRegistrationStartDates(IStorage * storage)
{
	vector<RegistrationStartDate> allRegistrationStartDates;
	vector<string> registrationStartDatesAsString = storage->getAll(RegistrationStartDate::SERIAL);
	for each (string registrationStartDateAsString in registrationStartDatesAsString)
	{
		RegistrationStartDate * registrationStartDate = new RegistrationStartDate(registrationStartDateAsString, storage);
		allRegistrationStartDates.push_back(*registrationStartDate);
	}
	return allRegistrationStartDates;
}

/*
** Converts a RegistrationStartDate to String.
** Used for Debug purposes only!
*/
string RegistrationStartDate::ToString()
{
	string regdate("Course: [objId:" + to_string(this->id));
	regdate += " serial: " + to_string(this->SERIAL);
	regdate += " date: " + this->date;
	regdate += "]";
	return regdate;
}