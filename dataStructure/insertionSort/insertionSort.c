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
					���� i�� 1�̰� j�� 0�̶�� ��������.
					{ 5, 1, 6, 4, 2, 3 }
					���� tempValue�� 1�� ���� �����س��Ҵ�.
					���� �����̹Ƿ� 1�� ���� 5�� 1�� ��ġ�� �־�� �Ѵ�.
					memmove_s�� �Լ��� ù��° ���ں��� ���ʴ�� ����
					&numberArray[j + 1]�� ���� j�� 0�̹Ƿ� j+1�� 5�� ���� ��ġ�� 1�� ����Ű�� �޸� �ּҸ� ���Ѵ�.
					�� ù��° ���ڴ� �������� �ּҴ�.
					�ι�° ���ڴ� �������� ����� ���ϴµ� sizeof(numberArray[0])�� ���� 4����Ʈ�� ���� ���̰� (i - j)�� �ű� ������.
					�� int���� �� �� �ű���ΰ��ε� ���� i�� 1, j�� 0�̹Ƿ� �ű� ������ 1���̴�.
					������ ���ڴ� ���� �ű� �������� �ּҸ� ���Ѵ�.
					�츮�� 5�� ��ġ�� 1�� �ִ� �ڸ��� �ű� ���̹Ƿ� 5�� ��ġ�� &numberArray[j]�� �־���.
					������ ���ڴ� �ι�° ���ڿ� ���������� �ű� �������� ũ���̴�.
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