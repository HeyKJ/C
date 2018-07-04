#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *nextNode;
} Node;

typedef struct LinkedQueue
{
	Node *headNode;
	Node *rearNode;
	int count; //데이터 개수
} LinkedQueue;

LinkedQueue* createLinkedQueue(); //링크드 큐 생성
void destroyLinkedQueue(LinkedQueue *linkedQueue); //링크드 큐 소멸
Node* createNode(int newData); //노드 생성
void destroyNode(Node* node); //노드 소멸
int isEmpty(LinkedQueue *linkedQueue);
void enQueue(LinkedQueue *linkedQueue, int newData); //데이터 삽입
Node* deQueue(LinkedQueue *linkedQueue); //데이터 삭제

int main()
{
	/*링크드 큐 생성*/
	printf("create linkedQueue...\n");
	LinkedQueue *linkedQueue = createLinkedQueue();

	/*데이터 삽입*/
	printf("\ninsert data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("enqueue : %d\n", i);
		enQueue(linkedQueue, i);
	}

	/*데이터 제거*/
	printf("\ndelete data...\n");
	for (int i = 0; i < 11; i++)
	{
		Node *deQueueNode = deQueue(linkedQueue);
		printf("[%d] dequeue : %d\n", i, deQueueNode->data);
		destroyNode(deQueueNode);
	}

	/*데이터 삽입*/
	printf("\ninsert data...\n");
	enQueue(linkedQueue, 10);
	enQueue(linkedQueue, 11);
	printf("enqueue : %d\n", 10);
	printf("enqueue : %d\n", 11);

	/*링크드 큐 소멸*/
	destroyLinkedQueue(linkedQueue);

	return 0;
}

LinkedQueue* createLinkedQueue()
{
	LinkedQueue *linkedQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue)); //링크드 큐 메모리 생성
	linkedQueue->headNode = NULL;
	linkedQueue->rearNode = NULL;
	linkedQueue->count = 0;
	return linkedQueue;
}

void destroyLinkedQueue(LinkedQueue *linkedQueue)
{
	if (linkedQueue != NULL)
	{
		Node *currentNode = linkedQueue->headNode;
		
		while (currentNode != NULL)
		{
			free(currentNode);
			currentNode = currentNode->nextNode;
		}

		free(linkedQueue);
	}
}

Node* createNode(int newData)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = newData;
	node->nextNode = NULL;
	return node;
}

void destroyNode(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
}

int isEmpty(LinkedQueue *linkedQueue)
{
	return linkedQueue->count == 0;
}

void enQueue(LinkedQueue *linkedQueue, int newData)
{
	Node* newNode = createNode(newData);

	if (linkedQueue->count == 0)
	{
		linkedQueue->headNode = newNode;
		linkedQueue->rearNode = newNode;
	}
	else
	{
		linkedQueue->rearNode->nextNode = newNode;
		linkedQueue->rearNode = newNode;
	}
	
	linkedQueue->count++;
}

Node* deQueue(LinkedQueue *linkedQueue)
{
	if (isEmpty(linkedQueue))
	{
		printf("Queue is already empty!");
		return NULL;
	}

	Node *orgHeadNode = linkedQueue->headNode;
	linkedQueue->headNode = orgHeadNode->nextNode;
	orgHeadNode->nextNode = NULL;
	linkedQueue->count--;
	return orgHeadNode;
}