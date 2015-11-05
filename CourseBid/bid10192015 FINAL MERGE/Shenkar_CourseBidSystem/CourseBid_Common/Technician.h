/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** User.h
** Technician class
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include <vector>
#include <string>
#include <sstream>

#include "User.h"

class Technician : public User {
public:
	//static serial number for all objects Technician
	static const int SERIAL = 3;

	/*
	** Constructor.
	*/
	Technician(long userId, IStorage * storage) :User(userId, storage) { }

	/*
	** Constructor.
	*/
	Technician(string technicianAsStrign, IStorage * storage);

	/* Static Method
	** This function returns a technician by object id.
	** If not found technician with given id - throws an exception.
	*/
	static Technician getTechnicianById(IStorage * storage, int id);

	/* Static Method
	** This function returns a technician by student id.
	** If not found - returns NULL.
	*/
	static Technician* getTechnicianByTechnicianId(IStorage * storage, int userId);

	/*
	** Static Method - Returns a vector of all technicians.
	*/
	static vector<Technician> getAllTechnician(IStorage * storage);

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
	** Converts a Technician to String.
	** Used for Debug purposes only!
	*/
	string ToString();
};

#endif TECHNICIAN_H