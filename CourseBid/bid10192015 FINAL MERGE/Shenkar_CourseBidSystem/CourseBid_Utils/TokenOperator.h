#ifndef TOKENOPERATOR_H
#define TOKENOPERATOR_H

#include "Token.h"

class TokenOperator : public Token {
public:
	TokenOperator(string value) : Token(value, Token::TOKEN_TYPE::OPERATOR) {}
	Token* clone() const	{ return(new TokenOperator(getValue())); }
};

#endif