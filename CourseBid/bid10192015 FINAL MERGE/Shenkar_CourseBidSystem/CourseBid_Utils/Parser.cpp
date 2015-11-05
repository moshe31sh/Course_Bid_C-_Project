/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Parser.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "Parser.h"

void Parser::parseTokenResult(const string expression, const int at_value) {
	result = 0;
	error = false;
	result=_parseTokenResult(new Lexer(expression), at_value);
}

double Parser::_parseTokenResult(Lexer* lexer, const int at_value) {
	int i = 0;
	double res = 0;
	Token::TOKEN_TYPE rem_last_action = Token::TOKEN_TYPE::NOTHING;
	char rem_operator_value = -1;
	const vector<Token*> &vec_token = lexer->getTokenVector();

	Token::TOKEN_TYPE token_type;
	string token_value;
	while(i < vec_token.size() && !error) {
		token_type = vec_token[i]->getTokenType();
		token_value = vec_token[i]->getValue();

		// Replace AT with NUM
		if (token_type == Token::TOKEN_TYPE::AT) {
			token_type = Token::TOKEN_TYPE::NUM;
			if (token_value[0] == '-')
				token_value = "-"+to_string(at_value); // convert to string!
			else
				token_value = to_string(at_value); // convert to string!
		}

		switch (token_type) {
		case Token::TOKEN_TYPE::NUM:

			if (rem_last_action == Token::TOKEN_TYPE::NOTHING || rem_last_action == Token::TOKEN_TYPE::OPERATOR) {
				if (rem_last_action == Token::TOKEN_TYPE::NOTHING)
					res = stoi(token_value);
				else {
					if (rem_operator_value == '+')
						res += stoi(token_value);
					else
						if (rem_operator_value == '-')
							res -= stoi(token_value);
						else
							if (rem_operator_value == '*')
								res *= stoi(token_value);
							else
								if (rem_operator_value == '/')
									res /= stoi(token_value);
								else
									error = true;
				}
				rem_last_action = Token::TOKEN_TYPE::NUM;

			} else
				error = true;

			break;
		
		case Token::TOKEN_TYPE::BRACKET:

			if (rem_last_action == Token::TOKEN_TYPE::NOTHING || rem_last_action == Token::TOKEN_TYPE::OPERATOR || rem_last_action == Token::TOKEN_TYPE::BRACKET_PARSED) {
				
				if (rem_last_action == Token::TOKEN_TYPE::BRACKET_PARSED) {
					if (token_value[0] != ')')
						error = true;

				} else {
					string substr_inside_bracket = getSubstringInsideBracket(vec_token, i);
					Lexer* lex_temp = new Lexer(substr_inside_bracket);
					res += _parseTokenResult(lex_temp, at_value);

					if (token_value[0] == '(') {
						i = findBracketCloserPosition(vec_token, i); // jump over ')'
						if (i < 0)
							error = true;
					}

					//rem_last_action = Token::TOKEN_TYPE::BRACKET;
					
				}
				rem_last_action = Token::TOKEN_TYPE::BRACKET_PARSED;
			}
			else
				error = true;

			
			break;

		case Token::TOKEN_TYPE::OPERATOR:

			if (rem_last_action == Token::TOKEN_TYPE::NUM || rem_last_action == Token::TOKEN_TYPE::BRACKET || rem_last_action == Token::TOKEN_TYPE::BRACKET_PARSED) {
				rem_last_action = Token::TOKEN_TYPE::OPERATOR;
				rem_operator_value = token_value[0]; // must be one char (operators: +,-,*,/)
			}
			else
				error = true;

			break;

		case Token::TOKEN_TYPE::BRACKET_PARSED:

			if (rem_last_action == Token::TOKEN_TYPE::NUM || rem_last_action == Token::TOKEN_TYPE::BRACKET) {
				rem_last_action = Token::TOKEN_TYPE::BRACKET_PARSED;
			}
			else
				error = true;

			break;

		default:
			error = true;
			rem_last_action = Token::TOKEN_TYPE::ERROR;
			break;
		}

		// error found. ilegal syntax
		if (rem_last_action == Token::TOKEN_TYPE::ERROR) {
			error = true;
			res = -999;
			result = -999;
		}
		i++;
	}

	if (lexer!=NULL) delete lexer;
	return(res);
}

