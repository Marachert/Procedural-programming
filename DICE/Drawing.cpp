#include <iostream>
#include "ConsoleLib.h"

#define Left (MiddleX - width / 2)
#define Right (MiddleX + width / 2)
#define Top (MiddleY - height / 2)
#define Buttom (MiddleY + height / 2)

void DoubleLineFrame(int height, int width, int MiddleX, int MiddleY, ConsoleColor line, ConsoleColor background)
{
	const unsigned char DblLeftCornerTop = 201;
	const unsigned char DblRightCornerTop = 187;
	const unsigned char DblRightCornerButtom = 188;
	const unsigned char DblLeftCornerButtom = 200;
	const unsigned char DblLine = 205;
	const unsigned char DblVerticalLine = 186;

	SetColor(line, Black);
	WriteChar(Left, Top, DblLeftCornerTop);
	WriteChar(Right, Top, DblRightCornerTop);
	WriteChar(Right, Buttom, DblRightCornerButtom);
	WriteChar(Left, Buttom, DblLeftCornerButtom);
	WriteChars(Left + 1, Top, DblLine, width - 1);
	WriteChars(Left + 1, Buttom, DblLine, width - 1);

	for (int y = Top + 1; y < Buttom; y++)
	{
		WriteChar(Left, y, DblVerticalLine);
		WriteChar(Right, y, DblVerticalLine);
	}

	SetColor(White, Black);
}

int DiceSide(int num, int MiddleX, int MiddleY)
{
	const int ArraySize = 7;
	const int DiceSizeX = 10;
	const int DiceSizeY = 5;
	int ArrayX[ArraySize]{ MiddleX - 3, MiddleX, MiddleX + 3, MiddleX, MiddleX - 3, MiddleX, MiddleX + 3 };
	int ArrayY[ArraySize]{ MiddleY - 1, MiddleY - 1, MiddleY - 1, MiddleY, MiddleY + 1, MiddleY + 1, MiddleY + 1 };

	switch (num)
	{
	case 1:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		WriteChar(ArrayX[3], ArrayY[3], '*');
		break;
	case 2:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		for (int y = 0; y < ArraySize; y++)
		{
			if (y == 0 || y == 6)
				WriteChar(ArrayX[y], ArrayY[y], '*');
		}
		break;
	case 3:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		for (int y = 0; y < ArraySize; y++)
		{
			if (y == 0 || y == 6 || y == 3)
				WriteChar(ArrayX[y], ArrayY[y], '*');
		}
		break;
	case 4:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		for (int y = 0; y < ArraySize; y++)
		{
			if (y != 1 && y != 3 && y != 5)
				WriteChar(ArrayX[y], ArrayY[y], '*');
		}
		break;
	case 5:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		for (int y = 0; y < ArraySize; y++)
		{
			if (y != 1 && y != 5)
				WriteChar(ArrayX[y], ArrayY[y], '*');
		}
		break;
	case 6:
		DoubleLineFrame(DiceSizeY, DiceSizeX, MiddleX, MiddleY, Green, Black);
		for (int y = 0; y < ArraySize; y++)
		{
			if (y != 3)
				WriteChar(ArrayX[y], ArrayY[y], '*');
		}
		break;
	default:
		break;
	}
	return num;
}

