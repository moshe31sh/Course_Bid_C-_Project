/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** User.h
** User abstract class for all kind of users.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstdint>	
using namespace std;

#include "IdObj.h"

//NOTE: USER IS ABSTRACT CLASS
class User : public IdObj{
protected:
	long userId;
	string firstName;
	string lastName;
	string email;
	string password;
	bool isLocked;
public:
	/*
	** Public static storage tags
	*/
	static const string TAG_USERID;
	static const string TAG_FIRSTNAME;
	static const string TAG_LASTNAME;
	static const string TAG_EMAIL;
	static const string TAG_PASSWORD;
	static const string TAG_ISLOCKED;

	/*
	** Constructor.
	*/
	User(long id, IStorage * storage) : IdObj(id, storage) { }

	/*
	** Virtual destructor.
	*/
	virtual ~User() {};

	/*
	** Get/Set Methods
	*/
	long getId()						{ return userId; }
	void setFirstName(string firstName)	{ this->firstName = firstName; }
	string getFirstName()				{ return firstName; }
	void setLastName(string lastName)	{ this->lastName = lastName; }
	string getLastName()				{ return lastName; }
	void setEmail(string email)			{ this->email = email; }
	string getEmail()					{ return email; }
	void setPassword(string password)	{ this->password = password; }
	bool verifyPassword(string password){ return (this->password.compare(password) == 0); }
	void setLocked(bool isLocked)		{ this->isLocked = isLocked; }
	bool getLocked()					{ return isLocked; }

	/* NON IMPLEMENTED STORAGE METHODS - NEED TO OVERRIDE - AS USER IS STILL AN ABSTRACT CLASS*/
	virtual void save(bool recursive)=0;
	virtual void deleteMe()=0;
};

#endif USER_H