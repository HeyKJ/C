#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *data;
	struct Node *leftNode;
	struct Node *rightNode;
} Node;

Node* createNode(char *newData); //��� ����
void destroyNode(Node *destoryNode); //��� ����
void destroyTree(Node *rootNode); //Ʈ�� �Ҹ�
void printPreorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���
void printInorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���
void printPostorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���

int main()
{
	/*��� ����*/
	Node *rootNode = createNode("A");
	Node *bNode = createNode("B");
	Node *cNode = createNode("C");
	Node *dNode = createNode("D");
	Node *eNode = createNode("E");
	Node *fNode = createNode("F");
	Node *gNode = createNode("G");

	rootNode->leftNode = bNode;
	bNode->leftNode = cNode;
	bNode->rightNode = dNode;

	rootNode->rightNode = eNode;
	eNode->leftNode = fNode;
	eNode->rightNode = gNode;
	
	/*���� ��ȸ�� ������ Ʈ�� ���*/
	printf("preorder...\n");
	printPreorderTreeTraversal(rootNode);
	printf("\n\n");

	/*���� ��ȸ�� ������ Ʈ�� ���*/
	printf("inorder...\n");
	printInorderTreeTraversal(rootNode);
	printf("\n\n");

	/*���� ��ȸ�� ������ Ʈ�� ���*/
	printf("postorder...\n");
	printPostorderTreeTraversal(rootNode);
	printf("\n\n");

	/*Ʈ�� �Ҹ�*/
	destroyTree(rootNode);
	return 0;
}

Node* createNode(char *newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(newData) + 1);
	strcpy_s(newNode->data, sizeof(newNode->data), newData);
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

void destroyNode(Node *destoryNode)
{
	if (destoryNode != NULL)
	{
		free(destoryNode);
	}
}

void destroyTree(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	//Ʈ�� �Ҹ��� ���� ��ȸ�� �̿�
	destroyNode(rootNode->leftNode);
	destroyNode(rootNode->rightNode);
	free(rootNode);
}

void printPreorderTreeTraversal(Node *rootNode)
{
	if (rootNode == NULL)
		return;
		
	printf("%s\t", rootNode->data);
	printPreorderTreeTraversal(rootNode->leftNode);
	printPreorderTreeTraversal(rootNode->rightNode);
}

void printInorderTreeTraversal(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	printInorderTreeTraversal(rootNode->leftNode);
	printf("%s\t", rootNode->data);
	printInorderTreeTraversal(rootNode->rightNode);
}

void printPostorderTreeTraversal(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	printPostorderTreeTraversal(rootNode->leftNode);
	printPostorderTreeTraversal(rootNode->rightNode);
	printf("%s\t", rootNode->data);
}