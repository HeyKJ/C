#include "linkedListStack.h"
#include "stackCalculator.h"

int main()
{
	char infixExpression[100] = { 0 }; //사용자가 입력한 중위 표기식이 저장될 변수
	char postfixExpression[100] = { 0 }; //사용자가 입력한 중위 표기식이 후위 표기식으로 변경되어 저장될 변수

	/*중위 표기식 입력*/
	printf("Enter infix expression : ");
	scanf_s("%s", infixExpression, sizeof(infixExpression));

	/*후위 표기식으로 전환*/
	getPostfix(infixExpression, postfixExpression);
	printf("postfixExpression : %s\n", postfixExpression);

	/*후위 표기식으로 전환된 식을 계산*/
	printf("result : %lf\n", calculate(postfixExpression));

	return 0;
}

