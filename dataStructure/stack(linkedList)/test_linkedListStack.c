#include "linekdListStack.h"

int main()
{

	LinkedListStack* stack = NULL;
	Node* newNode = NULL;

	/*���� ����*/
	printf("create stack...\n");
	createStack(&stack);

	/*���� ���� ���*/
	printStackStatus(stack);

	/*������ 1�� ����*/
	printf("\npush data...\n");
	newNode = createNode("first");
	Push(stack, newNode);

	/*���� ���� ���*/
	printStackStatus(stack);

	/*������ 1�� ����*/
	printf("\npush data...\n");
	newNode = createNode("second");
	Push(stack, newNode);

	/*���� ���� ���*/
	printStackStatus(stack);

	/*������ 1�� ��ȯ*/
	printf("\npop data...\n");
	printf("pop data : %s\n", Pop(stack)->data);

	/*���� ���� ���*/
	printStackStatus(stack);

	/*������ 1�� ��ȯ*/
	printf("\npop data...\n");
	printf("pop data : %s\n", Pop(stack)->data);

	/*���� ���� ���*/
	printStackStatus(stack);

	/*���� �Ҹ�*/
	printf("\ndestroy stack...\n");
	destroyStack(stack);

	return 0;
}