#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__


// ������ ����� �����
void card_frame(int middle_x, int middle_y);

// ������ ������ ���� ������������ �������
void black_field(int length, int width, int middle_x, int middle_y);

// ������ ������������ ���� ��� ������� ������� �� �����
void color_field(int length, int width, int middle_x, int middle_y);

// ������ ���������� ����� ������ �����
void brown_table_frame(int middle_x, int middle_y);

// ������ ������� ���� ������������ �������
void green_field(int length, int width, int middle_x, int middle_y);

// ������� � ������� ���������
void control_button();

// ������ ����� � ���������� ���������� �����
int card_on_display(int middle_x, int middle_y, int card_num);

// ������ �����
void shuffle_cards(const int array[], int Size, int start_x, int start_y);

// ������ ������ "DEAL" �������� �����������
int start_buttom(int middle_y, int middle_x);

// ������ ������ � 5$ �������� �����������
int five_dollars_buttom(int middle_y, int middle_x);

// ������ ������ � 10$ �������� �����������
int ten_dollars_buttom(int middle_y, int middle_x);

// ������ ������ � 25$ �������� �����������
int twenty_five__dollars_buttom(int middle_y, int middle_x);

// ������ ������ � 50$ �������� �����������
int fivty__dollars_buttom(int middle_y, int middle_x);

// ������ ������ "MAX BET" � �������� �����������
int max_bet_buttom(int middle_y, int middle_x);

// ������ ������ "HIT" � �������� �����������
int hit_buttom(int middle_y, int middle_x);

// ������ ������ "STAND" � �������� �����������
int stand_buttom(int middle_y, int middle_x);

// ������� ����� ������ ������
void red_frame_around_buttom(int middle_y, int middle_x);

// ������ ����� ������ ������
void black_frame_around_buttom(int middle_y, int middle_x);

// ������� ����� ������ ������
void blue_frame_around_buttom(int middle_y, int middle_x);

// ������� "TOTAL BET" �� �����
void total_bet_on_display(int bet, int middle_x, int middle_y);

// ������� "BANK" �� �����
void bank_on_display(int bet, int middle_x, int middle_y);

// ������� ������� ������ ����������� � ������������ ������ �� �����
void min_max_bet_on_display(int middle_x, int middle_y);

// ��������� ����� ������ � ���������� ���������� ��������
int dollars_for_bet(int buttom_number);

// ������� ��������������� ������� ������ ������������ ������
void max_bet_warning(int middle_x, int middle_y);

// ������� ��������������� ������� ��� ����� ������� ������� ������
void make_your_bet_warning(int middle_x, int middle_y);

// ������� "YOU HAVE ONLY" �� �����
void you_have_only_on_display(int bet, int middle_x, int middle_y);

// ������� ��������� ������ � ���������� ������������ ���������� ����� �������� != 0 (�������� ����������� 0) 
int index_random_card(int arr[], int Size);

// ���������, ��� ���������� ���� � ������� ������ 30
bool enough_cards_in_deck(const int arr[], int Size);

// ������� ����� ��������� �������
int sum_of_cards(const int arr[], int Size);

// ������� ���� �� �����
void score_on_display(int middle_x, int middle_y, int score);

// ��������� ������� �� ������� ���a � � ����������� ��� 1 ����
bool ace_in_score(int arr[], int Size);

// ������� "YOU WON ..." 
void you_won_inscription(int middle_x, int middle_y, int winner_points);

// ������� "YOU LOSE ..." 
void you_lose_inscription(int middle_x, int middle_y);

// ������������ ���� � ������� � ������ ����
void clear_green_field();

// ������� "PUSH" �������� ������ ���������� �����
void push_inscription(int middle_x, int middle_y);

// ������� "GAME OVER"
void game_over(int middle_y, int middle_x);

// ������� "BLACK JACK"
void black_jack(int middle_y, int middle_x);

// ������ ������ "PLAY" 
void play_button(int middle_y, int middle_x);

// ������ ������ "RULES" 
void rules_button(int middle_y, int middle_x);

// ������ ������ "ABOUT" 
void about_button(int middle_y, int middle_x);

// ������ ������ "EXIT"
void exit_button(int middle_y, int middle_x);

// ����������� ����� �� ����� ������
void cards_arround(const int arr[], int Size);

// ���� ������
void bets_menu();

// ������� ����
void game_menu();

// �������
void rules();

// ������� "EXIT. ARE YOU SHURE? Y/N"
void exit_are_you_sure(int middle_x, int middle_y);

// ������� "Public domain"
void public_domain();

// ������� "PRESS ESC TO EXIT"
void press_esc_to_exit(int middle_x, int middle_y);

/// ������� �� ������������� �������
void use_buttons(int middle_x, int middle_y);


#endif
