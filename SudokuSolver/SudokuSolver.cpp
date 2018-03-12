// SudokuSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Square
	//The Square class represents a single 3x3 segment of a sudoku
{
	int SolvedArray[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
	bool GuessArray[9][3][3] = {
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } },
	{ { true,true,true },{ true,true,true },{ true,true,true } }
	};

public:
	bool issolved = false;

	void PrintSolved();
	void PrintGuess(int GuessNumber);
	void DeleteGuessesFromColumn(int Number, int ColumnNumber);
	void DeleteGuessesFromRow(int Number, int RowNumber);
	/*void CheckSolved();*/
	Square();
};

Square::Square(void)
//Constructor to fill in numbers already known at the start.
{

	return;
}

void Square::DeleteGuessesFromColumn(int Number, int ColumnNumber)
//Deletes a number from a whole column in the guesses matrix
{
	int i;

	Number--;
	for (i = 0; i < 3; i++) {
		GuessArray[Number][i][ColumnNumber] = false;
	}
	return;
}

void Square::DeleteGuessesFromRow(int Number, int RowNumber)
//Deletes a number from a whole row in the guesses matrix
{
	int i;

	Number--;
	for (i = 0; i < 3; i++) {
		GuessArray[Number][RowNumber][i] = false;
	}
	return;
}

//void Square::CheckSolved()
//{
//	int NumCols = 3, NumRows = 3, i, j, k;
//	bool Solved = false;
//
//
//	for (k = 8; i > -1; i--)
//	{
//		for (i = NumCols - 1; i > -1; i--)
//		{
//			for (j = 0; j < NumCols; j++)
//			{
//				std::cout << GuessArray[k][i][j];
//			}
//			std::cout << std::endl;
//		}
//		if (Solved)
//		{
//
//		}
//	}
//}

void Square::PrintSolved()
{
	int NumCols = 3, NumRows = 3, i, j;

	for (i = NumCols - 1; i > -1; i--)
	{
		for (j = 0; j < NumCols; j++)
		{
			std::cout << SolvedArray[i][j];
		}
		std::cout << std::endl;
	}
}

void Square::PrintGuess(int GuessNumber)
{
	int NumCols = 3, NumRows = 3, i, j;

	GuessNumber--;
	for (i = NumCols - 1; i > -1; i--)
	{
		for (j = 0; j < NumCols; j++)
		{
			std::cout << GuessArray[GuessNumber][i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	Square sq1;
	sq1.PrintGuess(9);
	std::cout << std::endl;
	sq1.DeleteGuessesFromColumn(9, 0);
	sq1.PrintGuess(9);
	std::cout << std::endl;
	sq1.PrintGuess(8);
	std::cout << std::endl;
	sq1.PrintGuess(7);
	std::cout << std::endl;
	sq1.PrintGuess(6);
	std::cout << std::endl;
	sq1.PrintGuess(5);
	std::cout << std::endl;
	sq1.PrintGuess(4);
	std::cout << std::endl;
	sq1.PrintGuess(3);
	std::cout << std::endl;
	sq1.PrintGuess(2);
	std::cout << std::endl;
	sq1.PrintGuess(1);
	getchar();
	return 0;
}

