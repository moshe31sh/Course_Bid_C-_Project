/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Formula.h
** Formula class
**
** Author:  Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef FORMULA_H
#define FORMULA_H

#include <iostream>
#include <cstdint>	
#include <sstream>
#include <string>
using namespace std;

#include "IdObj.h"
class Formula : public IdObj {
private:
	//serial number for all objects Formula
	static const int SERIAL = 5;
	string formula;
public:
	/*
	**STORAGE TAGS
	*/
	static const string TAG_FORMULA;

	/*
	** Consrtuctor.
	*/
	Formula(int id, IStorage * storage) : IdObj(id, storage) {}

	/*
	** Consrtuctor.
	*/
	Formula(string formula, IStorage * storage);

	/*
	** Static Method - Returns a vector of all formulas.
	*/
	static vector<Formula> getAllFormulas(IStorage * storage);

	/*
	** get/set inline methods
	*/
	void setFormula(string formula)	{ this->formula = formula; }
	string getFormula()			{ return formula; }

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
	** Converts a RegistrationStartDate to String.
	** Used for Debug purposes only!
	*/
	string ToString();
};

#endif FORMULA_H