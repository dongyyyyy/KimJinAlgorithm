#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 저울 문제

int main()
{
	int size, i, j, tmp, min = 0, tmps;
	int total;
	int *weight;
	printf("저울추 개수를 입력하시오 : ");
	scanf_s("%d", &size);
	weight = (int *)malloc(sizeof(int)*size);//메모리 할당
	memset(weight, 0, sizeof(int)*size); // 0으로 초기화
	for (i = 0; i < size; i++)
	{
		printf("%d번째 추의 무게 : ", i + 1);
		scanf_s("%d", &weight[i]);
	}
	//오름차순 정렬
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (weight[i] > weight[j])
			{
				tmp = weight[i];
				weight[i] = weight[j];
				weight[j] = tmp;
			}
		}
	}
	printf("오름차순으로 정렬\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", weight[i]);
	}
	puts("");
	if (weight[0] != 1)
	{
		printf("최저 = %d\n", 1);
	}
	else
	{
		total = 1;
		//현재까지의 합 + 1 보다 큰 값이 다음 인덱스에 저장된 수라면
		//이전 추들로 무게를 구할 수 없다.
		for (i = 1; i < size; i++)
		{
			if (weight[i] > total + 1)
				break;
			total += weight[i];
		}
		printf("최저 = %d\n", total + 1);
	}
}