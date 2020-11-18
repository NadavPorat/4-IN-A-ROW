#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


/*************** NAME AND I.D ***************/
		// NADAV PORAT 311119374//

/*********** THE PURPOSE OF THE PROGRAM ************/
			// PLAY THE GAME 4 IN A ROW//


/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];

/*********** Declarations ************/

/// This function initializes the game board by assigning each cell
/// with ' ' (resulting with an empty game board).
void initBoard();

/// This function gets a row number and a column number (a cell),
/// and returns the character in that cell (could be 'X', 'O' or ' ').
/// For example:
/// char c = getCell(1, 1);
char getCell(int row, int col);

/// This function gets a row number, a column number and a sign,
/// and assigns the cell with the given sign.
/// For example:
/// setCell(1, 1, 'X');
void setCell(int row, int col, char sign);

/// This function clears the screen.
void clearScreen();

/// This funcation prints the right value where the player wonts it - player1 and player2.
void player1();
void player2();

/// This print the bord
void printboard();

/// This check if player win by 4 in a colomn
bool checkTur(char ch, int colomn);

/// This check if player win by 4 in a row
bool checkshora(char ch, int colomn);

/// This check if player win by 4 in digona line
bool checkDiagonalLine1(char ch, int colomn); // diagona line to the right
bool checkDiagonalLine2(char ch, int colomn);// diagona line to the left

/// This check if we got draw
bool checkdraw();

/*************** Main ****************/
int main()
{
	int colomn1, colomn2, row2 = 6;
	bool win = false;
	bool win1 = false;
	bool win2 = false;
	bool win3 = false;

	printboard();
	while (win == false && win1 == false && win2 == false && win3 == false && checkdraw() == false)// as long as no one has wins then keep playing
	{
		printf("Player number 1:\n");
		printf("Please enter column input (a number between 1-7):");
		scanf("%d", &colomn1);
		player1(colomn1);
		win = checkTur('X', colomn1);
		win1 = checkshora('X', colomn1);
		win2 = checkDiagonalLine1('X', colomn1);
		win3 = checkDiagonalLine2('X', colomn1);
		if (win == true || win1 == true || win2 == true || win3 == true) {
			printf("player1 Win \n");
		}
		else
		{
			printf("Player number 2:\n");
			printf("Please enter column input (a number between 1-7):");
			scanf("%d", &colomn2);
			player2(colomn2);
			win = checkTur('O', colomn2);
			win1 = checkshora('O', colomn2);
			win2 = checkDiagonalLine1('O', colomn2);
			win3 = checkDiagonalLine2('O', colomn2);
			if (win == true || win1 == true || win2 == true || win3 == true) {
				printf("player2 Win \n");
			}

			if (checkdraw() == true)
				printf(" It's a Draw\n\n");
		}
	}
}


/********** Implementations **********/
char getCell(int row, int col)
{
	return board[row - 1][col - 1];
}

void setCell(int row, int col, char sign)
{
	board[row - 1][col - 1] = sign;
}

void initBoard()
{
	int i, j;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			setCell(i + 1, j + 1, ' ');
		}
	}
}

void clearScreen()
{
	system("cls");
}

