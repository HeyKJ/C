#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
} Node;

typedef struct CircularQueue
{
	int capacity; //배열 크기
	int firstIndex; //전단 인덱스
	int rearIndex; //후단 인덱스
	int count; //현재 순환큐에 저장된 데이터 개수
	Node *Nodes;
} CircularQueue;

CircularQueue* createCircularQueue(int capacity); //순환큐 생성
void destroyCircularQueue(CircularQueue *circularQueue); //순환큐 소멸
int isEmpty(CircularQueue *circularQueue);
int isFull(CircularQueue *circularQueue);
void enQueue(CircularQueue *circularQueue, int newData); //데이터 삽입
int deQueue(CircularQueue *circularQueue); //데이터 삭제

int main()
{
	/*순환큐 생성*/
	printf("create circularQueue...\n");
	CircularQueue *circularQueue = createCircularQueue(10);

	/*데이터 삽입*/
	printf("\ninsert data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("enqueue : %d\n", i);
		enQueue(circularQueue, i);
	}

	enQueue(circularQueue, 100); //Queue is Full!

	/*데이터 제거*/
	printf("\ndelete data...\n");
	for (int i = 0; i < 10; i++)
	{
		printf("dequeue : %d\n", deQueue(circularQueue));
	}

	/*데이터 삽입*/
	printf("\ninsert data...\n");
	enQueue(circularQueue, 10);
	enQueue(circularQueue, 11);
	printf("enqueue : %d\n", 10);
	printf("enqueue : %d\n", 11);

	/*데이터 제거*/
	printf("\ndelete data...\n");
	printf("dequeue : %d\n", deQueue(circularQueue));
	printf("dequeue : %d\n", deQueue(circularQueue));
	printf("dequeue : %d\n", deQueue(circularQueue)); //empty

	/*순환큐 소멸*/
	destroyCircularQueue(circularQueue);
	
	return 0;
}

CircularQueue* createCircularQueue(int capacity)
{
	CircularQueue *circularQueue = (CircularQueue*)malloc(sizeof(CircularQueue)); //순환큐 메모리 생성
	circularQueue->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1)); //노드 배열 메모리 생성, 더미 노드를 하나 더 생성하기 때문에 capacity + 1이 된다.
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