#include <stdio.h>
#include <ctype.h>
void main()
{
	char c;
	printf("Enter characters(^Z for exit):\n");
	while ((c = fgetc(stdin)) != EOF)
	{
		if (isupper(c))
			fputc(tolower(c), stdout);	// ���� ����
		else
			fputc(toupper(c), stdout);
	}
}