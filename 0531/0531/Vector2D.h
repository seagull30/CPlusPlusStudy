#pragma once

#include <iostream>

class Vector2D
{
public:
	//생성자 : 필드의 초기화
	Vector2D() : Vector2D(0, 0) {}
	Vector2D(int x, int y) : _x(x), _y(y) {}

	//접근자(Getter)
	int GetX() const { return _x; }
	int GetY() const { return _y; }
	//설정자(setter)
	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }
	// 두  벡터끼리 더함
	Vector2D operator+(const Vector2D& rhs) const
	{
		return Vector2D(_x + rhs._x, _y + rhs._y);
	}

	// 두 벡터끼리 뺌
	Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(_x - rhs._x, _y - rhs._y);
	}

	// 스칼라곱
	Vector2D operator*(int rhs) const
	{
		return Vector2D(_x * rhs, _y * rhs);
	}
private:
	int		_x;
	int		_y;
};

Vector2D operator*(int lhs, const Vector2D& rhs)
{
	return rhs * lhs;
}

std::ostream& operator<<(std::ostream& oss, const Vector2D& vec)
{
	oss << "Vec(" << vec.GetX() << ", " << vec.GetY() << ")";
		return oss;
}