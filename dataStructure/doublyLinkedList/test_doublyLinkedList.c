#include "doublyLinkedList.h"

void printfNodeList(Node* list); //��� ����Ʈ ���

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

	/*���ο� ��� ��� 2�� �߰�*/
	newNode = createNode(-1);
	insertNewHead(&list, newNode); //list�� -1���� ���� ��带 ��� ���� �߰�
	
	newNode = createNode(-2);
	insertNewHead(&list, newNode); //list�� -2���� ���� ��带 ��� ���� �߰�

	/*����Ʈ ���*/
	printfNodeList(list);

	//����Ʈ ����° ��忡 ���ο� ��带 ����
	printf("\ninsert newNode after thrid node...\n\n");
	currentNode = getNodeAt(list, 2); //����°�� �ִ� ��� ��ȯ
	newNode = createNode(3000); //3000���� ���� ���ο� ��带 ����
	insertAfter(currentNode, newNode); //����° ��� �ڿ� newNode�� ����
	
	/*����Ʈ ���*/
	printfNodeList(list);

	/*����Ʈ �׹�° ��带 ����*/
	printf("\nafter remove forth node...\n\n");
	currentNode = getNodeAt(list, 3);
	removeNode(&list, currentNode);
	destoryNode(currentNode);

	/*����Ʈ ���*/
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
		printf("list[%d][%u] : %d\n", i, currentNode, currentNode->data);
	}
}