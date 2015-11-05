#include "Token.h"

Token::Token(string value, Token::TOKEN_TYPE token_type) : value(value), token_type(token_type)	{}
Token::TOKEN_TYPE Token::getTokenType()										{ return(token_type); }
Token* Token::getToken()													{ return(this); }
string Token::getValue() const												{ return(value); }
//Token::~Token()																{}