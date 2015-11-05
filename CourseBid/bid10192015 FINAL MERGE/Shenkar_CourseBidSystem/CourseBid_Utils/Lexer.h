/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Lexer.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <cstdint>	
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

#include "TokenContainer.h"

class Lexer {
private:
	// Parser* parser;
	vector<Token*> vec_token;
	void switchPrevAndPrevPrev();
	void saveAsToken(string expression, int start_index, int end_index, Token::TOKEN_TYPE token_type);
	void saveAsToken(string s, Token::TOKEN_TYPE token_type);
	Token* createToken(string token_string, Token::TOKEN_TYPE token_type);
	//string fixForUnaryOperator(string expr);
public:
	Lexer(string expression);
	vector<Token*> getTokenVector();
	void tokenize(string expression);
	static void copyVecToken(Lexer* lexer, vector<Token*>& vec_token_copy, int s_pos, int e_pos);
	static void copyVecToken(const vector<Token*>& vec_token_source, vector<Token*>& vec_token_copy, int s_pos, int e_pos);
};

#endif LEXER_H