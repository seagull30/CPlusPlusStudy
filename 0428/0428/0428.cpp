#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

}

//char word[1000001] = "";

//long long additionalCost, variableCost, salesCost;
//scanf("%lld %lld %lld", &additionalCost, &variableCost, &salesCost);
//long long POE = additionalCost / (salesCost - variableCost);
//if (POE<0)
//	printf("-1");
//else
//	printf("%lld", POE + 1);
//


//백준 10809
/*
char S[100] = "";
scanf("%s", S);

for (int j = 0; j < 26; j++)
{
	int count = 0;
	for (int i = 0; i < strlen(S); i++)
	{
		if ((int)S[i] - ('a' + j) == 0) {
			printf("%d ", i);
			count++;
			break;
		}
	}
	if (count == 0)
		printf("-1 ");
}
*/

//백준 2675
/*
int testCase;
scanf("%d", &testCase);

for (int i = 0; i < testCase; i++)
{
	int loop;
	scanf("%d", &loop);
	char S[20] = "";
	scanf("%s", S);

	for (int j = 0; j < strlen(S); j++)
	{
		for (int k = 0; k < loop; k++)
			printf("%C", S[j]);
	}
	printf("\n");
}
*/

//백준 1316
/*
int group;
scanf("%d", &group);
int count=0;
for (int i = 0; i < group; i++)
{
	char word[101] = "";
	scanf("%s", word);
	int wordCount[26] = { 0, };
	bool check = true;
	wordCount[word[0] - 'a']++;
	for (int j = 1; j < strlen(word); j++)
	{
		wordCount[word[j] - 'a']++;
		if(word[j]==word[j-1])
			wordCount[word[j] - 'a']--;
	}
	for (int j = 0; j < 26; j++) {
		check = check && (wordCount[j] == 1 || wordCount[j] == 0);
	}
	if (check == true)
		count++;
}
printf("%d", count);
*/

//백준 1152
/*
fgets(word, sizeof(word), stdin);
int count = 0;

for (int i = 0; i < strlen(word); i++)
{
	if ((word[i] == ' ' && i != 0) || (i == strlen(word) - 2) && word[strlen(word) - 2] != ' ')
		count++;

}

printf("%d", count);

*/

//백준 5622
/*
char input[16] = "";
int output = 0;
scanf("%s", input);
for (int i = 0; input[i] != '\0'; i++)
{
	switch (input[i]) {
	case 'A': case 'B': case 'C':
		output += 3;
		break;
	case 'D': case 'E': case 'F':
		output += 4;
		break;
	case 'G': case 'H': case 'I':
		output += 5;
		break;
	case 'J': case 'K': case 'L':
		output += 6;
		break;
	case 'M': case 'N': case 'O':
		output += 7;
		break;
	case 'P': case 'Q': case 'R': case 'S':
		output += 8;
		break;
	case 'T': case 'U': case 'V':
		output += 9;
		break;
	case 'W': case 'X': case 'Y': case 'Z':
		output += 10;
		break;
	}

}
printf("%d\n", output);
*/

//백준 2941
/*
	char input[101] = "";
	scanf("%s", input);
	int count = 0;
	for (int i = 0; input[i] != 0; i++)
	{
		count++;
		if (input[i] == '=' || input[i] == '-' || (input[i] == 'j'&& (input[i-1] == 'n'|| input[i - 1] == 'l')))
		{
			count--;
			if (input[i] == '=' && input[i - 1] == 'z' && input[i - 2] == 'd')
				count--;
		}
	}
	printf("%d", count);
	*/

	//백준 2908
	/*
		char num1[4] = "";
		char num2[4] = "";
		scanf("%s %s", num1, num2);
		char temp[4] = "";
		for (int i = 0; i < 3; i++)
			temp[i] = num1[2 - i];
		strcpy(num1, temp);
		for (int i = 0; i < 3; i++)
			temp[i] = num2[2 - i];
		strcpy(num2, temp);
		if (0 < strcmp(num1, num2))
			printf("%s\n", num1);
		else
		printf("%s\n", num2);

	*/

	//백준 1157
	/*
		scanf("%s", word);

		int count[26] = { 0, };
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (word[i] >= 'a')
				count[word[i] - 'a']++;
			else
				count[word[i] - 'A']++;
		}
		int overlap = 0;
		int maxAlpha = 0;
		int maxCount = 0;
		for (int i = 0; i < 26; i++)
		{
			if (maxAlpha == count[i])
			{
				maxCount++;
			}
			if (maxAlpha < count[i])
			{
				overlap = i;
				maxAlpha = count[i];
				maxCount = 0;
			}
		}
		if (maxCount > 0)
		printf("?");
		else
		printf("%c", 'A' + overlap);
	*/

	//백준 1712
/*
long long a, b, c;
scanf("%lld %lld %lld", &a, &b, &c);

if (b >= c) {
	printf("-1");
	return 0;
}
long long POE = a / (c - b);
printf("%lld", POE + 1);

return 0;
*/