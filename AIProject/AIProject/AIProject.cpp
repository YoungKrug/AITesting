// AIProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vec2.h"
#include "GameStarter.h"
#include <iostream>
using namespace PlayerInfo;
int main()
{
	Game* newGame = new Game();
	newGame->Update();
	system("Pause");
	return 0;
}
