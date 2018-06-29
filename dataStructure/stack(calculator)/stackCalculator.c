#include "linkedListStack.h"
#include "stackCalculator.h"

const char NUMBER[] = { '.', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

int isNumber(char cipher)
{
	for (int i = 0; i < sizeof(NUMBER); i++)
	{
		if (cipher == NUMBER[i])
		{
			return 1;
		}
	}

	return 0;
}

int getPriority(char operator)
{
	int priority = -1; //����

	switch (operator)
	{
	case LEFT_PARENTHESIS:
		priority = 0;
		break;
	case MULTIPLY:
	case DIVIDE:
		priority = 2;
		break;
	case PLUS:
	case MINUS:
		priority = 1;
		break;
	}

	return priority;
}

int isPrior(char operatorInstack, char operatorInToken)
{
	return getPriority(operatorInstack) > getPriority(operatorInToken);
}

void getPostfix(char* infixExpression, char* postfixExpression)
{
	/*���� ����*/
	LinkedListStack* stack = NULL;
	createStack(&stack);

	int position = 0;
	int needWhiteSpace = 0; //���� �ʿ� ����

	/*
		�Է¹��� ���� ǥ���(infixExpression)�� ���� ǥ������� ��ȯ�ϱ� ���� ����
		1. �ǿ�����(����)�� ���ÿ� ���� �ʰ� �ٷ� ����Ѵ�
		2. ')' �ݴ� ��ȣ�� �����ٸ� ���ÿ��� '(' ���� ��ȣ�� ���� �� ���� ��ȯ(pop) �� ����Ѵ�
		�� �� �� ��ȣ ��� ���ÿ� �����ְų� ���� ǥ��Ŀ� ��µǸ� �ȵȴ�
		3. �������� ���, ���� �ֻ��� ���ÿ� �ִ� �������� ������ ���� ���ÿ� �׾ƾ��ϴ� �������� �������� ���ٸ� ��ȯ �� ����Ѵ�(���� ������ ���� �� ����)
		4. �� �̻� ���� ��(infixExpression)�� ���ٸ� ���ÿ� �ִ� ��� �����͸� ��ȯ �� ����Ѵ�
	*/
	for (unsigned int i = 0; i < strlen(infixExpression); i++)
	{
		//������ ��� ���ÿ� �����ʰ� �ٷ� ����ϱ� ���� ���� ǥ���(postfixExpression)�� �ű��
		if (isNumber(infixExpression[i]))
		{
			postfixExpression[position++] = infixExpression[i];
			needWhiteSpace = 1; //���ڸ� �����ϱ� ���� ������ �ʿ���
		}
		else
		{
			/*
				���� ������ ���� ���� ���ǽ�
				���� ���ڰ� �̹� �����̶�� �� ������ �߰��� �ʿ䰡 ����
			*/
			if (postfixExpression[position - 1] != SPACE && needWhiteSpace)
			{
				postfixExpression[position++] = SPACE;
				needWhiteSpace = 0;
			}

			//')' �ݴ� ��ȣ�� ���
			if (infixExpression[i] == RIGHT_PARENTHESIS)
			{
				Node* topNode = NULL;

				//'(' ���� ��ȣ�� ������ ������ ��� ��ȯ(Pop)
				while (!isEmpty(stack) && (topNode = Pop(stack))->data[0] != LEFT_PARENTHESIS)
				{
					postfixExpression[position++] = topNode->data[0];
					destroyNode(topNode);
				}

				//��ȯ�� ���� ��ȣ�� ������� �ʴ´�
				//�ݴ� ��ȣ�� ���ÿ� ���� �ʴ´�
			}
			//'(' ���� ��ȣ�� ��� �ٷ� ���ÿ� ����
			else if (infixExpression[i] == LEFT_PARENTHESIS)
			{
				char newData[2] = { infixExpression[i] };
				Push(stack, createNode(newData));
			}
			//+, -, *, / �������� ���
			else
			{
				Node* topNode = NULL;

				//�ֻ��� ���ÿ� �ִ� �������� ������ ���� �������� �������� ���ٸ� ��ȯ�Ѵ�
				while (!isEmpty(stack) && isPrior(stack->topNode->data[0], infixExpression[i]))
				{
					topNode = Pop(stack);
					postfixExpression[position++] = topNode->data[0];
					destroyNode(topNode);
				}

				//���������� ��ȯ�� ������� �ش� �����ڸ� ���ÿ� ����(push)�Ѵ�
				char newData[2] = { infixExpression[i] };
				Push(stack, createNode(newData));
			}
		}
	}

	/*���� ǥ��� -> ���� ǥ������� ��ȯ�� �Ǿ��ٸ� ���ÿ� ���� �����͸� ��� ��ȯ �� ���*/
	Node* topNode;

	while (!isEmpty(stack))
	{
		topNode = Pop(stack);
		postfixExpression[position++] = topNode->data[0];
		destroyNode(topNode);
	}

	destroyStack(stack);
}

double calculate(char* postfixExpression)
{
	/*���� ����*/
	LinkedListStack* stack = NULL;
	createStack(&stack);

	//���� �ε����� �� �ε����� ������ ������ 3.34�� ���� �����̻��� ���ڸ� �ϳ��� ���� ����
	int startPosition = -1, endPosition = -1;

	/*
		���� ǥ��� ����
		1. �ǿ�����(����)�� ���ÿ� �״´�
		2. �����ڸ� ������ ���ÿ��� 2ȸ ��ȯ(pop)�� �ϰ� [�ι�° ��ȯ�� ������ (����) ù��° ��ȯ�� ������]�� ����� �ٽ� ���ÿ� �״´�
	*/
	for (unsigned int i = 0; i < strlen(postfixExpression); i++)
	{
		//������ ���
		if (postfixExpression[i] == SPACE) continue;

		//������ ���
		if (isNumber(postfixExpression[i]))
		{
			//ù �����̶�� startPosition�� �����Ѵ�
			if (startPosition == -1)
				startPosition = i;

			//���� ���ڰ� ���ڰ� �ƴ� ��� ���ÿ� �״´�
			if (!isNumber(postfixExpression[i + 1]))
			{
				char token[50] = { 0 };
				int position = 0, endPosition = i;

				for (; startPosition <= endPosition; startPosition++)
				{
					token[position++] = postfixExpression[startPosition];
				}

				Push(stack, createNode(token));
				//�ʱ�ȭ
				startPosition = -1; 
				endPosition = -1;
			}

			continue;
		}

		//�������� ��� ���ÿ��� 2ȸ ��ȯ(pop)�� ���� �� ���� ����� �ٽ� ���ÿ� ����
		Node* firstNode = Pop(stack); //ù��° ��ȯ�� ���
		Node* secondNode = Pop(stack); //�ι�° ��ȯ�� ���

		double firstData = atof(firstNode->data); //string to double
		double secondData = atof(secondNode->data);
		double resultData = 0; //��� ���� ������ ����

		char operator = postfixExpression[i]; //���� ������
		char tempResultData[100]; //������� �ӽ÷� ����� ����, ����->���ڿ��� �ٲٱ� ����
		
		//��ȯ�� ���� �Ҹ�
		destroyNode(firstNode);
		destroyNode(secondNode);

		/*�����ڿ� ���� ���� ó�� ����*/
		switch (operator)
		{
		case '+': resultData = secondData + firstData; break;
		case '-': resultData = secondData - firstData; break;
		case '*': resultData = secondData * firstData; break;
		case '/': resultData = secondData / firstData; break;
		}

		/*
			����� ������� ���ÿ� ����
			(Node�� ����� data�� char* ���̰� ���� ����� ������� double ���̱� ������ tempResultData�� �ʿ��ߴ� ��!)
		*/
		_gcvt_s(tempResultData, sizeof(tempResultData), resultData, 6); //double to string
		Push(stack, createNode(tempResultData));
	}

	/*���� �� ��ȯ*/
	Node* resultNode = Pop(stack);
	double result = atof(resultNode->data);
	destroyNode(resultNode);
	destroyStack(stack);
	return result;
}