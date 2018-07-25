#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
	int data;
	struct Node *leftChildNode;
	struct Node *rightChildNode;
} Node;

Node* createNode(int newData); //노드 생성
void destroyNode(Node *destroyNode); //노드 소멸
void insertTree(Node *rootNode, Node *newNode); //이진 탐색 트리에 노드 추가
Node* binarySearch(Node *rootNode, int targetData); //이진 탐색
Node* findMinNode(Node *rootNode); //이진 탐색:최소값
void printTree(Node *rootNode, int depth); //트리 출력
void destroyTree(Node *rootNode); //트리 소멸
Node* removeNode(Node *rootNode, int targetData); //특정 노드를 트리에서 제거
Node* findParentNode(Node *rootNode, Node *childNode); //부모 노드 찾기

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
	printf("최소값 : %d\n", minNode->data);

	Node *targetNode = binarySearch(rootNode, targetData);
	if (targetNode == NULL)
		printf("%d를 찾지 못했습니다.\n",targetData);
	else
		printf("%d을 찾았습니다!\n", targetData);

	Node *parentNode = findParentNode(rootNode, targetNode);
	if (parentNode == NULL)
		printf("부모 노드가 없습니다.\n");
	else
		printf("부모 노드의 값 : %d\n", parentNode->data);
	
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
			지울 노드가 양쪽 자식을 모두 갖고있다면 지울 노드의 오른편 자식들 중에서 최하위 노드를 삭제 후 반환합니다.
			반환된 노드는 현재 지울 노드에 위치합니다.
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