#include "Sudoku.h"

Sudoku::Sudoku()											//setting the values of all variables and eleemnts of the matrix to 0
{
	error_message_detector = 0; 
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) matrix[i][j] = 0;
	}
}

void Sudoku::Putting_into_matrix(string location_of_the_file)
{
	string lines_in_file[10];
	int detector = 0;			//should be 9 in total  //used for detecting an error in input

	for (int i = 0; i < 9; i++) {
		getline(file, lines_in_file[i]);						//inputs lines from the file into the strings in the program

		int j_matrix = 0;
		for (int j = 0; j < lines_in_file[i].size(); j++) {
			if (lines_in_file[i][j] != '0' && lines_in_file[i][j] != '1' && lines_in_file[i][j] != '2' && lines_in_file[i][j] != '3'
				&& lines_in_file[i][j] != '4' && lines_in_file[i][j] != '5' && lines_in_file[i][j] != '6'
				&& lines_in_file[i][j] != '7' && lines_in_file[i][j] != '8' && lines_in_file[i][j] != '9') continue;		//if the input is not a digit, skip it
			else { matrix[i][j_matrix] = lines_in_file[i][j] - 48; detector++; }		//putting the appriprate number into the float matrix 
			j_matrix++;
		}

		try {
			if (detector != 9) throw 'a';					//if 9 digits weren't detected, throw an exception
		}
		catch (char a) {
			error_message_detector++;
		}
		detector = 0;
	}

}

void Sudoku::Matrix_evaluation()
{
	int requirements_fulfilled = 0;		//in total should be 9 + 9 + 9 = 27

	for (int i = 0; i < 9; i++)
	{
		float sum_row = 0; //should be 1+2+3+4+5+6+7+8+9 =  46 to pass the requirement
		float sum_collumn = 0;
		for (int j = 0; j < 9; j++) sum_row += matrix[i][j];							//checking the particular row
		if (sum_row == 45) requirements_fulfilled++;

		for (int j = 0; j < 9; j++) sum_collumn += matrix[j][i];							//checking the particular collumn
		if (sum_collumn == 45) requirements_fulfilled++;
	}

	int row = 0, collumn = 0;
	int when_to_change_rows = 0, when_to_change_collumns = 0;
	for (int particular_grid = 0; particular_grid < 9; particular_grid++) {				//checking all 9 3x3 grids

		float sum_grid = 0;
		for (int i = row; i < row + 3; i++)
		{
			for (int j = collumn; j < collumn + 3; j++)
			{
				sum_grid += matrix[i][j];
			}
		}

		if (sum_grid == 45) requirements_fulfilled++;
		sum_grid = 0;

		collumn += 3;

		if (particular_grid == 2 || particular_grid == 5) {						//next 3 rows, set collumn to 0
			collumn = 0; row += 3;
		}
	}

	try {
		if (error_message_detector != 0) throw 'a';								//if error message detector has value different than 0, throw an exception
	}
	catch (char x)
	{
		cout << "ERROR";
	}

	if (error_message_detector == 0) {
		if (requirements_fulfilled == 27) cout << "CORRECT";					//if all of the requirements were met, display the message "CORRECT"
		try {
			if (requirements_fulfilled != 27) throw 1;

		}
		catch (int x)
		{
			cout << "WRONG";													//if not all of the requirements were met, display the message "WRONG"
		}
	}
}

void Sudoku::Initialize_sudoku(string location_of_the_file)
{
	file.open(location_of_the_file, ios::in);

	if (file.is_open())
	{
		Putting_into_matrix(location_of_the_file);			//putting the input into the matrix
		Matrix_evaluation();								//calculations
	}
	else {
		try { throw 'a'; }				//exception handling - file cannot be opened
		catch (char x)
		{
			cout << "File cannot be opened";
		}
	}


}