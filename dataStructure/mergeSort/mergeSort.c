#include <stdio.h>
#include <stdlib.h>

void mergeSort(int numberArray[], int left, int right); //n/2 분할
void merge(int numberArray[], int left, int mid, int right); //합병

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
	//left와 right의 위치가 같다면 1/2로 분할 할 수 없다.
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergeSort(numberArray, left, mid); //left부터 중심까지의 요소들을 다시 분할
		mergeSort(numberArray, mid + 1, right); //중심 다음부터 right까지의 요소들을 다시 분할
		merge(numberArray, left, mid, right); //더 이상 분할되지 않는다면 합병
	}
}

void merge(int numberArray[], int left, int mid, int right)

{
	int *tempArray = (int*)malloc(sizeof(numberArray[0]) * ((mid + right) + 1)); //합병 정렬은 임시로 담을 배열이 필요
	int i = left, j = mid + 1, k = left;

	/*1/2로 분할되었던 두 요소들의 값을 비교하여 임시 배열에 저장*/
	while (i <= mid && j <= right)
	{
		if (numberArray[i] <= numberArray[j])
			tempArray[k++] = numberArray[i++];
		else
			tempArray[k++] = numberArray[j++];
	}

	/*남은 요소들을 차례대로 임시 배열에 저장*/
	while (i <= mid)
	{
		tempArray[k++] = numberArray[i++];
	}

	while (j <= right)
	{
		tempArray[k++] = numberArray[j++];
	}

	/*원래 배열에 값을 넘김*/
	for (int i = left; i <= right; i++)
	{
		numberArray[i] = tempArray[i];
	}

	free(tempArray);
}