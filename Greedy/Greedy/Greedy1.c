#include <stdio.h>
#include <limits.h>
//ATM문제
int main()
{
	int p[] = { 3 , 1 , 4 , 3 , 2 };
	int i, j, sum = 0, total = 0;
	int tmp;
	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++) // 배열을 내림차순으로 정렬
	{
		for (j = i + 1; j < sizeof(p) / sizeof(p[0]); j++)
		{
			if (p[i] > p[j])
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++) // 배열 탐색 순차적으로
	{
		total += p[i]; //값을 누적해감
		sum += total; // 누적한 값들을 다 더함 1 + (1+2) + (1+2+3) + (1+2+3+3) + (1+2+3+3+4) 
					  // 가장 큰 수가 가장 마지막에 추가되기 때문에 큰 수일 수록 적게 더해져서 최저의 시간이 소요
	}

	printf("sum = %d\n", sum);

	return 0;

}