void printboard()
{
	int i, j, k;
	char colomn = 'A';
	printf("  ");
	for (i = 1; i <= COLS; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");
	for (j = 1; j <= ROWS; j++)
	{
		printf("%c ", colomn);
		for (k = 1; k <= COLS; k++)
		{
			printf("%c  ", getCell(k, j));

		}
		printf("\n\n");
		colomn++;
	}
}

void player1(int colomn)//ask for number 
{
	int row = 6, row2 = 6;

	if ((colomn <= 0) || (colomn > 7))
		printf("incorrect input \n\n");
	else
	{
		{
			while ((getCell(colomn, row2) == 'O') || (getCell(colomn, row2) == 'X'))
			{
				row2--;

			}
			if (row2 > 0)
			{
				setCell(colomn, row2, 'X');
				clearScreen();
				printboard();

			}
			else
				printf("No more place\n");
			if (getCell(colomn, row) == ' ')
			{
				setCell(colomn, row, 'X');
				clearScreen();
				printboard();

			}

		}

	}



}
void player2(int colomn)//ask for number 
{
	int row = 6, row2 = 6;
	if ((colomn <= 0) || (colomn > 7))
		printf("incorrect input \n\n");
	else
	{
		{
			while ((getCell(colomn, row2) == 'O') || (getCell(colomn, row2) == 'X'))
			{
				row2--;

			}
			if (row2 > 0)
			{
				setCell(colomn, row2, 'O');
				clearScreen();
				printboard();

			}
			else
				printf("No more place\n");
			if (getCell(colomn, row) == ' ')
			{
				setCell(colomn, row, 'O');
				clearScreen();
				printboard();

			}

		}

	}

}

bool checkTur(char ch, int colomn)
{

	int row = 0;

	while (getCell(colomn, row) != ch) { // to get the true row
		row++;
	}

	if ((getCell(colomn, row + 1) == ch) && (getCell(colomn, row + 2) == ch) && (getCell(colomn, row + 3) == ch))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkshora(char ch, int colomn) {
	int row = 1;

	while (getCell(colomn, row) != ch) {
		row++;
	} // to get the right row 


	if ((getCell(colomn + 1, row) == ch) && (getCell(colomn + 2, row) == ch) && (getCell(colomn + 3, row) == ch))
	{
		return true;
	}
	else if ((getCell(colomn - 1, row) == ch) && (getCell(colomn - 2, row) == ch) && (getCell(colomn - 3, row) == ch))
	{
		return true;
	}
	else if ((getCell(colomn + 1, row) == ch) && (getCell(colomn - 2, row) == ch) && (getCell(colomn - 1, row) == ch))
	{
		return true;
	}
	else if ((getCell(colomn + 1, row) == ch) && (getCell(colomn + 2, row) == ch) && (getCell(colomn - 1, row) == ch))
	{
		return true;
	}

	else {
		return false;
	}
}

bool checkDiagonalLine1(char ch, int colomn)
{
	int row = 0;
	while (getCell(colomn, row) != ch) {
		row++; //// to get the true row
	}
	if ((getCell(colomn + 1, row + 1) == ch) && (getCell(colomn + 2, row + 2) == ch) && (getCell(colomn + 3, row + 3) == ch))
	{
		return true;
	}
	else if ((getCell(colomn - 1, row - 1) == ch) && (getCell(colomn + 1, row + 1) == ch) && (getCell(colomn + 2, row + 2) == ch))
	{
		return true;
	}
	else if ((getCell(colomn - 1, row - 1) == ch) && (getCell(colomn - 2, row - 2) == ch) && (getCell(colomn + 1, row + 1) == ch))
	{
		return true;
	}
	else if ((getCell(colomn - 1, row - 1) == ch) && (getCell(colomn - 2, row - 2) == ch) && (getCell(colomn - 3, row - 3) == ch))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool checkDiagonalLine2(char ch, int colomn)
{
	int row = 0;
	while (getCell(colomn, row) != ch) {
		row++; //// to get the true row
	}
	if ((getCell(colomn - 1, row + 1) == ch) && (getCell(colomn - 2, row + 2) == ch) && (getCell(colomn - 3, row + 3) == ch))
	{
		return true;
	}
	else if ((getCell(colomn + 1, row - 1) == ch) && (getCell(colomn - 1, row + 1) == ch) && (getCell(colomn - 2, row + 2) == ch))
	{
		return true;
	}
	else if ((getCell(colomn - 1, row + 1) == ch) && (getCell(colomn + 1, row - 1) == ch) && (getCell(colomn - 2, row - 2) == ch))
	{
		return true;
	}
	else if ((getCell(colomn + 1, row - 1) == ch) && (getCell(colomn + 2, row - 2) == ch) && (getCell(colomn + 3, row - 3) == ch))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool checkdraw()
{
	int count = 0, colomn, row = 1; //z,q is counter to chek when win

	for (colomn = 1; colomn < 8; colomn++) {
		if ((getCell(colomn, row) == 'O') || (getCell(colomn, row) == 'X'))
		{
			count++;
		}
	}
	if (count == 7) {
		return(true);
	}
	else
	{
		return (false);
	}
}

 