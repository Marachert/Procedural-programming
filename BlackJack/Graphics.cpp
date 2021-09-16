// Функции, которые отвечают за графику игры

#include <iostream>
#include <time.h>
#include <conio.h>
#include "ConsoleLib.h"


using namespace std;

#define LEFT (middle_x - 3)
#define RIGHT (middle_x + 4)
#define TOP (middle_y - 3)
#define BUTTOM (middle_y + 3)

const unsigned char vertical_line = 179;
const unsigned char left_top = 218;
const unsigned char right_top = 191;
const unsigned char left_buttom = 192;
const unsigned char right_buttom = 217;
const unsigned char horisontal_line = 196;
const unsigned char dbl_left_corner_top = 201;
const unsigned char dbl_right_corner_top = 187;
const unsigned char dbl_right_corner_buttom = 188;
const unsigned char dbl_left_corner_buttom = 200;
const unsigned char dbl_line = 205;
const unsigned char dbl_vertical_line = 186;
const unsigned char flat_left_vertical_line = 221;
const unsigned char flat_right_vertical_line = 222;
const unsigned char flat_bottom_line = 220;
const unsigned char flat_top_line = 223;

const int card_width = 8;
const char hearts = 3, spades = 6, diamonds = 4, clubs = 5, cards_back = 178;


// рисует пустую карту
void card_frame(int middle_y, int middle_x)
{
	set_color(Black, White);
	write_char(LEFT, TOP, left_top);
	write_char(LEFT, BUTTOM, left_buttom);
	write_char(RIGHT, TOP, right_top);
	write_char(RIGHT, BUTTOM, right_buttom);
	write_chars(LEFT + 1, TOP, horisontal_line, card_width - 2);
	write_chars(LEFT + 1, BUTTOM, horisontal_line, card_width - 2);

	for (int y = TOP + 1; y < BUTTOM; y++)
	{
		write_char(LEFT, y, vertical_line);
		write_char(RIGHT, y, vertical_line);
	}

	set_color(White, White);

	for (int y = TOP + 1; y < BUTTOM; y++)
		for (int x = LEFT + 1; x < RIGHT; x++)
			write_char(x, y, 32);
	set_color(White, Black);
}

// Рисует черное поле необходимого размера
void black_field(int length, int width, int middle_x, int middle_y)
{
	set_color(Black, Black);
	for (int y = middle_y - width / 2; y <= middle_y + width / 2; y++)
		write_chars(middle_x - length / 2, y, 'O', length);
}

// Рисуем разноцветное поле для боковых вставок на экран
void color_field(int length, int width, int middle_x, int middle_y)
{
	for (int y = middle_y - width / 2; y <= middle_y + width / 2; y++)
		for (int x = middle_x - length / 2; x <= middle_x + length / 2; x++)
		{
			if (x % 2 == 0)
			{
				set_color(Red, Yellow);
				write_char(x, y, hearts);
			}
			else if (x % 3 == 0)
			{
				set_color(Black, Yellow);
				write_char(x, y, spades);
			}
			else
			{
				set_color(Black, Yellow);
				write_char(x, y, clubs);
			}
			if (x % 4 == 0)
			{
			set_color(Red, Yellow);
			write_char(x, y, diamonds);
			}
		}
}

// Рисуем коричневую рамку вокруг стола
void brown_table_frame(int middle_x, int middle_y)
{
	set_color(Brown, Brown);

	for (int y = middle_y - 10; y < middle_y + 11; y++)
		for (int x = middle_x - 40; x < middle_x + 40; x++)
		{
			if (y == middle_y - 10 || y == middle_y + 10)
				write_char(x, y, 254);
			if (x == middle_x - 40 || x == middle_x + 39 || x == middle_x - 39 || x == middle_x + 38)
				write_char(x, y, 219);
		}

}

// Рисует зеленое поле необходимого размера
void green_field(int length, int width, int middle_x, int middle_y)
{
	set_color(Green, Green);
	for (int y = middle_y - width / 2; y <= middle_y + width / 2; y++)
		write_chars(middle_x - length / 2, y, 'O', length);
}

// Надпись о кнопках навигации
void control_button()
{
	set_color(Black, Red);
	write_str(42, 27, "Press \"ESC\" to return to the main menu");
	set_color(White, Black);
}

