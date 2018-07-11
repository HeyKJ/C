#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void* data;
	struct Node *parentNode;
} Node;

Node* createNode(void* newData); //��� ����
void destroyNode(Node *destroyNode); //��� �Ҹ�
Node* findDisjointSet(Node *node); //���� �˻�
void unionDisjointSet(Node *node1, Node *node2); //������

int main()
{
	/*A ������ ��� ����*/
	Node *aRootNode = createNode("A");
	Node *aNode1 = createNode("A-1");
	Node *aNode2 = createNode("A-2");
	Node *aNode3 = createNode("A-3");
	aNode1->parentNode = aRootNode;
	aNode2->parentNode = aRootNode;
	aNode3->parentNode = aRootNode;

	/*B ������ ��� ����*/
	Node *bRootNode = createNode("B");
	Node *bNode1 = createNode("B-1");
	Node *bNode2 = createNode("B-2");
	Node *bNode3 = createNode("B-3");
	bNode1->parentNode = bRootNode;
	bNode2->parentNode = bRootNode;
	bNode3->parentNode = bRootNode;

	/*������ ��带 �����Ͽ� ���� �˻� ����*/
	printf("aNode2�� ���� �˻� ��� : %s\n", findDisjointSet(aNode2)->data); //��Ʈ ����� ������ A ���
	printf("bNode3�� ���� �˻� ��� : %s\n", findDisjointSet(bNode3)->data); //��Ʈ ����� ������ B ���

	/*�� ������ �и��Ǿ� �����Ƿ� ��Ʈ ��尡 �ٸ��� Ȯ��*/
	printf("A���� == B���� : %s\n", findDisjointSet(aNode2) == findDisjointSet(bNode3) ? "true" : "false");

	/*������*/
	printf("������ ����...\n");
	unionDisjointSet(aNode1, bNode2);

	/*�� ������ ���Ͽ����Ƿ� ��Ʈ ��尡 ������ Ȯ��*/
	printf("A���� == B���� : %s\n", findDisjointSet(aNode2) == findDisjointSet(bNode3) ? "true" : "false");

	/*��� �Ҹ�*/
	destroyNode(aRootNode);
	destroyNode(aNode1);
	destroyNode(aNode2);
	destroyNode(aNode3);
	destroyNode(bRootNode);
	destroyNode(bNode1);
	destroyNode(bNode2);
	destroyNode(bNode3);
	return 0;
}

Node* createNode(void* newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->parentNode = NULL;
	return newNode;
}

void destroyNode(Node *destroyNode)
{
	if (destroyNode != NULL)
		free(destroyNode);
}

Node* findDisjointSet(Node *node)
{
	/*���� �˻��� �Ҽӵ� ��� ��带 �˻��ϴ°� �ƴ϶� �ش� ������ ��ǥ�ϴ� ��Ʈ ��带 ã�� ��*/
	while (node->parentNode != NULL)
	{
		node = node->parentNode;
	}

	return node;
}

void unionDisjointSet(Node *node1, Node *node2)
{
	node1 = findDisjointSet(node1); //node1�� ��Ʈ ��带 �˻�
	node2 = findDisjointSet(node2); //node2�� ��Ʈ ��带 �˻�
	node2->parentNode = node1;
}