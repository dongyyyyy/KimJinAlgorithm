#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// ���� ����

int main()
{
	int size, i, j, tmp, min = 0, tmps;
	int total;
	int *weight;
	printf("������ ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &size);
	weight = (int *)malloc(sizeof(int)*size);//�޸� �Ҵ�
	memset(weight, 0, sizeof(int)*size); // 0���� �ʱ�ȭ
	for (i = 0; i < size; i++)
	{
		printf("%d��° ���� ���� : ", i + 1);
		scanf_s("%d", &weight[i]);
	}
	//�������� ����
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
	printf("������������ ����\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", weight[i]);
	}
	puts("");
	if (weight[0] != 1)
	{
		printf("���� = %d\n", 1);
	}
	else
	{
		total = 1;
		//��������� �� + 1 ���� ū ���� ���� �ε����� ����� �����
		//���� �ߵ�� ���Ը� ���� �� ����.
		for (i = 1; i < size; i++)
		{
			if (weight[i] > total + 1)
				break;
			total += weight[i];
		}
		printf("���� = %d\n", total + 1);
	}
}