#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int multi[8][9] = { 0 };
	int i, j, n;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 9; j++)
			multi[i][j] = (i + 2) * (j + 1);

	printf("--구구단 표는 다음과 같습니다.\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%5d", multi[i][j]);
		printf("\n");
	}
	printf("--원하는 구구단은? ");
	scanf("%d", &n);
	for (j = 0; j < 9; j++)
		printf("%5d", multi[n - 2][j]);

	return 0;
}