// Рисует карту по её номеру в заданных координатах и возвращает количество очков, номиналом этой карты
int card_on_display(int middle_x, int middle_y, int card_num)
{
	enum cards
	{
		card_back = 100,

		hearts_two = 102,
		hearts_three = 103,
		hearts_four = 104,
		hearts_five = 105,
		hearts_six = 106,
		hearts_seven = 107,
		hearts_eight = 108,
		hearts_nine = 109,
		hearts_ten = 110,
		hearts_jack = 111,
		hearts_queen = 112,
		hearts_king = 113,
		hearts_ace = 114,

		spades_two = 202,
		spades_three = 203,
		spades_four = 204,
		spades_five = 205,
		spades_six = 206,
		spades_seven = 207,
		spades_eight = 208,
		spades_nine = 209,
		spades_ten = 210,
		spades_jack = 211,
		spades_queen = 212,
		spades_king = 213,
		spades_ace = 214,

		diamonds_two = 302,
		diamonds_three = 303,
		diamonds_four = 304,
		diamonds_five = 305,
		diamonds_six = 306,
		diamonds_seven = 307,
		diamonds_eight = 308,
		diamonds_nine = 309,
		diamonds_ten = 310,
		diamonds_jack = 311,
		diamonds_queen = 312,
		diamonds_king = 313,
		diamonds_ace = 314,

		clubs_two = 402,
		clubs_three = 403,
		clubs_four = 404,
		clubs_five = 405,
		clubs_six = 406,
		clubs_seven = 407,
		clubs_eight = 408,
		clubs_nine = 409,
		clubs_ten = 410,
		clubs_jack = 411,
		clubs_queen = 412,
		clubs_king = 413,
		clubs_ace = 414
	};

	cards card;

	card = cards(card_num);

	switch (card)
	{
	case card_back:
		card_frame(middle_x, middle_y);
		set_color(Red, White);
		for (int y = TOP + 1; y < BUTTOM + 1; y++)
			for (int x = LEFT + 1; x < RIGHT - 1; x++)
				write_char(y, x, cards_back);
		return 0;
	case hearts_two:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2)|| (y == TOP + 4 && x == LEFT + 2) || 
					(y == BUTTOM - 2 && x == RIGHT - 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '2');
		return hearts_two % 100;

	case hearts_three:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '3');
		return hearts_three % 100;

	case hearts_four:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '4');
		return hearts_four % 100;

	case hearts_five:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '5');
		return hearts_five % 100;

	case hearts_six:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '6');
		return hearts_six % 100;

	case hearts_seven:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '7');
		return hearts_seven % 100;

	case hearts_eight:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '8');
		return hearts_eight % 100;

	case hearts_nine:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '9');
		return hearts_nine % 100;

	case hearts_ten:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3) ||
					(y == TOP + 4 && x == LEFT + 5))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, '1');
		write_char(TOP + 2, LEFT + 1, '0');

		return hearts_ten % 100;

	case hearts_jack:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, 'J');
		return hearts_ten % 100;

	case hearts_queen:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, 'Q');
		return hearts_ten % 100;

	case hearts_king:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, 'K');
		return hearts_ten % 100;

	case hearts_ace:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, hearts);
			}
		write_char(TOP + 1, LEFT + 1, 'A');
		return hearts_ten % 100 + 1;

// Рисует пики
	case spades_two:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '2');
		return spades_two % 100;

	case spades_three:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '3');
		return spades_three % 100;

	case spades_four:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '4');
		return spades_four % 100;

	case spades_five:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '5');
		return spades_five % 100;

	case spades_six:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '6');
		return spades_six % 100;

	case spades_seven:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '7');
		return spades_seven % 100;

	case spades_eight:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '8');
		return spades_eight % 100;

	case spades_nine:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '9');
		return spades_nine % 100;

	case spades_ten:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3) ||
					(y == TOP + 4 && x == LEFT + 5))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, '1');
		write_char(TOP + 2, LEFT + 1, '0');
		return spades_ten % 100;

	case spades_jack:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, 'J');
		return spades_ten % 100;

	case spades_queen:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, 'Q');
		return spades_ten % 100;

	case spades_king:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, 'K');
		return spades_ten % 100;

	case spades_ace:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, spades);
			}
		write_char(TOP + 1, LEFT + 1, 'A');
		return spades_ten % 100 + 1;

