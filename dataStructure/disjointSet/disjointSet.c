#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void* data;
	struct Node *parentNode;
} Node;

Node* createNode(void* newData); //노드 생성
void destroyNode(Node *destroyNode); //노드 소멸
Node* findDisjointSet(Node *node); //집합 검색
void unionDisjointSet(Node *node1, Node *node2); //합집합

int main()
{
	/*A 집합의 노드 생성*/
	Node *aRootNode = createNode("A");
	Node *aNode1 = createNode("A-1");
	Node *aNode2 = createNode("A-2");
	Node *aNode3 = createNode("A-3");
	aNode1->parentNode = aRootNode;
	aNode2->parentNode = aRootNode;
	aNode3->parentNode = aRootNode;

	/*B 집합의 노드 생성*/
	Node *bRootNode = createNode("B");
	Node *bNode1 = createNode("B-1");
	Node *bNode2 = createNode("B-2");
	Node *bNode3 = createNode("B-3");
	bNode1->parentNode = bRootNode;
	bNode2->parentNode = bRootNode;
	bNode3->parentNode = bRootNode;

	/*임의의 노드를 선택하여 집합 검색 실행*/
	printf("aNode2의 집합 검색 결과 : %s\n", findDisjointSet(aNode2)->data); //루트 노드의 데이터 A 출력
	printf("bNode3의 집합 검색 결과 : %s\n", findDisjointSet(bNode3)->data); //루트 노드의 데이터 B 출력

	/*두 집합은 분리되어 있으므로 루트 노드가 다름을 확인*/
	printf("A집합 == B집합 : %s\n", findDisjointSet(aNode2) == findDisjointSet(bNode3) ? "true" : "false");

	/*합집합*/
	printf("합집합 실행...\n");
	unionDisjointSet(aNode1, bNode2);

	/*두 집합을 합하였으므로 루트 노드가 같음을 확인*/
	printf("A집합 == B집합 : %s\n", findDisjointSet(aNode2) == findDisjointSet(bNode3) ? "true" : "false");

	/*노드 소멸*/
	destroyNode(aRootNode);
	destroyNode(aNode1);
	destroyNode(aNode2);
	destroyNode(aNode3);
	destroyNode(bRootNode);
	destroyNode(bNode1);
	destroyNode(bNode2);
	destroyNode(bNode3);
	return 0;
}

Node* createNode(void* newData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->parentNode = NULL;
	return newNode;
}

void destroyNode(Node *destroyNode)
{
	if (destroyNode != NULL)
		free(destroyNode);
}

Node* findDisjointSet(Node *node)
{
	/*집합 검색은 소속된 모든 노드를 검색하는게 아니라 해당 집합을 대표하는 루트 노드를 찾는 것*/
	while (node->parentNode != NULL)
	{
		node = node->parentNode;
	}

	return node;
}

void unionDisjointSet(Node *node1, Node *node2)
{
	node1 = findDisjointSet(node1); //node1의 루트 노드를 검색
	node2 = findDisjointSet(node2); //node2의 루트 노드를 검색
	node2->parentNode = node1;
}