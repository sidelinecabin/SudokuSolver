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
	void PrintSquareForGuess(int GuessNumber);
	void DeleteGuessesFromColumn(int Guess, int ColumnNumber);
	void DeleteGuessesFromRow(int Guess, int RowNumber);
	void DeleteGuessesFromSquare(int Guess);
	void CheckSolved();
	Square();
};

Square::Square(void)
//Constructor to fill in numbers already known at the start.
{

	return;
}

void Square::DeleteGuessesFromColumn(int Guess, int ColumnNumber)
//Deletes a number from a whole column in the guesses matrix
{
	int i;

	Guess--;
	for (i = 0; i < 3; i++) {
		GuessArray[Guess][i][ColumnNumber] = false;
	}
	return;
}

void Square::DeleteGuessesFromRow(int Guess, int RowNumber)
//Deletes a number from a whole row in the guesses matrix
{
	int i;

	Guess--;
	for (i = 0; i < 3; i++) {
		GuessArray[Guess][RowNumber][i] = false;
	}
	return;
}

void Square::DeleteGuessesFromSquare(int Guess) {
	int GridSize = 3, i, j;

	Guess--;
	for (i = 0; i < GridSize; i++) {
		for (j = 0; j < GridSize; j++) {
			GuessArray[Guess][j][i] = false;
		}
	}
	return;
}

void Square::CheckSolved()
{
	int NumCols = 3, NumRows = 3, i, j, k;

	for (i = 0; i < NumCols; i++)
	{
		for (j = 0; j < NumCols; j++)
		{
			int Guesses = 0;
			int CurrentGuess;
			for (k = 8; k > -1; k--)
			{
				if (GuessArray[k][i][j])
				{
					Guesses++;
					CurrentGuess = k + 1;
				}
			}
			if (Guesses == 1) SolvedArray[i][j] = CurrentGuess;
		}
	}
}

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

void Square::PrintSquareForGuess(int GuessNumber)
{
	int NumCols = 3, i, j;

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
	sq1.PrintSquareForGuess(9);
	std::cout << std::endl;
	sq1.DeleteGuessesFromSquare(9);
	sq1.PrintSquareForGuess(9);
	std::cout << std::endl;
	sq1.CheckSolved();
	sq1.PrintSolved();
	getchar();
	return 0;
}

