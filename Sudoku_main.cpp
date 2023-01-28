#include <iostream>
#include <string>
#include <fstream>
#include "Sudoku.h"


int main(int argc, char** argv)
{
	try {
		if (argc <= 1) throw 1;					//if less than 1 argument is detected, throw an exceptionS
	}
	catch (int x)
	{
		cout << "Less than 1 argument was given, the program cannot be executed";
	}

	if (argc > 1) {

		const string input(argv[1]);

		Sudoku* sudoku = new Sudoku();
		sudoku->Initialize_sudoku(input);
		delete sudoku;
	}

	return 0;
}
