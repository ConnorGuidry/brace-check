/* The idea for this program was taken from an exercise in The C Programming
Language, 2nd ed., by K&R. This is purely for educational purposes and will
not see serious development beyond the scope of the exercise

This program checks a test file for basic C syntax errors with respect to braces
of all types, including comments. */

#include <stdio.h>
#include <regex.h>

int main(int argc, char *argv[])
{
	//Pointer to a FILE type
	FILE *fp;
	char ch;

	//Opens file from argument in READ mode, fp points to file
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error opening selected file.\n");
		return 1;
	}

	//While current char is not EOF
	while ((ch = getc(fp)) != EOF)
	{
		printf("%c", ch);	
	}
	
	//Closes file
	fclose(fp);

	return 0;
}
