#ifndef TOKENAT_H
#define TOKENAT_H

#include "Token.h"

class TokenAt : public Token {
public:
	TokenAt(string value) : Token(value, Token::TOKEN_TYPE::AT) {}
	Token* clone() const	{ return(new TokenAt(getValue())); }
};

#endif