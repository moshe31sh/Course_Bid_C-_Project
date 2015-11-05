/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** Technician.cpp
** Technician class
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "Technician.h"

/*
** Constructor.
*/
Technician::Technician(string technicianAsString, IStorage * storage):User(0, storage)
{
	long serialS = storage->getNumberFromStringByTag(technicianAsString, storage->TAG_SERIAL);
	if (serialS != this->SERIAL)
	{
		throw new exception(); //wrong serial
	}
	this->id = storage->getNumberFromStringByTag(technicianAsString, storage->TAG_ID);
	this->userId = storage->getNumberFromStringByTag(technicianAsString, TAG_USERID);
	this->firstName = storage->getStringFromStringByTag(technicianAsString, TAG_FIRSTNAME);
	this->lastName = storage->getStringFromStringByTag(technicianAsString, TAG_LASTNAME);
	this->email = storage->getStringFromStringByTag(technicianAsString, TAG_EMAIL);
	this->password = storage->getStringFromStringByTag(technicianAsString, TAG_PASSWORD);
	this->isLocked = storage->getNumberFromStringByTag(technicianAsString, TAG_ISLOCKED);
}

/* Static Method
** This function returns a technician by object id.
** If not found technician with given id - throws an exception.
*/
Technician Technician::getTechnicianById(IStorage * storage, int id)
{
	vector<Technician> allTechnicians;
	vector<string> techniciansAsString = storage->getAll(SERIAL);
	for each (string technicianAsString in techniciansAsString)
	{
		if (id == storage->getNumberFromStringByTag(technicianAsString, storage->TAG_ID))
		{
			Technician * tech = new Technician(technicianAsString, storage);
			return *tech;
		}
	}
	throw new exception(); //no technician found;
}

/* Static Method
** This function returns a technician by student id.
** If not found - returns NULL.
*/
Technician* Technician::getTechnicianByTechnicianId(IStorage * storage, int userId)
{
	vector<Technician> allTechnicians;
	vector<string> techniciansAsString = storage->getAll(SERIAL);
	for each (string technicianAsString in techniciansAsString)
	{
		if (userId == storage->getNumberFromStringByTag(technicianAsString, TAG_USERID))
		{
			Technician * tech = new Technician(technicianAsString, storage);
			return tech;
		}
	}
	return NULL;
}

/*(Storage override)
** Creates record and saves to DB using IStorage from base IdObj. 
** Recursiveness not works for this class, no matter if true or false - here only for inheritance.
*/
void Technician::save(bool recursive)
{
	//create the record
	string record = string("<" + storage->TAG_OBJ + ">");
	record += string("<" + storage->TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
	record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
	record += string("<" + TAG_USERID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << userId))->str() + "\">");
	record += string("<" + TAG_FIRSTNAME + "=\"" + firstName + "\">");
	record += string("<" + TAG_LASTNAME + "=\"" + lastName + "\">");
	record += string("<" + TAG_EMAIL + "=\"" + email + "\">");
	record += string("<" + TAG_PASSWORD + "=\"" + password + "\">");
	record += string("<" + TAG_ISLOCKED + "=\"" + static_cast<ostringstream*>(&(ostringstream() << isLocked))->str() + "\">");
	record += string("<\\" + storage->TAG_OBJ + ">");
	storage->save(record);
}

/*(Storage override)
Delete record and save DB using IStorage from base IdObj.
*/
void Technician::deleteMe()
{
	storage->deleteObj(this->SERIAL, this->id);
	storage->save();
}

/*
** Static Method - Returns a vector of all technicians.
*/
vector<Technician> Technician::getAllTechnician(IStorage * storage)
{
	vector<Technician> allTechnician;
	vector<string> techniciansAsString = storage->getAll(Technician::SERIAL);
	for each (string technicianAsString in techniciansAsString)
	{
		Technician * technician = new Technician(technicianAsString, storage);
		allTechnician.push_back(*technician);
	}
	return allTechnician;
}

/*
** Converts a Technician to String.
** Used for Debug purposes only!
*/
string Technician::ToString()
{
	string tech("String: [objId:" + to_string(this->id));
	tech += " serial: " + to_string(this->SERIAL);
	tech += " student: " + to_string(this->userId);
	tech += " name: " + this->firstName;
	tech += " surname: " + this->lastName;
	tech += " email: " + this->email;
	tech += " isLocked: " + to_string(this->isLocked);
	return tech;
}