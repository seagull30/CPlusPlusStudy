// 0413.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#define MAX_LINE 5

int main()
{

#pragma region 과제1

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int star = 0; star < line + 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 과제2

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int space = 0; space < MAX_LINE - line - 1; space++)
		{
			cout << " ";
		}
		for (int star = 0; star < line + 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 과제3

	for (int line = MAX_LINE; line > 0; line--)
	{
		for (int star = 0; star < line; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 과제4

	for (int line = MAX_LINE; line > 0; line--)
	{
		for (int space = 0; space < MAX_LINE - line; space++)
		{
			cout << " ";
		}
		for (int star = 0; star < line; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 과제5

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int space = 0; space < MAX_LINE - line - 1; space++)
		{
			cout << " ";
		}
		for (int star = 0; star < line * 2 + 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 과제6

	for (int line = MAX_LINE; line > 0; line--)
	{
		for (int space = 0; space < MAX_LINE - line; space++)
		{
			cout << " ";
		}
		for (int star = 0; star < line * 2 - 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 과제7

	for (int line = -MAX_LINE + 1; line < MAX_LINE; line++)
	{
		for (int space = 0; space < abs(line); space++)
		{
			cout << " ";
		}
		for (int star = 0; star < (MAX_LINE - abs(line) - 1) * 2 + 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 별찍기8      

	for (int line = -MAX_LINE + 1; line < MAX_LINE; line++)
	{
		for (int star = 0; star < MAX_LINE - abs(line); star++)
		{
			cout << "*";
		}
		for (int space = 0; space < abs(line) * 2; space++)
		{
			cout << " ";
		}
		for (int star = 0; star < MAX_LINE - abs(line); star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion 

#pragma region 별찍기9

	for (int line = -MAX_LINE + 1; line < MAX_LINE; line++)
	{
		for (int star = 0; star < MAX_LINE - abs(line); star++)
		{
			cout << " ";
		}
		for (int space = 0; space < abs(line) * 2 + 1; space++)
		{
			cout << "*";
		}
		for (int star = 0; star < MAX_LINE - abs(line); star++)
		{
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

#pragma endregion 

#pragma region 별찍기15

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int space = 0; space < MAX_LINE - line; space++)
		{
			cout << " ";
		}

		for (int star = 0; star < line * 2 + 1; star++)
		{
			(star == 0 || star == line * 2) ? cout << "*" : cout << " ";
		}

		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 별찍기16

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int space = 0; space < MAX_LINE - line; space++)
		{
			cout << " ";
		}

		for (int star = 0; star < line * 2 + 1; star++)
		{
			(star % 2 == 0) ? cout << "*" : cout << " ";
		}

		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 별찍기17

	for (int line = 0; line < MAX_LINE; line++)
	{
		for (int space = 0; space < MAX_LINE - line; space++)
		{
			cout << " ";
		}

		for (int star = 0; star < line * 2 + 1; star++)
		{
			(star % 2 == 0) ? cout << "*" : cout << " ";
		}

		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 별찍기20
	for (int line = 0; line < MAX_LINE; line++)
	{
		if (line % 2 == 1) {
			for (int star = 0; star < MAX_LINE * 2; star++)
			{
				(star % 2 == 1) ? cout << "*" : cout << " ";
			}

		}
		else
			for (int star = 0; star < MAX_LINE * 2; star++)
			{
				(star % 2 == 0) ? cout << "*" : cout << " ";
			}
		cout << endl;
	}
	cout << endl;

#pragma endregion

#pragma region 별찍기21
	for (int line = 0; line < MAX_LINE * 2; line++)
	{
		if (line % 2 == 1) {
			for (int star = 0; star < MAX_LINE; star++)
			{
				(star % 2 == 1) ? cout << "*" : cout << " ";
			}

		}
		else
			for (int star = 0; star < MAX_LINE; star++)
			{
				(star % 2 == 0) ? cout << "*" : cout << " ";
			}
		cout << endl;
	}
	cout << endl;

#pragma endregion
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


