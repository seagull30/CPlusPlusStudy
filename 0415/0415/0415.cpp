﻿// 0415.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
    프로그래밍 기초(메모리, CPU, 디스크)
    _getch()
    구조체
    1. 절차적
    2. 구조적
    3. 객체지향적
    ### 추상화 ###
    C언어에서 코드를 추상화하는 데 사용되는  삼총사 : 배열, 구조체, 함수

    추상화 : 실제 세계 (현상)을 간략화/기호화/보편화 해서 표현한 것
    코드에서 추상화가 필요한 이유 : 결국 코드는 사람이 짜는 것이기 때문에
    다른 사람이 코드를 해석하기 위해 편리해야 하고
    다른 사람이 인수인계받아서 유지보수하기 편리해야하고
    다른 사람들과 함께 공동으로 코드를 만들기 편리해야 한다.

     - 배열 : 속성이 동일한 여러 개의 데이터를 같은 이름과 순서를 지정한 연속된 번호로
              서로 연관되어 있음을 표시함으로써 추상화함
     - 구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화한다.
     - 함수 : 프로세스(코드)를 특정 기능 단위로 묶어서 추상화

     최악의 추상화 -> 추상화 단계를 상승시키는 과정
     string a, b, c; // 최악의 추상화
     string a[3];
     string name1, name2, name3;
     string studentName[3]; //위의 것보다 의도가 명확하게 드러나기 때문에 좋은 추상화

     구조체란
     - 변수를 모아 놓은 집합체
     - 특정 변수들이 무언가의 하위 개념으로 묶일 수 있을 때
     - studentName[10], studentAge[10], studentKoreanScore[10],...
     - '학생'의 'XXX'
     - 이름, 나이, 국어점수, 석차 등등등 '학생'이라는 구조체로 묶어서 사용

     1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 정의된다.
     (해당 함수의 바깥쪽 앞(위))

     2. 구조체 정의 방법
     struct 구조체 변수명
     {
        구조체 안에 들어갈 하위 변수들
     }
     구조체는 일종의 우리가 새롭게 만든 데이터형

     구조체 안에 들어갈 수 있는 하위변수는 무엇이 있을까?
     당연히 int,bool,float 같은 기본 자료형들은 모두 사용 가능
     string <- 클래스도 쓸 수 있다

     3. 구조체 선언과 초기화
     기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
     int a[3]={10, 20, 30};

     주석 없이 코드를 배우지 않은 사람에

*/

#include <iostream>
#include <string>

using namespace std;

//struct score
//{
//    int kor;
//    int eng;
//    int math;
//};
//
//
//struct student
//{
//    string name;
//    string home;
//    int age;
//    int monthlyScore[12];// 배열도 넣을 수 있다.
//    score myscore;  //앞에 선언한 구조체도 넣을 수 있다.
//    
//}; // 중괄호의 끝과 세미클론 사이에다 student의 변수를 미리 선언 할수 있다.
// name, age, koreanscore,rank라는 하위 변수 




int main() // 이놈이 지금 우리가 쓰고 있는 유일한 함수
{
//   student minseop; //구조체 변수의 선언
//   
//   score myscore = { 50, 80, 90 };
//
//
//
//   //초간단 실습 : student 구조체를 사용하여 자기 자신의 정보를 입력해 보자.
//
//   cout << myscore.kor<< myscore.eng<< myscore.math << endl;

    /*과제: 미궁탈출 게임의 업데이트
    tile : 지형 정보를 넣고(숲, 늪, 평지)
    player : 피로도를 넣고
    플레이어가 어느 지형에 있는지, 플레이어의 피로도가 얼마인지(숲 :-1, 늪:-3, 평지:0)
    표시되도록 수정해 봅시다.


    */
   /*
        1. 두 정수를 입력받은 후 두 정수의 사칙연산 + 나머지(%)결과를 출력하기
        2. 최솟값과 최댓값을 입력받은 후 두 수 사이의 랜덤한 숫자 1개 출력하기
        3. 1~3사이의 숫자를 입력받은후 입력받은 숫자에 따라 다른 인삿말이 나오도록하기
        (출력 예시 : 숫자를 입력하시오(1~3) : 3
        좋은 하루 입니다.)
        4. 1부터 100까지의 숫자를 차례대로 출력하기
        출력되는 숫자의 옆에 홀수이면 홀수, 짝수이면 짝수라고 표시하기
        출력되는 숫자의 옆에 3의 배수이면 3의 배수라고, 5의 배수는 5의 배수라고 표시하기
   
        5. 1~100 사이의 임의의 숫자를 맞추는 게임
        오답을 입력하면 컴퓨터가 정답이 오답보다 큰지 작은지 알려주고 다섯 번 안에 못맞추면 게임 오버
   
   
   
   
   
   
   
   
   
   
   
   
   
   */



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