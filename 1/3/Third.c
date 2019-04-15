#include <stdio.h>
/* 3번 문제 
	Maximize the sum of arr[i]*i
	Given an array of N integers. You are allowed to rearrange the element of the array. 
	The task is to find the maximum value of Σarr[i]*i. where i = 0 , 1 , 2 ... n-1
	*/
void Input();
int* InputArray(int *, int);
void Print(int *, int);
int* SortArray(int *, int);
void MaximizeTheSum(int *, int);

int main()
{
	Input();
	return 0;
}

void Input()
{
	int N;
	int *arr;
	printf("Input N : ");
	scanf_s("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);
	arr = InputArray(arr,N);
	Print(arr,N);
	arr = SortArray(arr, N);
	printf("Sort\n");
	Print(arr, N);
	MaximizeTheSum(arr, N);
}

int* InputArray(int *arr, int size)
{
	int i;
	printf("배열을 입력하시오\n");
	for (i = 0; i < size; i++)
	{
		printf("arr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}

void Print(int *arr, int size)
{
	int i;
	printf("Input = {");
	for (i = 0; i < size; i++)
	{
		printf("%d%s", arr[i], i != size - 1 ? ", " : "");
	}
	puts("}");
}

int* SortArray(int *arr, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}

void MaximizeTheSum(int *arr, int size)
{
	int i,sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += arr[i] * i;
	}
	printf("Output : %d", sum);
}