#include <iostream>
#include <windows.h>

using namespace std;

//Displaying a welcome menu and game rules
void welcomeScreen()
{
	system("color 6d");

	cout << "\n\n\n\n\n\t\t\t\t\tWELCOME TO WORLD OF \"COWS AND BULLS!!!\"\n\n"
		"\t\t\tYou need to guess the secret four-digit number, the numbers in which \n"
		"\t\t\tare not repeated and the first number is not equal to 0. After each \n"
		"\t\t\tmove, the computer will show how many numbers are correct, but not in \n"
		"\t\t\ttheir position (cows) and how many guessed up to the position (bulls).\n\n\n"

		"\n\n\n\n\n\n\n\n\n\t\t\t\tCopyright (c) Marushchak Co 2021 All rights reserved.";

	Sleep(5000);
	system("cls");
}

//displays the winner's inscription
void winnerSign(int count)
{
	system("cls");
	system("color 9e");

	cout << "YOU WIN IN " << count << " TRIES!!!" << endl;

	Sleep(4000);
	system("cls");
}

