#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumThree(int x, int y, int z);
long long sum(int* a, int n);
void swap(int* a, int* b);
int islower(char a);
int isupper(char a);
char toupper(char a);
char tolower(char a);
int strlen(const char* str);
char* strchr(char* a, char b);
char* strrchr(char* a, char b);

void strcpy(char* a, char* b);

void strcat(char* a, char* b);

int strcmp(char* a, char* b);

char* strstr(char* a, const char* b);



int main(void)
{
	int a[3] = { 1,2,3 };
	int n = 3;
	printf("%lld\n", sum(a, n));

	int b = 10;
	int c = 20;
	swap(&b, &c);
	char d = 'g';
	char e = 'T';
	char f[] = "asdasdadadadasdasdasd";
	char g[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";

	printf("%p %s\n", strchr(g, 'a'), strchr(g, 'a'));
	printf("%p %s\n", strrchr(f, 'L'), strrchr(f, 'L'));


	strcpy(f, g);
	printf("%s\n", f);

	char h[50] = "kl;k;kasdghfcghfchfdbh";		
	char i[10] = "asd ";

	printf("str : %p %s\n", strstr(h, "hfcg"), strstr(h, "hfcg"));

	printf("strcmp : %d\n", strcmp(h, i));


	strcat(h, i);
	printf("%s\n", h);

	printf("%d\n", strlen(f));

	printf("%c\n", tolower(d));
	printf("%c\n", toupper(d));
	printf("%c\n", tolower(d));

	printf("%d %d\n", b, c);

	return 0;
}

int islower(char a)
{
	if (a >= 'a' && a <= 'z')
		return 1;
	else
		return 0;
}

int isupper(char a)
{
	if (a >= 'A' && a <= 'Z')
		return 1;
	else
		return 0;
}

char toupper(char a)
{
	if (a >= 'a' && a <= 'z')
		return a - 'a' + 'A';
	else
		return a;
}

char tolower(char a)
{
	if (a >= 'A' && a <= 'Z')
		return a - 'A' + 'a';
	else
		return a;
}

int strlen(const char* str)
{
	unsigned int i = 0;
	for (; str[i] != '\0'; i++) {}

	return i;
}

char* strchr(char* a, char b)
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == b)
			return &a[i];
	}

	return NULL;
}

char* strrchr(char* a, char b)
{
	int c = strlen(a) - 1;
	for (int i = c; a[i] != '\0'; i--)
	{
		if (a[i] == b)
			return &a[i];
	}

	return NULL;
}

void strcpy(char* a, char* b)
{
	for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++)
		a[i] = b[i];
}

void strcat(char* a, char* b)
{
	int i = strlen(a);	
	for (int j = 0; b[j] != '\0'; j++)
	{
		a[i] = b[j];
		i++;
	}
	a[i] = '\0';
}

int strcmp(char* a, char* b)
{
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

char* strstr(char* a, const char* b)
{
	int i, j;

	for (i = 0; a[i] != '\0'; i++)
	{
		for (j = 0; b[j] != '\0'; j++)
		{
			if (a[i + j] != b[j])
				break;
		}
		if (b[j + 1] != '\0')
			continue;
		return &a[i];

	}
	return NULL;
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

long long sum(int* a, int n)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int sumThree(int x, int y, int z)
{
	return x + y + z;
}

//long long V, A, B;
//scanf("%lld %lld %lld", &A, &B, &V);
//
//
//printf("%lld", (V - B) / (A - B));
//printf("%lld", V  / (A - B));


//백준 10250
/*
int testCase;
scanf("%d", &testCase);

for (int i = 0; i < testCase; i++)
{
	int W, H, N;
	scanf("%d %d %d", &H, &W, &N);

	if (N % H == 0)
		printf("%d\n", H * 100 + N / H);
	else
		printf("%d\n", N % H * 100 + (N / H + 1));
}

return 0;
*/




//int testCase;
//scanf("%d", &testCase);
//for (int i = 0; i < testCase; i++)
//{
//	int k, n;
//	scanf("%d %d", &k, &n);
//	if (k == 0)
//		printf("%d", n);
//	else
//		
//}
