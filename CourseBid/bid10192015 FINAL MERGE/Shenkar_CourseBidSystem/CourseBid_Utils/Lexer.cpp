/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Lexer.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "Lexer.h"

Lexer::Lexer(string expression)
{
	tokenize(expression);
	/*
	for (int i = 0; i < vec_token.size(); i++)
		cout << vec_token[i]->getValue() << endl;
	*/
}

vector<Token*> Lexer::getTokenVector() {
	return(vec_token);
}

/*string Lexer::fixForUnaryOperator(string expr) {
	if (expr[0] == '-')
		expr = "0" + expr;
	
	int i = 0;

	bool rem_open_bracket = false;
	while (i < expr.length()) {
		if (rem_open_bracket && expr[i] == '-') {
			expr = expr.substr(0, i) + "0" + expr.substr(i, expr.length());
			rem_open_bracket = false;
		}

		if (expr[i] == '(' || expr[i] == '/')
			rem_open_bracket = true;
		else
			rem_open_bracket = false;

		i++;
	}
	return(expr);
}*/


void Lexer::tokenize(string expression)
{
	Token::TOKEN_TYPE token_type = Token::TOKEN_TYPE::ERROR;
	int index_start = -1;
	// char rem_bef=-1;
	// bool is_in_unary_minus = false;
	// bool calc_minus = false;
	// expression=fixForUnaryOperator(expression);
	for (int i = 0; i < expression.length(); i++) {
		
		if (expression[i] >= '0' && expression[i] <= '9') {
			if (index_start == -1) {
				index_start = i;
				token_type = Token::TOKEN_TYPE::NUM;
			}
		}
		else { // copy only one char
			// but first, copy the rest in the memory (if exist, it should be a number)
			if (index_start != -1) {
				saveAsToken(expression, index_start, i - 1, token_type);
				index_start = -1;
				token_type = Token::TOKEN_TYPE::ERROR;
			}

			// copy one char
			switch (expression[i]) {
			case '@':
				token_type = Token::TOKEN_TYPE::AT;
				break;

			case '(':
				token_type = Token::TOKEN_TYPE::BRACKET;
				break;

			case ')':
				token_type = Token::TOKEN_TYPE::BRACKET;
				break;

			case '+':
				token_type = Token::TOKEN_TYPE::OPERATOR;
				break;

			case '-':
				/*if (rem_bef == '+' || rem_bef == '-' || rem_bef == '*' || rem_bef == '/' || rem_bef == '(' || rem_bef == -1) {
					index_start = i;
					is_in_unary_minus = true;
					token_type = Token::TOKEN_TYPE::OPERATOR;
				}
				else {*/
					token_type = Token::TOKEN_TYPE::OPERATOR;
					//is_in_unary_minus = false;
				//}
				break;

			case '*':
				token_type = Token::TOKEN_TYPE::OPERATOR;
				break;

			case '/':
				token_type = Token::TOKEN_TYPE::OPERATOR;
				break;

			default:
				token_type = Token::TOKEN_TYPE::ERROR;
				break;
			}
			//if (is_in_unary_minus == false) {
				saveAsToken(expression, i, i, token_type);
				index_start = -1;
				token_type = Token::TOKEN_TYPE::ERROR;
			//}
		}
	}

	if (index_start != -1)
		saveAsToken(expression, index_start, expression.length() - 1, token_type);
}

void Lexer::switchPrevAndPrevPrev() {
	int vec_size = vec_token.size() - 1; // last index
	Token* temp = vec_token[vec_size]; // save last one
	vec_token[vec_size] = vec_token[vec_size - 1];
	vec_token[vec_size - 1] = temp;
}

Token* Lexer::createToken(string token_string, Token::TOKEN_TYPE token_type) {
	Token* token;
	switch (token_type) {
	case Token::TOKEN_TYPE::AT:
		token = new TokenAt(token_string);
		break;

	case Token::TOKEN_TYPE::BRACKET:
		token = new TokenBracket(token_string);
		break;

	case Token::TOKEN_TYPE::NUM:
		token = new TokenNum(token_string);
		break;

	case Token::TOKEN_TYPE::OPERATOR:
		token = new TokenOperator(token_string);
		break;

	default:
		token = new TokenUnrec(token_string);
		break;
	}
	return(token);
}

void Lexer::saveAsToken(string token_string, Token::TOKEN_TYPE token_type) {
	Token* token = createToken(token_string, token_type);
	vec_token.push_back(token);
}

void Lexer::saveAsToken(string expression, int start_index, int end_index, Token::TOKEN_TYPE token_type) {
	string token_string = expression.substr(start_index, end_index - start_index + 1);
	saveAsToken(token_string, token_type);
	/*Token* token = createToken(token_string, token_type);
	
	vec_token.push_back(token);*/
}

void Lexer::copyVecToken(Lexer* lexer, vector<Token*>& vec_token_copy, int s_pos, int e_pos) {
	copyVecToken(lexer->getTokenVector(), vec_token_copy, s_pos, e_pos);
}


void Lexer::copyVecToken(const vector<Token*>& vec_token_source, vector<Token*>& vec_token_copy, int s_pos, int e_pos) {
	for (int i = s_pos; i <= e_pos; i++)
		vec_token_copy.push_back(vec_token_source[i]);
}