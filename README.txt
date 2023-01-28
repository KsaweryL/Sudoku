The program solves the sudoku game for the given input file.

The file "Sudoku.h" contains the sudoku class, its variables alongside the methods defined in it while
"Sudoku.cpp" file has the code for each of those methods.

Variables:
- matrix[10][10] - contains the input matrix that is to be calculated later. Its type is the float
- error_message_detector - detects whether the message "ERROR" should be displayed, its type is the integer
- file - the stream object of class fstream that is used to operate on files

Methods:
- Putting_into_matrix - accepts the location_of_the_file string, puts the content of the file into the matrix
- Matrix_evaluation - calculates if the matrix fulfils all of the requirements of the sudoku game
- Initialize_sudoku - accepts the location_of_the_file string, initializes the sudoku game, uses two of the methods described above

The constructor sets the value of all variables and elements of the matrix to 0.

First, the program checks if any argument except from the name of the program was passed and if not, the program is not executed.

If the input in command line is correct, however, the object is created and the appropriate method (Initialize_sudoku), which executes the rest of the program, is initiated.
