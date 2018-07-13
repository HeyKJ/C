#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numberArray[] = {1, 4, 5, 2, 3};
	int length = sizeof(numberArray) / sizeof(numberArray[0]);

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i; j < length - (i + 1); j++)
		{
			if (numberArray[j] > numberArray[j + 1])
			{
				int temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", numberArray[i]);
	}

	return 0;
}