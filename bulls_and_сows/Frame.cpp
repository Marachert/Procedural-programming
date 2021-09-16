#include <iostream>
#include <iomanip>
using namespace std;

const unsigned char TopLeft = 201;
const unsigned char MiddleTop = 203;
const unsigned char TopRight = 187;
const unsigned char HorizontalLine = 205;
const unsigned char VerticalLine = 186;
const unsigned char CrosspieceLeft = 204;
const unsigned char CrosspieceRight = 185;
const unsigned char CrosspieceMiddle = 206;

// draw header of the table of results
void topOfFrame()
{
	for (int y = 0; y <= 35; y++)
	{
		if (y == 0)
			cout << TopLeft;
		else if (y == 15 || y == 25)
			cout << MiddleTop;
		else  if (y == 35)
			cout << TopRight;
		else
			cout << HorizontalLine;
	}
	cout << endl;

	cout << VerticalLine << setw(14) << " YOUR NUMBER  " << VerticalLine << setw(9) << "COWS   " << VerticalLine <<
		setw(9) << "BULLS  " << VerticalLine << endl;

	for (int y = 0; y <= 35; y++)
	{
		if (y == 0)
			cout << CrosspieceLeft;
		else if (y == 15 || y == 25)
			cout << CrosspieceMiddle;
		else  if (y == 35)
			cout << CrosspieceRight;
		else
			cout << HorizontalLine;
	}
}

//results recorded in a frame
void resultInFrame(int playerNumber, int cows, int bulls)
{
	cout << VerticalLine << setw(10) << playerNumber << "    " << VerticalLine << setw(5) << cows << "    " << VerticalLine <<
		setw(5) << bulls << "    " << VerticalLine << endl;

	for (int y = 0; y <= 35; y++)
	{
		if (y == 0)
			cout << CrosspieceLeft;
		else if (y == 15 || y == 25)
			cout << CrosspieceMiddle;
		else  if (y == 35)
			cout << CrosspieceRight;
		else
			cout << HorizontalLine;
	}
}