// Рисуем бубны
	case diamonds_two:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '2');
		return diamonds_two % 100;

	case diamonds_three:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '3');
		return diamonds_three % 100;

	case diamonds_four:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '4');
		return diamonds_four % 100;

	case diamonds_five:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '5');
		return diamonds_five % 100;

	case diamonds_six:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '6');
		return diamonds_six % 100;

	case diamonds_seven:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '7');
		return diamonds_seven % 100;

	case diamonds_eight:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '8');
		return diamonds_eight % 100;

	case diamonds_nine:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '9');
		return diamonds_nine % 100;

	case diamonds_ten:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3) ||
					(y == TOP + 4 && x == LEFT + 5))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, '1');
		write_char(TOP + 2, LEFT + 1, '0');

		return diamonds_ten % 100;

	case diamonds_jack:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, 'J');
		return diamonds_ten % 100;

	case diamonds_queen:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, 'Q');
		return diamonds_ten % 100;

	case diamonds_king:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, 'K');
		return diamonds_ten % 100;

	case diamonds_ace:
		card_frame(middle_x, middle_y);
		set_color(Red, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, diamonds);
			}
		write_char(TOP + 1, LEFT + 1, 'A');
		return diamonds_ten % 100 + 1;

// Рисует трефы
	case clubs_two:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '2');
		return clubs_two % 100;

	case clubs_three:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == BUTTOM - 2 && x == RIGHT - 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '3');
		return clubs_three % 100;

	case clubs_four:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '4');
		return clubs_four % 100;

	case clubs_five:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '5');
		return spades_five % 100;

	case clubs_six:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '6');
		return clubs_six % 100;

	case clubs_seven:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '7');
		return clubs_seven % 100;

	case clubs_eight:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '8');
		return clubs_eight % 100;

	case clubs_nine:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '9');
		return clubs_nine % 100;

	case clubs_ten:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 1 && x == RIGHT - 3) ||
					(y == TOP + 5 && x == LEFT + 2) || (y == BUTTOM - 3 && x == RIGHT - 3) ||
					(y == BUTTOM - 3 && x == LEFT + 2) || (y == TOP + 3 && x == LEFT + 3) ||
					(y == TOP + 5 && x == LEFT + 3) || (y == TOP + 4 && x == LEFT + 2) ||
					(y == TOP + 4 && x == LEFT + 4) || (y == TOP + 4 && x == LEFT + 3) ||
					(y == TOP + 4 && x == LEFT + 5))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, '1');
		write_char(TOP + 2, LEFT + 1, '0');
		return clubs_ten % 100;

	case clubs_jack:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, 'J');
		return clubs_ten % 100;

	case clubs_queen:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, 'Q');
		return clubs_ten % 100;

	case clubs_king:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, 'K');
		return clubs_ten % 100;

	case clubs_ace:
		card_frame(middle_x, middle_y);
		set_color(Black, White);

		for (int y = 0; y < BUTTOM; y++)
			for (int x = 0; x < RIGHT; x++)
			{
				if ((y == TOP + 1 && x == LEFT + 2) || (y == BUTTOM - 2 && x == RIGHT - 4))
					write_char(y, x, clubs);
			}
		write_char(TOP + 1, LEFT + 1, 'A');
		return clubs_ten % 100 + 1;
	}
}

// Тасует карты
void shuffle_cards(const int array[], int Size, int start_x, int start_y)
{
	green_field(10, 10, 87, start_y);

	for (int x = 0; x < 5; x++) 
	{		
		for (int y = start_x; y < start_x + 60; y += 3)
		{
			card_on_display(start_y, y, array[rand() % 104 + 1]);
			Sleep(15);
		}
	}
	for (int y = start_x; y < start_x + 60; y += 3)
	{
		card_on_display(start_y, y, array[0]);
		Sleep(15);
	}
	for (int y = start_x - 3; y < start_x + 66; y += 3)
	{
		green_field(3, 7, y, start_y);
		Sleep(15);
	}
	card_on_display(start_y, 87, array[0]);
}

