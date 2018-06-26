#include "arrayStack.h"



int main()
{
	ArrayStack* stack = NULL;
	
	/*스택 생성*/
	printf("create stack...\n");
	createStack(&stack, 10); //10개의 데이터를 담을 스택 생성
	
	/*데이터 삽입*/
	printf("\npush data...\n");
	for (int i = 0; i < 5; i++)
	{
		Push(stack, i); //스택에 i값을 차례대로 삽입
	}

	/*현재 스택 상태를 출력*/
	printStackStatus(stack);

	/*데이터 반환*/
	printf("\npop data...\n");
	for (int i = 0; i < 10; i++)
	{
		if (isEmpty(stack))
		{
			printf("[%d] stack is empty...\n", i);
			break;
		}

		printf("[%d] pop : %d\n", i, Pop(stack));
	}

	/*현재 스택 상태를 출력*/
	printStackStatus(stack);

	/*스택 소멸*/
	printf("\ndestroy stack...\n");
	destroyStack(stack);

	return 0;
}

void printStackStatus(ArrayStack* stack); //스택 상태 출력