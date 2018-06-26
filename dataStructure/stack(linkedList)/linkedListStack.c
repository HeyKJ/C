#include "linekdListStack.h"

void createStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); //링크드 리스트 스택 메모리 생성
	//초기화
	(*stack)->headNode = NULL;
	(*stack)->topNode = NULL;
}

void destroyStack(LinkedListStack* stack)
{
	while (!isEmpty(stack))
	{
		destroyNode(Pop(stack));
	}

	free(stack);
}

Node* createNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //노드 메모리 생성
	newNode->data = (char*)malloc(strlen(newData) + 1); //입력받은 문자열 만큼의 메모리 생성
	strcpy_s(newNode->data, strlen(newData) + 1, newData); //newNode->data에 입력받은 문자열을 복사
	newNode->nextNode = NULL; //다음 노드 초기화
	return newNode;
}

void destroyNode(Node* node)
{
	free(node->data);
	free(node);
}

int isEmpty(LinkedListStack* stack)
{
	return stack->headNode == NULL;
	//또는 return stack->topNode == NULL;
}

int getSize(LinkedListStack* stack)
{
	int count = 0;
	Node* currentNode = stack->headNode;
	
	while (currentNode != NULL)
	{
		count++;
		currentNode = currentNode->nextNode; //다음 노드로 이동
	}

	return count;
}

void Push(LinkedListStack* stack, Node* newNode)
{
	/*
		링크드 리스트 스택의 list가 NULL이라면 스택만 생성되고 
		데이터가 삽입되지 않았다는 뜻이므로 시작 노드는 지금 추가되는 newNode가 된다
	*/
	if (stack->headNode == NULL)
	{
		stack->headNode = newNode;
	}
	else
	{
		stack->topNode->nextNode = newNode; //기존 topNode의 다음 노드는 newNode가 된다
	}

	stack->topNode = newNode; //스택의 최상위(테일) 노드는 지금 추가되는 newNode가 된다
}

Node* Pop(LinkedListStack* stack)
{
	Node* currentNode = stack->headNode;
	Node* oldTopNode = stack->topNode;

	//스택에 데이터가 1개만 있을 경우 데이터가 반환된 후에는 스택에서 사라져야 함
	if (currentNode == oldTopNode)
	{
		stack->headNode = NULL;
		stack->topNode = NULL;
		return oldTopNode;
	}

	/*
		스택은 LIFO구조이기 때문에 Pop 함수가 호출되면 최상위(테일) 노드가 반환이 되고
		그 이전 노드가 새로운 최상위(테일)이 된다
		[headNode -> Node1 -> Node2 -> tailNode] 에서 Pop 호출 후
		[headNode -> Node1 -> Node2]로 변경
		따라서 tailNode를 바라보는 이전 노드를 탐색
	*/

	while (currentNode->nextNode != oldTopNode)
	{
		currentNode = currentNode->nextNode;
	}

	stack->topNode = currentNode; //기존 최상위(테일) 노드를 바라보던 노드가 새로운 최상위(테일) 노드가 된다
	currentNode->nextNode = NULL; //최상위(테일) 노드이기 때문에 다음 노드는 NULL
	return oldTopNode;
}

void printStackStatus(LinkedListStack* stack)
{
	printf("\nprint stack status..\n");
	printf("stack is empty? : %s\n", isEmpty(stack) ? "true" : "false");
	printf("stack size : %d\n", getSize(stack));

	if (!isEmpty(stack))
	{
		printf("stack first data : %s\n", stack->headNode->data);
		printf("stack last data : %s\n", stack->topNode->data);
	}

}