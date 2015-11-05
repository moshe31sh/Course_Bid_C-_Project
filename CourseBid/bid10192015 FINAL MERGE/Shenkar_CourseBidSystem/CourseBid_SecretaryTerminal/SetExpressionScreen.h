/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** SetExpressionScreen.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef SETEXPRESSIONSCREEN_H
#define SETEXPRESSIONSCREEN_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include "UIScreen.h"
#include "Parser.h"
#include "Student.h"


class SetExpressionScreen : public UIScreen {
	string expression;
	Parser *parser;
public:
	SetExpressionScreen();
	~SetExpressionScreen();
	void SetExpression(string&);
	bool verifyAndSetExpression(string, Student *);
	void show();
};

#endif SETEXPRESSIONSCREEN_H