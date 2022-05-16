#pragma once
#include "Common.h"
#include "Type.h"
#include "Player.h"

#include "Framework/Text.h"
#include "Framework/Timer.h"


typedef struct tagMonster
{
	Text	Text;
	COORD	Coord;
	float	Speed;
	struct tagPlayer* player;
	
} Monster;

void Monster_Init(Monster* Monster, struct tagPlayer* player);
void Monster_Update(Monster* Monster);
void Monster_Render(Monster* Monster);
void Monster_Release(Monster* Monster);
//void spawn_Monster(Monster* Monster);
bool Game_Over(Monster* Monster);