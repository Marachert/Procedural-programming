#include <iostream>
#include "Frame.h"
#include "Display.h"
#include "Numbers.h"

int main()
{
	int playerNumber, count = 0, secretNumber = fourDifferentDigitsNumber();

	welcomeScreen();

	topOfFrame();
	
	while (true)
	{
		playerNumber = enterPlayerNumber();

		resultInFrame(playerNumber, cows(playerNumber, secretNumber), bulls(playerNumber, secretNumber));

		count++;

		if (bulls(playerNumber, secretNumber) == 4)
		{
			winnerSign(count);
			break;
		}
	}
}