#include <stdio.h>
//������� ����
int countN(int number);
int discount(int number, int discountNumber);
int main()
{
	int originalNumber, discountNumber, n;
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &originalNumber);
	n = countN(originalNumber); // �Է¹��� ���� �ڸ����� �ľ��ϴ� �Լ�
	while (1)
	{
		printf("������ ���� ������ �Է��Ͻÿ� : (����  : -1)");
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
		num = countN(number / 10) + 1; //���ݱ����� �ڸ����� Ȯ���ϱ� ���� ����Լ�
	}
	else
		return 1;
}

int discount(int number, int discountNumber) // ���� ���� 1�� �ڸ����� Ȯ�� �� ���� �����ϸ� �ٷ� ���� ��ȯ
{											 // �ƴ� ��� ������ ���� ���ϰ� ���ȣ��
	if (number % 10 == discountNumber) // simplestcase
	{
		return number / 10;
	}
	else
		return discount(number / 10, discountNumber) * 10 + number % 10;
}