// Рисует кнопку "DEAL"  заданных координатах и возвращает 1
int start_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Blue);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Blue, Blue);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Red, Blue);
	write_str(LEFT, TOP + 2, "  DEAL ");

	set_color(White, Black);
	return 1;
}

// Рисует кнопку в 5$ заданных координатах
int five_dollars_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Cyan);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Cyan, Cyan);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Cyan);
	write_str(LEFT + 2, TOP + 2, "5$");

	set_color(White, Black);
	return 5;
}

// Рисует кнопку в 10$ заданных координатах
int ten_dollars_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Cyan);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Cyan, Cyan);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Cyan);
	write_str(LEFT + 2, TOP + 2, "10$");

	set_color(White, Black);
	return 10;
}

// Рисует кнопку в 25$ заданных координатах
int twenty_five__dollars_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Cyan);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Cyan, Cyan);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Cyan);
	write_str(LEFT + 2, TOP + 2, "25$");

	set_color(White, Black);
	return 25;
}

// Рисует кнопку в 50$ заданных координатах
int fivty__dollars_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Cyan);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Cyan, Cyan);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Cyan);
	write_str(LEFT + 2, TOP + 2, "50$");

	set_color(White, Black);
	return 50;
}

// Рисует кнопку "MAX BET" в заданных координатах
int max_bet_buttom(int middle_y, int middle_x)
{
	set_color(Brown, Cyan);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Cyan, Cyan);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Cyan);
	write_str(LEFT, TOP + 2, "MAX BET");

	set_color(White, Black);
	return 100;
}

// Рисует кнопку "HIT" в заданных координатах
int hit_buttom(int middle_y, int middle_x)
{
	set_color(Brown, LightMagenta);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(LightMagenta, LightMagenta);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, White);
	write_str(LEFT, TOP + 2, "  HIT  ");

	return 100;
}

// Рисует кнопку "STAND" в заданных координатах
int stand_buttom(int middle_y, int middle_x)
{
	set_color(Brown, LightMagenta);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(LightMagenta, LightMagenta);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, White);
	write_str(LEFT, TOP + 2, " STAND ");

	return 100;
}

// Красная рамка вокруг кнопки
void red_frame_around_buttom(int middle_y, int middle_x)
{
	set_color(Red, Red);

	write_chars(middle_x - 5, middle_y - 3, ' ', 11);
	write_chars(middle_x - 5, middle_y + 1, ' ', 11);
	for (int y = middle_y - 3; y < middle_y + 2; y++)
	{
		write_char(middle_x - 6, y, ' ');
		write_char(middle_x + 6, y, ' ');
	}

	set_color(White, Black);
}

// Черная рамка вокруг кнопки
void black_frame_around_buttom(int middle_y, int middle_x)
{
	set_color(Black, Black);

	write_chars(middle_x - 5, middle_y - 3, ' ', 11);
	write_chars(middle_x - 5, middle_y + 1, ' ', 11);
	for (int y = middle_y - 3; y < middle_y + 2; y++)
	{
		write_char(middle_x - 6, y, ' ');
		write_char(middle_x + 6, y, ' ');
	}

	set_color(White, Black);
}

// Голубая рамка вокруг кнопки
void blue_frame_around_buttom(int middle_y, int middle_x)
{
	set_color(Blue, Blue);

	write_chars(middle_x - 5, middle_y - 3, ' ', 11);
	write_chars(middle_x - 5, middle_y + 1, ' ', 11);
	for (int y = middle_y - 3; y < middle_y + 2; y++)
	{
		write_char(middle_x - 6, y, ' ');
		write_char(middle_x + 6, y, ' ');
	}

	set_color(White, Black);
}

// Выводит "TOTAL BET" на экран
void total_bet_on_display(int bet, int middle_x, int middle_y)
{

	set_color(Magenta, Green);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 9);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 9);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 5, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 5, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 5, y, dbl_vertical_line);
	}
	set_color(Magenta, Green);
	write_str(middle_x - 4, middle_y - 1, "TOTAL BET");

	char last_num = 48;
	set_color(Red, Green);

	write_char(middle_x + 2, middle_y, '$');
	write_char(middle_x + 1, middle_y, last_num + bet % 10);
	write_char(middle_x, middle_y, last_num + bet / 10 % 10);
	write_char(middle_x - 1, middle_y, last_num + bet / 100);
}

