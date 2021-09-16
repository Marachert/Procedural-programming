#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// generate random number from 0 to 9
int getRandomNumber()
{
	srand((unsigned)time(0));
	return rand() % 10;
}

// generate an arbitrary four-digit number with non-repeating digits
int fourDifferentDigitsNumber()
{
	int array[4];

	for (int x = 0; x < 4; x++)
		array[x] = getRandomNumber();

	for (int x = 1; x < 4; x++)
	{
		do
		{
			array[0] = getRandomNumber();
			if (array[0] != array[1] && array[0] != array[2] && array[0] != array[3] && array[3] != 0)
				break;
		} while (true);

		int temp = array[0];
		array[0] = array[x];
		array[x] = temp;
	}
	system("cls");
	return array[0] * 1000 + array[1] * 100 + array[2] * 10 + array[3];
}

//the function returns the number entered by the player
int enterPlayerNumber()
{
	int playerNumber;

	system("color 4a");

	cout << "   Enter your number: ";
	cin >> playerNumber;

	return playerNumber;
}

//returns the number of complete matches
int bulls(int playerNum, int secretNum)
{
	int playerArray[4], secretArray[4], numOfCorrectIndexes = 0;

	playerArray[0] = playerNum / 1000;
	playerArray[1] = playerNum / 100 % 10;
	playerArray[2] = playerNum / 10 % 10;
	playerArray[3] = playerNum % 10;

	secretArray[0] = secretNum / 1000;
	secretArray[1] = secretNum / 100 % 10;
	secretArray[2] = secretNum / 10 % 10;
	secretArray[3] = secretNum % 10;

	for (int y = 0; y < 4; y++)
	{
		if (playerArray[y] == secretArray[y])
			numOfCorrectIndexes++;
	}
	return numOfCorrectIndexes;
}

// returns the number of correctly entered digits that are out of place
int cows(int playerNum, int secretNum)
{
	int playerArray[4], secretArray[4], numOfCorrectDiggits = 0;

	playerArray[0] = playerNum / 1000;
	playerArray[1] = playerNum / 100 % 10;
	playerArray[2] = playerNum / 10 % 10;
	playerArray[3] = playerNum % 10;

	secretArray[0] = secretNum / 1000;
	secretArray[1] = secretNum / 100 % 10;
	secretArray[2] = secretNum / 10 % 10;
	secretArray[3] = secretNum % 10;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (playerArray[y] == secretArray[x] && y != x)
				numOfCorrectDiggits++;
		}
	return numOfCorrectDiggits;
}




