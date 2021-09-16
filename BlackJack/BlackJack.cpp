#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "Graphics.h"
#include "ConsoleLib.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	const int cards_in_deck = 105;

	// Паузы между действиями по времени
	const int general_timing = 500;

	// Массив координат по горизонтали нижних кнопок
	int array_button_coordinates[6]{ 30, 42, 54, 66, 78, 90 };

	// Массив координат по вертикали кнопок меню
	int menu_button_coordinates[4]{ 12, 17, 22, 27 };

	// Колода карт в игре
	int in_game_deck_of_cards[cards_in_deck];

	// Создаем массив на 108 игральных карт плюс рубашка
	const int deck_of_cards[cards_in_deck]{ 100, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109,
										   109, 110, 110, 111, 111, 112, 112, 113, 113, 114, 114, 202, 202, 203, 203, 204,
										   204, 205, 205, 206, 206, 207, 207, 208, 208, 209, 209, 210, 210, 211, 211, 212,
										   212, 213, 213, 214, 214, 302, 302, 303, 303, 304, 304, 305, 305, 306, 306, 307,
										   307, 308, 308, 309, 309, 310, 310, 311, 311, 312, 312, 313, 313, 314, 314, 402,
										   402, 403, 403, 404, 404, 405, 405, 406, 406, 407, 407, 408, 408, 409, 409, 410,
										   410, 411, 411, 412, 412, 413, 413, 414, 414 };

	const int left_arrow = 75;
	const int right_arrow = 77;
	const int up_arrow = 72;
	const int down_arrow = 80;
	const int spacebar = 13;
	const int esc = 27;
	show_cursor(false);
	set_console_size(30, 150);

	// Общие очки игрока
	int bank_of_player = 200;

	bool main_exit = false;



	// Начало игры
	while (!main_exit)
	{
		// Игровое меню
		game_menu();

		int key_bet = 0;
		int button_number = 0;

		//Перемещение по меню
		while (true)
		{
			bool exit = false;

			key_bet = _getch();
			//key_bet = _getch();

			if (button_number < 3 && key_bet == down_arrow)
			{
				black_frame_around_buttom(menu_button_coordinates[button_number], 60);
				button_number++;
				red_frame_around_buttom(menu_button_coordinates[button_number], 60);
			}
			else if (button_number > 0 && key_bet == up_arrow)
			{
				black_frame_around_buttom(menu_button_coordinates[button_number], 60);
				button_number--;
				red_frame_around_buttom(menu_button_coordinates[button_number], 60);
			}

			// Кнопка выхода из программы
			else if (button_number == 3 && key_bet == spacebar)
			{
				exit_are_you_sure(61, 18);

				while (true)
				{
					key_bet = _getch();

					if (toupper(key_bet) == 'N')
					{
						clear_screen();

						break;
					}
					else if (toupper(key_bet) == 'Y')
					{
						clear_screen();
						main_exit = true;
						break;
					}
				}
				break;
			}
			// Начало цикла PLAY
			else if (button_number == 0 && key_bet == spacebar)
			{
				while (!exit)
				{
					// Раскидываем карты по всему экрану для эффективного начала
					green_field(get_console_size_x(), get_console_size_y(), get_console_size_x() / 2,
						get_console_size_y() / 2);
					cards_arround(deck_of_cards, cards_in_deck);
					black_field(get_console_size_x(), get_console_size_y(), get_console_size_x() / 2,
						get_console_size_y() / 2);

					//Страховка от случайных нажатий
					while (_kbhit())
						_getch();

					clear_screen();
					// Рисуем зеленое игровое поле 
					green_field(80, 20, 60, 10);
					set_color(Blue, Green);
					write_str(56, 2, "DEALER");
					write_str(56, 12, "PLAYER");

					// Рисуем цветные поля по бокам стола (типа красивый ковер)
					color_field(18, 30, 109, 15);
					color_field(18, 30, 10, 15);

					// Коричневая рамка вокруг стола
					brown_table_frame(60, 10);

					// Кнопка общей ставки
					total_bet_on_display(0, 29, 14);

					// Банк на экран
					bank_on_display(bank_of_player, 29, 18);

					// Кнопка о минимальной и максимальной ставке
					min_max_bet_on_display(85, 18);

					// Табличка выхода на экран
					press_esc_to_exit(27, 23);

					//Табличка про кнопка на экран
					use_buttons(90, 23);

					// Игровой цикл
					while (bank_of_player != 0 || !exit)
					{
						// Шаг игрока равен количеству карт игрока, начиная со второй 
						int player_step = 1;

						// Шаг дилера равен количеству карт дилера, начиная со второй 
						int dealer_step = 1;

						// Выводим меню ставок
						bets_menu();

						// Обнуляем кнопку после меню
						button_number = 0;

						key_bet = 0;
						int total_bet = 0;

						// Счетчик нажатия кнопки максимальная ставка (защита от многократного нажатия)
						int hits_of_max_bet = 0;

						// Делаем ставки
						while (!exit)
						{
							key_bet = _getch();

							// Переходим к меню ставок
							if (button_number < 5 && key_bet == right_arrow)
							{
								black_frame_around_buttom(29, array_button_coordinates[button_number]);
								button_number++;
								red_frame_around_buttom(29, array_button_coordinates[button_number]);
							}
							else if (button_number > 0 && key_bet == left_arrow)
							{
								black_frame_around_buttom(29, array_button_coordinates[button_number]);
								button_number--;
								red_frame_around_buttom(29, array_button_coordinates[button_number]);
							}
							else if (key_bet == spacebar && button_number > 0 && button_number < 5)
							{
								total_bet += dollars_for_bet(button_number);
								bank_of_player -= dollars_for_bet(button_number);
								bank_on_display(bank_of_player, 29, 18);

								// Выводим предупреждение насчет преувеличения максимальной ставки
								if (total_bet > 100)
								{
									blue_frame_around_buttom(29, array_button_coordinates[button_number]);
									bank_of_player += dollars_for_bet(button_number);
									bank_on_display(bank_of_player, 29, 18);
									max_bet_warning(56, 23);
									red_frame_around_buttom(29, array_button_coordinates[button_number]);
									total_bet -= dollars_for_bet(button_number);
									continue;
								}
								else if (bank_of_player < 0)
								{
									bank_of_player += dollars_for_bet(button_number);
									bank_on_display(bank_of_player, 29, 18);
									you_have_only_on_display(bank_of_player, 56, 23);

									continue;
								}
								else
								{
									blue_frame_around_buttom(29, array_button_coordinates[button_number]);
									Sleep(general_timing);
									total_bet_on_display(total_bet, 29, 14);
									red_frame_around_buttom(29, array_button_coordinates[button_number]);
								}
							}

							// Предупреждение, если игрок пытается начать игру без ставки 
							// или недостаточно денег в банке для желаемой ставки
							else if (key_bet == spacebar && button_number == 0)
							{
								if (total_bet == 0)
								{
									make_your_bet_warning(56, 23);
									continue;
								}
								else
									break;
							}

							// Выбор кнопки максимальной ставки
							else if (key_bet == spacebar && button_number == 5)
							{
								if (bank_of_player == 0 || hits_of_max_bet == 1)
									continue;


								if (bank_of_player < 100)
								{
									total_bet += bank_of_player;
									total_bet_on_display(total_bet, 29, 14);
									bank_of_player = 0;
								}
								else
								{
									bank_of_player = bank_of_player - 100 + total_bet;
									total_bet = 100;
									total_bet_on_display(total_bet, 29, 14);
								}
								bank_on_display(bank_of_player, 29, 18);

								// Обозначаем, что кнопка максимальной ставки нажата
								hits_of_max_bet++;

								continue;
							}
							// В случае нажатия ESC предоставляем выбор (Y/N)
							else if (key_bet == esc)
							{
								exit_are_you_sure(60, 23);

								while (true)
								{
									key_bet = _getch();

									if (toupper(key_bet) == 'N')
									{
										black_field(27, 4, 56, 23);
										break;
									}
									else if (toupper(key_bet) == 'Y')
									{
										black_field(27, 4, 56, 23);
										exit = true;
										break;
									}
								}
							}
						}
						if (exit)
							break;

						key_bet = 0;
						button_number = 1;

						// Создаем игровые кнопки
						black_field(74, 5, 60, 28);
						hit_buttom(29, 42);
						stand_buttom(29, 78);
						red_frame_around_buttom(29, 42);

						// Заводим массивы для счета очков игрока и крупье. 
						const int size_of_score_array = 7;
						int dealer_score[size_of_score_array]{ 0 };
						int player_score[size_of_score_array]{ 0 };

						// Проверяем, что количество карт в коллоде больше 30
						if (!enough_cards_in_deck(in_game_deck_of_cards, cards_in_deck))
						{
							// Если меньше 30 - тасуем и заполняем игровую колоду
							shuffle_cards(deck_of_cards, cards_in_deck, 30, 7);

							for (int y = 0; y < cards_in_deck; y++)
								in_game_deck_of_cards[y] = deck_of_cards[y];
						}

						// Сдаем 2 карты игроку
						player_score[0] = card_on_display(16, 50, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
						Sleep(general_timing);
						player_score[1] += card_on_display(16, 53, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);

						// выводим счет игрока на экран
						score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));

						Sleep(general_timing);

						// Сдаем 1 карту дилеру
						dealer_score[0] = card_on_display(7, 50, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
						Sleep(general_timing);

						// Еще одну рубашкой вверх
						card_on_display(7, 53, deck_of_cards[0]);

						// Страхуемся от нажатия кнопок во время раздачи
						while (_kbhit())
							_getch();

						// выводим счет дилера на экран
						score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));

						// Переходим к раздаче по выбору игрока
						while (bank_of_player >= 0)
						{
							exit = false;
							key_bet = 0;

							while (_kbhit())
								key_bet = _getch();

							// Проверяем карты игрока на наличие туза при переборе и меняем его значение с 11 на 1, если перебор
							if (sum_of_cards(player_score, size_of_score_array) > 21 && ace_in_score(player_score, size_of_score_array))
							{
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								Sleep(general_timing * 5);

								continue;
							}

							// Если общий перебор - выводим надпись о проигрыше и заканчиваем раздачу
							else if (sum_of_cards(player_score, size_of_score_array) > 21)
							{
								clear_green_field();
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								you_lose_inscription(57, 16);
								Sleep(general_timing * 5);
								clear_green_field();

								break;
							}

							// Если сумма очков игрока равна 21, заканчиваем раздачу и награждаем игрока
							if (sum_of_cards(player_score, size_of_score_array) == 21)
							{
								//Сдаем контрольную карту диллеру
								Sleep(750);
								dealer_score[1] = card_on_display(7, 53, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);

								// Выводим счет диллера на экран
								score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));

								// Складываем полученные очки и выводим общий счет на экран
								bank_of_player += total_bet * 2;
								bank_on_display(bank_of_player, 29, 18);

								Sleep(general_timing * 3);

								// Зарисовываем поле
								clear_green_field();

								// Надпись о количестве выигранных денег
								you_won_inscription(59, 16, total_bet * 2);
								Sleep(general_timing * 3);
								green_field(30, 7, 50, 16);

								// Заканчиваем раздачу
								break;
							}

							// Перемещение по меню "HIT", "STAY"
							if (button_number == 1 && key_bet == right_arrow)
							{
								black_frame_around_buttom(29, array_button_coordinates[button_number]);
								button_number += 3;
								red_frame_around_buttom(29, array_button_coordinates[button_number]);
							}
							else if (button_number == 4 && key_bet == left_arrow)
							{
								black_frame_around_buttom(29, array_button_coordinates[button_number]);
								button_number -= 3;
								red_frame_around_buttom(29, array_button_coordinates[button_number]);
							}
							// В случае нажатия ESC предоставляем выбор (Y/N)
							else if (key_bet == esc)
							{
								exit_are_you_sure(56, 23);

								while (true)
								{
									key_bet = _getch();

									if (toupper(key_bet) == 'N')
									{
										black_field(27, 4, 56, 23);
										break;
									}
									else if (toupper(key_bet) == 'Y')
									{
										black_field(27, 4, 56, 23);
										exit = true;
										break;
									}
								}
							}


							// Если нажата кнопка "HIT" раздаем дальше карты игроку
							if (key_bet == spacebar && button_number == 1)
							{
								blue_frame_around_buttom(29, array_button_coordinates[button_number]);
								Sleep(general_timing);
								red_frame_around_buttom(29, array_button_coordinates[button_number]);

								player_score[player_step + 1] = card_on_display(16, 53 + player_step * 3,
									deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
								Sleep(general_timing);

								player_step++;

								// выводим счет игрока на экран
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								Sleep(general_timing);
								continue;
							}

							// Если нажата кнопка "STAY" - заканчиваем ход игрока и начинаем раздачу дилера, пока он не достигнет минимум 17 
							else if (key_bet == spacebar && button_number == 4)
							{
								blue_frame_around_buttom(29, array_button_coordinates[button_number]);
								Sleep(general_timing);
								red_frame_around_buttom(29, array_button_coordinates[button_number]);

								do
								{
									dealer_score[dealer_step + 1] = card_on_display(7, 50 + dealer_step * 3,
										deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);

									score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));
									Sleep(general_timing);

									dealer_step++;

									// Проверяем карты дилера на наличие туза при переборе и переводим его в 1, если перебор
									if (sum_of_cards(dealer_score, size_of_score_array) > 21 && ace_in_score(dealer_score, size_of_score_array))
									{
										score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));
										Sleep(general_timing * 5);

										continue;
									}

								} while (sum_of_cards(dealer_score, size_of_score_array) < 17);

								black_frame_around_buttom(29, array_button_coordinates[button_number]);

								// Если у дилера меньше очков, чем у игрока, то присваеваем победу игроку
								if (sum_of_cards(dealer_score, size_of_score_array) < sum_of_cards(player_score, size_of_score_array) ||
									sum_of_cards(dealer_score, size_of_score_array) > 21)
								{
									bank_of_player += total_bet * 2;
									bank_on_display(bank_of_player, 29, 18);
									Sleep(general_timing * 3);
									clear_green_field();
									you_won_inscription(57, 16, total_bet * 2);
									Sleep(general_timing * 3);
									clear_green_field();
									break;
								}
								// Присваеваем победу дилеру, если у него больше очков
								else if (sum_of_cards(dealer_score, size_of_score_array) > sum_of_cards(player_score, size_of_score_array))
								{
									//bank_of_player -= total_bet;
									//bank_on_display(bank_of_player, 29, 18);
									Sleep(general_timing * 3);
									clear_green_field();
									you_lose_inscription(57, 16);
									Sleep(general_timing * 3);
									clear_green_field();

									break;
								}
								// При ничье каждый остается при своих
								else if (sum_of_cards(dealer_score, size_of_score_array) == sum_of_cards(player_score, size_of_score_array))
								{
									bank_of_player += total_bet;
									bank_on_display(bank_of_player, 29, 18);
									clear_green_field();
									push_inscription(57, 16);
									Sleep(general_timing * 3);
									clear_green_field();

									break;
								}
							}
							// В случае нажатия ESC предоставляем выбор (Y/N)
							else if (key_bet == esc)
							{
								exit_are_you_sure(56, 23);

								while (true)
								{
									key_bet = _getch();

									if (toupper(key_bet) == 'N')
									{
										black_field(22, 4, 56, 23);
										break;
									}
									else if (toupper(key_bet) == 'Y')
									{
										black_field(22, 4, 56, 23);
										exit = true;
										break;
									}
								}
							}

							if (exit)
								break;

						}
					}
					game_over(45, 5);
					Sleep(general_timing * 3);
					clear_screen();
					black_field(100, 30, 60, 15);
					game_menu();
					red_frame_around_buttom(menu_button_coordinates[0], 60);
				}
			} // Окончание цикла PLAY

			// Выводим правила на экран
			else if (button_number == 1 && key_bet == spacebar)
			{
				clear_screen();
				rules();
				control_button();

				while (true)
				{
					key_bet = _getch();

					if (key_bet == esc)
					{
						clear_screen();
						break;
					}
				}
				game_menu();
				black_frame_around_buttom(menu_button_coordinates[0], 60);
				red_frame_around_buttom(menu_button_coordinates[1], 60);

				continue;
			}
			// Выводим правила на экран
			else if (button_number == 2 && key_bet == spacebar)
			{
			clear_screen();
			public_domain();
			control_button();


			while (true)
			{
				key_bet = _getch();

				if (key_bet == esc)
				{
					clear_screen();
					break;
				}
			}
			game_menu();
			black_frame_around_buttom(menu_button_coordinates[0], 60);
			red_frame_around_buttom(menu_button_coordinates[2], 60);

			continue;
			}

		}
	}
}


