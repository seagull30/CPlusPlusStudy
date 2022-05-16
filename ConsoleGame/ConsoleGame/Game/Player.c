#include "Player.h"

#include "Framework/Input.h"
#include "Framework/Renderer.h"

void Player_Init(Player* player)
{
	TextCopyWithWhite(&player->Text, L"P");
	SetCoord(player->Coord, 0, 0);
	Gun_Init(&player->yellowGun ,TEXT_COLOR_YELLOW);
	Gun_Init(&player->mazentaGun, TEXT_COLOR_MAGENTA);
	
}

void Player_Update(Player* player)
{
	if (Input_GetKey(VK_DOWN))
	{
		++player->Coord.Y;
	}

	if (Input_GetKey(VK_UP))
	{
		--player->Coord.Y;
	}

	if (Input_GetKey(VK_LEFT))
	{
		--player->Coord.X;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		++player->Coord.X;
	}
	if (Input_GetKey('1'))
	{
		Gun_Shoot(&player->yellowGun, player->Coord.X + 1, player->Coord.Y);
	}
	if (Input_GetKey('2'))
	{
		Gun_Shoot(&player->mazentaGun, player->Coord.X + 1, player->Coord.Y);
	}
	//if (Input_GetKey(VK_SPACE))
	//{
	//	Gun_Shoot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	//}
	//if (Input_GetKey('M'))
	//{
	//	spawn_Monster();
	//}
	

	Gun_Update(&player->yellowGun);
	Gun_Update(&player->mazentaGun);
}

void Player_Render(Player* player)
{
	Text* text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);

	Gun_Render(&player->yellowGun);
	Gun_Render(&player->mazentaGun);
}

void Player_Release(Player* player)
{
	Gun_Release(&player->yellowGun);
	Gun_Render(&player->mazentaGun);
}