#include "monster.h"
#include "Player.h"

#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Random.h"

void Monster_Init(Monster* Monster, struct tagPlayer* player)
{
	TextCopyWithWhite(&Monster->Text, L"M");
	SetCoord(Monster->Coord, Random_GetNumberFromRange(0, 115), Random_GetNumberFromRange(0, 30));
	Monster->player = player;
	Monster->Speed = 0.1f;

	//Monster->isActive =false;
}

void Monster_Update(Monster* Monster)
{
	static float time = 0.0f;
	time += Timer_GetDeltaTime();
	if (time > Monster->Speed)
	{
		if (Monster->player->Coord.X > Monster->Coord.X)
			++Monster->Coord.X;
		if (Monster->player->Coord.X < Monster->Coord.X)
			--Monster->Coord.X;
		if (Monster->player->Coord.Y > Monster->Coord.Y)
			++Monster->Coord.Y;
		if (Monster->player->Coord.Y < Monster->Coord.Y)
			--Monster->Coord.Y;
		time = 0;
	}

}
void Monster_Render(Monster* Monster)
{
	//if (Monster->isActive)
	//{
	Text* text = &Monster->Text;	
	Renderer_DrawText(text, 1, Monster->Coord.X, Monster->Coord.Y);
	//}
}
void Monster_Release(Monster* Monster)
{

}

//void spawn_Monster(void)
//{
//	Monster->isActive = true;
//}

bool Game_Over(Monster* Monster)
{
	if (Monster->player->Coord.X == Monster->Coord.X && Monster->player->Coord.Y == Monster->Coord.Y)
		return true;
	else
		return false;
}