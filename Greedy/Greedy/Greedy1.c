#include <stdio.h>
#include <limits.h>
//ATM����
int main()
{
	int p[] = { 3 , 1 , 4 , 3 , 2 };
	int i, j, sum = 0, total = 0;
	int tmp;
	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++) // �迭�� ������������ ����
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
	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++) // �迭 Ž�� ����������
	{
		total += p[i]; //���� �����ذ�
		sum += total; // ������ ������ �� ���� 1 + (1+2) + (1+2+3) + (1+2+3+3) + (1+2+3+3+4) 
					  // ���� ū ���� ���� �������� �߰��Ǳ� ������ ū ���� ���� ���� �������� ������ �ð��� �ҿ�
	}

	printf("sum = %d\n", sum);

	return 0;

}