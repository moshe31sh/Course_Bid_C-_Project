#ifndef TOKENNUM_H
#define TOKENNUM_H

#include "Token.h"

class TokenNum : public Token {
public:
	TokenNum(string value) : Token(value, Token::TOKEN_TYPE::NUM) {}
	Token* clone() const	{ return(new TokenNum(getValue())); }
};

#endif