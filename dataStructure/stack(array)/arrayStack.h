#pragma once
#define DEV
#ifdef DEV

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType data;
} Node;

typedef struct tagArrayStack
{
	int capacity; //���� �뷮
	int top; //��� �迭 �ֻ��� �ε���
	Node* Nodes; //��� �迭
} ArrayStack;

void createStack(ArrayStack** stack, int capacity); //���� ����
void destroyStack(ArrayStack* stack); //���� �Ҹ�
void Push(ArrayStack* stack, ElementType data); //������ ����
ElementType Pop(ArrayStack* stack); //������ ����(��ȯ)
int getSize(ArrayStack* stack); //���� ������ ��ȯ
int isEmpty(ArrayStack* stack); //���� empty ���� ��ȯ
void printStackStatus(ArrayStack* stack); //���� ���� ���

#endif // DEV