// Выводит "BANK" на экран
void bank_on_display(int bet, int middle_x, int middle_y)
{
	set_color(Magenta, Green);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 9);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 9);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 5, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 5, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 5, y, dbl_vertical_line);
	}
	set_color(Magenta, Green);
	write_str(middle_x - 4, middle_y - 1, "  BANK   ");

	char last_num = 48;
	set_color(Red, Green);

	write_char(middle_x + 2, middle_y, '$');
	write_char(middle_x + 1, middle_y, last_num + bet % 10);
	write_char(middle_x, middle_y, last_num + bet / 10 % 10);
	write_char(middle_x - 1, middle_y, last_num + bet / 100);
	write_char(middle_x - 2, middle_y, last_num + bet / 1000);

}

// Выводит надпись насчет минимальной и максимальной ставки на экран
void min_max_bet_on_display(int middle_x, int middle_y)
{
	set_color(Magenta, LightBlue);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 13);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 13);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Magenta, LightBlue);
	write_str(middle_x - 4, middle_y - 1, "MIN BET: 5$  ");
	write_str(middle_x - 4, middle_y, "MAX BET: 100$");

}

// Принимает номер кнопки и возвращает количество долларов
int dollars_for_bet(int buttom_number)
{
	switch (buttom_number)
	{
	case 1:
		return 5;
		break;
	case 2:
		return 10;
		break;
	case 3:
		return 25;
		break;
	case 4:
		return 50;
		break;
	default:
		break;
	}
}

// Выводит предупреждающую надпись насчет максимальной ставки
void max_bet_warning(int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 13);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 13);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Black, Red);
	write_str(middle_x - 4, middle_y - 1, "   MAX BET   ");
	write_str(middle_x - 4, middle_y, "     100$    ");

	Sleep(750);
	black_field(18, 4, middle_x + 1, middle_y);

	//Страховка от случайных нажатий
	while (_kbhit())
		_getch();
}

// Выводит предупреждающую надпись что нужно вначале сделать ставку
void make_your_bet_warning(int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 13);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 13);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Black, Red);
	write_str(middle_x - 4, middle_y - 1, "   PLEASE    ");
	write_str(middle_x - 4, middle_y, "MAKE YOUR BET");

	Sleep(2000);
	black_field(18, 4, middle_x + 1, middle_y);

	//Страховка от случайных нажатий
	while (_kbhit())
		_getch();

}

// Выводит "YOU HAVE ONLY" на экран
void you_have_only_on_display(int bank_of_player, int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 13);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 13);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Black, Red);
	write_str(middle_x - 4, middle_y - 1, "  YOU HAVE   ");
	write_str(middle_x - 4, middle_y, "             ");

	char last_num = 48;
	set_color(Black, Red);

	write_char(middle_x + 3, middle_y, '$');
	write_char(middle_x + 2, middle_y, last_num + bank_of_player % 10);
	write_char(middle_x + 1, middle_y, last_num + bank_of_player / 10 % 10);
	write_char(middle_x, middle_y, last_num + bank_of_player / 100);

	Sleep(2000);
	black_field(18, 4, middle_x + 1, middle_y);

	//Страховка от случайных нажатий
	while (_kbhit())
		_getch();
}

// Функция принимает массив и возвращает произвольный порядковый номер значения != 0 (значению присваевает 0) 
int index_random_card(int arr[], int Size)
{
	while (true)
	{
		int z = rand() % 104 + 1;

		if (arr[z] == 0)
			continue;
		else
		{
			arr[z] = 0;
			return z;
		}
	}
}

// Проверяем, что количество карт в коллоде больше 30
bool enough_cards_in_deck(const int arr[], int Size)
{
	int sum = 0;

	for (int y = 0; y < Size; y++)
	{
		if (arr[y] > 0)
			sum++;
	}

	return (sum > 30);
}

// Считает сумму элементов массива
int sum_of_cards(const int arr[], int Size)
{
	int sum = 0;

	for (int y = 0; y < Size; y++)
		sum += arr[y];

	return sum;
}

// Выводим счет на экран
void score_on_display(int middle_x, int middle_y, int score)
{
	char last_num = 48;
	set_color(Red, Green);

	write_char(middle_x + 1, middle_y, last_num + score % 10);
	write_char(middle_x, middle_y, last_num + score / 10 % 10);
}

