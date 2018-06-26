#include "linekdListStack.h"

void createStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack)); //��ũ�� ����Ʈ ���� �޸� ����
	//�ʱ�ȭ
	(*stack)->headNode = NULL;
	(*stack)->topNode = NULL;
}

void destroyStack(LinkedListStack* stack)
{
	while (!isEmpty(stack))
	{
		destroyNode(Pop(stack));
	}

	free(stack);
}

Node* createNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //��� �޸� ����
	newNode->data = (char*)malloc(strlen(newData) + 1); //�Է¹��� ���ڿ� ��ŭ�� �޸� ����
	strcpy_s(newNode->data, strlen(newData) + 1, newData); //newNode->data�� �Է¹��� ���ڿ��� ����
	newNode->nextNode = NULL; //���� ��� �ʱ�ȭ
	return newNode;
}

void destroyNode(Node* node)
{
	free(node->data);
	free(node);
}

int isEmpty(LinkedListStack* stack)
{
	return stack->headNode == NULL;
	//�Ǵ� return stack->topNode == NULL;
}

int getSize(LinkedListStack* stack)
{
	int count = 0;
	Node* currentNode = stack->headNode;
	
	while (currentNode != NULL)
	{
		count++;
		currentNode = currentNode->nextNode; //���� ���� �̵�
	}

	return count;
}

void Push(LinkedListStack* stack, Node* newNode)
{
	/*
		��ũ�� ����Ʈ ������ list�� NULL�̶�� ���ø� �����ǰ� 
		�����Ͱ� ���Ե��� �ʾҴٴ� ���̹Ƿ� ���� ���� ���� �߰��Ǵ� newNode�� �ȴ�
	*/
	if (stack->headNode == NULL)
	{
		stack->headNode = newNode;
	}
	else
	{
		stack->topNode->nextNode = newNode; //���� topNode�� ���� ���� newNode�� �ȴ�
	}

	stack->topNode = newNode; //������ �ֻ���(����) ���� ���� �߰��Ǵ� newNode�� �ȴ�
}

Node* Pop(LinkedListStack* stack)
{
	Node* currentNode = stack->headNode;
	Node* oldTopNode = stack->topNode;

	//���ÿ� �����Ͱ� 1���� ���� ��� �����Ͱ� ��ȯ�� �Ŀ��� ���ÿ��� ������� ��
	if (currentNode == oldTopNode)
	{
		stack->headNode = NULL;
		stack->topNode = NULL;
		return oldTopNode;
	}

	/*
		������ LIFO�����̱� ������ Pop �Լ��� ȣ��Ǹ� �ֻ���(����) ��尡 ��ȯ�� �ǰ�
		�� ���� ��尡 ���ο� �ֻ���(����)�� �ȴ�
		[headNode -> Node1 -> Node2 -> tailNode] ���� Pop ȣ�� ��
		[headNode -> Node1 -> Node2]�� ����
		���� tailNode�� �ٶ󺸴� ���� ��带 Ž��
	*/

	while (currentNode->nextNode != oldTopNode)
	{
		currentNode = currentNode->nextNode;
	}

	stack->topNode = currentNode; //���� �ֻ���(����) ��带 �ٶ󺸴� ��尡 ���ο� �ֻ���(����) ��尡 �ȴ�
	currentNode->nextNode = NULL; //�ֻ���(����) ����̱� ������ ���� ���� NULL
	return oldTopNode;
}

void printStackStatus(LinkedListStack* stack)
{
	printf("\nprint stack status..\n");
	printf("stack is empty? : %s\n", isEmpty(stack) ? "true" : "false");
	printf("stack size : %d\n", getSize(stack));

	if (!isEmpty(stack))
	{
		printf("stack first data : %s\n", stack->headNode->data);
		printf("stack last data : %s\n", stack->topNode->data);
	}

}