#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	int searchCount;
	struct Node *nextNode;
} Node;

Node* createNode(int newData); //노드 생성
Node* cloneNode(Node *orgNode); //노드 복제
void destroyNode(Node *destroyNode); //노드 소멸
void append(Node **headNode, Node *newNode); //테일 노드 추가
void insert(Node *targetNode, Node *newNode); //targertNode 이후에 newNode를 추가
void Remove(Node **headNode, Node *removeNode); //링크드 리스트에서 removeNode 제거
void removeLinkedList(Node *removeNode); //링크드 리스트 소멸
void printLinkedList(Node *headNode); //링크드 리스트 출력
Node* sequentialSearch(Node *headNode, int targetData); //순차 탐색
Node* moveToFrontSearch(Node **headNode, int targetData); //순차 탐색:전진 이동법
Node* transposeSearch(Node **headNode, int targetData); //순차 탐색:전위법
Node* frequencyCount(Node **headNode, int targetData); //순차 탐색:빈도 계수법
int getIndex(Node *headNode, Node *targetNode);  //찾고자 하는 노드의 인덱스 반환
Node* getNode(Node *headNode, int targetIndex); //targetIndex 위치에 있는 노드 반환

int main()
{
	Node *headNode = createNode(0);
	Node *newNode = NULL;

	/*0~10까지 데이터 삽입*/
	for (int i = 1; i <= 10; i++)
	{
		newNode = createNode(i);
		append(&headNode, newNode);
	}

	printf("데이터 삽입 완료 후 링크드 리스트는 아래와 같이 나열되어 있다.\n");
	printLinkedList(headNode);
	printf("\n");

	/*데이터 3을 가진 노드를 순차 탐색*/
	printf("\n데이터 3을 가진 노드 순차 탐색\n");
	Node *targetNode = sequentialSearch(headNode, 3);
	printf("노드를 찾았나? : %d\n", targetNode != NULL);

	if (targetNode != NULL)
		printf("찾은 노드의 데이터 : %d\n", targetNode->data);
	
	printf("\n");

	/*데이터 3을 가진 노드를 순차 탐색(전진 이동법)*/
	printf("\n전진 이동법\n");
	targetNode = moveToFrontSearch(&headNode, 3);

	printf("\n탐색된 노드는 가장 앞에 위치한다.\n");
	printLinkedList(headNode);

	for (int i = 0; i < 10; i++)
	{
		/*데이터 10을 가진 노드를 순차 탐색(전위법)*/
		printf("\n전위법\n");
		targetNode = transposeSearch(&headNode, 10);

		printf("\n데이터 10이 탐색될 때 마다 앞으로 한칸씩 이동한다.\n");
		printLinkedList(headNode);
	}
	
	printf("\n");

	printf("\n빈도 계수법\n");
	printf("\n데이터가 탐색될 때 마다 탐색 횟수가 증가하며 리스트는 탐색 횟수 내림차순으로 나열된다.\n");
	frequencyCount(&headNode, 0);
	printLinkedList(headNode);

	printf("\n데이터가 탐색될 때 마다 탐색 횟수가 증가하며 리스트는 탐색 횟수 내림차순으로 나열된다.\n");
	frequencyCount(&headNode, 0);
	printLinkedList(headNode);

	printf("\n데이터가 탐색될 때 마다 탐색 횟수가 증가하며 리스트는 탐색 횟수 내림차순으로 나열된다.\n");
	frequencyCount(&headNode, 1);
	printLinkedList(headNode);

	printf("\n데이터가 탐색될 때 마다 탐색 횟수가 증가하며 리스트는 탐색 횟수 내림차순으로 나열된다.\n");
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