#include <iostream>﻿
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10
//using namespace std;
void loading();

struct state {
	int xPos;
	int yPos;
	int hp;
};

struct inventory {
	
	int potion;
};

struct player {
	state state;
	inventory inventory;
};

struct tile {
	int xPos;
	int yPos;
	int value;
	char icon;
	//int count;
};


int main()
{

	srand(time(NULL));


	struct state monster[50] = {0,0,50};
	struct player me = {0,0,10,0};

	struct tile potion = {-1,-1,0,'P'};
	struct tile exit = { 0,0,1,'E'};
	//struct tile monster[50] = {-1,-1,2,'M',50};

	char map[MAP_SIZE][MAP_SIZE];
	int stageCount = 0;
	int monsterCount = 0;

	int dice = 0;

	int inputKey;
	bool checkLoop;
	int dummy = 0;


	loading();

	while (me.state.hp > 0) {

		system("cls");
		//맵 생성
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				map[i][j] = ' ';
			}
		}
		//변수 초기화
		checkLoop = 1;
		me.state.xPos = 0; me.state.yPos = 0;
		stageCount++;
		monsterCount = stageCount;
		exit.xPos = rand() % (MAP_SIZE - 1) + 1; exit.yPos = rand() % (MAP_SIZE - 1) + 1;
		exit.value = 0;
		me.state.hp += stageCount / 2;

		map[me.state.yPos][me.state.xPos] = 'O';
		map[exit.yPos][exit.xPos] = exit.icon;
		// 몬스터 생성
		for (int i = stageCount; i > 0; i--) {
			monster[i].xPos = rand() % (MAP_SIZE - 1); monster[i].yPos = rand() % (MAP_SIZE - 1);
			if (map[monster[i].yPos][monster[i].xPos] != ' ')
				i++;
			else
				map[monster[i].yPos][monster[i].xPos] = 'M';
			monster[i].hp = 50;
		}
		//포션 생성
		potion.value = rand() % 2;
		if (potion.value > 0)
		{
			for (int i = potion.value; i > 0; i--) {
				potion.xPos = rand() % (MAP_SIZE - 1) + 1; potion.yPos = rand() % (MAP_SIZE - 1) + 1;
				if (map[potion.yPos][potion.xPos] != ' ')
					i++;
				else
					map[potion.yPos][potion.xPos] = potion.icon;
			}
		}

		//stage 시작

		std::cout << "\n\n\n\n\n\n\n\n\tS  T  A  G  E\n\n\n\t      " << stageCount << std::endl;
		Sleep(2000);

		while (checkLoop == 1)
		{
			//화면 초기화후 맵표시
			system("cls");

			std::cout << "조작키 : wasd	O : 플레이어	P : 포션\n포션   : 2	E : 탈출지점	M : 몬스터\n" << std::endl;

			map[exit.yPos][exit.xPos] = 'E';				//화면에 탈출구 표시
			for (int i = stageCount; i > 0; i--)	//화면에 몬스터 표시
				map[monster[i].yPos][monster[i].xPos] = 'M';

			//화면에 맵 표시
			std::cout << "▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒" << std::endl;
			for (int i = 0; i < MAP_SIZE; i++) {
				std::cout << "▒ ";
				for (int j = 0; j < MAP_SIZE; j++) {
					std::cout << map[i][j] << " ";
				}
				std::cout << "▒" << std::endl;
			}
			std::cout << "▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒" << std::endl;
			//상태 표시
			std::cout << "\n현재 " << stageCount << "층 입니다." << std::endl;
			std::cout << "남은 몬스터 수 : " << monsterCount << std::endl;
			std::cout << "HP : " << me.state.hp << std::endl;
			std::cout << "남은 포션 : " << me.inventory.potion << std::endl;

			//플레이어 이전 위치 값 초기화
			map[me.state.yPos][me.state.xPos] = ' ';
			//플레이어 행동
			switch (inputKey = _getch())
			{
			case 'w':
				if ((map[me.state.yPos - 1][me.state.xPos] == '#') || (me.state.yPos - 1 < 0))
					me.state.yPos = me.state.yPos;

				else
					me.state.yPos -= 1;

				break;

			case 'a':

				if ((map[me.state.yPos][me.state.xPos - 1] == '#') || (me.state.xPos - 1 < 0))
					me.state.xPos = me.state.xPos;

				else
					me.state.xPos -= 1;

				break;

			case 's':

				if ((map[me.state.yPos + 1][me.state.xPos] == '#') || (me.state.yPos + 1 > MAP_SIZE - 1))
					me.state.yPos = me.state.yPos;

				else
					me.state.yPos += 1;

				break;


			case 'd':

				if ((map[me.state.yPos][me.state.xPos + 1] == '#') || (me.state.xPos + 1 > MAP_SIZE - 1))
					me.state.xPos = me.state.xPos;

				else
					me.state.xPos += 1;

				break;
			case '2': //포션 사용
				if (me.inventory.potion > 0) {
					me.state.hp += 5;
					me.inventory.potion--;
				}
				else {
					std::cout << "남은 포션이 없습니다." << std::endl;
					Sleep(100);
					continue;
				}
				break;
			default:
				continue;
			}

			for (int i = monsterCount; i > 0; i--) {
				map[monster[i].yPos][monster[i].xPos] = ' ';
			}

			//몬스터 조우 확인
			for (int i = stageCount; i > 0; i--) {
				if ((me.state.xPos == monster[i].xPos) && (me.state.yPos == monster[i].yPos)) {

					//전투
					for (int text = 1; text <= 2; text++)
					{
						system("cls");
						for (int time = 0; time <= 1005000000; time++)
						{
							int demo = 1;
						}
						std::cout << "  ■■■                                   ■          " << std::endl;
						std::cout << "  ■   ■                                  ■          " << std::endl;
						std::cout << "  ■   ■                 ■        ■     ■   ■■■■   " << std::endl;
						std::cout << "  ■■■    ■■       ■■■■  ■■■■  ■ ■       ■  " << std::endl;
						std::cout << "  ■   ■ ■   ■■       ■        ■     ■ ■■■■■■  " << std::endl;
						std::cout << "  ■   ■ ■   ■■       ■        ■     ■ ■       " << std::endl;
						std::cout << "  ■■■    ■■■ ■■    ■■      ■■  ■  ■■■■■  " << std::endl;
						for (int time = 0; time <= 1005000000; time++)
						{
							int demo = 1;
						}

					}
					while (monster[i].hp > 0 && me.state.hp > 0)
					{


						system("cls");
						std::cout << "공격 : 1	포션 : 2\n\n" << std::endl;
						std::cout << "몬스터" << "\t\t\t플레이어" << "\n" << std::endl;
						std::cout << "체력 : " << monster[i].hp << "\t\t체력 : " << me.state.hp << std::endl;
						std::cout << "\t\tVS\t주사위 : " << dice + 1 << std::endl;
						std::cout << "\t\t\t남은 포션 : " << me.inventory.potion << std::endl;
						if (dice == 0)
						{
							std::cout << "\n\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
						}
						else if (dice == 1)
						{
							std::cout << "\n\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
						}
						else if (dice == 2)
						{
							std::cout << "\n\t\t\t □□■ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t ■□□ " << std::endl;
						}
						else if (dice == 3)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}
						else if (dice == 4)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}
						else if (dice == 5)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}


						switch (inputKey = _getch())
						{
						case '1': //공격
							dice = rand() % 6;
							monster[i].hp -= dice * 10;
							break;
						case '2': //포션 사용
							if (me.inventory.potion > 0) {
								me.state.hp += 5;
								me.inventory.potion--;
							}
							else {
								std::cout << "남은 포션이 없습니다." << std::endl;
								Sleep(100);
								continue;
							}
							break;

						default:
							continue;
						}

						if (monster[i].hp > 0) {
							me.state.hp -= rand() % 2 + 1;
						}
					}
					monsterCount--;
					monster[i].hp = 50;
					monster[i].xPos = -1;
					monster[i].yPos = -1;
					if (monsterCount == 0)
						exit.value = 1;
				}
			}
			//포션 획득
			if (me.state.xPos == potion.xPos && me.state.yPos == potion.yPos) {
				me.inventory.potion++;
				potion.value--;
				map[potion.yPos][potion.xPos] = ' ';
				potion.xPos = -1;
				potion.yPos = -1;
			}

			//탈출구 도착 행동종료 종료
			if (((me.state.xPos == exit.xPos) && (me.state.yPos == exit.yPos)) && exit.value)
				checkLoop = 0;
			//플레이어 사망 while문 종료
			if (me.state.hp <= 0) {
				system("cls");
				std::cout << "      ■■■■■■■           ■■         ■                ■ ■■■■■■■■■■" << std::endl;
				std::cout << "  ■■              ■       ■    ■       ■■            ■■ ■                  " << std::endl;
				std::cout << "  ■■■■■■■■         ■■■■■■     ■  ■        ■  ■ ■■■■■■■■■■" << std::endl;
				std::cout << "  ■■    ■■    ■     ■            ■   ■    ■    ■    ■ ■                  " << std::endl;
				std::cout << "      ■■          ■ ■                ■ ■      ■■      ■ ■■■■■■■■■■" << std::endl;
				std::cout << "\n\n" << std::endl;
				std::cout << "\n\n" << std::endl;
				std::cout << "      ■■■■■■     ■                ■ ■■■■■■■■■■ ■■■■■■■■■    " << std::endl;
				std::cout << "    ■            ■     ■            ■   ■                   ■                ■  " << std::endl;
				std::cout << "  ■                ■     ■        ■     ■■■■■■■■■■ ■■■■■■■■■    " << std::endl;
				std::cout << "    ■            ■         ■    ■       ■                   ■  ■■■■          " << std::endl;
				std::cout << "      ■■■■■■             ■■         ■■■■■■■■■■ ■          ■■■■  " << std::endl;
				dummy = _getch();
				checkLoop = 0;
			}
			//현재 플레이어 위치 표시
			map[me.state.yPos][me.state.xPos] = 'O';

		}

	}
	//프로그램 종료
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\t\t\t\t" << stageCount << "스테이지까지 클리어 하셨습니다.\n\n\n\n\n" << std::endl;
}

void loading() {
	int dummy;

#pragma region LoadingScreen
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■□□□□□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■□□□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G" << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  " << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■■■□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■■■■■■" << "\n\n" << std::endl;
	system("cls");
	Sleep(500);
#pragma endregion


#pragma region Maintitle
	std::cout << "                                ■■■      ■" << std::endl;
	std::cout << "                                ■    ■    ■" << std::endl;
	std::cout << "                                ■    ■    ■" << std::endl;
	std::cout << "                                ■■■      ■" << std::endl;
	std::cout << "  ■■■■■      ■■■■■          ■          ■■■■■      ■      ■" << std::endl;
	std::cout << "  ■                  ■            ■  ■        ■              ■    ■" << std::endl;
	std::cout << "  ■■■■■          ■            ■■■        ■              ■■■" << std::endl;
	std::cout << "          ■          ■          ■      ■      ■              ■    ■" << std::endl;
	std::cout << "  ■■■■■          ■          ■      ■      ■■■■■      ■      ■" << std::endl;
	std::cout << "\n\n\n\n\n\n\n\t\t\t\t -   Press  Any  Key   -" << std::endl;
	dummy = _getch();
#pragma endregion


}
