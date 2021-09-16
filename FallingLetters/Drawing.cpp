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

	for (int y = Top + 1; y < Buttom; y++)
		for (int x = Left + 1; x < Right; x++)
		{
			SetColor(Yellow, background);
			WriteChar(x, y, ' ');
		}

	SetColor(White, Black);
}
