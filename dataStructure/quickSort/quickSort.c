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
	printf("피벗 : %d\n", pivot);
	++left; //피벗 다음 인덱스부터 검사가 진행되도록 +1을 해줌

	while (left <= right)
	{
		//피벗보다 큰 수가 나올 때까지 다음칸으로 이동
		while (numberArray[left] <= pivot && left < right)
			++left;
		
		//피벗보다 작은 수가 나올 때까지 이전칸으로 이동
		while (numberArray[right] > pivot && left <= right)
			--right;

		//left와 right가 같은 값이 아니라면 left와 right의 위치에 있는 값을 서로 바꿈
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

	//피벗과 마지막 right자리에 있던 값을 바꿈, 이제 right자리에 피벗이 있음
	swap(&numberArray[pivotIndex], &numberArray[right]);


	return right;
}

void quickSort(int numberArray[], int left, int right)
{
	if (left < right)
	{
		int index = partition(numberArray, left, right); //마지막 피벗 위치를 반환

		quickSort(numberArray, left, index - 1); //최초 설정한 left부터 피벗 위치 전까지의 데이터를 다시 정렬
		quickSort(numberArray, index + 1, right); //피벗 위치 다음 인덱스부터 최초 설정한 right까지 데이터를 다시 정렬
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

