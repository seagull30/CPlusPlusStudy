#include "Scenemanger.h"
#include <windows.h>

int main()
{
	while (true)
	{
		if (SceneManger::IsSetnextScene())
		{
			SceneManger::Change();
		}
		SceneManger::Update();
		SceneManger::Render();

		Sleep(500);
	}
	return 0;
}


