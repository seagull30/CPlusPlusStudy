#include <iostream>

using namespace std;
class A
{
public:
	virtual void Func1()
	{
		cout << "void A:: Func1" << endl;
	}
	virtual void Func2()
	{
		cout << "void A:: Func2" << endl;
	}
};

class B : public A
{
public:
	void Func1() 
	{
		cout << "void B:: Func1" << endl;
	}
	void Func3()
	{
		cout << "void B:: Func3" << endl;
	}
};

int main()
{
	A a;
	B b;

	A* temp = &b;
	temp->Func1();
	temp->Func2();
}