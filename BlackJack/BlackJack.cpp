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

	// ����� ����� ���������� �� �������
	const int general_timing = 500;

	// ������ ��������� �� ����������� ������ ������
	int array_button_coordinates[6]{ 30, 42, 54, 66, 78, 90 };

	// ������ ��������� �� ��������� ������ ����
	int menu_button_coordinates[4]{ 12, 17, 22, 27 };

	// ������ ���� � ����
	int in_game_deck_of_cards[cards_in_deck];

	// ������� ������ �� 108 ��������� ���� ���� �������
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

	// ����� ���� ������
	int bank_of_player = 200;

	bool main_exit = false;



	// ������ ����
	while (!main_exit)
	{
		// ������� ����
		game_menu();

		int key_bet = 0;
		int button_number = 0;

		//����������� �� ����
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

			// ������ ������ �� ���������
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
			// ������ ����� PLAY
			else if (button_number == 0 && key_bet == spacebar)
			{
				while (!exit)
				{
					// ����������� ����� �� ����� ������ ��� ������������ ������
					green_field(get_console_size_x(), get_console_size_y(), get_console_size_x() / 2,
						get_console_size_y() / 2);
					cards_arround(deck_of_cards, cards_in_deck);
					black_field(get_console_size_x(), get_console_size_y(), get_console_size_x() / 2,
						get_console_size_y() / 2);

					//��������� �� ��������� �������
					while (_kbhit())
						_getch();

					clear_screen();
					// ������ ������� ������� ���� 
					green_field(80, 20, 60, 10);
					set_color(Blue, Green);
					write_str(56, 2, "DEALER");
					write_str(56, 12, "PLAYER");

					// ������ ������� ���� �� ����� ����� (���� �������� �����)
					color_field(18, 30, 109, 15);
					color_field(18, 30, 10, 15);

					// ���������� ����� ������ �����
					brown_table_frame(60, 10);

					// ������ ����� ������
					total_bet_on_display(0, 29, 14);

					// ���� �� �����
					bank_on_display(bank_of_player, 29, 18);

					// ������ � ����������� � ������������ ������
					min_max_bet_on_display(85, 18);

					// �������� ������ �� �����
					press_esc_to_exit(27, 23);

					//�������� ��� ������ �� �����
					use_buttons(90, 23);

					// ������� ����
					while (bank_of_player != 0 || !exit)
					{
						// ��� ������ ����� ���������� ���� ������, ������� �� ������ 
						int player_step = 1;

						// ��� ������ ����� ���������� ���� ������, ������� �� ������ 
						int dealer_step = 1;

						// ������� ���� ������
						bets_menu();

						// �������� ������ ����� ����
						button_number = 0;

						key_bet = 0;
						int total_bet = 0;

						// ������� ������� ������ ������������ ������ (������ �� ������������� �������)
						int hits_of_max_bet = 0;

						// ������ ������
						while (!exit)
						{
							key_bet = _getch();

							// ��������� � ���� ������
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

								// ������� �������������� ������ ������������� ������������ ������
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

							// ��������������, ���� ����� �������� ������ ���� ��� ������ 
							// ��� ������������ ����� � ����� ��� �������� ������
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

							// ����� ������ ������������ ������
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

								// ����������, ��� ������ ������������ ������ ������
								hits_of_max_bet++;

								continue;
							}
							// � ������ ������� ESC ������������� ����� (Y/N)
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

						// ������� ������� ������
						black_field(74, 5, 60, 28);
						hit_buttom(29, 42);
						stand_buttom(29, 78);
						red_frame_around_buttom(29, 42);

						// ������� ������� ��� ����� ����� ������ � ������. 
						const int size_of_score_array = 7;
						int dealer_score[size_of_score_array]{ 0 };
						int player_score[size_of_score_array]{ 0 };

						// ���������, ��� ���������� ���� � ������� ������ 30
						if (!enough_cards_in_deck(in_game_deck_of_cards, cards_in_deck))
						{
							// ���� ������ 30 - ������ � ��������� ������� ������
							shuffle_cards(deck_of_cards, cards_in_deck, 30, 7);

							for (int y = 0; y < cards_in_deck; y++)
								in_game_deck_of_cards[y] = deck_of_cards[y];
						}

						// ����� 2 ����� ������
						player_score[0] = card_on_display(16, 50, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
						Sleep(general_timing);
						player_score[1] += card_on_display(16, 53, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);

						// ������� ���� ������ �� �����
						score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));

						Sleep(general_timing);

						// ����� 1 ����� ������
						dealer_score[0] = card_on_display(7, 50, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
						Sleep(general_timing);

						// ��� ���� �������� �����
						card_on_display(7, 53, deck_of_cards[0]);

						// ���������� �� ������� ������ �� ����� �������
						while (_kbhit())
							_getch();

						// ������� ���� ������ �� �����
						score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));

						// ��������� � ������� �� ������ ������
						while (bank_of_player >= 0)
						{
							exit = false;
							key_bet = 0;

							while (_kbhit())
								key_bet = _getch();

							// ��������� ����� ������ �� ������� ���� ��� �������� � ������ ��� �������� � 11 �� 1, ���� �������
							if (sum_of_cards(player_score, size_of_score_array) > 21 && ace_in_score(player_score, size_of_score_array))
							{
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								Sleep(general_timing * 5);

								continue;
							}

							// ���� ����� ������� - ������� ������� � ��������� � ����������� �������
							else if (sum_of_cards(player_score, size_of_score_array) > 21)
							{
								clear_green_field();
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								you_lose_inscription(57, 16);
								Sleep(general_timing * 5);
								clear_green_field();

								break;
							}

							// ���� ����� ����� ������ ����� 21, ����������� ������� � ���������� ������
							if (sum_of_cards(player_score, size_of_score_array) == 21)
							{
								//����� ����������� ����� �������
								Sleep(750);
								dealer_score[1] = card_on_display(7, 53, deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);

								// ������� ���� ������� �� �����
								score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));

								// ���������� ���������� ���� � ������� ����� ���� �� �����
								bank_of_player += total_bet * 2;
								bank_on_display(bank_of_player, 29, 18);

								Sleep(general_timing * 3);

								// ������������ ����
								clear_green_field();

								// ������� � ���������� ���������� �����
								you_won_inscription(59, 16, total_bet * 2);
								Sleep(general_timing * 3);
								green_field(30, 7, 50, 16);

								// ����������� �������
								break;
							}

							// ����������� �� ���� "HIT", "STAY"
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
							// � ������ ������� ESC ������������� ����� (Y/N)
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


							// ���� ������ ������ "HIT" ������� ������ ����� ������
							if (key_bet == spacebar && button_number == 1)
							{
								blue_frame_around_buttom(29, array_button_coordinates[button_number]);
								Sleep(general_timing);
								red_frame_around_buttom(29, array_button_coordinates[button_number]);

								player_score[player_step + 1] = card_on_display(16, 53 + player_step * 3,
									deck_of_cards[index_random_card(in_game_deck_of_cards, cards_in_deck)]);
								Sleep(general_timing);

								player_step++;

								// ������� ���� ������ �� �����
								score_on_display(47, 12, sum_of_cards(player_score, size_of_score_array));
								Sleep(general_timing);
								continue;
							}

							// ���� ������ ������ "STAY" - ����������� ��� ������ � �������� ������� ������, ���� �� �� ��������� ������� 17 
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

									// ��������� ����� ������ �� ������� ���� ��� �������� � ��������� ��� � 1, ���� �������
									if (sum_of_cards(dealer_score, size_of_score_array) > 21 && ace_in_score(dealer_score, size_of_score_array))
									{
										score_on_display(47, 3, sum_of_cards(dealer_score, size_of_score_array));
										Sleep(general_timing * 5);

										continue;
									}

								} while (sum_of_cards(dealer_score, size_of_score_array) < 17);

								black_frame_around_buttom(29, array_button_coordinates[button_number]);

								// ���� � ������ ������ �����, ��� � ������, �� ����������� ������ ������
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
								// ����������� ������ ������, ���� � ���� ������ �����
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
								// ��� ����� ������ �������� ��� �����
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
							// � ������ ������� ESC ������������� ����� (Y/N)
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
			} // ��������� ����� PLAY

			// ������� ������� �� �����
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
			// ������� ������� �� �����
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


