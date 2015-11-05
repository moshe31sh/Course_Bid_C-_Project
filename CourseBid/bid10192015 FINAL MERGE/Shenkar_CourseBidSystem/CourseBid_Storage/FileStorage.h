/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** FileStorage.h
** File Storage based on XML implements IStorage.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
using namespace std;
#include "IStorage.h"
#include "DBEventLog.h"

/*
** This Class Implements XML Storage.
*/
class FileStorage : public IStorage {
private:
	string filename = "..\\db.xml";	//DB file xml name
	vector<string> buffer;			//Main Memory buffer for real time work
public:
	/*
	** Returns long value by tag (key) in given line
	*/
	virtual long getNumberFromStringByTag(string str, string tag);

	/*
	** Returns string value by tag (key) in given line
	*/
	virtual string getStringFromStringByTag(string str, string tag);

	virtual vector<long> getInnerNumbersByTag(string str, string tag);

	/*
	** Constructor: creates File Storage DB if not exists or reads memory to buffer.
	*/
	FileStorage();

	/*
	** Constructor: creates buffer outside.
	*/
	FileStorage(vector<string> buf, string filename) { filename = filename; buffer = buf; }

	/* (overriden parrent)
	** Returns all objects of given class serial as string.
	*/
	virtual vector<string> getAll(long serial);

	/* (overriden parrent)
	** Public function:	Stores memory in DB.
	** 					If given line == "" not changing before saving
	** 					Else searching for serial and id all memory
	** 						if exists => overriding line
	** 						else  => adding line
	** Throws: exception : new line does not contain serial or ID
	** To see how to build a string please see: IStorage::save(string line)
	*/
	virtual void save(string line="");

	/* (overriden parrent)
	** This  function will delete the record with given class serial and id if such line found in DB
	** NOTE: Change will take place in DB only after save()
	*/
	virtual void deleteObj(long serial, long id);
	
	/* (overriden parrent)
	** This function will return minimal unique id>0 for given class.
	*/
	virtual long generateId(long serial);			 
};

#endif FILE_STORAGE_H