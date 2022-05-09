#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int N;
//백준 10872
int factorial(int a)
{
	if (a < 2)
		return 1;
	else
		return a * factorial(a - 1);
}
//백준 10870
int Fibonacci(int a, int b, int c)
{
	if (c == 0)
		return  a;
	else
		Fibonacci(b, a + b, --c);
}

void print_binary(int a)
{
	if (a > 0)
	{
		print_binary(a / 2);
		printf("%d", a % 2);
	}
}

//백준 17478
void print_recursion(int a, int b)
{
	int i = b;
	char str[200] = "";
	for (int j = 0; j < i * 4; j++)
	{
		str[j] = '_';
	}
	if (a >= b)
	{
		if (i == 0)
			printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
		
		if (a == b)
		{
			printf("%s\"재귀함수가 뭔가요?\"\n%s\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", str, str);
		}
		else
		{
			printf("%s\"재귀함수가 뭔가요?\"\n%s\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n%s마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n%s그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", str, str, str, str);
			print_recursion(a, ++i);
		}
		printf("%s라고 답변하였지.\n", str);
	}
}

//백준 17478

void print_star(int a, int b, int c)
{
	if (a == 0)
	{
		putchar('*');

		return;
	}
	if ((b / a) % 3 = 1 && (c / a) % 3 == 1)
		putchar(' ');
	else
		print_star(a / 3, b, c);	
}


void hanoi(int numerOfDisc, int startPos, int viaPos, int targetPos)
{
	if (numerOfDisc == 1)
	{
		printf("%d %d\n", startPos, targetPos);
		return;
	}
	hanoi(numerOfDisc - 1, startPos, targetPos, viaPos);
	hanoi(1, startPos, viaPos, targetPos);
	hanoi(numerOfDisc - 1, viaPos, startPos, targetPos);
}
int hanoicount(int numerOfDisc, int startPos, int viaPos, int targetPos)
{
	int result = 0;
	if (numerOfDisc == 1)
	{
		
		return 1;
	}
	result += hanoicount(numerOfDisc - 1, startPos, targetPos, viaPos);
	result += hanoicount(1, startPos, viaPos, targetPos);
	result += hanoicount(numerOfDisc - 1, viaPos, startPos, targetPos);
}


int main()
{
	int loopCount;
	scanf("%d", &N);
	//printf("%d", factorial(loopCount));
	//printf("%d", Fibonacci(0, 1, loopCount));
	//print_binary(loopCount);
	//print_recursion(loopCount, 0);
	//printf("%d\n", hanoicount(loopCount, 1, 2, 3));
	//hanoi(loopCount, 1, 2, 3);
	for(int i=;)
	return 0;

}