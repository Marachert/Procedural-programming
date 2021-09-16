#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int Size = 8;
const int numOfSteps = 8;
int stepByRow[numOfSteps]{ -2, -2, -1, -1,  1, 1,  2, 2 };
int stepByCol[numOfSteps]{ -1,  1, -2,  2, -2, 2, -1, 1 };

// ������� ��������� ������ �� �����
void printArray(int arr[][Size])
{
	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
			cout << setw(3) << arr[y][x];
		cout << endl;
	}
}


// ������������. ������� � ����������� �����
bool horseWay(int chessBoard[][Size], int row, int col, int stepNumber)
{
// ��������� ����
	chessBoard[row][col] = stepNumber;

	//printArray(chessBoard);
	//Sleep(3000);
	//system("cls");

// ������� ������ �� ��������
	if (stepNumber == Size * Size)
		return true;

	// ���������� ��������� ���� �����
	for (int y = 0; y < numOfSteps; y++)
	{
		int nextStepRow = row + stepByRow[y];
		int nextStepCol = col + stepByCol[y];

// ��� ������� ���� ��������� ����
		if ((chessBoard[nextStepRow][nextStepCol] == 0) &&
			nextStepRow >= 0 && nextStepRow < Size &&
			nextStepCol >= 0 && nextStepCol < Size)
		{
			if (horseWay(chessBoard, nextStepRow, nextStepCol, stepNumber + 1))
				return true;

// �������� ������, � ������� ��� ���������� �����
			chessBoard[nextStepRow][nextStepCol] = 0;
		}
	}
// ��� ���������� ���� ��������� ��������� �������� �� ����� �� �������� LIFO
	return false;
}

int main()
{
	int chessBoard[Size][Size]{ 0 };
	int row, col, stepNumber = 1;
	char letter;

	cout << "Please enter horse position (ex. A1): ";
	cin >> letter >> row;

	// ������������� �������� ��������� ��� ����������� ��������� �����
	col = int(letter) - 65;
	row = Size - row;
	
	horseWay(chessBoard, row, col, stepNumber);

	printArray(chessBoard);	
}