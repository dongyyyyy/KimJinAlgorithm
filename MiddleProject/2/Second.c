#include <stdio.h>
/*
	2������
	Find the number of zeros
	Given an array of 1s and 0s which has all 1s first followed by all 0s. Find the number of
	0s. Count the number of zeros in the given array.
*/
void Input();
int* InputArray(int *, int);
void Print(int *, int);
int ZeroCount(int*, int);

int main()
{
	Input();
	return 0;
}

void Input()
{
	int *arr;
	int size, i;
	printf("�迭�� ũ�⸦ �Է��Ͻÿ� : ");
	scanf_s("%d", &size);
	arr = (int *)malloc(sizeof(int)*size);
	arr = InputArray(arr, size);
	Print(arr, size);
	printf("Output : %d ", ZeroCount(arr, size));
}

int* InputArray(int *arr, int size)
{
	int i;
	printf("�迭�� �Է��Ͻÿ�\n");
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
		printf("%d%s", arr[i],i!=size-1?", ":"");
	}
	puts("}");
}

int ZeroCount(int *arr, int n)
{
	if (n == 1)
	{
		if (arr[n - 1] == 0)
			return 1;
		else
			return 0;
	}
	else
	{
		if (arr[n - 1] == 0)
		{
			return ZeroCount(arr, n - 1) + 1;
		}
		else
		{
			return ZeroCount(arr,n-1);
		}
	}
}