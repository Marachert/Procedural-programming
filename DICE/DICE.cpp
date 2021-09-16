#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include "ConsoleLib.h"
#include "Drawing.h"

const int PositionXFirstDice = 10;
const int PositionYFirstDice = 6;
const int PositionXSecondDice = 25;
const int PositionYSecondDice = 6;

// Псевдографика крутящихся игровых костей
void FakeGraphics()
{
	for (int y = 0; y < 20; y++)
	{
		DiceSide(rand() % 6 + 1, PositionXFirstDice, PositionYFirstDice);
		DiceSide(rand() % 6 + 1, PositionXSecondDice, PositionYSecondDice);
		Sleep(100);
		ClearScreen();
	}
}

int main()
{
	const char SpaceBar = 32;
	int key = 0, PlayerPoints = 0, ComputerPoints = 0;

	srand((unsigned)time(0));
	ShowCursor(false);

	WriteStr(50, 10, "Player's turn (Enter SPACEBAR )...");
	key = _getch();

	if (key == 0 || key == 0xE0)
		_getch;

	if (key == SpaceBar)
	{
		FakeGraphics();
		PlayerPoints = DiceSide(rand() % 6 + 1, PositionXFirstDice, PositionYFirstDice) +
			           DiceSide(rand() % 6 + 1, PositionXSecondDice, PositionYSecondDice);
	}

	Sleep(5000);
	ClearScreen();
	WriteStr(50, 10, "Computer's turn...");
	Sleep(5000);
	FakeGraphics();
	ComputerPoints = DiceSide(rand() % 6 + 1, PositionXFirstDice, PositionYFirstDice) +
				     DiceSide(rand() % 6 + 1, PositionXSecondDice, PositionYSecondDice);

	Sleep(5000);
	ClearScreen();
	(PlayerPoints > ComputerPoints) ? WriteStr(50, 10, "Player WIN") : WriteStr(50, 10, "Computer WIN");


	while (_kbhit)
		_getch;
}