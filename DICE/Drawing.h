#ifndef _DRAWING_H
#define _DRAWING_H

// Рисует рамку по заданным параметрам
void DoubleLineFrame(int height, int width, int MiddleX, int MiddleY, ConsoleColor line, ConsoleColor background);

// Рисует сторону игральной кости заданного числа в заданную позицию на экране
int DiceSide(int num, int MiddleX, int MiddleY);

#endif // !_DRAWING_
