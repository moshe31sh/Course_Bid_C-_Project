/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** maincpp.cpp
** <This is Utils Library. This main is not in use!>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef UTILS
#define UTILS
#include <iostream>
#include <cstdint>
using namespace std;

/*
/This is UTILS Library
/This main is not in use
/
*/

#include "Parser.h"
#include "Lexer.h"
int main(int argc, char* argv[])
{
	cout << "UTILS Lib" << endl;

	//Parser p();
	//Lexer lexer("123+4*(6/2)");
	Parser parser;
	//parser.parseTokenResult("123+@/2", 10);;
	parser.parse("-(--(-123*(-@))/-2)", 10);
	//parser.parse("2/-1", 10);
	if (parser.isError())
		cout << "Error.." << endl;
	else
		cout << "result: " << parser.getResult() << endl;
	system("pause");

}
#endif UTILS