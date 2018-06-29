#pragma once
#define DEV
#ifdef DEV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* data; //문자열을 저장하기 위한 char 포인터 변수
	struct tagNode* nextNode;
} Node;

typedef struct tagLinkedListStack
{
	//int capacity; 배열이 아니기때문에 동적 할당이 가능하여 capacity(용량)이 필요 없음
	Node* headNode; //링크드 리스트 스택 노드를 바라보는 포인터 변수
	Node* topNode; //링크드 리스트 스택 노드의 최상위(테일) 노드를 바라보는 포인터 변수
				   //사실 topNode는 필요없음 하지만 테일 노드를 찾기 위해선 headNode부터 순차 탐색(루프)를 돌아야 함
} LinkedListStack;

void createStack(LinkedListStack** stack); //스택 생성
void destroyStack(LinkedListStack* stack); //스택 소멸
Node* createNode(char* newData); //노드 생성
void destroyNode(Node* node); //노드 소멸
int isEmpty(LinkedListStack* stack); //스택 empty 여부 반환 
int getSize(LinkedListStack* stack); //스택 길이 반환
void Push(LinkedListStack* stack, Node* newNode); //스택 삽입
Node* Pop(LinkedListStack* stack); //스택 반환
void printStackStatus(LinkedListStack* stack); //스택 상태 출력
Node* getTop(LinkedListStack* stack); //최상위(테일) 노드 반환

#endif