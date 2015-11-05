/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Parser.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <stack>
#include <cstdint>	
using namespace std;

#include "Lexer.h"
#include "TokenContainer.h"

class Parser {
private:
	double result;
	bool error;
	int findBracketCloserPosition(const vector<Token*>& vec_token, int bracket_start);
	int findBracketOpenerPosition(const vector<Token*>& vec_token);
	string getSubstringInsideBracket(const vector<Token*>& vec_token, int bracket_start);
	void reduce(vector<Token*>& vec_token, Token* token_reducde, int pos_start_clear, int pos_end_clear);
	vector<Token*> _parse(vector<Token*> vec_token);
	void copyVecToken(const vector<Token*>& vec_token_source, vector<Token*>& vec_token_copy_to, int pos_start, int pos_end);
	int findMultDivOperator(const vector<Token*>& vec_token);
	int findPlusMinusOperator(const vector<Token*>& vec_token);
	double stodFixUnary(string num);
	void parseTokenResult(const string, const int at_value);
	double _parseTokenResult(Lexer* lexer, const int at_value);
public:
	void parse(const string expr, const int at_value);
	bool isError();
	double getResult();
	~Parser();
};

#endif PARSER_H