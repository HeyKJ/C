#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *data;
	struct Node *leftNode;
	struct Node *rightNode;
} Node;

Node* createNode(char *newData); //노드 생성
void destroyNode(Node *destoryNode); //노드 제거
void destroyTree(Node *rootNode); //트리 소멸
void printPreorderTreeTraversal(Node *rootNode); //트리 탐색 : 전위 순회로 출력
void printInorderTreeTraversal(Node *rootNode); //트리 탐색 : 중위 순회로 출력
void printPostorderTreeTraversal(Node *rootNode); //트리 탐색 : 후위 순회로 출력

int main()
{
	/*노드 생성*/
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
	
	/*전위 순회를 응용한 트리 출력*/
	printf("preorder...\n");
	printPreorderTreeTraversal(rootNode);
	printf("\n\n");

	/*중위 순회를 응용한 트리 출력*/
	printf("inorder...\n");
	printInorderTreeTraversal(rootNode);
	printf("\n\n");

	/*후위 순회를 응용한 트리 출력*/
	printf("postorder...\n");
	printPostorderTreeTraversal(rootNode);
	printf("\n\n");

	/*트리 소멸*/
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

	//트리 소멸은 후위 순회를 이용
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