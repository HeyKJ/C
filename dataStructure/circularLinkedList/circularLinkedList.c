#include "circularLinkedList.h"

//��� ����
Node* createNode(ElemnetType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //���ο� ��� ���� �޸� �Ҵ�
	newNode->data = newData; //newData ������ ����
	newNode->prevNode = NULL; //���ο� ����̹Ƿ� ���� ���� NULL�� �ʱ�ȭ
	newNode->nextNode = NULL; //���ο� ����̹Ƿ� ���� ���� NULL�� �ʱ�ȭ
	return newNode;
}

//��� �Ҹ�
void destoryNode(Node* node)
{
	free(node); //�ش� ��� �޸� ����
}

//��� �߰�
void appendNode(Node** headNode, Node* newNode)
{
	//��� ��尡 NULL�̶�� ���� �߰��Ǵ� newNode�� ��� ��尡 �ȴ�
	if (*headNode == NULL)
	{
		//���� ��� ��尡 �߰��ȴٸ� ȯ�� ��ũ�� ����Ʈ���� ���� ���, ���� ��嵵 ��� ����̴�
		*headNode = newNode;
		(*headNode)->prevNode = newNode;
		(*headNode)->nextNode = newNode;
	}
	else
	{
		//���� ���� ��� ��� ���̿� ���ο� ��带 �߰��Ѵ�
		Node* tailNode = (*headNode)->prevNode;
		tailNode->nextNode->prevNode = newNode;
		tailNode->nextNode = newNode;
		newNode->nextNode = *headNode;
		newNode->prevNode = tailNode;
	}
}

//Ư�� ����� ���� ��� �߰�
void insertAfter(Node* currentNode, Node* newNode)
{
	/*
	headNode <-> currentNode <-> tailNode ������ ��尡 �����ߴٰ� �����ϸ�
	���� newNode�� currentNode ���Ŀ� �߰��Ǿ��ϹǷ� �Ʒ��� ����
	headNode <-> currentNode <-> newNode <-> tailNode
	���� newNode�� ���� ���� currentNode�� �ǰ� ���� ���� tailNode�� �ǰ�
	currentNode�� ���� ����� tailNode�� ���� ���� newNode�� �ٶ󺸰�
	currentNode�� ���� ���� newNode�� �ٶ󺻴�
	*/
	newNode->prevNode = currentNode;
	newNode->nextNode = currentNode->nextNode;

	if (currentNode->nextNode != NULL)
	{
		currentNode->nextNode->prevNode = newNode;
	}

	currentNode->nextNode = newNode;


}

//��� ����
void removeNode(Node** headNode, Node* removeNode)
{
	//�����Ϸ��� ��尡 ��� ����� ���
	if (*headNode == removeNode)
	{
		/*
		headNode <-> Node <-> tailNode������ ��尡 �����ߴٰ� �����ϸ�
		headNode�� �������� �ϹǷ� Node <-> tailNode�� �Ǿ� �Ѵ�
		���� ��� ���� Node�� �ȴ�
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
		headNode <-> currentNode <-> removeNode <-> Node <-> tailNode������ ��尡 �����ߴٰ� �����ϸ�
		removeNode�� ���ŵǾ� �ϹǷ�
		headNode <-> currentNode <-> Node <-> tailNode�� �Ǿ� �Ѵ�
		���� removeNode�� ���� ����� currentNode�� removeNode�� ���� ����� Node�� �ٶ󺸰�
		removeNode�� ���� ����� Node�� removeNode�� ���� ����� currentNode�� �ٶ󺻴�
		*/
		removeNode->prevNode->nextNode = removeNode->nextNode;
		removeNode->nextNode->prevNode = removeNode->prevNode;

		removeNode->prevNode = NULL;
		removeNode->nextNode = NULL;
	}
}

//Ư�� ��ġ�� �ִ� ��� ���ϱ�
Node* getNodeAt(Node* headNode, int location)
{
	Node* currentNode = headNode;

	while (currentNode != NULL && --location >= 0)
	{
		currentNode = currentNode->nextNode;
	}

	return currentNode;
}

//��� ���� ���ϱ�
int getNodeCount(Node* headNode)
{
	int count = 0;
	Node* currentNode = headNode;

	while (currentNode != NULL)
	{
		//ȯ�� ��ũƮ ����Ʈ�̱� ������ �ٽ� ��� ���� ���ƿԴٸ� break
		if (count > 0 && headNode == currentNode)
		{
			break;
		}

		currentNode = currentNode->nextNode;
		count++;
	}

	return count;
}
