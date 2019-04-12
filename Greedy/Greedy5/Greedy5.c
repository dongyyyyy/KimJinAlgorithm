#include <stdio.h>
#include <stdlib.h>
//구멍보트 문제

int main()
{
	int i, j, size, kg, tmp_kg, tmp, count = 1;
	int *people;
	printf("보트의 무게를 입력하시오 : ");
	scanf_s("%d", &kg);
	printf("사람의 수를 입력하시오 : ");
	scanf_s("%d", &size);
	people = (int *)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++)
	{
		printf("%d번째 사람의 무게 : ", i + 1);
		scanf_s("%d", &people[i]);
	}
	//오름차순 정렬
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (people[i] > people[j])
			{
				tmp = people[i];
				people[i] = people[j];
				people[j] = tmp;
			}
		}
	}
	printf("오름차순으로 정렬\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", people[i]);
	}
	puts("");
	tmp_kg = kg;
	for (i = 0; i < size; i++)
	{
		if (tmp_kg - people[i] > 0)
		{
			tmp_kg -= people[i];
		}
		else
		{
			count++;
			tmp_kg = kg;
		}
	}
	printf("총 필요한 보트의 개수 = %d\n", count);
}