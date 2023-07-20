#include <stdio.h>
#include <stdlib.h>
void generateData();
void printData();
int totalData();
int data[10];

int main(void)
{
	srand(200);
	generateData();
	printf("발생된 10개의 난수: \n");
	printData();
	printf("10개 난수의 합 = %d \n", totalData());
	printf("10개 난수중 가장 큰 수 = %d \n", maxData());
}

void generateData()
{
	int* p;
	p = data;
	for (int i = 0; i < 10; i++)
		*p++ = rand() % 100;
}

void printData()
{
	int* pi = data;
	for (int i = 0; i < 10; i++)
		printf("%d ", *pi++);
	printf("\n");
}

int totalData()
{
	int *pi = data, sum = 0;
	for (int i = 0; i < 10; i++)
		sum += *pi++;
	return sum;
}

int maxData()
{
	int* pi = data, max = -1;
	for (int i = 0; i < 10; i++)
		if (*(pi + i) > max)
			max = *(pi + i);
	return max;
}