// Проверяем раздачу на наличие тузa и присваиваем ему 1 очко
bool ace_in_score(int arr[], int Size)
{
	bool z = false;
	for (int y = 0; y < Size; y++)
	{
		if (arr[y] == 11)
		{
			arr[y] = 1;
			z = true;
			break;
		}
	}
	return z;
}

// Надпись "YOU WON ..." 
void you_won_inscription(int middle_x, int middle_y, int winner_points)
{
	set_color(Red, Green);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 9);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 9);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 5, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 5, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 5, y, dbl_vertical_line);
	}
	set_color(Red, Green);
	write_str(middle_x - 4, middle_y - 1, " YOU WON ");

	char last_num = 48;
	set_color(Red, Green);

	write_char(middle_x + 2, middle_y, '$');
	write_char(middle_x + 1, middle_y, last_num + winner_points % 10);
	write_char(middle_x, middle_y, last_num + winner_points / 10 % 10);
	write_char(middle_x - 1, middle_y, last_num + winner_points / 100);

}

// Надпись "PUSH" означает равное количество очков
void push_inscription(int middle_x, int middle_y)
{
	set_color(Red, Green);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 10);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 10);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 6, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 6, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 6, y, dbl_vertical_line);
	}
	set_color(Red, Green);
	write_str(middle_x - 4, middle_y - 1, "   PUSH  ");

}

// Надпись "YOU LOSE ..." 
void you_lose_inscription(int middle_x, int middle_y)
{
	set_color(Red, Green);
	write_chars(middle_x - 4, middle_y - 2, dbl_line, 10);
	write_chars(middle_x - 4, middle_y + 1, dbl_line, 10);
	write_char(middle_x - 5, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 6, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 5, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 6, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 5, y, dbl_vertical_line);
		write_char(middle_x + 6, y, dbl_vertical_line);
	}
	set_color(Red, Green);
	write_str(middle_x - 4, middle_y - 1, " YOU LOSE");

}

// Зарисовывает поле с картами и счетом карт
void clear_green_field()
{
	green_field(30, 7, 52, 7);
	green_field(30, 7, 52, 16);
	green_field(6, 1, 47, 3);
	green_field(6, 1, 47, 12);
	green_field(3, 1, 53, 12);
}

// Надпись "GAME OVER"
void game_over(int middle_y, int middle_x)
{
	clear_screen();
	show_cursor(false);
	set_color(Red, Green);

	write_str(middle_y, middle_x + 0,  " XXX     X    X     X  XXXXX");
	write_str(middle_y, middle_x + 1,  "X   X   X X   XX   XX  X    ");
	write_str(middle_y, middle_x + 2,  "X      X   X  X X X X  X    ");
	write_str(middle_y, middle_x + 3,  "X  XX  XXXXX  X  X  X  XXXX ");
	write_str(middle_y, middle_x + 4,  "X   X  X   X  X     X  X    ");
	write_str(middle_y, middle_x + 5,  "X   X  X   X  X     X  X    ");
	write_str(middle_y, middle_x + 6,  " XXXX  X   X  X     X  XXXXX");
	write_str(middle_y, middle_x + 7,  "                            ");
	write_str(middle_y, middle_x + 8,  "                            ");
	write_str(middle_y, middle_x + 9,  "  XXX   X   X  XXXXX  XXXX  ");
	write_str(middle_y, middle_x + 10, " X   X  X   X  X      X   X ");
	write_str(middle_y, middle_x + 11, " X   X  X   X  X      X   X ");
	write_str(middle_y, middle_x + 12, " X   X  X   X  XXXX   XXXX  ");
	write_str(middle_y, middle_x + 13, " X   X  X   X  X      XX    ");
	write_str(middle_y, middle_x + 14, " X   X   X X   X      X X   ");
	write_str(middle_y, middle_x + 15, "  XXX     X    XXXXX  X  X  ");
	write_str(middle_y, middle_x + 16, "                            ");
	write_str(middle_y, middle_x + 17, "                            ");
}

