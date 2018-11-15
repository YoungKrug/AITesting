#pragma once
#include <Windows.h>
#include <iostream>
#include "Vec2.h"
namespace PlayerInfo
{
	class Player
	{
	public:
		Player(){}
		Player(Vector2 *pos, char characterLetter)
		{
			playerPos = pos;
			letter = characterLetter;
			states = MOVETOWARDS;
			gotoxy();
		}
		void ChangePlayerPos(Vector2 *pos)
		{
			MoveChar();
			std::cout << "  ";
			playerPos = pos;
			gotoxy();
		}
		void MoveChar()
		{
			COORD coord;
			coord.X = playerPos->x;
			coord.Y = playerPos->y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		void gotoxy()
		{
			COORD coord;
			coord.X = playerPos->x;
			coord.Y = playerPos->y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << letter;// the player
		}
		void MovePlayer(Vector2* pos) // IT WORKS POGGER
		{
			// Move towards methods
			if (playerPos->x == pos->x && playerPos->y == pos->y) // werid
			{ 
				//std::cout << *playerPos << std::endl;
				return;
			}
			gotoxy();
			//std::cout << *playerPos << " : Point we are going to : " << *pos << std::endl;
			playerPos->MoveTowards(pos);
		}
	public:
		Vector2* playerPos;
		char letter;
		enum PlayerAiStates
		{
			MOVETOWARDS,
			STOP,
			TURN,
			ATTACK
		};
		PlayerAiStates states;
	};
}