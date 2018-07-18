#include <stdio.h>

#define DEV DEV;

void quickSort(int numberArray[], int left, int right);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int numberArray[], int left, int right)
{
	int pivotIndex = left;
	int pivot = numberArray[pivotIndex];
	printf("�ǹ� : %d\n", pivot);
	++left; //�ǹ� ���� �ε������� �˻簡 ����ǵ��� +1�� ����

	while (left <= right)
	{
		//�ǹ����� ū ���� ���� ������ ����ĭ���� �̵�
		while (numberArray[left] <= pivot && left < right)
			++left;
		
		//�ǹ����� ���� ���� ���� ������ ����ĭ���� �̵�
		while (numberArray[right] > pivot && left <= right)
			--right;

		//left�� right�� ���� ���� �ƴ϶�� left�� right�� ��ġ�� �ִ� ���� ���� �ٲ�
		if (left < right)
			swap(&numberArray[left], &numberArray[right]);
		else
			break;
	}
	

	for (int i = 0; i < 4; i++)
	{
		printf("%d\t", numberArray[i]);
	}

	printf("\n");

	//�ǹ��� ������ right�ڸ��� �ִ� ���� �ٲ�, ���� right�ڸ��� �ǹ��� ����
	swap(&numberArray[pivotIndex], &numberArray[right]);


	return right;
}

void quickSort(int numberArray[], int left, int right)
{
	if (left < right)
	{
		int index = partition(numberArray, left, right); //������ �ǹ� ��ġ�� ��ȯ

		quickSort(numberArray, left, index - 1); //���� ������ left���� �ǹ� ��ġ �������� �����͸� �ٽ� ����
		quickSort(numberArray, index + 1, right); //�ǹ� ��ġ ���� �ε������� ���� ������ right���� �����͸� �ٽ� ����
	}
}

#ifdef DEBUG
int main()
{
	int numberArray[] = { 1, 4, 2, 3 };
	int length = sizeof(numberArray) / sizeof(numberArray[0]);

	quickSort(numberArray, 0, length - 1);

	for (int i = 0; i < length; i++)
	{
		printf("%d\n", numberArray[i]);
	}

	return 0;
}
#endif // DEBUG

