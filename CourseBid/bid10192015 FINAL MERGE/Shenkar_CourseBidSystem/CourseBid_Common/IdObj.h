/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** IdObj.h
** IdObj is a base abstract class. Derived class must implement its storage methods.
** Derived class can be stored by id in storage object. Pointer to it is here in base class.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef ID_OBJ_H
#define ID_OBJ_H

#include <iostream>
#include <vector>
#include <cstdint>

#include "IStorage.h"

class IdObj {
protected:
	//each object must have unique object id
	long id;
	//pointer to storage
	IStorage * storage;
public:
	/*
	** Default IdObj Constructor
	*/
	IdObj() {}

	/*
	** Constructor.
	*/
	IdObj(long id, IStorage * storage) : id(id), storage(storage) {}

	/*
	** Virtual Destructor.
	*/
	virtual ~IdObj() {};

	/*
	** Get/Set methods
	*/
	long getId() { return id; }

	/* NON IMPLEMENTED STORAGE METHODS - NEED OVERRIDE*/
	virtual void save(bool recursive) =0;
	virtual void deleteMe() =0;
};

#endif ID_OBJ_H