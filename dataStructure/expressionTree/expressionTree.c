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
void destroyNode(Node *destroyNode); //��� �Ҹ�
void destroyTree(Node *rootNode); //Ʈ�� �Ҹ�
void printPreorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���
void printInorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���
void printPostorderTreeTraversal(Node *rootNode); //Ʈ�� Ž�� : ���� ��ȸ�� ���
void buildExpressionTree(char **expression, int *position, Node **rootNode);
double calculate(Node *rootNode);

int main()
{
	char expression[100]; //���� ������ ���� �� ����
	char *context = NULL;
	char *token = NULL; //��ū�� ���� �� ����
	char **tokenArray = NULL;
	int whiteSpaceCount = 0, i = 0;

	/*���� ������ �Է�*/
	printf("���� ǥ����� �Է�(��: 10 2 +) : ");
	gets_s(expression, sizeof(expression)); //���� ������ �Է¹���

	/*�Է¹��� ���� ���Ŀ� �����ϴ� ���� ����*/
	for (unsigned int j = 0; j < strlen(expression); j++)
	{
		if (expression[j] == 32)
			whiteSpaceCount++;
	}

	/*�������� ���ڿ����� ������ 2���� �迭 �޸� ����*/
	tokenArray = (char**)malloc(sizeof(char*) * (whiteSpaceCount + 1));
	
	/*ù��° ��ū ����*/
	token = strtok_s(expression, " ", &context);
	tokenArray[i] = (char*)malloc(strlen(token) + 1);
	strcpy_s(tokenArray[i], sizeof(tokenArray[i]), token);

	/*������ ��ū ����*/
	while ((token = strtok_s(NULL, " ", &context)) != NULL)
	{
		i++;
		tokenArray[i] = (char*)malloc(strlen(token) + 1);
		strcpy_s(tokenArray[i], sizeof(tokenArray[i]), token);
	}

	Node *rootNode = NULL;
	/*�Է¹��� ���� ǥ������� Ʈ���� ����*/
	buildExpressionTree(tokenArray, &i, &rootNode);
	
	/*��� ���*/
	printf("��� : %lf\n", calculate(rootNode));

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
		/*���� ǥ����� �ں��� �б� ������ �������� ���� ä��� ������ ä��*/
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