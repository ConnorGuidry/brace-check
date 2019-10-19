/* Generic stack structure. Content copied piecemeal from zeeev/GenericStack
@GitHub */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct generic_stack{
	int memberSize;
	int totalElements;
	void *data;
	int top;
}Stack;

Stack* initStack(int memberSize, int totalElements)
{
	Stack *s = malloc(sizeof(Stack));
	
	s->top = -1;
	s->memberSize = memberSize;
	s->totalElements = totalElements;
	s->data = malloc(totalElements*memberSize);
	
	return s;
}

int deleteStack(Stack *s)
{
	free(s->data);
	free(s);
	return 0;
}

int expandStack(Stack *s)
{
	s->data = realloc(s->data, s->totalElements * 2* s->memberSize);
	s->totalElements *= 2;
	return 0;
}

int push(Stack *s, void *data)
{
	if (s->top == s->totalElements -1)
		expandStack(s);

	s->top++;
	void* target = (char*)s->data+(s->top*s->memberSize);
	memcpy(target, data, s->memberSize);
	return 0;
}

int stackTop(Stack *s, void *target)
{
	if (s->top == -1)
		return 1;

	void *source = (char*)s->data+(s->top*s->memberSize);
	memcpy(target, source, s->memberSize);
	return 0;
}

int pop(Stack *s, void *target)
{
	if (s->top == -1) 
	    return 1;
  
	void* source = (char*)s->data+(s->top*s->memberSize);
	s->top--;
	memcpy(target, source, s->memberSize);
	return 0;	
}

int getMax(Stack *s, void* max, int (*compare)(const void *a, const void *b))
{
	if(s->top == -1) 
		return 1;

	void* maxTemp = s->data;
	int i = 1;
	while(i++ <= s->top) 
	{
		void* b = (char*)s->data + s->memberSize*i;
		int result = compare(maxTemp, b);
		if(result == 1)
			maxTemp = b;
	}
	
	memcpy(max, maxTemp, s->memberSize);
	return 0;
}


/*
int main(int argc, char *argv[])
{
	Stack *charstack = initStack(1, 1);
	char *character = argv[1];
	push(charstack, character);	
	char *charresult = malloc(8);
	pop(charstack, charresult);
	printf("%c\n", *charresult);
	return 0;
}
*/