int Parser::findBracketCloserPosition(const vector<Token*>& vec_token, int bracket_start) {
	int pos = -1;
	int counter = 0;
	int i = bracket_start;
	bool flag = true;
	while(i < vec_token.size() && flag) {
		if (vec_token[i]->getTokenType() == Token::TOKEN_TYPE::BRACKET) {
			if (vec_token[i]->getValue() == "(")
				counter++;
			else
				counter--;

			if (counter == 0) pos = i;

			if (counter < 0) flag = false;
		}
		i++;
	}
	return(pos);
}

string Parser::getSubstringInsideBracket(const vector<Token*>& vec_token, int bracket_start) {
	string substr;
	int end_pos = findBracketCloserPosition(vec_token, bracket_start);
	if (end_pos != -1) {
		for (int i = bracket_start + 1; i < end_pos; i++)
			substr+=vec_token[i]->getValue();
	}
	return(substr);
}

void Parser::reduce(vector<Token*>& vec_token, Token* token_reducde, int pos_start_clear, int pos_end_clear) {
	vec_token[pos_start_clear] = token_reducde;
	vec_token.erase(vec_token.begin() + pos_start_clear + 1, vec_token.begin() + pos_end_clear + 1);

	//cout << "reduce";
}

bool Parser::isError() {
	return(error);
}

double Parser::getResult() {
	return(result);
}

void Parser::parse(const string expr, const int at_value) {
	error = false;
	vector<Token*> vec_token = (Lexer(expr)).getTokenVector();
	for (int i = 0; i < vec_token.size(); i++)
		if (vec_token[i]->getTokenType() == Token::TOKEN_TYPE::AT) { // replace '@' with his numeric value
			if (vec_token[i]->getValue()[0] == '-')
				vec_token[i] = new TokenNum("-"+to_string(at_value));
			else
				vec_token[i] = new TokenNum(to_string(at_value));
		}
	_parse(vec_token);
}

vector<Token*> Parser::_parse(vector<Token*> vec_token) {
	int i = 0;
	double res = 0;

	int pos_start, pos_end;

	if (vec_token.size() == 0)
		error = true;

	// reduce bracket (...)
	while (!error && (pos_start = findBracketOpenerPosition(vec_token)) != -1) {
		if ((pos_end = findBracketCloserPosition(vec_token, pos_start)) != -1) {
			vector<Token*> vec_copy;
			copyVecToken(vec_token, vec_copy, pos_start+1, pos_end-1);
			vec_copy = _parse(vec_copy); // call himself again
			
			// must return 1 value, and it's need to be a NUM!
			if (vec_copy.size() != 1 && vec_copy[0]->getTokenType() == Token::TOKEN_TYPE::NUM)
				error = true;
			else
				reduce(vec_token, vec_copy[0]->getToken(), pos_start, pos_end);
		} else
			error = true;
	}



	bool found;
	// search for unary minus
	do {
		found = false;
		i = 0;
		while (i < vec_token.size()) {
			if (vec_token[i]->getTokenType() == Token::TOKEN_TYPE::OPERATOR && vec_token[i]->getValue()[0] == '-') {
				if (i == 0) {
					if (vec_token.size() > 1)
						if (vec_token[i + 1]->getTokenType() == Token::TOKEN_TYPE::NUM) {
							reduce(vec_token, new TokenNum("-" + vec_token[i + 1]->getValue()), i, i + 1);
							found = true;
						} else {
							if (vec_token[i + 1]->getTokenType() == Token::TOKEN_TYPE::OPERATOR && vec_token[i + 1]->getValue()[0] == '-') {
								vec_token.erase(vec_token.begin() + i, vec_token.begin() + i + 2);
								found = true;
							} else
								error = true;
						}
					else
						error = true;
				}
				else {
					if (vec_token[i - 1]->getTokenType() == Token::TOKEN_TYPE::OPERATOR) {
						if (i + 1 < vec_token.size()) {

							if (vec_token[i + 1]->getTokenType() == Token::TOKEN_TYPE::NUM) {
								reduce(vec_token, new TokenNum("-" + vec_token[i + 1]->getValue()), i, i + 1);
								found = true;
							}
							else {
								if (vec_token[i + 1]->getTokenType() == Token::TOKEN_TYPE::OPERATOR) {
									if (vec_token[i + 1]->getValue()[0] == '-')
										vec_token.erase(vec_token.begin() + i, vec_token.begin() + i + 1);
									else
										reduce(vec_token, new TokenNum("-" + vec_token[i + 1]->getValue()), i, i + 1);

									found = true;
								}
								else
									error = true;
							}

						}
						else
							error = true;
					}
				}
			}
			if (found) {
				found = false;
				i = 0; // start over
			}
			else
				i++;
		}
	} while (!error && found);



	// reduce NUM OP_MD NUM.  =>  OP_MD= *,/
	while (!error && (pos_start = findMultDivOperator(vec_token)) != -1) {
		// check if is token before and after
		if (pos_start != 0 && pos_start < vec_token.size()) {
			if (vec_token[pos_start - 1]->getTokenType() == Token::TOKEN_TYPE::NUM && vec_token[pos_start + 1]->getTokenType() == Token::TOKEN_TYPE::NUM) {
				double t1 = stodFixUnary(vec_token[pos_start - 1]->getValue());
				double t2 = stodFixUnary(vec_token[pos_start + 1]->getValue());

				if (vec_token[pos_start]->getValue() == "*") // mult
					reduce(vec_token, new TokenNum(to_string(t1*t2)), pos_start - 1, pos_start + 1);
				else // divide
					reduce(vec_token, new TokenNum(to_string(t1 / t2)), pos_start - 1, pos_start + 1);
			} else
				error = true;
		} else
			error = true;
	}


	while (!error && (pos_start=findPlusMinusOperator(vec_token))!=-1) {
		// check if is token before and after
		if (pos_start != 0 && pos_start < vec_token.size()) {
			double t1 = stodFixUnary(vec_token[pos_start - 1]->getValue());
			double t2 = stodFixUnary(vec_token[pos_start + 1]->getValue());

			if (vec_token[pos_start - 1]->getTokenType() == Token::TOKEN_TYPE::NUM && vec_token[pos_start + 1]->getTokenType() == Token::TOKEN_TYPE::NUM)
				if (vec_token[pos_start]->getValue() == "+") // plus
					reduce(vec_token, new TokenNum(to_string(t1 + t2)), pos_start - 1, pos_start + 1);
				else // minus
					reduce(vec_token, new TokenNum(to_string(t1 - t2)), pos_start - 1, pos_start + 1);
			else
				error = true;
		}
		else
			error = true;
	}

	if (!(vec_token.size() == 1 && vec_token[0]->getTokenType() == Token::TOKEN_TYPE::NUM))
		error = true;
	else
		result = stodFixUnary(vec_token[0]->getValue()); // save result

	return(vec_token);
}

