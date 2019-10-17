/* The idea for this program was taken from an exercise in The C Programming
Language, 2nd ed., by K&R. This is purely for educational purposes and will
not see serious development beyond the scope of the exercise

This program checks a test file for basic C syntax errors with respect to braces
of all types, including comments. */

#include <stdio.h>
#include <regex.h>
typedef enum { false, true } bool;

//Pointer to a FILE type
FILE *fp;
char ch;

//Flags to check for open/close comments
bool isPrevOpen = false;
bool isPrevClose = false;
bool isComplete = false;


void populateStack()
{
	//While current char is not EOF
	while ((ch = getc(fp)) != EOF)
	{
		printf("%c", ch);	
	
		//If ch matches any brace, or beginning of open comment, close comment
		if ((ch == '(') || (ch == ')') || (ch == '{') || (ch == '}') ||
			(ch == '[') || (ch == ']') || (ch == '"') || 
			(ch == '/') || (ch == '*'))
		{
			//If previous char was beginning of open comment, check current completes
			if (isPrevOpen)
			{
				if (ch == '*')
					{
						//do push 
						printf("\nPushing open comment to stack\n");
						isComplete = true;
						isPrevOpen = false;
					}
			}
			//If previous char was beginning of close comment, check current completes
			if (isPrevClose)
			{
				if (ch == '/')
					{
						//do push 
						printf("\nPushing close comment to stack\n");
						isComplete = true;
						isPrevClose = false;
					}
			}

			//If char is component of comment and previous was not
			if ((ch == '/') && (isPrevOpen == false) && (isComplete == false))
				isPrevOpen = true;
		
			//If char is component of comment and previous was not
			if ((ch == '*') && (isPrevClose == false) && (isComplete == false))
				isPrevClose = true;
			
			//If current char is not comment brace component, flags to false
			if ((ch != '*') && (ch != '/'))
				isPrevClose, isPrevOpen = false;			
			
			//If char is not end of open comment and prev was, reset flag
			if ((ch != '*') && (isPrevOpen == true))
				isPrevOpen == false;

			//If char is not end of close comment and prev was, reset flag
			if ((ch != '/') && (isPrevClose == true))
				isPrevClose == false;

			//If push completed, set flags to false
			if (isComplete == true)
			{
				isPrevOpen, isPrevClose = false;
				isComplete = false;
			}
		}
	}

}
int main(int argc, char *argv[])
{
	//Opens file from argument in READ mode, fp points to file
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error opening selected file.\n");
		return 1;
	}

	populateStack();
		
	//Closes file
	fclose(fp);

	return 0;
}
