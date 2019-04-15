#include <stdio.h>
/*
	1번 문제
	Find Maximum length snake sequence.
	Given a grid of numbers. find maximum length Sanke sequence and print it.
	If multiple snake sequences exists with the maximum length. print any one of them.
	A snake sequence is made up of adjacent numbers in the grid such that for each number.
	the number on the right or the number below it is +1 or -1 its value. For example,
	if you are at location (x,y) in the grid, you can either move right i.e. (x,y+1) if that number is +- 1 or move down
	i.e (x+1,y) if that number is +-1.
*/
#define N 4 // 배열의 크기를 직접 입력해줄 경우

int max(int, int);
void input();
void printOneArray(int *);

int main()
{
	input();
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void input()
{
	int i, j, temp, count = N * 2 - 1;
	//int n;
	int **dp;
	int index[][4] = { 9,6,5,2,8,7,6,5,7,3,1,6,1,1,1,7 };
	//동적할당 시 사용할 index변수 
	//int **index;
	int *dpsequence;
	int *longestsequnce;

	/*
	//배열 직접 입력시 사용하는 scanf_s()
	printf("배열의 크기를 입력하시오 : ");
	scanf_s("%d", &n);
	*/

	/* 배열 동적 할당*/
	dp = (int **)malloc(sizeof(int*)*N);
	//index = (int **)malloc(sizeof(int*)*n);
	dpsequence = (int *)malloc(sizeof(int)*N * 2 - 1);
	longestsequnce = (int *)malloc(sizeof(int)*N * 2 - 1);

	for (i = 0; i < N; i++)
	{
		dp[i] = (int *)malloc(sizeof(int)*N);
		//index[i] = (int *)malloc(sizeof(int)*n);
	}
	/*
	//동적 할당시 배열 직접 입력
	for (i = 0; i < n; i++)
	{
		printf("index[%d]번째 열값 입력\n",i);
		for (j = 0; j < n; j++)
		{
			printf("index[%d][%d] = ", i, j);
			scanf_s("%d", &index[i][j]);
		}
	}
	*/
	printf("Grid of Number");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", index[i][j]);
		}
		puts("");
	}
	/* Dynamic programming Algorithm */
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					dp[i][j] = index[i][j];
				else
					dp[i][j] = index[i][j] + dp[i][j - 1];
			}
			else
			{
				if (j > 0)
				{
					dp[i][j] = max(dp[i - 1][j] + index[i][j], dp[i][j - 1] + index[i][j]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + index[i][j];
				}
			}
		}
	}
	printf("Dynamic Algorithm\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	i = j = N - 1;
	while (1)
	{
		if (j == N - 1 && i == N - 1)
		{
			dpsequence[--count] = dp[i][j];
			longestsequnce[count] = index[i][j];
			temp = max(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i - 1][j] == temp)
			{
				i--;
			}
			else
			{
				j--;
			}
			dpsequence[--count] = temp;
			longestsequnce[count] = index[i][j];
		}
		else if (i == 0 && j == 0)
		{
			dpsequence[--count] = dp[i][j];
			longestsequnce[count] = index[i][j];
			break;
		}
		else
		{
			temp = max(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i - 1][j] == temp)
			{
				i--;
			}
			else
			{
				j--;
			}
			dpsequence[--count] = temp;
			longestsequnce[count] = index[i][j];
		}
	}
	printf("Longest snake sequence\n");
	printOneArray(longestsequnce);
	printf("Maximum length snake sequence\n");
	printOneArray(dpsequence);
}

void printOneArray(int *arr)
{
	int i;
	for (i = 0; i < N * 2 - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}