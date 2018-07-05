#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *leftChildNode;
	struct Node *rightSiblingNode;
} Node;

Node* createNode(int newData); //노드 생성
void destroyTree(Node *destroyNode); //노드 소멸
void appendNode(Node *parentNode, Node *newChildNode); //노드 추가
void printTree(Node *node, int depth); //노드 구조 출력

int main()
{
	/*루트 노드 생성*/
	printf("create rootNode...\n");
	Node *rootNode = createNode(0);

	/*2개의 자식 노드 생성*/
	printf("\ncreate rootNode's childNode...\n");
	Node *childNode = createNode(1);
	appendNode(rootNode, childNode);

	printf("\ncreate rootNode's childNode...\n");
	childNode = createNode(2);
	appendNode(rootNode, childNode);

	/*마지막으로 추가된 자식 노드에 다시 자식 노드를 추가*/
	printf("\ncreate childNode's childNode...\n");
	Node *newChildNode = createNode(3);
	appendNode(childNode, newChildNode);

	/*트리 구조 출력*/
	printTree(rootNode, 0);

	/*트리 소멸*/
	destroyTree(rootNode);
	return 0;
}

Node* createNode(int newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); //노드 메모리 생성
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
	//자식 노드가 없을 경우
	if (parentNode->leftChildNode == NULL)
	{
		parentNode->leftChildNode = newChildNode;
		return;
	}

	Node *childNode = parentNode->leftChildNode;

	while (childNode->rightSiblingNode != NULL)
	{
		childNode = childNode->rightSiblingNode; //NULL이 나올 때 까지 다음 형제 노드로 이동
	}

	childNode->rightSiblingNode = newChildNode; //오른쪽에 새로운 형제 노드를 추가
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