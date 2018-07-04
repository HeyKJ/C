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
	int count; //������ ����
} LinkedQueue;

LinkedQueue* createLinkedQueue(); //��ũ�� ť ����
void destroyLinkedQueue(LinkedQueue *linkedQueue); //��ũ�� ť �Ҹ�
Node* createNode(int newData); //��� ����
void destroyNode(Node* node); //��� �Ҹ�
int isEmpty(LinkedQueue *linkedQueue);
void enQueue(LinkedQueue *linkedQueue, int newData); //������ ����
Node* deQueue(LinkedQueue *linkedQueue); //������ ����

int main()
{
	/*��ũ�� ť ����*/
	printf("create linkedQueue...\n");
	LinkedQueue *linkedQueue = createLinkedQueue();

	/*������ ����*/
	printf("\ninsert data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("enqueue : %d\n", i);
		enQueue(linkedQueue, i);
	}

	/*������ ����*/
	printf("\ndelete data...\n");
	for (int i = 0; i < 11; i++)
	{
		Node *deQueueNode = deQueue(linkedQueue);
		printf("[%d] dequeue : %d\n", i, deQueueNode->data);
		destroyNode(deQueueNode);
	}

	/*������ ����*/
	printf("\ninsert data...\n");
	enQueue(linkedQueue, 10);
	enQueue(linkedQueue, 11);
	printf("enqueue : %d\n", 10);
	printf("enqueue : %d\n", 11);

	/*��ũ�� ť �Ҹ�*/
	destroyLinkedQueue(linkedQueue);

	return 0;
}

LinkedQueue* createLinkedQueue()
{
	LinkedQueue *linkedQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue)); //��ũ�� ť �޸� ����
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