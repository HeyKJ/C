#include <stdio.h>
#include <stdlib.h> //qsort �Լ��� ����� ��� ����

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	//���� �������� �ϰ�ʹٸ� num1 < num2�� 1�� ��ȯ, num1 > num2�� -1�� ��ȯ�ϸ� �ȴ�.
	if (num1 < num2) return -1;
	else if (num1 == num2) return 0;
	else return 1;
}

int main()
{
	int numberArray[] = { 1, 4, 2, 3 };
	int length = sizeof(numberArray) / sizeof(numberArray[0]);
	qsort(numberArray, length, sizeof(numberArray[0]), compare);

	for (int i = 0; i < length; i++)
	{
		printf("%d\t", numberArray[i]);
	}

	printf("\n");
	return 0;
}