#include <stdio.h>
#include <stdlib.h> //qsort 함수가 선언된 헤더 파일

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	//내림 차순으로 하고싶다면 num1 < num2는 1을 반환, num1 > num2를 -1로 반환하면 된다.
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