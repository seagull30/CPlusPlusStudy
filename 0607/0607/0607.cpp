#include "temp.h"
#include <iostream>
template <typename T1, typename T2>
void Print(const T1& a, const T2& b)
{
    std::cout << a << '\n';
    std::cout << b << '\n';
}

// 명시적 특수화
template <>
void Print(const int& a, const double& b)
{
    std::cout << "이것은 명시적으로 특수화 되었습니다.\n";
}

// 부분 특수화
template <typename T>
void Print(const T& a, const int& b)
{
    std::cout << "이것은 부분적으로 특수화 되었습니다.\n";
}

int main()
{

    double d = 1.0;
    Print(d, d); // Print<double, double>; 암시적 특수화 버전 호출

    int i = 1;
    Print(i, d); // Print<int, double>; 명시적 특수화 버전 호출

    Print(d, i); // Print<double, int>; 부분 특수화 버전 호출


	return 0;
}

