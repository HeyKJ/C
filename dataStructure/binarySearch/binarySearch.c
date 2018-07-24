#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEV

int searchCount = 0;

int binarySearch(int numberArray[], int size, int targetData);

#ifdef DEBUG

int main()
{
	int numberArray[100] = { 0 };
	int size = sizeof(numberArray) / sizeof(numberArray[0]);

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		numberArray[i] = rand() % 100;
	}

	int targetData = 50;
	int resultIndex = binarySearch(numberArray, size, targetData);

	if (resultIndex == -1)
		printf("%d�� ã�� ���߽��ϴ�.\n", targetData);
	else
		printf("%d�� %d��° �ε����� ��ġ�մϴ�.\n", targetData, resultIndex);

	printf("���� Ƚ�� : %d\n", searchCount);

	return 0;
}

#endif // DEBUG

int binarySearch(int numberArray[], int size,  int targetData)
{
	int left = 0, right = size - 1, resultIndex = -1;

	while (left <= right)
	{
		searchCount++;
		int mid = (left + right) / 2;

		if (numberArray[mid] == targetData)
		{
			resultIndex = mid;
			break;
		}
		else if (numberArray[mid] < targetData)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return resultIndex;
}