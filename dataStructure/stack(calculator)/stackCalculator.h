#pragma once
#define DEBUG
#ifdef DEBUG

#include "linkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS = '('
	,RIGHT_PARENTHESIS = ')'
	,PLUS = '+'
	,MINUS = '-'
	,MULTIPLY = '*'
	,DIVIDE = '/'
	,SPACE = 32
	,OPERAND
} SYMBOL;

#endif // DEBUG

int isNumber(char cipher); //숫자 판별
int getPriority(char operator); //연산자 순위
int isPrior(char operatorInstack, char operatorInToken); //두개의 연산자 비교
void getPostfix(char* infixExpression, char* postfixExpression); //후위 표기식으로 전환
double calculate(char* postfixExpression); //후위 표기식으로 전환된 식을 계산