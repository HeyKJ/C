#include "linkedListStack.h"
#include "stackCalculator.h"

int main()
{
	char infixExpression[100] = { 0 }; //����ڰ� �Է��� ���� ǥ����� ����� ����
	char postfixExpression[100] = { 0 }; //����ڰ� �Է��� ���� ǥ����� ���� ǥ������� ����Ǿ� ����� ����

	/*���� ǥ��� �Է�*/
	printf("Enter infix expression : ");
	scanf_s("%s", infixExpression, sizeof(infixExpression));

	/*���� ǥ������� ��ȯ*/
	getPostfix(infixExpression, postfixExpression);
	printf("postfixExpression : %s\n", postfixExpression);

	/*���� ǥ������� ��ȯ�� ���� ���*/
	printf("result : %lf\n", calculate(postfixExpression));

	return 0;
}