// Надпись "BLACK JACK"
void black_jack(int middle_y, int middle_x)
{

	show_cursor(false);
	set_color(Brown, Black);

	write_str(middle_y, middle_x + 0, "XXX   X      XX    XX   X  X         X   XX    XX   X  X");
	write_str(middle_y, middle_x + 1, "X  X  X     X  X  X  X  X  X         X  X  X  X  X  X  X");
	write_str(middle_y, middle_x + 2, "X  X  X     X  X  X     X X          X  X  X  X     X X ");
	write_str(middle_y, middle_x + 3, "XXX   X     XXXX  X     XX           X  XXXX  X     XX  ");
	write_str(middle_y, middle_x + 4, "X  X  X     X  X  X     X X          X  X  X  X     X X ");
	write_str(middle_y, middle_x + 5, "X  X  X     X  X  X  X  X  X      X  X  X  X  X  X  X  X");
	write_str(middle_y, middle_x + 6, "XXX   XXXX  X  X   XX   X  X       XX   X  X   XX   X  X");
}

// Рисует кнопку "PLAY" 
void play_button(int middle_y, int middle_x)
{
	set_color(LightBlue, Green);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Green, Green);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Green);
	write_str(LEFT, TOP + 2, " PLAY ");
	set_color(White, Black);
}

// Рисует кнопку "RULES" 
void rules_button(int middle_y, int middle_x)
{
	set_color(LightBlue, Green);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Green, Green);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Green);
	write_str(LEFT, TOP + 2, " RULES ");

	set_color(White, Black);
}

// Рисует кнопку "ABOUT" 
void about_button(int middle_y, int middle_x)
{
	set_color(LightBlue, Green);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Green, Green);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Green);
	write_str(LEFT, TOP + 2, " ABOUT ");

	set_color(White, Black);
}

// Рисует кнопку "EXIT"
void exit_button(int middle_y, int middle_x)
{
	set_color(LightBlue, Green);
	write_char(LEFT - 2, TOP + 1, left_top);
	write_char(LEFT - 2, BUTTOM - 3, left_buttom);
	write_char(RIGHT + 1, TOP + 1, right_top);
	write_char(RIGHT + 1, BUTTOM - 3, right_buttom);
	write_chars(LEFT - 1, TOP + 1, horisontal_line, card_width + 1);
	write_chars(LEFT - 1, BUTTOM - 3, horisontal_line, card_width + 1);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
	{
		write_char(LEFT - 2, y, vertical_line);
		write_char(RIGHT + 1, y, vertical_line);
	}

	set_color(Green, Green);

	for (int y = TOP + 2; y < BUTTOM - 3; y++)
		for (int x = LEFT - 1; x < RIGHT + 1; x++)
			write_char(x, y, 32);

	set_color(Blue, Green);
	write_str(LEFT, TOP + 2, " EXIT ");
	set_color(White, Black);
}

// Раскидывает карты по всему экрану
void cards_arround(const int arr[], int Size)
{

	for (int y = 0; y < 150; y++)
	{
		card_on_display(rand() % 24 + 4, rand() % 112 + 4, arr[rand() % 104 + 1]);
		set_color(Red, Blue);
		write_str(get_console_size_x() / 2 - 6, get_console_size_y() / 2, "LOADING...");
		Sleep(1);
	}
}

// Меню ставок
void bets_menu()
{
	start_buttom(29, 30);
	five_dollars_buttom(29, 42);
	ten_dollars_buttom(29, 54);
	twenty_five__dollars_buttom(29, 66);
	fivty__dollars_buttom(29, 78);
	max_bet_buttom(29, 90);
	black_frame_around_buttom(29, 42);
	red_frame_around_buttom(29, 30);
	total_bet_on_display(0, 29, 14);
}

// Игровое меню
void game_menu()
{
	black_jack(35, 1);
	color_field(18, 30, 109, 15);
	color_field(18, 30, 10, 15);
	play_button(12, 60);
	rules_button(17, 60);
	about_button(22, 60);
	exit_button(27, 60);
	red_frame_around_buttom(12, 60);
}

