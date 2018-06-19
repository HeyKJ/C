#pragma once
#define DEV
#ifdef DEV

#include <stdio.h>
#include <stdlib.h>

typedef int ElemnetType;
typedef struct tagNode
{
	ElemnetType data;
	struct tagNode* nextNode;
} Node;

Node* createNode(ElemnetType newData); //노드 생성
void destoryNode(Node* node); //노드 소멸
void appendNode(Node** headNode, Node* newNode); //노드 추가
void insertAfter(Node* currentNode, Node* newNode); //특정 노드의 다음 노드 추가
void insertNewHead(Node** headNode, Node* newHeadNode); //헤드 노드 추가
void removeNode(Node** headNode, Node* removeNode); //노드 제거
Node* getNodeAt(Node* headNode, int location); //특정 위치에 있는 노드 구하기
int getNodeCount(Node* headNode); //노드 개수 구하기

#endif
