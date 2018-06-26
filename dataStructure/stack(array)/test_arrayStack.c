#include "arrayStack.h"



int main()
{
	ArrayStack* stack = NULL;
	
	/*���� ����*/
	printf("create stack...\n");
	createStack(&stack, 10); //10���� �����͸� ���� ���� ����
	
	/*������ ����*/
	printf("\npush data...\n");
	for (int i = 0; i < 5; i++)
	{
		Push(stack, i); //���ÿ� i���� ���ʴ�� ����
	}

	/*���� ���� ���¸� ���*/
	printStackStatus(stack);

	/*������ ��ȯ*/
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

	/*���� ���� ���¸� ���*/
	printStackStatus(stack);

	/*���� �Ҹ�*/
	printf("\ndestroy stack...\n");
	destroyStack(stack);

	return 0;
}

void printStackStatus(ArrayStack* stack); //���� ���� ���