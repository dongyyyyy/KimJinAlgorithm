#include <stdio.h>
#include <stdlib.h>
//���ۺ�Ʈ ����

int main()
{
	int i, j, size, kg, tmp_kg, tmp, count = 1;
	int *people;
	printf("��Ʈ�� ���Ը� �Է��Ͻÿ� : ");
	scanf_s("%d", &kg);
	printf("����� ���� �Է��Ͻÿ� : ");
	scanf_s("%d", &size);
	people = (int *)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++)
	{
		printf("%d��° ����� ���� : ", i + 1);
		scanf_s("%d", &people[i]);
	}
	//�������� ����
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
	printf("������������ ����\n");
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
	printf("�� �ʿ��� ��Ʈ�� ���� = %d\n", count);
}