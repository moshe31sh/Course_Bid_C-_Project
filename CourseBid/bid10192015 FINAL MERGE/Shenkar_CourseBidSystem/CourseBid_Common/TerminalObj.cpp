/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** TerminalObj.cpp
** Registration Terminal Object class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "TerminalObj.h"

const string TerminalObj::TAG_LOCKED = "isLocked";
const string TerminalObj::CONFIGURATION_FILEPATH = "..\\config.ini";

/*
** Consrtuctor.
*/
TerminalObj::TerminalObj(string terminalAsString, IStorage * storage) : IdObj(0, storage)
{
	long serialS = storage->getNumberFromStringByTag(terminalAsString, storage->TAG_SERIAL);
	if (serialS != this->SERIAL)
	{
		throw new exception(); //wrong serial
	}
	this->id = storage->getNumberFromStringByTag(terminalAsString, storage->TAG_ID);
	this->isLocked = (storage->getNumberFromStringByTag(terminalAsString, TAG_LOCKED) != 0);
}

/*(Storage override)
** Creates record and saves to DB using IStorage from base IdObj.
** Recursiveness not works for this class, no matter if true or false - here only for inheritance.
*/
void TerminalObj::save(bool recursive)
{
	//create the record
	string record = string("<" + storage->TAG_OBJ + ">");
	record += string("<" + storage->TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
	record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
	record += string("<" + TAG_LOCKED + "=\"" + static_cast<ostringstream*>(&(ostringstream() << (int)isLocked))->str() + "\">");
	record += string("<\\" + storage->TAG_OBJ + ">");
	storage->save(record);
}

/*(Storage override)
Delete record and save DB using IStorage from base IdObj.
*/
void TerminalObj::deleteMe()
{
	storage->deleteObj(this->SERIAL, this->id);
	storage->save();
}

/*
** Static Method - Returns a vector of all RegistrationStartDates.
*/
vector<TerminalObj> TerminalObj::getAllTerminals(IStorage * storage)
{
	vector<TerminalObj> allTerminals;
	vector<string> terminalsAsString = storage->getAll(TerminalObj::SERIAL);
	for each (string terminalAsString in terminalsAsString)
	{
		TerminalObj * terminal = new TerminalObj(terminalAsString, storage);
		allTerminals.push_back(*terminal);
	}
	return allTerminals;
}

/*
** Converts a TerminalObj to String.
** Used for Debug purposes only!
*/
string TerminalObj::ToString()
{
	string terminalStr("Terminal: [objId:" + to_string(this->id));
	terminalStr += " serial: " + to_string(this->SERIAL);
	terminalStr += " isLocked: " + this->isLocked;
	terminalStr += "]";
	return terminalStr;
}

/*
** Check if Terminal Id exists in DB and Terminal is not locked.
*/
bool TerminalObj::isTerminalLegal()
{
	long terminalId = getTerminalConfiguration();
	FileStorage fileStorage;
	vector<TerminalObj> allTerminals = TerminalObj::getAllTerminals(&fileStorage);
	for each (TerminalObj terminalObj in allTerminals)
	{
		if (terminalObj.getId() == terminalId)
		{
			if (terminalObj.getLocked()) return false;
			else return true;
		}
	}
	cout << "\nSystem Cannot be Started! Terminal not exists in DB. Please Call Technician!\n" << endl;
	system("pause");
	exit(0);
}

/*
** Get Terminal Id from configuration file
*/
long TerminalObj::getTerminalConfiguration()
{
	ifstream stream;
	cout << "OPENING:" << CONFIGURATION_FILEPATH << endl;
	stream.open(CONFIGURATION_FILEPATH);
	if (!stream.is_open()) {
		cout << "\nSystem Cannot be Started! Configuration file for registration terminal not found. Please call technician!\n" << endl;
		system("pause");
		exit(0);
	}
	string line;
	long id;
	getline(stream, line);
	istringstream(line) >> id;
	stream.close();
	cout << "CLOSE:" << CONFIGURATION_FILEPATH << endl;
	return id;
}