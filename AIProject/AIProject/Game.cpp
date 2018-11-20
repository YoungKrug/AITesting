#include "pch.h"
#include <iostream>
#include "Player.h"
#include "GameStarter.h"
#include "Vec2.h"
namespace PlayerInfo
{
	void Game::Update()
	{
		Player* player = new Player(new Vector2(50, 40),'v');
		Player* enemy = new Player(new Vector2(10, 0),'x'); 
		InitGame(*player,40);
		while (1)
		{
			InitUpdate();
			player->MovePlayer(enemy->playerPos, *enemy); // asd
			
			
			// Updater



		}
		delete(player);
		delete(enemy);
	}

}