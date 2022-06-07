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
		std::cout << "¾ß»ýÀÇ" << _seungil << "ÀÌ ÅÂ¾î³µ´Ù.\n";
		srand(time(NULL));
	}
	virtual void Update() override
	{
		int behaviour = 1 + rand() % 4;
		switch (behaviour)
		{
		case 1:
			std::cout << _seungil << "ÀÌ´Â ¸¶ÀÌÂé¸¦ »¯°å´Ù.\n";
			break;

		case 2:
			std::cout << _seungil << "ÀÌ´Â ¸¶ÀÌÂé¸¦ ÇÑ ¹Ú½º ±¸¸ÅÇß´Ù.\n";
			break;

		case 3:
			std::cout << _seungil << "ÀÌ´Â ¸¶ÀÌÂé¸¦ ³ª´²ÁØ´Ù.\n";
			break;

		case 4:
			std::cout << _seungil << "ÀÌ´Â ¸¶ÀÌÂé¸¦ ¸ÀÀÖ°Ô ¸Ô´Â´Ù.\n";
			break;
		}
		
	}
	virtual void Render() override
	{
		std::cout << _seungil << "ÀÌ´Â ±â»Ú°Ô ÃãÀ» Ãá´Ù.\n";

	}
	virtual void Release()
	{
		std::cout << "½Â¹Ù.\n";
	}
private:
	using SeungIl = std::string;
	SeungIl		_seungil = "2^1";
};