#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
} Node;

typedef struct CircularQueue
{
	int capacity; //�迭 ũ��
	int firstIndex; //���� �ε���
	int rearIndex; //�Ĵ� �ε���
	int count; //���� ��ȯť�� ����� ������ ����
	Node *Nodes;
} CircularQueue;

CircularQueue* createCircularQueue(int capacity); //��ȯť ����
void destroyCircularQueue(CircularQueue *circularQueue); //��ȯť �Ҹ�
int isEmpty(CircularQueue *circularQueue);
int isFull(CircularQueue *circularQueue);
void enQueue(CircularQueue *circularQueue, int newData); //������ ����
int deQueue(CircularQueue *circularQueue); //������ ����

int main()
{
	/*��ȯť ����*/
	printf("create circularQueue...\n");
	CircularQueue *circularQueue = createCircularQueue(10);

	/*������ ����*/
	printf("\ninsert data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("enqueue : %d\n", i);
		enQueue(circularQueue, i);
	}

	enQueue(circularQueue, 100); //Queue is Full!

	/*������ ����*/
	printf("\ndelete data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("dequeue : %d\n", deQueue(circularQueue));
	}

	/*������ ����*/
	printf("\ninsert data...\n");
	enQueue(circularQueue, 10);
	enQueue(circularQueue, 11);
	printf("enqueue : %d\n", 10);
	printf("enqueue : %d\n", 11);

	/*������ ����*/
	printf("\ndelete data...\n");
	printf("dequeue : %d\n", deQueue(circularQueue));
	printf("dequeue : %d\n", deQueue(circularQueue));
	printf("dequeue : %d\n", deQueue(circularQueue)); //empty

	/*��ȯť �Ҹ�*/
	destroyCircularQueue(circularQueue);
	
	return 0;
}

CircularQueue* createCircularQueue(int capacity)
{
	CircularQueue *circularQueue = (CircularQueue*)malloc(sizeof(CircularQueue)); //��ȯť �޸� ����
	circularQueue->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1)); //��� �迭 �޸� ����, ���� ��带 �ϳ� �� �����ϱ� ������ capacity + 1�� �ȴ�.
	circularQueue->capacity = capacity;
	circularQueue->firstIndex = 0;
	circularQueue->rearIndex = 0;
	circularQueue->count = 0;
	return circularQueue;
}

void destroyCircularQueue(CircularQueue *circularQueue)
{
	if (circularQueue != NULL)
	{
		free(circularQueue->Nodes);
		free(circularQueue);
	}
}

int isEmpty(CircularQueue *circularQueue)
{
	return circularQueue->firstIndex == circularQueue->rearIndex;
}

int isFull(CircularQueue *circularQueue)
{
	int firstIndex = circularQueue->firstIndex;
	return circularQueue->count == circularQueue->capacity;
}

void enQueue(CircularQueue *circularQueue, int newData)
{
	if (isFull(circularQueue))
	{
		printf("Queue is Full!\n");
		return;
	}
	 
	int position = circularQueue->rearIndex++;

	if (circularQueue->rearIndex > circularQueue->capacity)
		circularQueue->rearIndex = 0;

	circularQueue->Nodes[position].data = newData;
	circularQueue->count++;
}

int deQueue(CircularQueue *circularQueue)
{
	if (isEmpty(circularQueue))
	{
		printf("Queue is Empty.. there is no data for return\n");
		return '\0';
	}

	int position = position = circularQueue->firstIndex++;
	
	if(circularQueue->firstIndex > circularQueue->capacity)
		circularQueue->firstIndex = 0;
	
	circularQueue->count--;
	return circularQueue->Nodes[position].data;
}