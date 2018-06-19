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

Node* createNode(ElemnetType newData); //��� ����
void destoryNode(Node* node); //��� �Ҹ�
void appendNode(Node** headNode, Node* newNode); //��� �߰�
void insertAfter(Node* currentNode, Node* newNode); //Ư�� ����� ���� ��� �߰�
void insertNewHead(Node** headNode, Node* newHeadNode); //��� ��� �߰�
void removeNode(Node** headNode, Node* removeNode); //��� ����
Node* getNodeAt(Node* headNode, int location); //Ư�� ��ġ�� �ִ� ��� ���ϱ�
int getNodeCount(Node* headNode); //��� ���� ���ϱ�

#endif
