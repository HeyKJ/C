#include "linekdListStack.h"

int main()
{

	LinkedListStack* stack = NULL;
	Node* newNode = NULL;

	/*스택 생성*/
	printf("create stack...\n");
	createStack(&stack);

	/*스택 상태 출력*/
	printStackStatus(stack);

	/*데이터 1개 삽입*/
	printf("\npush data...\n");
	newNode = createNode("first");
	Push(stack, newNode);

	/*스택 상태 출력*/
	printStackStatus(stack);

	/*데이터 1개 삽입*/
	printf("\npush data...\n");
	newNode = createNode("second");
	Push(stack, newNode);

	/*스택 상태 출력*/
	printStackStatus(stack);

	/*데이터 1개 반환*/
	printf("\npop data...\n");
	printf("pop data : %s\n", Pop(stack)->data);

	/*스택 상태 출력*/
	printStackStatus(stack);

	/*데이터 1개 반환*/
	printf("\npop data...\n");
	printf("pop data : %s\n", Pop(stack)->data);

	/*스택 상태 출력*/
	printStackStatus(stack);

	/*스택 소멸*/
	printf("\ndestroy stack...\n");
	destroyStack(stack);

	return 0;
}