#include "arrayStack.h"

void createStack(ArrayStack** stack, int capacity)
{
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack)); //���� �޸� ����
	(*stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity); //capacity��ŭ�� ��� �޸� ����
	(*stack)->capacity = capacity; //�Էµ� capacity ����
	(*stack)->top = 0; //top �ʱ�ȭ
}

void destroyStack(ArrayStack* stack)
{
	free(stack->Nodes); //��� �޸� ����
	free(stack); //���� �޸� ����
}

void Push(ArrayStack* stack, ElementType data)
{
	stack->Nodes[stack->top++].data = data; //��� �ֻ��� �ε����� data�� ���� �� top ���� ����
}

ElementType Pop(ArrayStack* stack)
{
	return stack->Nodes[--stack->top].data; //top�� ��� �ε������� +1 ũ�� ������ 1 ���� �� data�� ��ȯ
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