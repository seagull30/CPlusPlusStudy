#include <iostream>
#include "Vector2D.h"
/*
using namespace std;

int main()
{
	Vector2D vec(2, 4);
	Vector2D vec2(3, 5);
	
	cout << vec + vec2 << '\n';
	cout << vec - vec2 << '\n';
	cout << vec * 2 << '\n';
	cout << 2 * vec<< '\n';
	/*
	vec._x = 10;

	// 1. 데이터 은닉에 위반 => 객체지향적 설계에 맞지 않음.
	//	-데이터 은닉(Data Hidding) : 구현 세부 사항에 사용되는 데이터를 외부에 노출하지 않는 것
	// 2. 디버깅이 어려워짐.
	// 3. 확장성이 떨어짐.
	
}
	*/


class A
{
public:
	int _data;
	A& operator=(A a)
	{
		std::swap(_data, a._data);
		return *this;
	}
};

int main()
{
	A a;
	a._data = 25;
	A b;
	b._data = 28;
	int c = 23;
	int d = 22;
	std::swap(c, d);

	std::cout << c << d << std::endl;
	a = b;
	std::cout << a._data << std::endl;
	std::cout << b._data << std::endl;

}
