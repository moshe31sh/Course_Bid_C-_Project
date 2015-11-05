#ifndef TOKENBRACKET_H
#define TOKENBRACKET_H

#include "Token.h"

class TokenBracket : public Token {
public:
	TokenBracket(string value) : Token(value, Token::TOKEN_TYPE::BRACKET) {}
	Token* clone() const		{ return(new TokenBracket(getValue())); }
};

#endif