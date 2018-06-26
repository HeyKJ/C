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
	int capacity; //스택 용량
	int top; //노드 배열 최상위 인덱스
	Node* Nodes; //노드 배열
} ArrayStack;

void createStack(ArrayStack** stack, int capacity); //스택 생성
void destroyStack(ArrayStack* stack); //스택 소멸
void Push(ArrayStack* stack, ElementType data); //데이터 삽입
ElementType Pop(ArrayStack* stack); //데이터 제거(반환)
int getSize(ArrayStack* stack); //스택 사이즈 반환
int isEmpty(ArrayStack* stack); //스택 empty 여부 반환
void printStackStatus(ArrayStack* stack); //스택 상태 출력

#endif // DEV
