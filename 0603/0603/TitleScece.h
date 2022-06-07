#pragma once
#include "Scene.h"
#include <iostream>
#include <string.h>
#include <Time.h>
#include <random>

class TitleScene : public Scene
{
public:
	virtual void Init() override
	{
		std::cout << "�߻���" << _seungil << "�� �¾��.\n";
		srand(time(NULL));
	}
	virtual void Update() override
	{
		int behaviour = 1 + rand() % 4;
		switch (behaviour)
		{
		case 1:
			std::cout << _seungil << "�̴� �����鸦 �����.\n";
			break;

		case 2:
			std::cout << _seungil << "�̴� �����鸦 �� �ڽ� �����ߴ�.\n";
			break;

		case 3:
			std::cout << _seungil << "�̴� �����鸦 �����ش�.\n";
			break;

		case 4:
			std::cout << _seungil << "�̴� �����鸦 ���ְ� �Դ´�.\n";
			break;
		}
		
	}
	virtual void Render() override
	{
		std::cout << _seungil << "�̴� ��ڰ� ���� ���.\n";

	}
	virtual void Release()
	{
		std::cout << "�¹�.\n";
	}
private:
	using SeungIl = std::string;
	SeungIl		_seungil = "2^1";
};