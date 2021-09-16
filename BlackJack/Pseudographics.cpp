//#include <iostream>
//#include <time.h>
//#include <Windows.h>
//#include <stdlib.h>
//
//#include "Graphics.h"
//#include "ConsoleLib.h"
//
//// Растягивает карты по игральному столу
//void shuffle_cards(int array[], int Size, int start_x, int start_y)
//{
//	srand((unsigned)time(NULL));
//
//	for (int y = start_x; y < start_x + 60; y + 3)
//	{
//		int z = 0;
//		while (array[z] != 0)
//		{
//			z = rand() % 107;
//			array[z] = 0;
//		}
//		card_on_display(y, start_y, array[z]);
//		Sleep(500);
//	}
//}