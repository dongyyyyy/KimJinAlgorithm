#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//최소 타일의 개수

int main()
{
	int number, i, j, h, w, count = 0;
	char **arr;
	srand(time(NULL));
	scanf_s("%d %d", &h, &w);
	arr = (char **)malloc(sizeof(char*)*h);
	for (i = 0; i < h; i++)
	{
		arr[i] = (char *)malloc(sizeof(char)*w);
	}
	for (i = 0; i < h; i++) // 타일 생성
	{
		for (j = 0; j < w; j++)
		{
			number = rand() % 2;
			if (number == 0)
			{
				arr[i][j] = '.';
			}
			else
			{
				arr[i][j] = 'X';
			}
			printf("%c", arr[i][j]);
		}
		puts("");
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (arr[i][j] == '.')
			{
				if (j < w - 1 && arr[i][j + 1] == '.')
				{
					arr[i][j] = arr[i][j + 1] = '2';
					count++;
				}
				else if (i < h - 1 && arr[i + 1][j] == '.')
				{
					arr[i][j] = arr[i + 1][j] = '2';
					count++;
				}
				else
				{
					arr[i][j] = '1';
					count++;
				}
			}
		}
	}
	printf("===============================================================\n");
	for (i = 0; i < h; i++) // 타일 변환 후
	{
		for (j = 0; j < w; j++)
		{
			printf("%c", arr[i][j]);
		}
		puts("");
	}
	printf("총 타일의 개수 : %d\n", count);
}
