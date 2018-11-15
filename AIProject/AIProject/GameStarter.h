#pragma once
#include <chrono>
#include<vector>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "Player.h"
namespace PlayerInfo
{
	class Game
	{
	public:
		void gotoxy(int x, int y)
		{
			COORD coord;
			coord.X = x;
			coord.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		Game() {};
		void InitGame(Player& player, int boxSize)
		{
			CreateBox(40);
			player.ChangePlayerPos(new Vector2(boxSize - boxSize / 2, boxSize / 2 + boxSize));
		}
		Game Get()
		{
			return *this;
		}
		bool CheckIfLocationIsUsed(const Vector2 pos)
		{
			for (int i = 0; i < positions.size(); i++)
			{
				if (positions[i] == pos)
					return true;
			}
			return false;
		}
		void Update();
		void CreateBox(int size)
		{
			int height = size;
			int width = size;
			gotoxy(0, 0);
			for (int i = 0; i < size; i++)
			{
				gotoxy(0, height + i);
				std::cout << "o";
				gotoxy(width, height + i);
				std::cout << "o";
				gotoxy(i, height);
				std::cout << "o";
				gotoxy(i, height + size);
				std::cout << "o";
				positions.push_back(Vector2(0, height + i));
				positions.push_back(Vector2(width, height + i));
				positions.push_back(Vector2(i, height));
				positions.push_back(Vector2(i, height + size));
			}
			//TileMap* map = map->getInstance();
			//map->SetTiles(positions);
		
			


		}
		//void Start();
		std::vector<Vector2> positions;
	protected:
		void InitUpdate()
		{
			using namespace std::this_thread;
			std::this_thread::sleep_for(std::chrono::microseconds(15005)); // its 1,02 may be the computer tbh but the function works
		}
	};
}