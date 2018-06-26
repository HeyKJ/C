#include "arrayStack.h"

void createStack(ArrayStack** stack, int capacity)
{
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack)); //스택 메모리 생성
	(*stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity); //capacity만큼의 노드 메모리 생성
	(*stack)->capacity = capacity; //입력된 capacity 설정
	(*stack)->top = 0; //top 초기화
}

void destroyStack(ArrayStack* stack)
{
	free(stack->Nodes); //노드 메모리 해제
	free(stack); //스택 메모리 해제
}

void Push(ArrayStack* stack, ElementType data)
{
	stack->Nodes[stack->top++].data = data; //노드 최상위 인덱스에 data를 삽입 후 top 값을 증가
}

ElementType Pop(ArrayStack* stack)
{
	return stack->Nodes[--stack->top].data; //top은 노드 인덱스보다 +1 크기 때문에 1 감소 후 data를 반환
}

int getSize(ArrayStack* stack)
{
	return stack->top;
}

int isEmpty(ArrayStack* stack)
{
	return stack->top == 0;
}

void printStackStatus(ArrayStack* stack)
{
	printf("\nprint stack status...\n");
	printf("capacity : %d\n", stack->capacity);
	printf("top : %d\n", stack->top);
	printf("stack size : %d\n", getSize(stack));
	printf("stack is empty? : %s\n", isEmpty(stack) ? "true" : "false");
}