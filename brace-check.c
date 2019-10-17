#include <stdio.h>
#include <regex.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error opening selected file.\n");
		return 1;
	}

	while ((ch = getc(fp)) != EOF)
	{
		printf("%c", ch);	
	}
	
	fclose(fp);

	return 0;
}
