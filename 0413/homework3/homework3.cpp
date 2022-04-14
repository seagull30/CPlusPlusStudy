#include <iostream>
#include <conio.h>

#define MAP_SIZE 10
using namespace std;

int main()
{
	/*
			실습3.
			A ~ Z 키 중에 하나를 정답으로 설정한다.
			유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
			유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
			틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오버

			*추가1. 틀릴 때마다 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌드를 준다.

			*추가2. 입력된 값이 대소문자 구분없이 처리될 수 있도록 수정 해보자.

		*/

	int inputChar; int randChar; int life = 5;


	srand(time(NULL));

	randChar = rand() % 26 + 65;
	while (life > 0)
	{
		cout << "정답 일것같은 알파벳을 누르세요  " << endl;
		inputChar = _getch();
		if (inputChar > 96 && inputChar < 123) {
			inputChar -= 32;
		}
		if (inputChar > 64 && inputChar < 91) {
			if (inputChar == randChar) {
				cout << "승리" << "\n\n";
				break;
			}
			else {
				life--;
				cout << "오답 남은 목숨 : " << life << endl;
				randChar < inputChar ? cout << "입력값보다 정답은 앞에 있습니다." << "\n\n" : cout << "입력값보다 정답은 뒤에 있습니다." << "\n\n";

				if (life == 0)
					cout << "게임 오버" << "\n\n";
			}
		}
		else
			cout << "알파벳을 입력해주세요" << endl;
	}

	/*
	콘솔형 탈출게임
	10 * 10 크기의 맵을 구상한다. (2차원 배열)
	플레이어(0,0)가 존재한다.
	탈출지점이 존재한다.
	wasd 키입력을 통해 플레이어를 이동시킨다.
	탈출지점은 (0,0)을 제외하고 랜덤 설정
	O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료


	#O########
	##########
	##########
	##########
	##########
	##########
	##########
	######E###
	##########
	##########		#:벽 O:플레이어 E: 탈출지점

	system("cls"); -콘솔창 갱신
*/
	srand(time(NULL));

	char map[MAP_SIZE][MAP_SIZE];
	int playerX = 0; int playerY = 0; bool checkLoop = 1;
	int exitX = rand() % (MAP_SIZE - 1) + 1; int exitY = rand() % (MAP_SIZE - 1) + 1;
	int inputKey;

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			map[i][j] = ' ';
		}
	}


	map[playerY][playerX] = 'O';
	map[exitY][exitX] = 'E';



	while (checkLoop == 1) {
		system("cls");
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		map[playerY][playerX] = ' ';

		switch (inputKey = _getch())
		{
		case 'W':
			if (map[playerY - 1][playerX] == '#' || playerY - 1 < 0)
				playerY = playerY;

			else
				playerY -= 1;

			break;

		case 'A':

			if (map[playerY][playerX - 1] == '#' || playerX - 1 < 0)
				playerX = playerX;

			else
				playerX -= 1;

			break;

		case 'S':

			if (map[playerY + 1][playerX] == '#' || playerY + 1 > MAP_SIZE - 1)
				playerY = playerY;

			else
				playerY += 1;

			break;


		case 'D':

			if (map[playerY][playerX + 1] == '#' || playerX + 1 > MAP_SIZE - 1)
				playerX = playerX;

			else
				playerX += 1;

			break;
		}
		if (playerX == exitX && playerY == exitY)
			checkLoop = 0;
		map[playerY][playerX] = 'O';
	}

	system("cls");
	cout << "탈출에 성공했습니다." << endl;






}