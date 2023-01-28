#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Sudoku {
	float matrix[10][10];				//contains the proper file input 
	int error_message_detector;			//detects if the "error" message should be displayed
	fstream file;						
public:
	Sudoku();

	void Putting_into_matrix(string location_of_the_file);			//puts the content of the file in the matrix
	void Matrix_evaluation();										//calculates if the matrix fulfills all of the requirements of the sudoku game
	void Initialize_sudoku(string location_of_the_file);			//initialises the sudoku game, uses two of the methods described above
};
