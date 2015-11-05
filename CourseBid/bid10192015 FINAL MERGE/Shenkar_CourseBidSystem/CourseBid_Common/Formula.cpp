/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** Formula.cpp
** Formula class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "Formula.h"

const string Formula::TAG_FORMULA = "formula";

/*
** Consrtuctor.
** NOTE: formulaAsString is full string as stored in DB (not only formula string itself)
*/
Formula::Formula(string formulaAsString, IStorage * storage) : IdObj(0, storage)
{
	long serialS = storage->getNumberFromStringByTag(formulaAsString, storage->TAG_SERIAL);
	if (serialS != this->SERIAL)
	{
		throw new exception(); //wrong serial
	}
	this->id = storage->getNumberFromStringByTag(formulaAsString, storage->TAG_ID);
	this->formula = storage->getStringFromStringByTag(formulaAsString, TAG_FORMULA);
}

/*(Storage override)
** Creates record and saves to DB using IStorage from base IdObj.
** Recursiveness not works for this class, no matter if true or false - here only for inheritance.
*/
void Formula::save(bool recursive)
{
	//create the record
	string record = string("<" + storage->TAG_OBJ + ">");
	record += string("<" + storage->TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
	record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
	record += string("<" + TAG_FORMULA + "=\"" + formula + "\">");
	record += string("<\\" + storage->TAG_OBJ + ">");
	storage->save(record);
}

/*(Storage override)
Delete record and save DB using IStorage from base IdObj.
*/
void Formula::deleteMe()
{
	storage->deleteObj(this->SERIAL, this->id);
	storage->save();
}

/*
** Static Method - Returns a vector of all RegistrationStartDates.
*/
vector<Formula> Formula::getAllFormulas(IStorage * storage)
{
	vector<Formula> allFormulas;
	vector<string> formulasAsString = storage->getAll(Formula::SERIAL);
	for each (string formulaAsString in formulasAsString)
	{
		Formula * formula = new Formula(formulaAsString, storage);
		allFormulas.push_back(*formula);
	}
	return allFormulas;
}

/*
** Converts a RegistrationStartDate to String.
** Used for Debug purposes only!
*/
string Formula::ToString()
{
	string formulaStr("Formula: [objId:" + to_string(this->id));
	formulaStr += " serial: " + to_string(this->SERIAL);
	formulaStr += " formula: " + this->formula;
	formulaStr += "]";
	return formulaStr;
}