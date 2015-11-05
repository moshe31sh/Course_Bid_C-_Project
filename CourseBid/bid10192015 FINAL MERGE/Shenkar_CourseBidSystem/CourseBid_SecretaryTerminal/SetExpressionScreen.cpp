/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** SetExpressionScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "SetExpressionScreen.h"

SetExpressionScreen::SetExpressionScreen()
{
	try{
		this->parser = new Parser();
	}
	catch (bad_alloc e){
		cerr << e.what();
	}

}


SetExpressionScreen::~SetExpressionScreen(){
	if (parser!=NULL) delete parser;
}

void SetExpressionScreen::SetExpression(string &exp)
{

}

bool SetExpressionScreen::verifyAndSetExpression(string exp, Student *student)
{
	this->parser->parse(exp, student->getCompletedCourses().size());
	if (this->parser->isError()){

		return false;
	}
	else {

		student->setPoints(this->parser->getResult());
		student->save(true);
	}

	return true;
}

void SetExpressionScreen::show()
{

}