// Правила
void rules()
{
	write_str(7, 2, "   Players are allowed to draw additional cards to improve their hands. A hand with an ace valued as 11 is");
	write_str(7, 3, "called \"soft\", meaning that the hand will be guaranteed to not score more than 21 by taking an additional");
	write_str(7, 4, "The value of cards two through ten is their pip value (2 through 10). Face cards (Jack, Queen, and King)");
	write_str(7, 5, "   Players are each dealt two cards, individually facing up or down depending on the casino and the table.");
	write_str(7, 6, "are all worth ten. Aces can be worth one or eleven. A hand's value is the sum of the card values. ");
	write_str(7, 7, "card. The value of the ace will become one to prevent the hand from exceeding 21. ");
	write_str(7, 8, "   Once all the players have completed their hands, it is the dealer's turn. The dealer hand will not be ");
	write_str(7, 9, "completed if all players have either exceeded the total of 21 or received blackjacks. The dealer then reveals ");
	write_str(7, 10, "the hidden card and must draw cards, one by one, until the cards total up to 17 points. At 17 points or higher ");
	write_str(7, 11, "the dealer must stop. (At most tables the dealer also hits on a \"soft\" 17, i.e. a hand containing an ace and ");
	write_str(7, 12, "one or more other cards totaling six.) Players bet on the basis that they will individually have better hands ");
	write_str(7, 13, "than the dealer. The better hand is the hand where the sum of the card values is closer to 21 without ");
	write_str(7, 14, "exceeding 21. The detailed outcome of the hand follows:");
	write_str(7, 15, "If the player is dealt an Ace and a ten-value card (called a \"blackjack\" or \"natural\"), and the dealer does ");
	write_str(7, 16, "not, the player wins and usually receives a bonus.");
	write_str(7, 18, "  If the player exceeds a sum of 21 (\"busts\"), the player loses, even if the dealer also exceeds 21.");
	write_str(7, 19, "  If the dealer exceeds 21 (\"busts\") and the player does not, the player wins.");
	write_str(7, 20, "  If the player attains a final sum higher than the dealer and does not bust, the player wins.");
	write_str(7, 21, "  If both dealer and player receive a blackjack or any other hands with the same sum, this will be called a ");
	write_str(7, 22, "\"push\" and no one wins.");
}

// Надпись "EXIT. ARE YOU SHURE? Y/N"
void exit_are_you_sure(int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 10, middle_y - 2, dbl_line, 19);
	write_chars(middle_x - 10, middle_y + 1, dbl_line, 19);
	write_char(middle_x - 11, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 11, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 11, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Red, Black);
	write_str(middle_x - 10, middle_y - 1, "        EXIT       ");
	write_str(middle_x - 10, middle_y, " ARE YOU SURE? Y/N");
}

// Надпись "Public domain"
void public_domain()
{
	write_str(45, 10, "THIS GAME IS A PUBLIC DOMAIN...");
	write_str(50, 17, "Marushchak Sergiy, 2021");
}

// Надпись "PRESS ESC TO EXIT"
void press_esc_to_exit(int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 6, middle_y - 2, dbl_line, 15);
	write_chars(middle_x - 6, middle_y + 1, dbl_line, 15);
	write_char(middle_x - 7, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 7, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 7, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Red, Black);
	write_str(middle_x - 6, middle_y - 1, "   PRESS \"ESC\" ");
	write_str(middle_x - 6, middle_y, "    TO EXIT   ");
}

// Надпись об навигационных кнопках
void use_buttons(int middle_x, int middle_y)
{
	set_color(Black, Red);
	write_chars(middle_x - 10, middle_y - 2, dbl_line, 19);
	write_chars(middle_x - 10, middle_y + 1, dbl_line, 19);
	write_char(middle_x - 11, middle_y - 2, dbl_left_corner_top);
	write_char(middle_x + 9, middle_y - 2, dbl_right_corner_top);
	write_char(middle_x - 11, middle_y + 1, dbl_left_corner_buttom);
	write_char(middle_x + 9, middle_y + 1, dbl_right_corner_buttom);

	for (int y = middle_y - 1; y < middle_y + 1; y++)
	{
		write_char(middle_x - 11, y, dbl_vertical_line);
		write_char(middle_x + 9, y, dbl_vertical_line);
	}
	set_color(Red, Black);
	write_str(middle_x - 10, middle_y - 1, "USE \"ENTER\", \"LEFT\"");
	write_str(middle_x - 10, middle_y, "AND \"RIGHT\" BUTTONS");
}

