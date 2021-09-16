#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "ConsoleLib.h"
#include "Drawing.h"


int main()
{
	const int Esc = 27;
	const int Zero = 48;
	const int MiddleOfFrameX = 107;
	const int WidthOfFrame = 20;
	const int HightOfFrame = 10;
	const int MiddleOfFrameY = 8;

	int key = 0, speed = 500, points = 0;
	char life = 57, PointsCh = 48;

	srand((unsigned)time(0));

	ShowCursor(false);

	// ������ ����� ������� �����������
	DoubleLineFrame(HightOfFrame, WidthOfFrame, MiddleOfFrameX, MiddleOfFrameY, Blue, Magenta);
	WriteStr(100, 5, "LIFES:");
	WriteStr(99, 7, "POINTS:");
	WriteStr(99, 9, "PRESS ESC TO EXIT");

	while (key != Esc)
	{
		// ������ ������������ ����� � ������������ ���������� ������ �������
		int CursorX = rand() % 90;
		int CursorY = 1;
		char ch = rand() % 25 + 65;

		while (CursorY < GetConsoleSizeY())
		{
			//������� �������� ����� � �������� ���������
			Sleep(speed);
			SetColor(Green, Black);
			WriteChar(CursorX, CursorY, ch);
			SetColor(Black);
			WriteChar(CursorX, (CursorY - 1), ' ');
			
			// ��������� ����� �� ������� �������. ��� ������� �������� ��� � ���������� key
			while (_kbhit())
			{
				key = _getch();

				if (key == 0 || key == 0xE0)
				{
					_getch();
					key = 0;
				}
			}

			// ���������� ���������� �������� � �������� ������. ��� ���������� ��� ��� ������� ESC 
			// ����������� �������� � ���������� �������. 
			if (toupper(key) == ch || key == Esc)
			{
				points++;
				speed -= 5;

				if (speed == 25)
					speed = 500;
				WriteChar(CursorX, CursorY, ' ');
				break;
			}

			// ���� ����� ����� �� ����� �������, ��������� ���������� ������ �� 1
			if (CursorY == GetConsoleSizeY() - 1)
				life--;

			if (life == Zero)
			{
				ClearScreen();
				SetColor(Green, Black);
				WriteStr(GetConsoleSizeX() / 2, GetConsoleSizeY() / 2, "GAME OVER!!!");
				Sleep(2000);
				break;
			}

			// ������� ���������� ������ � ����� �� �����
			SetColor(Red, Black);
			WriteChar(107, 5, life);
			WriteChar(110, 7, PointsCh + points % 10);
			WriteChar(109, 7, PointsCh + points / 10 % 10);
			WriteChar(108, 7, PointsCh + points / 100 % 10);
			WriteChar(107, 7, PointsCh + points / 1000 % 10);

			CursorY++;
		}
	}
}