#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

class Token {
private:
	string value;

public:
	static enum TOKEN_TYPE { NUM, AT, OPERATOR, BRACKET, BRACKET_PARSED, ERROR, NOTHING };
	Token(string value, Token::TOKEN_TYPE);
	Token::TOKEN_TYPE getTokenType();
	string getValue() const;
	Token* getToken();
	virtual Token* clone() const = 0;
	//virtual ~Token() = 0;
protected:
	Token::TOKEN_TYPE token_type;
};

#endif