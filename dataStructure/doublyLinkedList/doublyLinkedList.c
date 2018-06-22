#include "doublyLinkedList.h"

//노드 생성
Node* createNode(ElemnetType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //새로운 노드 동적 메모리 할당
	newNode->data = newData; //newData 데이터 저장
	newNode->prevNode = NULL; //새로운 노드이므로 이전 노드는 NULL로 초기화
	newNode->nextNode = NULL; //새로운 노드이므로 다음 노드는 NULL로 초기화
	return newNode;
}

//노드 소멸
void destoryNode(Node* node)
{
	free(node); //해당 노드 메모리 해제
}

//노드 추가
void appendNode(Node** headNode, Node* newNode)
{
	//헤드 노드가 NULL이라면 현재 추가되는 newNode가 헤드 노드가 된다
	if (*headNode == NULL)
	{
		*headNode = newNode;
	}
	else
	{
		Node* tailNode = *headNode;
		
		//계속 다음 노드로 이동한다
		while (tailNode->nextNode != NULL)
		{
			tailNode = tailNode->nextNode;
		}

		tailNode->nextNode = newNode; //마지막 테일 노드에 왔다면 그 다음 노드로 newNode를 바라본다
		newNode->prevNode = tailNode; //새로 추가되는 newNode는 tailNode 이후에 추가되는 노드이므로 neNode의 이전 노드는 tailNode를 바라본다
	}
}

//특정 노드의 다음 노드 추가
void insertAfter(Node* currentNode, Node* newNode)
{
	/*
		headNode <-> currentNode <-> tailNode 순으로 노드가 존재했다고 가정하면
		현재 newNode는 currentNode 이후에 추가되야하므로 아래와 같다
		headNode <-> currentNode <-> newNode <-> tailNode
		따라서 newNode의 이전 노드는 currentNode가 되고 다음 노드는 tailNode가 되고
		currentNode의 다음 노드인 tailNode의 이전 노드는 newNode를 바라보고
		currentNode의 다음 노드는 newNode를 바라본다
	*/
	newNode->prevNode = currentNode;
	newNode->nextNode = currentNode->nextNode;

	if (currentNode->nextNode != NULL)
	{
		currentNode->nextNode->prevNode = newNode;
	}

	currentNode->nextNode = newNode;
	
	
}

//헤드 노드 추가
void insertNewHead(Node** headNode, Node* newHeadNode)
{
	//헤드 노드가 없다면 새로 추가될 newHeadNode가 헤드 노드가 된다
	if (*headNode == NULL)
	{
		*headNode = newHeadNode;
	}
	else
	{
		/*
			headNode -> Node -> tailNode순으로 노드가 존재했다고 가정하면
			newHeadNode -> headNode -> Node -> tailNode가 되야하므로
			newHeadNode의 다음 노드는 headNode가 되고
			기존 headNode는 더이상 헤드 노드가 아니므로
			헤드 노드를 newHeadNode로 수정한다
		*/
		newHeadNode->nextNode = *headNode;
		*headNode = newHeadNode;
	}
}

//노드 제거
void removeNode(Node** headNode, Node* removeNode)
{
	//제거하려는 노드가 헤드 노드인 경우
	if (*headNode == removeNode)
	{
		/*
			headNode <-> Node <-> tailNode순으로 노드가 존재했다고 가정하면
			headNode가 지워져야 하므로 Node <-> tailNode가 되야 한다
			따라서 헤드 노드는 Node가 된다
		*/
		(*headNode) = removeNode->nextNode;

		if (removeNode->prevNode != NULL)
		{
			(*headNode)->prevNode = NULL;
		}

		removeNode->prevNode = NULL;
		removeNode->nextNode = NULL;
	}
	else
	{
		/*
		headNode <-> currentNode <-> removeNode <-> Node <-> tailNode순으로 노드가 존재했다고 가정하면
		removeNode는 제거되야 하므로
		headNode <-> currentNode <-> Node <-> tailNode가 되야 한다
		따라서 removeNode의 이전 노드인 currentNode는 removeNode의 다음 노드인 Node를 바라보고
		removeNode의 다음 노드인 Node는 removeNode의 이전 노드인 currentNode를 바라본다
		*/
		if (removeNode->prevNode != NULL)
		{
			removeNode->prevNode->nextNode = removeNode->nextNode;
		}

		if (removeNode->nextNode != NULL)
		{
			removeNode->nextNode->prevNode = removeNode->prevNode;
		}

		removeNode->prevNode = NULL;
		removeNode->nextNode = NULL;
	}
}

//특정 위치에 있는 노드 구하기
Node* getNodeAt(Node* headNode, int location)
{
	Node* currentNode = headNode;

	while (currentNode != NULL && --location >= 0)
	{
		currentNode = currentNode->nextNode;
	}

	return currentNode;
}

//노드 개수 구하기
int getNodeCount(Node* headNode)
{
	int count = 0;
	Node* currentNode = headNode;

	while (currentNode != NULL)
	{
		currentNode = currentNode->nextNode;
		count++;
	}

	return count;
}
