#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	int searchCount;
	struct Node *nextNode;
} Node;

Node* createNode(int newData); //��� ����
Node* cloneNode(Node *orgNode); //��� ����
void destroyNode(Node *destroyNode); //��� �Ҹ�
void append(Node **headNode, Node *newNode); //���� ��� �߰�
void insert(Node *targetNode, Node *newNode); //targertNode ���Ŀ� newNode�� �߰�
void Remove(Node **headNode, Node *removeNode); //��ũ�� ����Ʈ���� removeNode ����
void removeLinkedList(Node *removeNode); //��ũ�� ����Ʈ �Ҹ�
void printLinkedList(Node *headNode); //��ũ�� ����Ʈ ���
Node* sequentialSearch(Node *headNode, int targetData); //���� Ž��
Node* moveToFrontSearch(Node **headNode, int targetData); //���� Ž��:���� �̵���
Node* transposeSearch(Node **headNode, int targetData); //���� Ž��:������
Node* frequencyCount(Node **headNode, int targetData); //���� Ž��:�� �����
int getIndex(Node *headNode, Node *targetNode);  //ã���� �ϴ� ����� �ε��� ��ȯ
Node* getNode(Node *headNode, int targetIndex); //targetIndex ��ġ�� �ִ� ��� ��ȯ

int main()
{
	Node *headNode = createNode(0);
	Node *newNode = NULL;

	/*0~10���� ������ ����*/
	for (int i = 1; i <= 10; i++)
	{
		newNode = createNode(i);
		append(&headNode, newNode);
	}

	printf("������ ���� �Ϸ� �� ��ũ�� ����Ʈ�� �Ʒ��� ���� �����Ǿ� �ִ�.\n");
	printLinkedList(headNode);
	printf("\n");

	/*������ 3�� ���� ��带 ���� Ž��*/
	printf("\n������ 3�� ���� ��� ���� Ž��\n");
	Node *targetNode = sequentialSearch(headNode, 3);
	printf("��带 ã�ҳ�? : %d\n", targetNode != NULL);

	if (targetNode != NULL)
		printf("ã�� ����� ������ : %d\n", targetNode->data);
	
	printf("\n");

	/*������ 3�� ���� ��带 ���� Ž��(���� �̵���)*/
	printf("\n���� �̵���\n");
	targetNode = moveToFrontSearch(&headNode, 3);

	printf("\nŽ���� ���� ���� �տ� ��ġ�Ѵ�.\n");
	printLinkedList(headNode);

	for (int i = 0; i < 10; i++)
	{
		/*������ 10�� ���� ��带 ���� Ž��(������)*/
		printf("\n������\n");
		targetNode = transposeSearch(&headNode, 10);

		printf("\n������ 10�� Ž���� �� ���� ������ ��ĭ�� �̵��Ѵ�.\n");
		printLinkedList(headNode);
	}
	
	printf("\n");

	printf("\n�� �����\n");
	printf("\n�����Ͱ� Ž���� �� ���� Ž�� Ƚ���� �����ϸ� ����Ʈ�� Ž�� Ƚ�� ������������ �����ȴ�.\n");
	frequencyCount(&headNode, 0);
	printLinkedList(headNode);

	printf("\n�����Ͱ� Ž���� �� ���� Ž�� Ƚ���� �����ϸ� ����Ʈ�� Ž�� Ƚ�� ������������ �����ȴ�.\n");
	frequencyCount(&headNode, 0);
	printLinkedList(headNode);

	printf("\n�����Ͱ� Ž���� �� ���� Ž�� Ƚ���� �����ϸ� ����Ʈ�� Ž�� Ƚ�� ������������ �����ȴ�.\n");
	frequencyCount(&headNode, 1);
	printLinkedList(headNode);

	printf("\n�����Ͱ� Ž���� �� ���� Ž�� Ƚ���� �����ϸ� ����Ʈ�� Ž�� Ƚ�� ������������ �����ȴ�.\n");
	frequencyCount(&headNode, 2);
	printLinkedList(headNode);

	removeLinkedList(headNode);
	return 0;
}

Node* createNode(int newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->searchCount = 0;
	newNode->nextNode = NULL;
	return newNode;
}

Node* cloneNode(Node *orgNode)
{
	Node *cloneNode = (Node*)malloc(sizeof(Node));
	cloneNode->data = orgNode->data;
	cloneNode->searchCount = orgNode->searchCount;
	cloneNode->nextNode = orgNode->nextNode;
	return cloneNode;
}

void destroyNode(Node *destroyNode)
{
	if (destroyNode != NULL)
		free(destroyNode);
}

void append(Node **headNode, Node *newNode)
{
	if (*headNode == NULL)
	{
		*headNode = newNode;
	}
	else
	{
		Node *currentNode = *headNode;

		while (currentNode->nextNode != NULL)
		{
			currentNode = currentNode->nextNode;
		}

		currentNode->nextNode = newNode;
	}
}

