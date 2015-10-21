#ifndef INTOPOSTFIX_H_
#define INTOPOSTFIX_H_

#endif

#include <iostream>
#include <cctype>
#include <queue>

using namespace std;

inline int precedence(char sign);

inline bool isOperator(char c);

queue<string> infixToPostfix(string infix);