int Parser::findPlusMinusOperator(const vector<Token*>& vec_token) {
	int pos = -1;
	for (int i = 0; i < vec_token.size(); i++)
		if (vec_token[i]->getTokenType() == Token::TOKEN_TYPE::OPERATOR && (vec_token[i]->getValue() == "+") || (vec_token[i]->getValue() == "-"))
			pos = i;
	return(pos);
}

int Parser::findMultDivOperator(const vector<Token*>& vec_token) {
	int pos = -1;
	for (int i = 0; i < vec_token.size() && pos == -1; i++)
		if (vec_token[i]->getTokenType() == Token::TOKEN_TYPE::OPERATOR && (vec_token[i]->getValue() == "*") || (vec_token[i]->getValue() == "/"))
			pos = i;
	return(pos);
}

void Parser::copyVecToken(const vector<Token*>& vec_token_source, vector<Token*>& vec_token_copy_to, int pos_start, int pos_end) {
	
	//make sure vec_token_copy_to is clear
	while (vec_token_copy_to.size() != 0) vec_token_copy_to.erase(vec_token_copy_to.begin());

	for (int i = pos_start; i <= pos_end; i++)
		vec_token_copy_to.push_back(vec_token_source[i]->clone());
}

int Parser::findBracketOpenerPosition(const vector<Token*>& vec_token) {
	int pos = -1;
	int i = 0;
	while (pos == -1 && i < vec_token.size()) {
		if (vec_token[i]->getValue() == "(")
			pos = i;
		i++;
	}

	return(pos);
}

double Parser::stodFixUnary(string num) {
	bool is_negative = false;
	int i = 0;
	while (num[i] == '-') {
		is_negative = !is_negative;
		i++;
	}

	double res = stoi(num.substr(i, num.size()-i));
	if (is_negative)
		res *= -1;

	return(res);
}

Parser::~Parser() {
	
}