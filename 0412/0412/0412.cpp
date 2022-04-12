// 0412.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*

    제어문   데이터(타입) / 연산자 / <제어구조>

    1. 조건문 : 특정 조건에 따라서 실행문을 실행할지 안할지 제어 ( if / switch )

    2. 반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행시키도록 제어 ( while / for )
    

    1. 조건문 
    1-1. if 문
        
        if (조건식)
        {
            실행문1; (참일떄 실행후 if문 종료)
        }
        else (또는 else if)
        {
            실행문2; (조건을 만족하지 못할경우 실행)
        }
    
    조건문 실습1
    정수를 하나 입력 받아서 입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다" 출력.
    10 이하 9 초과 "9보다 큽니다." 출력
    9 이하 6초과 이면 "6보다 큽니다." 출력
    그 이외에는 "6보다 작거나 같습니다."출력

    1-2. switch 문
        switch (정수형 변수)
        {
            case 정수1:
                실행문1;
            break;

            case 정수2:
                실행문2;
            break;

            default:    (해당하는 정수값이 없을 떄)
                실행문3;
            break;
        }

    조건문 실습2
    당신의 고향은 어디입니까?
    1. 서울   2.양평    3. 광주   4. 대전   5.제주도
    _1

    안녕하세요. 당신의 고향은 서울이군요.
    안녕하수꽝. 혼자옵서예.
    5개 중에 선택해주세요

    2. 반복문

    2-1. while 문
    
        while (조건식) (조건식이 거짓이 될때까지 반복실행된다.)
        {
            실행문;
            조건식을 바꾸는 실행문;   while문을 중단시키는 첫번째 방법

            if (조건식)
            {
                break;   while문을 중단시키는 두번째 방법
            }
        }








    2-2. do-while 문 : while문과는 달리 무조건 1번은 실행한다.

        do
        {
            실행문;
        }while(조건문);
    
    

    2-3. for 문

    for((1)초기식; (2)조건식; (3)증감식)
    {
        (4)실행문;
    }

    (1) -> (2) -> (4) -> (3) -> (2) -> (4) -> (3) -> ... 조건식의 값이 0이 나올 때까지 




    과제 별찍기
    1)
    *
    **
    ***
    ****
    *****
     
    2)
        *
       **
      ***
     ****
    *****

    3)
    *****
    ****
    ***
    **
    * 
    
    4) 
    *****
     ****
      ***
       **
        * 

    5)
        *
       ***
      *****
     *******
    *********

    6)
    *********
     *******
      *****
       ***
        *

    7)
    
        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *

*/

#include <iostream>
using namespace std;

