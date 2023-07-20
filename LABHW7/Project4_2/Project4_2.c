#define NUM_OF_MEMBERS 15
// ���߿� 70, 100, 300,, 500, 1000���� �ٲپ� ������� ����
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// ���⼭�� �Լ� ���Ǹ� �պκп� ��ġ�Ѵ�. �� ������ ���ʿ��ϴ�.
void print_links(int data[][NUM_OF_MEMBERS])
{
	//���� ������Ʈ���� ����
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
	{
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			printf("%3d", data[i][j]);
		printf("\n");
	}
}
void matrix_multiplication(int data1[][NUM_OF_MEMBERS],
	int data2[][NUM_OF_MEMBERS],
	int result[][NUM_OF_MEMBERS])
{
	//���� ������Ʈ���� ����
	int i, j, k;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
	{
		for (j = 0; j < NUM_OF_MEMBERS; j++)
		{
			result[i][j] = 0;
			for (k = 0; k < NUM_OF_MEMBERS; k++)
			{
				result[i][j] += data1[i][k] * data2[k][j];
				if (result[i][j] == 1)
					break;
			}
		}
	}
}
void matrix_copy(int dest[][NUM_OF_MEMBERS],
	int src[][NUM_OF_MEMBERS])
{
	//�����ؾ��� �Լ�
	//src�� ��� ������ dest�� ����
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			dest[i][j] = src[i][j];
}
int check_links(int data[][NUM_OF_MEMBERS])
{
	//�����ؾ��� �Լ�
	//data�� ��� ���Ұ� 1�̸� 1 ����
	//�ϳ��� 0�̸� 0 ����
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			if (data[i][j] == 0)
				return 0;
	return 1;
}
int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };
	int link_data2[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };
	int i = 0, j = 0;
	int num_of_steps = 0;
	int ALL_ONES = 0;
	//srand( (unsigned int)time(NULL) );
	srand(100);
	for (i = 0; i < NUM_OF_MEMBERS; i++)
		link_data[i][i] = 1; // �� �밢�� ������ ��� 1��(�ڽ��� �ڱ� �ڽŰ� 1��)
	for (i = 0; i < NUM_OF_MEMBERS; i++)
	{
		j = 0;
		while (j < 2)
		{
			int new_link = rand() % NUM_OF_MEMBERS;
			if (new_link != i)
			{
				link_data[i][new_link] = 1;
				link_data[new_link][i] = 1;
				j++;
			}
		}
	}
	printf("\n�ʱ� 1�� ����:\n");
	print_links(link_data); // ����ڰ� 70�� �̻��̸� ����� �Ų����� ������ �ּ������� ó���Ѵ�.
	matrix_copy(link_data2, link_data);
	while (1)
	{
		num_of_steps++;
		matrix_multiplication(link_data, link_data2, link_result);
		printf("\n%d steps:\n", num_of_steps);
		print_links(link_result); // ����ڰ� 70�� �̻��̸� �ּ�ó��
		ALL_ONES = check_links(link_result);
		if (ALL_ONES) break;
		matrix_copy(link_data2, link_result);
	}
	printf("It takes %d steps.\n", num_of_steps);
}