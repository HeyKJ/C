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

int isNumber(char cipher); //���� �Ǻ�
int getPriority(char operator); //������ ����
int isPrior(char operatorInstack, char operatorInToken); //�ΰ��� ������ ��
void getPostfix(char* infixExpression, char* postfixExpression); //���� ǥ������� ��ȯ
double calculate(char* postfixExpression); //���� ǥ������� ��ȯ�� ���� ���