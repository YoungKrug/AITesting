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
			std::cout << " ";
			COORD coord;
			coord.X = playerPos->x;
			coord.Y = playerPos->y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		void gotoxy()
		{
			RemoveCurrentPos();
			std::cout << " ";
			COORD coord;
			coord.X = playerPos->x;
			coord.Y = playerPos->y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << letter;// the player
		}
		void RemoveCurrentPos()
		{
			COORD coord;
			coord.X = lastPos.x;
			coord.Y = lastPos.y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << "   ";// the player
		}

		void MovePlayer(Vector2* pos, Player &enemy) // IT WORKS POGGER
		{
			// Move towards methods
			if (playerPos->x == pos->x && playerPos->y == pos->y) // werid
			{
				//std::cout << *playerPos << std::endl;
				enemy.playerPos->RandomVector();
				enemy.ChangePlayerPos(enemy.playerPos);
				return;

			}
			gotoxy();
			//std::cout << *playerPos << " : Point we are going to : " << *pos << std::endl;
			lastPos = *playerPos;

			playerPos->MoveTowards(pos);

		}
	public:
		Vector2* playerPos;
		Vector2 lastPos;
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