/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** TerminalObj.h
** Registration Terminal Object class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef TERMINALOBJ_H
#define TERMINALOBJ_H

#include <iostream>
#include <cstdint>	
#include <sstream>
#include <string>
#include <fstream>
#include "FileStorage.h"
using namespace std;

#include "IdObj.h"
class TerminalObj : public IdObj {
private:
	//serial number for all objects Formula
	static const int SERIAL = 6;
	bool isLocked;
public:
	/*
	**STORAGE TAGS
	*/
	static const string TAG_LOCKED;

	/*
	** Configuration file path.
	*/
	static const string CONFIGURATION_FILEPATH;

	/*
	** Consrtuctor.
	*/
	TerminalObj(int id, IStorage * storage) : IdObj(id, storage) {}

	/*
	** Consrtuctor.
	*/
	TerminalObj(string terminalAsString, IStorage * storage);

	/*
	** Static Method - Returns a vector of all registration terminals.
	*/
	static vector<TerminalObj> getAllTerminals(IStorage * storage);

	/*
	** set inline method
	*/
	void setLocked(bool isLocked)	{ this->isLocked = isLocked; }

	/*
	** set inline method
	*/
	bool getLocked()			{ return isLocked; }

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
	** Converts a Terminal to String.
	** Used for Debug purposes only!
	*/
	string ToString();

	/*
	** Get Terminal Id from configuration file
	*/
	static long getTerminalConfiguration();

	/*
	** Check if Terminal Id exists in DB and Terminal is not locked.
	*/
	static bool isTerminalLegal();
	
};

#endif TERMINALOBJ_H