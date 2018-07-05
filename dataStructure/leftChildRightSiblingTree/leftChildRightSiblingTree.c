#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *leftChildNode;
	struct Node *rightSiblingNode;
} Node;

Node* createNode(int newData); //��� ����
void destroyTree(Node *destroyNode); //��� �Ҹ�
void appendNode(Node *parentNode, Node *newChildNode); //��� �߰�
void printTree(Node *node, int depth); //��� ���� ���

int main()
{
	/*��Ʈ ��� ����*/
	printf("create rootNode...\n");
	Node *rootNode = createNode(0);

	/*2���� �ڽ� ��� ����*/
	printf("\ncreate rootNode's childNode...\n");
	Node *childNode = createNode(1);
	appendNode(rootNode, childNode);

	printf("\ncreate rootNode's childNode...\n");
	childNode = createNode(2);
	appendNode(rootNode, childNode);

	/*���������� �߰��� �ڽ� ��忡 �ٽ� �ڽ� ��带 �߰�*/
	printf("\ncreate childNode's childNode...\n");
	Node *newChildNode = createNode(3);
	appendNode(childNode, newChildNode);

	/*Ʈ�� ���� ���*/
	printTree(rootNode, 0);

	/*Ʈ�� �Ҹ�*/
	destroyTree(rootNode);
	return 0;
}

Node* createNode(int newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); //��� �޸� ����
	newNode->data = newData;
	newNode->leftChildNode = NULL;
	newNode->rightSiblingNode = NULL;
	return newNode;
}

void destroyTree(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	if (rootNode->rightSiblingNode != NULL)
		destroyTree(rootNode->rightSiblingNode);

	if (rootNode->leftChildNode != NULL)
		destroyTree(rootNode->leftChildNode);

	rootNode->leftChildNode = NULL;
	rootNode->rightSiblingNode = NULL;
	free(rootNode);
}

void appendNode(Node *parentNode, Node *newChildNode)
{
	//�ڽ� ��尡 ���� ���
	if (parentNode->leftChildNode == NULL)
	{
		parentNode->leftChildNode = newChildNode;
		return;
	}

	Node *childNode = parentNode->leftChildNode;

	while (childNode->rightSiblingNode != NULL)
	{
		childNode = childNode->rightSiblingNode; //NULL�� ���� �� ���� ���� ���� ���� �̵�
	}

	childNode->rightSiblingNode = newChildNode; //�����ʿ� ���ο� ���� ��带 �߰�
}

void printTree(Node *node, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		printf("\t");
	}

	printf("%d\n", node->data);

	if (node->leftChildNode != NULL)
		printTree(node->leftChildNode, depth + 1);

	if(node->rightSiblingNode != NULL)
		printTree(node->rightSiblingNode, depth);
}