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
	int priority = -1; //순위

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
	/*스택 생성*/
	LinkedListStack* stack = NULL;
	createStack(&stack);

	int position = 0;
	int needWhiteSpace = 0; //공백 필요 여부

	/*
		입력받은 중위 표기식(infixExpression)을 후위 표기식으로 전환하기 위한 조건
		1. 피연산자(숫자)는 스택에 쌓지 않고 바로 출력한다
		2. ')' 닫는 괄호를 만났다면 스택에서 '(' 여는 괄호가 나올 때 까지 반환(pop) 후 출력한다
		이 때 두 괄호 모두 스택에 남아있거나 후위 표기식에 출력되면 안된다
		3. 연산자일 경우, 현재 최상위 스택에 있는 연산자의 순위가 현재 스택에 쌓아야하는 연산자의 순위보다 높다면 반환 후 출력한다(높은 순위가 없을 때 까지)
		4. 더 이상 읽을 식(infixExpression)이 없다면 스택에 있는 모든 데이터를 반환 후 출력한다
	*/
	for (unsigned int i = 0; i < strlen(infixExpression); i++)
	{
		//숫자일 경우 스택에 쌓지않고 바로 출력하기 위해 중위 표기식(postfixExpression)에 옮긴다
		if (isNumber(infixExpression[i]))
		{
			postfixExpression[position++] = infixExpression[i];
			needWhiteSpace = 1; //숫자를 구분하기 위해 공백이 필요함
		}
		else
		{
			/*
				이중 공백을 막기 위한 조건식
				이전 문자가 이미 공백이라면 또 공백을 추가할 필요가 없음
			*/
			if (postfixExpression[position - 1] != SPACE && needWhiteSpace)
			{
				postfixExpression[position++] = SPACE;
				needWhiteSpace = 0;
			}

			//')' 닫는 괄호일 경우
			if (infixExpression[i] == RIGHT_PARENTHESIS)
			{
				Node* topNode = NULL;

				//'(' 여는 괄호가 나오기 전까지 계속 반환(Pop)
				while (!isEmpty(stack) && (topNode = Pop(stack))->data[0] != LEFT_PARENTHESIS)
				{
					postfixExpression[position++] = topNode->data[0];
					destroyNode(topNode);
				}

				//반환된 여는 괄호는 출력하지 않는다
				//닫는 괄호는 스택에 쌓지 않는다
			}
			//'(' 여는 괄호일 경우 바로 스택에 쌓음
			else if (infixExpression[i] == LEFT_PARENTHESIS)
			{
				char newData[2] = { infixExpression[i] };
				Push(stack, createNode(newData));
			}
			//+, -, *, / 연산자일 경우
			else
			{
				Node* topNode = NULL;

				//최상위 스택에 있는 연산자의 순위가 현재 연산자의 순위보다 높다면 반환한다
				while (!isEmpty(stack) && isPrior(stack->topNode->data[0], infixExpression[i]))
				{
					topNode = Pop(stack);
					postfixExpression[position++] = topNode->data[0];
					destroyNode(topNode);
				}

				//순위에의한 반환이 끝난경우 해당 연산자를 스택에 삽입(push)한다
				char newData[2] = { infixExpression[i] };
				Push(stack, createNode(newData));
			}
		}
	}

	/*중위 표기식 -> 후위 표기식으로 전환이 되었다면 스택에 남은 데이터를 모두 반환 후 출력*/
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
	/*스택 생성*/
	LinkedListStack* stack = NULL;
	createStack(&stack);

	//시작 인덱스와 끝 인덱스를 지정한 이유는 3.34와 같이 두자이상의 숫자를 하나로 묶기 위함
	int startPosition = -1, endPosition = -1;

	/*
		후위 표기식 계산법
		1. 피연산자(숫자)는 스택에 쌓는다
		2. 연산자를 만나면 스택에서 2회 반환(pop)을 하고 [두번째 반환된 데이터 (연산) 첫번째 반환된 데이터]의 결과를 다시 스택에 쌓는다
	*/
	for (unsigned int i = 0; i < strlen(postfixExpression); i++)
	{
		//공백인 경우
		if (postfixExpression[i] == SPACE) continue;

		//숫자인 경우
		if (isNumber(postfixExpression[i]))
		{
			//첫 시작이라면 startPosition을 지정한다
			if (startPosition == -1)
				startPosition = i;

			//다음 문자가 숫자가 아닐 경우 스택에 쌓는다
			if (!isNumber(postfixExpression[i + 1]))
			{
				char token[50] = { 0 };
				int position = 0, endPosition = i;

				for (; startPosition <= endPosition; startPosition++)
				{
					token[position++] = postfixExpression[startPosition];
				}

				Push(stack, createNode(token));
				//초기화
				startPosition = -1; 
				endPosition = -1;
			}

			continue;
		}

		//연산자일 경우 스택에서 2회 반환(pop)을 수행 후 연산 결과를 다시 스택에 저장
		Node* firstNode = Pop(stack); //첫번째 반환된 노드
		Node* secondNode = Pop(stack); //두번째 반환된 노드

		double firstData = atof(firstNode->data); //string to double
		double secondData = atof(secondNode->data);
		double resultData = 0; //결과 값을 저장할 변수

		char operator = postfixExpression[i]; //현재 연산자
		char tempResultData[100]; //결과값이 임시로 저장될 변수, 숫자->문자열로 바꾸기 위함
		
		//반환된 노드는 소멸
		destroyNode(firstNode);
		destroyNode(secondNode);

		/*연산자에 따른 연산 처리 실행*/
		switch (operator)
		{
		case '+': resultData = secondData + firstData; break;
		case '-': resultData = secondData - firstData; break;
		case '*': resultData = secondData * firstData; break;
		case '/': resultData = secondData / firstData; break;
		}

		/*
			연산된 결과값을 스택에 저장
			(Node에 선언된 data는 char* 형이고 현재 연산된 결과값은 double 형이기 때문에 tempResultData가 필요했던 것!)
		*/
		_gcvt_s(tempResultData, sizeof(tempResultData), resultData, 6); //double to string
		Push(stack, createNode(tempResultData));
	}

	/*계산된 값 반환*/
	Node* resultNode = Pop(stack);
	double result = atof(resultNode->data);
	destroyNode(resultNode);
	destroyStack(stack);
	return result;
}