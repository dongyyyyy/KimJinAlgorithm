#include <stdio.h>
//���� ä���
// ���� ��ũ�� ũ�� 20L
// �������� ������� ��ġ ( ��� , 8 , 2 , 4 , 9 , 7 , 13 , 17 , 5, 9 , 3 , 11 )
// Ʈ���� ���⿡ ���� ��ũ���� ���Ḧ ������ ���� ���� ���� �� �ִ�.
// �ּ����� ������ �������� �����ؾ���
// ���� �����ϰ� �����ϸ� �ѹ��� 20�� ä��� �ִ��� �� �� ������ŭ �� �� �������� �̵��ϴ� ���� ������.
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
				printf("�̵��Ÿ� : %dKM ���� �⸧ : %dL ", len[j], fuel);
				if (j == sizeof(len) / sizeof(len[0]) - 1)
				{
					i = j + 1;
					printf("�̵��Ÿ� : %dKM ���� �⸧ : %dL & ����", len[j], fuel);
					break;
				}
			}
			else
			{
				printf("�⸧�� �����ϱ� ���� ����\n");
				i = j;
				fuel = 20;
				count++;
				break;
			}
		}
	}

	printf("�� ���� Ƚ�� = %d\n", count);

	return 0;
}
