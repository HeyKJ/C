#include "linkedList.h"

//��� ����
Node* createNode(ElemnetType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //���ο� ��� ���� �޸� �Ҵ�
	newNode->data = newData; //newData ������ ����
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
		*headNode = newNode;
	}
	else
	{
		Node* tailNode = *headNode;
		
		//��� ���� ���� �̵��Ѵ�
		while (tailNode->nextNode != NULL)
		{
			tailNode = tailNode->nextNode;
		}

		tailNode->nextNode = newNode; //������ ���� ��忡 �Դٸ� �� ���� ���� newNode�� �ٶ󺻴�

	}
}

//Ư�� ����� ���� ��� �߰�
void insertAfter(Node* currentNode, Node* newNode)
{
	/*
		headNode -> currentNode -> tailNode ������ ��尡 �����ߴٰ� �����ϸ�
		���� newNode�� currentNode ���Ŀ� �߰��Ǿ��ϹǷ� �Ʒ��� ����
		headNode -> currentNode -> newNode -> tailNode
		���� newNode�� ���� ���� tailNode�� �ٶ���� �ϸ�
		currentNode�� ���� ���� tailNode���� newNode�� �ٲ��
	*/
	newNode->nextNode = currentNode->nextNode;
	currentNode->nextNode = newNode;
}

//��� ��� �߰�
void insertNewHead(Node** headNode, Node* newHeadNode)
{
	//��� ��尡 ���ٸ� ���� �߰��� newHeadNode�� ��� ��尡 �ȴ�
	if (*headNode == NULL)
	{
		*headNode = newHeadNode;
	}
	else
	{
		/*
			headNode -> Node -> tailNode������ ��尡 �����ߴٰ� �����ϸ�
			newHeadNode -> headNode -> Node -> tailNode�� �Ǿ��ϹǷ�
			newHeadNode�� ���� ���� headNode�� �ǰ�
			���� headNode�� ���̻� ��� ��尡 �ƴϹǷ�
			��� ��带 newHeadNode�� �����Ѵ�
		*/
		newHeadNode->nextNode = *headNode;
		*headNode = newHeadNode;
	}
}

//��� ����
void removeNode(Node** headNode, Node* removeNode)
{
	//�����Ϸ��� ��尡 ��� ����� ���
	if (*headNode == removeNode)
	{
		/*
			headNode -> Node -> tailNode������ ��尡 �����ߴٰ� �����ϸ�
			headNode�� �������� �ϹǷ� Node -> tailNode�� �Ǿ� �Ѵ�
			���� ��� ���� Node�� �ȴ�
		*/
		*headNode = removeNode->nextNode;
	}
	else
	{
		Node* currentNode = *headNode;

		//��� ������ ���ʴ�� removeNode�� �ٶ󺸴� ��带 ã�´�
		while (currentNode != NULL && currentNode->nextNode != removeNode)
		{
			currentNode = currentNode->nextNode;
		}

		if (currentNode != NULL)
		{
			/*
				headNode -> currentNode -> removeNode -> Node -> tailNode������ ��尡 �����ߴٰ� �����ϸ�
				removeNode�� ���ŵǾ� �ϹǷ�
				headNode -> currentNode -> Node -> tailNode�� �Ǿ� �Ѵ�
				���� currentNode�� removeNode�� ���� ��带 �ٶ󺸸� �ȴ�
			*/
			currentNode->nextNode = removeNode->nextNode;
		}
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
		currentNode = currentNode->nextNode;
		count++;
	}

	return count;
}