int main()
{

#pragma region 실습1
    //입력
    //int input_Num;
    //
    //cout << "숫자를 입력해 주세요 : ";   
    //cin >> input_Num;
    //
    ////처리
    //if (input_Num > 10)
    //    cout << "입력된 숫자가 10보다 큽니다." << endl;    //출력
    //else if (input_Num > 9)
    //    cout << "입력된 숫자가 9보다 큽니다." << endl;    //출력
    //else if (input_Num > 6)
    //    cout << "입력된 숫자가 6보다 큽니다." << endl;    //출력
    //else
    //    cout << "6보다 작거나 같습니다." << endl;    //출력
#pragma endregion 

#pragma region 실습2
    //int hometown_Num;
    //
    //cout << "당신의 고향은 어디입니까?\n" << "1. 서울   2.양평    3. 광주   4. 대전   5.제주도" << endl;
    //
    //cin >> hometown_Num;
    //
    //switch (hometown_Num)
    //{
    //    
    //case 1:
    //    cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
    //    break;
    //
    //case 2:
    //    cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
    //    break;
    //
    //case 3:
    //    cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
    //    break;
    //
    //case 4:
    //    cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
    //    break;
    //
    //case 5:
    //    cout << "안녕하수꽝. 혼자옵서예." << endl;
    //    break;
    //
    //default:
    //    cout << "5개 중에 선택해주세요." << endl;
    //    
    //}
    
#pragma endregion

#pragma region 실습2_1

    //int hometown_Num2 = 0;
    //
    //cout << "당신의 고향은 어디입니까?\n 1. 서울   2.양평    3. 광주   4. 대전   5.제주도" << endl;
    //
    //
    //cin >> hometown_Num2;
    //
    //if (hometown_Num2 == 1)
    //    cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
    //else if (hometown_Num2 == 2)
    //    cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
    //else if (hometown_Num2 == 3)
    //    cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
    //else if (hometown_Num2 == 4)
    //    cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
    //else if (hometown_Num2 == 5)
    //    cout << "안녕하수꽝. 혼자옵서예." << endl;
    //else
    //    cout << "5개 중에 선택해주세요." << endl;
    
#pragma endregion

#pragma region while문
//hello world를 5번 출력하는 프로그램
    //int repeat_Count = 0;
    //
    //do 
    //{
    //    cout << "hello world!" << endl;
    //    repeat_Count++;
    //    
    //    if (repeat_Count >= 5)
    //        break;
    //} while (1);
#pragma endregion

#pragma region for문
//    for (int i = 0; i < 5; i++)
//    {
//        cout << "hello world!" << endl;
//    }
#pragma endregion

#pragma region 실습3

    //while문을 써서 정답을 맞출때까지 반복되는 프로그램으로 수정해보자

    //srand(time(NULL));
    //int corrent_Num = 1 + rand() % 9;
    //int input_Quiz_Num = 0;
    //
    //do
    //{
    //    cout << "정답일것같은 수를 입력해주세요 : ";
    //    cin >> input_Quiz_Num;
    //
    //    (corrent_Num == input_Quiz_Num) ? cout << "true" << endl : cout << "false" << endl;
    //
    //} while (input_Quiz_Num != corrent_Num);

#pragma endregion  

#pragma region 실습4
//    //4-1. 10부터 1까지 차례대로 출력되는 코드를 작성해보자.
//    
//for (int i = 10; i > 0; i--)
//{
//    cout << i << " ";
//    }
//cout << endl;
//
//
//
//
//
//    //4-2. 100미만의 3의 배수를 차례대로 출력되는 코드를 작성해보자.
//for (int j = 0; j < 100; j++)
//{
//    if (j % 3 == 0)
//        cout << j << " ";
//    }
//cout << endl;
//
//
//
//
//    //4-3. 1000미만의 2의 승수를 차례대로 출력되는 코드를 작성해보자.
//int temp;
//for (int k = 1; k < 1000; k*=2)
//{
//    cout << k << " ";
//}
#pragma endregion

#pragma region 실습5
////5-1. 구구단 2단을 차례대로 출력해보자.
////2*1=2
////2*2=4
//
//for (int i = 1; i < 10; i++)
//{
//    cout << "2 * " << i << " = " << i * 2 << endl;
//}
//
//
////5-2. 구구단 2단 ~ 9단을 차례대로 출력해보자.
////2단
//
////3단
// 
////4단 ... 
//for (int i = 2; i < 10; i++) {
//
//    for (int j = 1; j < 10; j++)
//    {
//        cout << i << " * " << j << " = " << i * j << endl;
//    }
//    cout << endl;
//}
//cout << endl;
// 
//
////5-3. 구구단 2단 ~ 9단을 차례대로 출력해보자.
//// 2단   3단   4단
//// 5단   6단   7단
//// 8단   9단    
//
//for (int i = 2; i < 10; i += 3) {
//    for (int j = 1; j < 10; j++) {
//        for (int k = i; k < i + 3; k++) {
//            if (k < 10) {
//                cout << k << " * " << j << " = ";
//                cout.width(2);
//                cout << k * j << "  ";
//            }
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
#pragma endregion

#pragma region 과제1

for (int line = 1; line < 6; line++)
{
    for (int star = 0; star < line; star++)
    {
        cout << "*";
    }
    cout << endl;
}
cout << endl;

#pragma endregion

#pragma region 과제2

for (int line = 1; line < 6; line++)
{
    for (int space = 0; space < 5 - line; space++)
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

#pragma region 과제3

for (int line = 5; line > 0; line--)
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

for (int line = 5; line > 0; line--)
{
    for (int space = 0; space < 5 - line; space++)
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
int star=1;
for (int line = 1; line < 6; line++)
{
    

    star += 2;
    cout << endl;
}
cout << endl;

#pragma endregion

#pragma region 과제6


#pragma endregion

#pragma region 과제7


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
