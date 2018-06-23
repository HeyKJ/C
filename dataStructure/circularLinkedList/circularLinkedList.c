#include "circularLinkedList.h"

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
		//최초 헤드 노드가 추가된다면 환형 링크드 리스트에선 이전 노드, 다음 노드도 헤드 노드이다
		*headNode = newNode;
		(*headNode)->prevNode = newNode;
		(*headNode)->nextNode = newNode;
	}
	else
	{
		//테일 노드와 헤드 노드 사이에 새로운 노드를 추가한다
		Node* tailNode = (*headNode)->prevNode;
		tailNode->nextNode->prevNode = newNode;
		tailNode->nextNode = newNode;
		newNode->nextNode = *headNode;
		newNode->prevNode = tailNode;
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
		removeNode->prevNode->nextNode = removeNode->nextNode;
		removeNode->nextNode->prevNode = removeNode->prevNode;
		(*headNode) = removeNode->nextNode;

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
		removeNode->prevNode->nextNode = removeNode->nextNode;
		removeNode->nextNode->prevNode = removeNode->prevNode;

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
		//환형 링크트 리스트이기 때문에 다시 헤드 노드로 돌아왔다면 break
		if (count > 0 && headNode == currentNode)
		{
			break;
		}

		currentNode = currentNode->nextNode;
		count++;
	}

	return count;
}