void insert(Node *targetNode, Node *newNode)
{
	if (targetNode->nextNode == NULL)
		targetNode->nextNode = newNode;
	else
	{
		Node *targetNextNode = targetNode->nextNode;
		targetNode->nextNode = newNode;
		newNode->nextNode = targetNextNode;
	}
}

void Remove(Node **headNode, Node *removeNode)
{
	if (*headNode == removeNode)
	{
		*headNode = removeNode->nextNode;
	}
	else
	{
		Node *currentNode = *headNode;

		while (currentNode->nextNode != removeNode)
		{
			currentNode = currentNode->nextNode;
		}

		currentNode->nextNode = removeNode->nextNode;
		destroyNode(removeNode);
	}
}

void removeLinkedList(Node *removeNode)
{
	if (removeNode != NULL && removeNode->nextNode != NULL)
		removeLinkedList(removeNode->nextNode);
	
	destroyNode(removeNode);
}

void printLinkedList(Node *headNode)
{
	Node *currentNode = headNode;

	while (currentNode != NULL)
	{
		printf("%d\t", currentNode->data);
		currentNode = currentNode->nextNode;
	}

	printf("\n");
}

Node* sequentialSearch(Node *headNode, int targetData)
{
	Node *currentNode = headNode;

	while (currentNode != NULL && currentNode->data != targetData)
	{
		currentNode = currentNode->nextNode;
	}

	return currentNode;
}

Node* moveToFrontSearch(Node **headNode, int targetData)
{
	Node *targetNode = sequentialSearch(*headNode, targetData);
	Node *cloneTargetNode = NULL;

	if (targetNode == NULL)
		return NULL;
	else
	{
		cloneTargetNode = cloneNode(targetNode);
		Remove(headNode, targetNode);

		Node *orgHeadNode = *headNode;

		*headNode = cloneTargetNode;
		(*headNode)->nextNode = orgHeadNode;
		return (*headNode);
	}
}

Node* transposeSearch(Node **headNode, int targetData)
{
	if ((*headNode)->data == targetData)
	{
		return *headNode;
	}

	if ((*headNode)->nextNode->data == targetData)
	{
		Node *orgHeadNode = *headNode;
		Node *targetNode = orgHeadNode->nextNode;
		orgHeadNode->nextNode = targetNode->nextNode;
		targetNode->nextNode = orgHeadNode;
		*headNode = targetNode;
		return *headNode;
	}

	Node *targetNode = sequentialSearch(*headNode, targetData);

	if (targetNode == NULL)
		return NULL;

	int targetIndex = getIndex(*headNode, targetNode);

	if (targetIndex == -1)
		return NULL;

	Node *targetPrevNode = getNode(*headNode, targetIndex - 1);
	Node *targetPrevPrevNode = getNode(*headNode, targetIndex - 2);

	targetPrevPrevNode->nextNode = targetNode;
	targetPrevNode->nextNode = targetNode->nextNode;
	targetNode->nextNode = targetPrevNode;
	return targetNode;
}

Node* frequencyCount(Node **headNode, int targetData)
{
	Node *targetNode = sequentialSearch(*headNode, targetData);

	if (targetNode == NULL)
		return NULL;
	else
		targetNode->searchCount++;

	if (*headNode == targetNode)
		return *headNode;

	Node *currentNode = *headNode;
	int targetSearchCount = targetNode->searchCount;
	int find = 0;

	while (currentNode != NULL)
	{
		if (currentNode == targetNode)
			break;

		if (currentNode->searchCount <= targetSearchCount)
		{
			find = 1;
			break;
		}
		else
			currentNode = currentNode->nextNode;
	}

	if (find == 0)
		return targetNode;
	else
	{
		Node *cloneTargetNode = cloneNode(targetNode);
		Remove(headNode, targetNode);

		int currentIndex = getIndex(*headNode, currentNode);

		if (currentIndex == 0)
		{
			Node *orgHeadNode = currentNode;
			cloneTargetNode->nextNode = orgHeadNode;
			*headNode = cloneTargetNode;
		}
		else
		{
			Node *currentPrevNode = getNode(*headNode, currentIndex - 1);
			insert(currentPrevNode, cloneTargetNode);
		}

		return cloneTargetNode;
	}
}

int getIndex(Node *headNode, Node *targetNode)
{
	int index = 0;
	Node *currentNode = headNode;

	while (currentNode != NULL && currentNode != targetNode)
	{
		currentNode = currentNode->nextNode;
		index++;
	}

	if (currentNode == NULL)
		return -1;
	else
		return index;
}

Node* getNode(Node *headNode, int targetIndex)
{
	if (targetIndex < 0)
		return NULL;

	int index = 0;
	Node * currentNode = headNode;

	while (currentNode != NULL && index != targetIndex)
	{
		index++;
		currentNode = currentNode->nextNode;
	}

	if (index != targetIndex)
		return NULL;
	else
		return currentNode;
}