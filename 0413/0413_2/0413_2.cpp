/*

	boolean타입
	bool is_alive = false;

	배열 (자료구조)
	같은 데이터타입의 여러 변수를 하나의 묶음으로 나타낸 것.

	배열의 데이터타입에 대한 동일한 크기로 메모리상에 연속된 공간이 할당된다.
	배열명이 메모리 시작 주소이다.

	이차원배열 및 다차원배열
	배열이 개념적으로 2중으로, 다중으로 구성되어 있는 것

	1차원 배열 : int student_nums[5];   5개의 int
			-> 5명의 학생이 있다.
	2차원 배열 : int student_nums[3][5];    15개의 int
			-> 3개의 반에 각각 5명의 학생이 있다.
	3차원 배열 :  int student_nums[4][3][5];    60개의 int
			-> 4개의 학년에 3개의 반이 존재하고, 각 반에 5명의 학생이 있다.

	(엔터 없이) 문자 하나를 입력받는 방법
	_getch();

	형변환 : 데이터타입을 변환한다.
	묵시적 형변환
	명시적 형변환


*/


#include <iostream>
#include <conio.h>

#define MAP_SIZE 10
using namespace std;

int main()
{

	//int nums[10] = { 1,2,3,4,5,6,7,8,9,12 };
	//int student_Name[3][5] = { {1,2,3,4,5} ,{6,7,8,9,10} ,{11,12,13,14,15} };
	//
	//for (int i = 0; i < 3; i++) 
	//{
	//    for (int j = 0; j < 5; j++) 
	//    {
	//        cout.width(2);
	//        cout << student_Name[i][j] << " ";
	//    }
	//    cout << endl;
	//}
	//
	//cout << student_Name[0][5];

	//cout << nums << endl;
	//for (int i = 0; i < 10; i++) {
	//    cout << &(nums[i]) << endl;
	//}

#pragma region 실습1
		/*
		실습1. string형 배열변수 5개짜리를 선언하고
		반복문을 통해학생의 이름을 입력받는다.

		입력을 다 받고나서 1 ~ 5사이의 값을 입력하면 해당 학생의 이름이 출력된다.

		예시)
			1번째 학생의 이름을 입력하세요 : ~
			2번째 학생의 이름을 입력하세요 : ~
			3번째 학생의 이름을 입력하세요 : ~
			4번째 학생의 이름을 입력하세요 : ~
			5번째 학생의 이름을 입력하세요 : ~

			1 ~ 5 사이의 번호를 입력하세요 : 3

			3번째 학생의 이름은 ...입니다.
	*/

	//string student[5];
	//int input_Number;
	//
	//for (int i = 0; i < 5; i++)
	//{
	//    cout << i + 1 << "번째 학생의 이름을 입력하세요 : ";
	//    cin >> student[i];
	//}
	//
	//cout << "\n1 ~ 5 사이의 번호를 입력하세요 : ";
	//cin >> input_Number;
	//
	//cout << "\n" << input_Number << "번째 학생의 이름은 " << student[input_Number - 1] << "입니다." << endl;

#pragma endregion 

#pragma region 실습2

	/*
		실습2.
		구구단의 결과를 저장하는 2차원 배열을 하나 선언하고,
		이중 for문을 이용해서 배열 변수에 구구단의 결과값을 저장하고,
		두 수를 입력받아서 적합한 결과값을 출력해보자.

		예시)
			(결과 저장 완료)
			몇 단을 볼까요? : 4
			몇을 곱할까요? : 7

			4 * 7 = 28

	*/

	//int guguDan[8][9];
	//int dan; int su;
	//for (int i = 0; i < 8; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		guguDan[i][j] = (i + 2) * (j + 1);
	//	}
	//}
	//cout << "(결과 저장 완료)" << "\n\n";
	//
	//cout << "몇 단을 볼까요? : ";
	//cin >> dan;
	//
	//cout << "몇을 곱할까요? : ";
	//cin >> su;
	//
	//cout << dan << " * " << su << " = " << guguDan[dan - 2][su - 1] << endl;


#pragma endregion

	//int input_key = _getch();
	//char input_key_char = _getch();
	//cout << input_key << endl;
	//cout << (int)input_key_char << endl;
	//
	//float test_float = 5.4f;

#pragma region 실습3

	/*
		실습3.
		A ~ Z 키 중에 하나를 정답으로 설정한다.
		유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
		유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
		틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오버
		
		*추가1. 틀릴 때마다 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌드를 준다.
		
		*추가2. 입력된 값이 대소문자 구분없이 처리될 수 있도록 수정 해보자.

	*/

//int inputChar; int randChar; int life=5;
//
//
//srand(time(NULL));
//
//randChar = rand() % 26 + 65;
//while (life > 0)
//{
//	cout << "정답 일것같은 알파벳을 누르세요  "<< endl;
//	inputChar = _getch();
//	if (inputChar > 96 && inputChar < 123) {
//		inputChar -= 32;
//	}
//	if (inputChar > 64 && inputChar < 91) {
//		if (inputChar == randChar) {
//			cout << "승리" << "\n\n";
//			break;
//		}
//		else {
//			life--;
//			cout << "오답 남은 목숨 : " << life << endl;
//			randChar > inputChar ? cout << "입력값보다 정답은 앞에 있습니다." << "\n\n" : cout << "입력값보다 정답은 뒤에 있습니다." << "\n\n";
//
//			if (life == 0)
//				cout << "게임 오버" << "\n\n";
//		}
//	}
//	else
//		cout << "알파벳을 입력해주세요" << endl;
//}

#pragma endregion

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
int playerX = 0; int playerY = 0; int i = 1;
int exitX = rand() % (MAP_SIZE-1) + 1; int exitY = rand() % (MAP_SIZE-1) + 1;
int inputKey;

for (int i = 0; i < MAP_SIZE; i++) {
	for (int j = 0; j < MAP_SIZE; j++) {
		map[i][j] = ' ';
	}
}


map[playerY][playerX] = 'O';
map[exitY][exitX] = 'E';



while (i == 1) {
	system("cls");
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	switch (inputKey = _getch())
	{
	case 'W':
		if (map[playerY - 1][playerX] == '#' || playerY - 1 < 0) {
			playerY = playerY;
		}
		else if (map[playerY - 1][playerX] == 'E') {
			i = 0;
		}
		else {
			map[playerY][playerX] = ' ';
			playerY -= 1;
		}

		break;

	case 'A':

		if (map[playerY][playerX - 1] == '#' || playerX - 1 < 0)
			playerX = playerX;
		else if (map[playerY][playerX - 1] == 'E') {
			i = 0;
		}
		else {
			map[playerY][playerX] = ' ';
			playerX -= 1;
		}

		break;

	case 'S':

		if (map[playerY + 1][playerX] == '#' || playerY + 1 > MAP_SIZE - 1)
			playerY = playerY;
		else if (map[playerY + 1][playerX] == 'E') {
			i = 0;
		}
		else {
			map[playerY][playerX] = ' ';
			playerY += 1;
		}

		break;


	case 'D':

		if (map[playerY][playerX + 1] == '#' || playerX + 1 > MAP_SIZE - 1)
			playerX = playerX;
		else if (map[playerY][playerX + 1] == 'E') {
			i = 0;
		}
		else {
			map[playerY][playerX] = ' ';
			playerX += 1;
		}

		break;
	}
	map[playerY][playerX] = 'O';
}

system("cls");
cout << "탈출에 성공했습니다." << endl;






}