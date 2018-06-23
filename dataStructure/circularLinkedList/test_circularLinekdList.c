#include "circularLinkedList.h"

void printfNodeList(Node* list);

int main()
{
	Node* list = NULL;
	Node* currentNode = NULL;
	Node* newNode = NULL;

	/*��� 5�� �߰�*/
	for (int i = 0; i < 5; i++)
	{
		newNode = createNode(i); //i���� ���� ���ο� ��带 ����
		appendNode(&list, newNode); //������ ��带 list�� �߰�
	}

    /*����Ʈ ���*/
	printfNodeList(list);

	//����Ʈ ����° ��忡 ���ο� ��带 ����
	printf("\ninsert newNode after thrid node...\n\n");
	currentNode = getNodeAt(list, 2); //����°�� �ִ� ��� ��ȯ
	newNode = createNode(3000); //3000���� ���� ���ο� ��带 ����
	insertAfter(currentNode, newNode); //����° ��� �ڿ� newNode�� ����

    /*����Ʈ ���*/
	printfNodeList(list);

	/*��� ����Ʈ�� ���̺��� 2�踸ŭ ������ ���� ȯ�� ��ũƮ ����Ʈ���� Ȯ��*/
	printf("\ndouble print..\n\n");

	for (int i = 0; i < getNodeCount(list) * 2; i++)
	{
		currentNode = getNodeAt(list, i); //list�� ��� ����� i��°�� ��ġ�� ��带 �����´�
		printf("list[%d] : %d\n", i, currentNode->data);
	}

	/*ù��° ��� ����*/
	printf("\nremove first node...\n\n");
	currentNode = getNodeAt(list, 0);
	removeNode(&list, currentNode);
	destoryNode(currentNode);
	printfNodeList(list);
	
	/*�ι�° ��� ����*/
	printf("\nremove second node...\n\n");
	currentNode = getNodeAt(list, 1);
	removeNode(&list, currentNode);
	destoryNode(currentNode);
	printfNodeList(list);

	/*��� ��� ����*/
	printf("\ndestroy all nodes..\n");
	int count = getNodeCount(list); //list�� ��� ��� ����
	for (int i = 0; i < count; i++)
	{
		currentNode = getNodeAt(list, i); //list�� ��� ����� i��°�� ��ġ�� ��带 �����´�

		if (currentNode != NULL)
		{
			removeNode(&list, currentNode); //list���� ����
			destoryNode(currentNode); //�ش� ��� �޸� ����
		}
	}

	return 0;
}

void printfNodeList(Node* list)
{
	Node* currentNode = NULL;
	int count = getNodeCount(list); //list�� ��� ��� ����

	for (int i = 0; i < count; i++)
	{
		currentNode = getNodeAt(list, i); //list�� ��� ����� i��°�� ��ġ�� ��带 �����´�
		printf("list[%d] : %d\n", i, currentNode->data);
	}
}