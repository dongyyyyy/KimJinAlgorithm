#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//zŽ��

int main()
{
	int **arr;
	int i, j, x, y, n, count = 0;
	printf("N X Y �� �Է��Ͻÿ� : ");
	scanf_s("%d %d %d", &n, &x, &y);
	arr = (int **)malloc(sizeof(int*)*pow(2, n));
	for (i = 0; i < pow(2, n); i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*pow(2, n));
	}
	for (i = 0; i < pow(2, n); i += 2)
	{
		for (j = 0; j < pow(2, n); j++) {
			if (j % 2 == 0)
			{
				arr[i][j] = ++count;

			}
			else
			{
				arr[i][j] = ++count;
				arr[i + 1][j - 1] = ++count;
				arr[i + 1][j] = ++count;
			}
		}
	}

	for (i = 0; i < pow(2, n); i++) // ���� ���
	{
		for (j = 0; j < pow(2, n); j++) {
			printf("%3d ", arr[i][j]);
		}
		puts("");
	}
	//������ Z Ž�� �˰���
	count = 0; // ī��Ʈ �ʱ�ȭ
	for (i = 0; i < pow(2, n); i += 2)
	{
		for (j = 0; j < pow(2, n); j++)
		{
			if (j % 2 == 0)
			{
				arr[i][j] = ++count;
				if (i == x && j == y)
				{
					printf("Matrix[%d][%d] = %d", i, j, count);
					return;
				}
			}
			else
			{
				arr[i][j] = ++count;
				if (i == x && j == y)
				{
					printf("Matrix[%d][%d] = %d", i, j, count);
					return;
				}
				arr[i + 1][j - 1] = ++count;
				if (i + 1 == x && j - 1 == y)
				{
					printf("Matrix[%d][%d] = %d", i + 1, j - 1, count);
					return;
				}
				arr[i + 1][j] = ++count;
				if (i + 1 == x && j == y)
				{
					printf("Matrix[%d][%d] = %d", i + 1, j, count);
					return;
				}
			}
		}
	}
	return 0;
}