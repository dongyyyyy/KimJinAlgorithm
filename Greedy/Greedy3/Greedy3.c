#include <stdio.h>
//수지우기 문제
int countN(int number);
int discount(int number, int discountNumber);
int main()
{
	int originalNumber, discountNumber, n;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &originalNumber);
	n = countN(originalNumber); // 입력받은 값의 자리수를 파악하는 함수
	while (1)
	{
		printf("삭제할 양의 정수를 입력하시오 : (종료  : -1)");
		scanf_s("%d", &discountNumber);
		if (discountNumber == -1)
		{
			break;
		}
		originalNumber = discount(originalNumber, discountNumber);
		printf("new = %d\n", originalNumber);
	}
}

int countN(int number)
{
	int num = 0;
	if (number / 10 >= 1)
	{
		num = countN(number / 10) + 1; //지금까지의 자리수를 확인하기 위한 재귀함수
	}
	else
		return 1;
}

int discount(int number, int discountNumber) // 가장 먼저 1의 자리부터 확인 후 삭제 가능하면 바로 몫을 반환
{											 // 아닐 경우 기존의 값을 더하고 재귀호출
	if (number % 10 == discountNumber) // simplestcase
	{
		return number / 10;
	}
	else
		return discount(number / 10, discountNumber) * 10 + number % 10;
}
