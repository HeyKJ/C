#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
	int data;
	struct Node *leftChildNode;
	struct Node *rightChildNode;
} Node;

Node* createNode(int newData); //��� ����
void destroyNode(Node *destroyNode); //��� �Ҹ�
void insertTree(Node *rootNode, Node *newNode); //���� Ž�� Ʈ���� ��� �߰�
Node* binarySearch(Node *rootNode, int targetData); //���� Ž��
Node* findMinNode(Node *rootNode); //���� Ž��:�ּҰ�
void printTree(Node *rootNode, int depth); //Ʈ�� ���
void destroyTree(Node *rootNode); //Ʈ�� �Ҹ�
Node* removeNode(Node *rootNode, int targetData); //Ư�� ��带 Ʈ������ ����
Node* findParentNode(Node *rootNode, Node *childNode); //�θ� ��� ã��

int main()
{
	Node *rootNode = NULL;
	Node *newNode = NULL;
	srand(time(NULL));
	int targetData = -1;

	for (int i = 0; i <= 5;)
	{
		if (i == 0)
		{
			rootNode = createNode(rand() % 100);
			i++;
			continue;
		}

		int data = rand() % 100;

		if (binarySearch(rootNode, data) != NULL)
			continue;
		else
		{
			newNode = createNode(data);
			
			if (i == 1)
				targetData = newNode->data;

			insertTree(rootNode, newNode);
			i++;
		}
	}

	printTree(rootNode, 0);

	Node *minNode = findMinNode(rootNode);
	printf("�ּҰ� : %d\n", minNode->data);

	Node *targetNode = binarySearch(rootNode, targetData);
	if (targetNode == NULL)
		printf("%d�� ã�� ���߽��ϴ�.\n",targetData);
	else
		printf("%d�� ã�ҽ��ϴ�!\n", targetData);

	Node *parentNode = findParentNode(rootNode, targetNode);
	if (parentNode == NULL)
		printf("�θ� ��尡 �����ϴ�.\n");
	else
		printf("�θ� ����� �� : %d\n", parentNode->data);
	
	removeNode(rootNode, targetData);

	printTree(rootNode, 0);
	destroyTree(rootNode);
	return 0;
}

Node* createNode(int newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->leftChildNode = NULL;
	newNode->rightChildNode = NULL;
	return newNode;
}

void destroyNode(Node *destroyNode)
{
	if (destroyNode != NULL)
		free(destroyNode);
}

void insertTree(Node *rootNode, Node *newNode)
{
	if (rootNode->data == newNode->data)
		return;
	else if (rootNode->data > newNode->data)
	{
		if (rootNode->leftChildNode == NULL)
			rootNode->leftChildNode = newNode;
		else
			insertTree(rootNode->leftChildNode, newNode);
	}
	else
	{
		if (rootNode->rightChildNode == NULL)
			rootNode->rightChildNode = newNode;
		else
			insertTree(rootNode->rightChildNode, newNode);
	}
}

Node* binarySearch(Node *rootNode, int targetData)
{
	if (rootNode == NULL)
		return NULL;
	
	if (rootNode->data == targetData)
		return rootNode;
	else if (rootNode->data < targetData)
		binarySearch(rootNode->rightChildNode, targetData);
	else
		binarySearch(rootNode->leftChildNode, targetData);
}

Node* findMinNode(Node *rootNode)
{
	if (rootNode->leftChildNode != NULL)
		findMinNode(rootNode->leftChildNode);
	else
		return rootNode;
}

void printTree(Node *rootNode, int depth)
{
	for (int i = 0; i < depth; i++)
		printf("\t");

	if (rootNode == NULL)
	{
		printf("NULL(%d)\n", depth);
		return;
	}
	else
	{
		printf("%d(%d)\n", rootNode->data, depth);
	}

	printTree(rootNode->leftChildNode, depth+1);
	printTree(rootNode->rightChildNode, depth+1);
}

void destroyTree(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	destroyTree(rootNode->leftChildNode);
	destroyTree(rootNode->rightChildNode);
	destroyNode(rootNode);
}

Node* removeNode(Node *rootNode, int targetData)
{
	if (rootNode == NULL)
		return NULL;

	Node *rNode = binarySearch(rootNode, targetData);
	Node *parentNode = NULL;

	if (rNode == NULL)
		return NULL;
	else
		parentNode = findParentNode(rootNode, rNode);

	if (rNode->leftChildNode == NULL && rNode->rightChildNode == NULL)
	{
		if (parentNode->leftChildNode == rNode)
			parentNode->leftChildNode = NULL;
		else 
			parentNode->rightChildNode = NULL;

		destroyNode(rNode);
	}
	else if (rNode->leftChildNode != NULL && rNode->rightChildNode != NULL)
	{
		/*
			���� ��尡 ���� �ڽ��� ��� �����ִٸ� ���� ����� ������ �ڽĵ� �߿��� ������ ��带 ���� �� ��ȯ�մϴ�.
			��ȯ�� ���� ���� ���� ��忡 ��ġ�մϴ�.
		*/
		int minData = findMinNode(rNode->rightChildNode)->data;
		removeNode(rNode, minData);
		rNode->data = minData;
	}
	else
	{
		Node *temp = NULL;

		if (rNode->leftChildNode != NULL)
			temp = rNode->leftChildNode;
		else
			temp = rNode->rightChildNode;

		if (parentNode->leftChildNode == rNode)
			parentNode->leftChildNode = temp;
		else
			parentNode->rightChildNode = temp;
	}

	return rNode;
}

Node* findParentNode(Node *rootNode, Node *childNode)
{
	if (rootNode == NULL || rootNode == childNode)
		return NULL;

	if (rootNode->leftChildNode == childNode || rootNode->rightChildNode == childNode)
		return rootNode;
	else
	{
		findParentNode(rootNode->leftChildNode, childNode);
		findParentNode(rootNode->rightChildNode, childNode);
	}
}