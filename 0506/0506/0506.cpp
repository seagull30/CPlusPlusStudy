#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "headerfile.h"

#define MIN(a,b) ((a) < (b) ? a : b)

#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
int factorial(int a)
{
	
}


int main()
{ 
	int loopCount;
	scanf("%d", &loopCount);
	printf("%d", factorial(loopCount));

	return 0;
		
}


















//민상아 너무 어렵다 살려줘라 ㅜㅜㅜ