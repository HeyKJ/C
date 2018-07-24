#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const int *a, const int *b);

int main()
{
	int numberArray[10000];
	int size = sizeof(numberArray) / sizeof(numberArray[0]);
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		numberArray[i] = rand() % 10000;
	}
		
	qsort(numberArray, size, sizeof(numberArray[0]), compare);

	int targetData = 10;
	int *find = bsearch(&targetData, numberArray, size, sizeof(numberArray[0]), compare); //bsearch는 C언어에서 제공하는 이진 탐색 라이브러리이다.
	if(find == NULL)
		printf("not found\n");
	else
		printf("find address: %d\n", find);

	return 0;
}

int compare(const int *a, const int *b)
{
	if (*a == *b) return 0;
	else if (*a < *b) return -1;
	else return 1;
}

