/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** IStorage.h
** Interface for storage class.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef ISTORAGE_H
#define ISTORAGE_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
using namespace std;

/*
** Common Storage Class must be overriten.
** String choosen to store have XML type format, but overriding function can store those as SQL, XML, CSV etc.
*/
class IStorage {
public:

	/*
	** Storage constants. Value must be given in .cpp of implementing class
	*/
	static const long VALUE_NOT_EXISTS;
	static const long KEY_NOT_EXISTS;
	static const string TAG_SERIAL;
	static const string TAG_ID;
	static const string TAG_OBJ;

	/* NON IMPLEMENTED STORAGE METHODS - NEED OVERRIDE*/
	/*
	** Returns long value by tag (key) in given line
	*/
	virtual long getNumberFromStringByTag(string str, string tag)=0;

	/*
	** Returns string value by tag (key) in given line
	*/
	virtual string getStringFromStringByTag(string str, string tag)=0;


	virtual vector<long> getInnerNumbersByTag(string str, string tag) = 0;

	/*
	**Returns all strings by given class serial.
	*/
	virtual vector<string> getAll(long serial) = 0;

	/*
	** To correctly build a string please use folowing syntaxis:
	**		<idobj><serial="CLASS_SERIAL_NUMBER"><id="OBJECT_ID_NUMBER"><key1="value1">...<keyN="valueN"><\idobj>
	** NOTE: Please don't forget to use "\" to write special symbols, for ex: " as \" and \ as \\
	** NOTE: Class inheritating  from IStorage must parse given string and save it in chosen way: XML, SQL, file etc.
	** NOTE: To store multiple object please use following syntax:
	**		<idobj>... <keyK><id1="INTERNAL_OBJECT_ID">...<idN="INTERNAL_OBJECT_ID"></keyK>...<\idobj>
	*/
	virtual void save(string line = "") = 0;

	/*
	** Delete given object from storage using serial and id.
	** NOTE: Change will take place in DB only after save()
	*/
	virtual void deleteObj(long serial, long id) = 0;

	/*
	** Generate unique object id for a new object.
	*/
	virtual long generateId(long serial) = 0;
};

#endif ISTORAGE_H