#include <stdio.h>
#include <stdlib.h>

void mergeSort(int numberArray[], int left, int right); //n/2 ����
void merge(int numberArray[], int left, int mid, int right); //�պ�

int main()
{
	int numberArray[] = { 3, 1, 2, 5, 4 };
	int length = sizeof(numberArray) / sizeof(numberArray[0]);

	mergeSort(numberArray, 0, length - 1);

	for (int i = 0; i < length; i++)
	{
		printf("%d\t", numberArray[i]);
	}

	printf("\n");
	return 0;
}

void mergeSort(int numberArray[], int left, int right)
{
	//left�� right�� ��ġ�� ���ٸ� 1/2�� ���� �� �� ����.
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergeSort(numberArray, left, mid); //left���� �߽ɱ����� ��ҵ��� �ٽ� ����
		mergeSort(numberArray, mid + 1, right); //�߽� �������� right������ ��ҵ��� �ٽ� ����
		merge(numberArray, left, mid, right); //�� �̻� ���ҵ��� �ʴ´ٸ� �պ�
	}
}

void merge(int numberArray[], int left, int mid, int right)

{
	int *tempArray = (int*)malloc(sizeof(numberArray[0]) * ((mid + right) + 1)); //�պ� ������ �ӽ÷� ���� �迭�� �ʿ�
	int i = left, j = mid + 1, k = left;

	/*1/2�� ���ҵǾ��� �� ��ҵ��� ���� ���Ͽ� �ӽ� �迭�� ����*/
	while (i <= mid && j <= right)
	{
		if (numberArray[i] <= numberArray[j])
			tempArray[k++] = numberArray[i++];
		else
			tempArray[k++] = numberArray[j++];
	}

	/*���� ��ҵ��� ���ʴ�� �ӽ� �迭�� ����*/
	while (i <= mid)
	{
		tempArray[k++] = numberArray[i++];
	}

	while (j <= right)
	{
		tempArray[k++] = numberArray[j++];
	}

	/*���� �迭�� ���� �ѱ�*/
	for (int i = left; i <= right; i++)
	{
		numberArray[i] = tempArray[i];
	}

	free(tempArray);
}