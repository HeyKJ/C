#pragma once
#define DEV
#ifdef DEV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* data; //���ڿ��� �����ϱ� ���� char ������ ����
	struct tagNode* nextNode;
} Node;

typedef struct tagLinkedListStack
{
	//int capacity; �迭�� �ƴϱ⶧���� ���� �Ҵ��� �����Ͽ� capacity(�뷮)�� �ʿ� ����
	Node* headNode; //��ũ�� ����Ʈ ���� ��带 �ٶ󺸴� ������ ����
	Node* topNode; //��ũ�� ����Ʈ ���� ����� �ֻ���(����) ��带 �ٶ󺸴� ������ ����
				   //��� topNode�� �ʿ���� ������ ���� ��带 ã�� ���ؼ� headNode���� ���� Ž��(����)�� ���ƾ� ��
} LinkedListStack;

void createStack(LinkedListStack** stack); //���� ����
void destroyStack(LinkedListStack* stack); //���� �Ҹ�
Node* createNode(char* newData); //��� ����
void destroyNode(Node* node); //��� �Ҹ�
int isEmpty(LinkedListStack* stack); //���� empty ���� ��ȯ 
int getSize(LinkedListStack* stack); //���� ���� ��ȯ
void Push(LinkedListStack* stack, Node* newNode); //���� ����
Node* Pop(LinkedListStack* stack); //���� ��ȯ
void printStackStatus(LinkedListStack* stack); //���� ���� ���
Node* getTop(LinkedListStack* stack); //�ֻ���(����) ��� ��ȯ

#endif