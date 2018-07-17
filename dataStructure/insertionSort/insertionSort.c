#include <stdio.h>
#include <string.h>

int main()
{
	int numberArray[] = { 5, 1, 6, 4, 2, 3 };
	int length = sizeof(numberArray) / sizeof(numberArray[0]);

	for (int i = 1; i < length; i++)
	{
		if (numberArray[i - 1] < numberArray[i])
			continue;

		int tempValue = numberArray[i];

		for (int j = 0; j < i; j++)
		{
			if (numberArray[j] > tempValue)
			{
				/*
					현재 i가 1이고 j가 0이라고 가정하자.
					{ 5, 1, 6, 4, 2, 3 }
					위에 tempValue에 1의 값을 저장해놓았다.
					삽입 정렬이므로 1을 빼서 5를 1의 위치에 넣어야 한다.
					memmove_s의 함수의 첫번째 인자부터 차례대로 보면
					&numberArray[j + 1]는 현재 j가 0이므로 j+1은 5의 다음 위치인 1을 가르키는 메모리 주소를 뜻한다.
					즉 첫번째 인자는 목적지의 주소다.
					두번째 인자는 목적지의 사이즈를 뜻하는데 sizeof(numberArray[0])는 현재 4바이트가 나올 것이고 (i - j)는 옮길 개수다.
					즉 int형을 몇 개 옮길것인가인데 현재 i가 1, j가 0이므로 옮길 개수는 1개이다.
					세번재 인자는 현재 옮길 데이터의 주소를 말한다.
					우리는 5의 위치를 1이 있던 자리에 옮길 것이므로 5의 위치인 &numberArray[j]를 넣었다.
					마지막 인자는 두번째 인자와 마찬가지로 옮길 데이터의 크기이다.
				*/
				memmove_s(&numberArray[j + 1], sizeof(numberArray[0]) * (i - j), &numberArray[j], sizeof(numberArray[0]) * (i - j));
				numberArray[j] = tempValue;
				break;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d\n", numberArray[i]);
	}
}