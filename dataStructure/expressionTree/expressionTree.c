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
void destroyNode(Node *destroyNode); //노드 소멸
void destroyTree(Node *rootNode); //트리 소멸
void printPreorderTreeTraversal(Node *rootNode); //트리 탐색 : 전위 순회로 출력
void printInorderTreeTraversal(Node *rootNode); //트리 탐색 : 중위 순회로 출력
void printPostorderTreeTraversal(Node *rootNode); //트리 탐색 : 후위 순회로 출력
void buildExpressionTree(char **expression, int *position, Node **rootNode);
double calculate(Node *rootNode);

int main()
{
	char expression[100]; //후위 계산식을 저장 할 변수
	char *context = NULL;
	char *token = NULL; //토큰을 저장 할 변수
	char **tokenArray = NULL;
	int whiteSpaceCount = 0, i = 0;

	/*후위 계산식을 입력*/
	printf("후위 표기식을 입력(예: 10 2 +) : ");
	gets_s(expression, sizeof(expression)); //후위 계산식을 입력받음

	/*입력받은 후위 계산식에 존재하는 공백 개수*/
	for (unsigned int j = 0; j < strlen(expression); j++)
	{
		if (expression[j] == 32)
			whiteSpaceCount++;
	}

	/*나누어진 문자열들을 저장할 2차원 배열 메모리 생성*/
	tokenArray = (char**)malloc(sizeof(char*) * (whiteSpaceCount + 1));
	
	/*첫번째 토큰 저장*/
	token = strtok_s(expression, " ", &context);
	tokenArray[i] = (char*)malloc(strlen(token) + 1);
	strcpy_s(tokenArray[i], sizeof(tokenArray[i]), token);

	/*나머지 토큰 저장*/
	while ((token = strtok_s(NULL, " ", &context)) != NULL)
	{
		i++;
		tokenArray[i] = (char*)malloc(strlen(token) + 1);
		strcpy_s(tokenArray[i], sizeof(tokenArray[i]), token);
	}

	Node *rootNode = NULL;
	/*입력받은 후위 표기식으로 트리를 생성*/
	buildExpressionTree(tokenArray, &i, &rootNode);
	
	/*계산 결과*/
	printf("결과 : %lf\n", calculate(rootNode));

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

void destroyNode(Node *destroyNode)
{
	if (destroyNode != NULL)
	{
		//free(destroyNode->data);
		free(destroyNode);
	}
}

void destroyTree(Node *rootNode)
{
	if (rootNode == NULL)
		return;

	destroyTree(rootNode->leftNode);
	destroyTree(rootNode->rightNode);
	destroyNode(rootNode);
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

void buildExpressionTree(char **expression, int *position, Node **rootNode)
{
	char *token = expression[*position];
	*position = *position - 1;
	*rootNode = createNode(token);

	if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
	{
		/*후위 표기식을 뒤부터 읽기 때문에 오른쪽을 먼저 채우고 왼쪽을 채움*/
		buildExpressionTree(expression, position, &(*rootNode)->rightNode);
		buildExpressionTree(expression, position, &(*rootNode)->leftNode);
	}
}

double calculate(Node *rootNode)
{
	if (rootNode == NULL)
		return 0;

	double result = 0, left = 0, right = 0;
	char *token = rootNode->data;
	

	if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
	{
		left = calculate(rootNode->leftNode);
		right = calculate(rootNode->rightNode);

		if (strcmp(token, "+") == 0) result = left + right;
		else if (strcmp(token, "-") == 0) result = left - right;
		else if (strcmp(token, "*") == 0) result = left * right;
		else result = left / right;
	}
	else
	{
		result = atof(token);
	}

	return result;
}