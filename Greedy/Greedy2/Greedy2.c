#include <stdio.h>
//연료 채우기
// 연료 탱크의 크기 20L
// 주유소의 상대적인 위치 ( 출발 , 8 , 2 , 4 , 9 , 7 , 13 , 17 , 5, 9 , 3 , 11 )
// 트럭이 좋기에 연료 탱크에는 연료를 제한이 없이 많이 넣을 수 있다.
// 최소한의 정지로 목적지에 도착해야함
// 가장 간단하게 생각하면 한번에 20을 채우고 최대한 갈 수 있을만큼 간 후 다음으로 이동하는 것을 생각함.
int main()
{
	int len[] = { 8,2,4,9,7,13,17,5,9,3,11 };
	int fuel = 20;
	int i, j;
	int count = 0;
	for (i = 0; i < sizeof(len) / sizeof(len[0]); )
	{
		for (j = i; j < sizeof(len) / sizeof(len[0]); j++)
		{
			if (fuel > len[j])
			{
				fuel -= len[j];
				printf("이동거리 : %dKM 남은 기름 : %dL ", len[j], fuel);
				if (j == sizeof(len) / sizeof(len[0]) - 1)
				{
					i = j + 1;
					printf("이동거리 : %dKM 남은 기름 : %dL & 도착", len[j], fuel);
					break;
				}
			}
			else
			{
				printf("기름을 충전하기 위해 멈춤\n");
				i = j;
				fuel = 20;
				count++;
				break;
			}
		}
	}

	printf("총 멈춘 횟수 = %d\n", count);

	return 0;
}
