#ifndef TOKENUNREC_H
#define TOKENUNREC_H

#include "Token.h"

class TokenUnrec : public Token {
public:
	TokenUnrec(string value) : Token(value, Token::TOKEN_TYPE::ERROR) {}
	Token* clone() const	{ return(new TokenUnrec(getValue())); }
};

#endif