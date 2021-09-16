#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__


// рисует рамку карты
void card_frame(int middle_x, int middle_y);

// Рисует черное поле необходимого размера
void black_field(int length, int width, int middle_x, int middle_y);

// Рисуем разноцветное поле для боковых вставок на экран
void color_field(int length, int width, int middle_x, int middle_y);

// Рисуем коричневую рамку вокруг стола
void brown_table_frame(int middle_x, int middle_y);

// Рисует зеленое поле необходимого размера
void green_field(int length, int width, int middle_x, int middle_y);

// Надпись о кнопках навигации
void control_button();

// Рисует карту и возвращает количество очков
int card_on_display(int middle_x, int middle_y, int card_num);

// Тасует карты
void shuffle_cards(const int array[], int Size, int start_x, int start_y);

// Рисует кнопку "DEAL" заданных координатах
int start_buttom(int middle_y, int middle_x);

// Рисует кнопку в 5$ заданных координатах
int five_dollars_buttom(int middle_y, int middle_x);

// Рисует кнопку в 10$ заданных координатах
int ten_dollars_buttom(int middle_y, int middle_x);

// Рисует кнопку в 25$ заданных координатах
int twenty_five__dollars_buttom(int middle_y, int middle_x);

// Рисует кнопку в 50$ заданных координатах
int fivty__dollars_buttom(int middle_y, int middle_x);

// Рисует кнопку "MAX BET" в заданных координатах
int max_bet_buttom(int middle_y, int middle_x);

// Рисует кнопку "HIT" в заданных координатах
int hit_buttom(int middle_y, int middle_x);

// Рисует кнопку "STAND" в заданных координатах
int stand_buttom(int middle_y, int middle_x);

// Красная рамка вокруг кнопки
void red_frame_around_buttom(int middle_y, int middle_x);

// Черная рамка вокруг кнопки
void black_frame_around_buttom(int middle_y, int middle_x);

// Голубая рамка вокруг кнопки
void blue_frame_around_buttom(int middle_y, int middle_x);

// Выводит "TOTAL BET" на экран
void total_bet_on_display(int bet, int middle_x, int middle_y);

// Выводит "BANK" на экран
void bank_on_display(int bet, int middle_x, int middle_y);

// Выводит надпись насчет минимальной и максимальной ставки на экран
void min_max_bet_on_display(int middle_x, int middle_y);

// Принимает номер кнопки и возвращает количество долларов
int dollars_for_bet(int buttom_number);

// Выводит предупреждающую надпись насчет максимальной ставки
void max_bet_warning(int middle_x, int middle_y);

// Выводит предупреждающую надпись что нужно вначале сделать ставку
void make_your_bet_warning(int middle_x, int middle_y);

// Выводит "YOU HAVE ONLY" на экран
void you_have_only_on_display(int bet, int middle_x, int middle_y);

// Функция принимает массив и возвращает произвольный порядковый номер значения != 0 (значению присваевает 0) 
int index_random_card(int arr[], int Size);

// Проверяем, что количество карт в коллоде больше 30
bool enough_cards_in_deck(const int arr[], int Size);

// Считает сумму элементов массива
int sum_of_cards(const int arr[], int Size);

// Выводим счет на экран
void score_on_display(int middle_x, int middle_y, int score);

// Проверяем раздачу на наличие тузa и и присваиваем ему 1 очко
bool ace_in_score(int arr[], int Size);

// Надпись "YOU WON ..." 
void you_won_inscription(int middle_x, int middle_y, int winner_points);

// Надпись "YOU LOSE ..." 
void you_lose_inscription(int middle_x, int middle_y);

// Зарисовывает поле с картами и счетом карт
void clear_green_field();

// Надпись "PUSH" означает равное количество очков
void push_inscription(int middle_x, int middle_y);

// Надпись "GAME OVER"
void game_over(int middle_y, int middle_x);

// Надпись "BLACK JACK"
void black_jack(int middle_y, int middle_x);

// Рисует кнопку "PLAY" 
void play_button(int middle_y, int middle_x);

// Рисует кнопку "RULES" 
void rules_button(int middle_y, int middle_x);

// Рисует кнопку "ABOUT" 
void about_button(int middle_y, int middle_x);

// Рисует кнопку "EXIT"
void exit_button(int middle_y, int middle_x);

// Раскидывает карты по всему экрану
void cards_arround(const int arr[], int Size);

// Меню ставок
void bets_menu();

// Игровое меню
void game_menu();

// Правила
void rules();

// Надпись "EXIT. ARE YOU SHURE? Y/N"
void exit_are_you_sure(int middle_x, int middle_y);

// Надпись "Public domain"
void public_domain();

// Надпись "PRESS ESC TO EXIT"
void press_esc_to_exit(int middle_x, int middle_y);

/// Надпись об навигационных кнопках
void use_buttons(int middle_x, int middle_y);


#endif
