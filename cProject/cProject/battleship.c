/* ENGGEN131 C Project 2023 - Battleships */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAP_SIZE 6
#define HIT 1000

// Prototype declarations of required functions
void PrintArray(int values[MAP_SIZE][MAP_SIZE]);
void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]);
void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]);
int CountValues(int value, int map[MAP_SIZE][MAP_SIZE]);
int TopLeftPosition(int size, int* row, int* col, int map[MAP_SIZE][MAP_SIZE]);
int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE]);
void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]);
void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col);
int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE]);


/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the required functions should go below
*******************************************************************************
*******************************************************************************
******************************************************************************/

void PrintArray(int values[MAP_SIZE][MAP_SIZE])
{
	// iterate through the rows and columns of the array and print their values
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (j == MAP_SIZE - 1) {
				// print the last element in the row w/ a line break and no space  
				printf("%d\n", values[i][j]);
			}
			else {
				// print the elements in the row seperated by a space
				printf("%d ", values[i][j]);
			}
		}
	}
}

void InitialiseMap(int map[MAP_SIZE][MAP_SIZE])
{
	// size 2 ship
	for (int i = 0; i < 2; i++) {
		map[i][0] = 2;
	}

	// size 3 ship
	for (int j = 1; j < 4; j++) {
		map[2][j] = 3;
	}

	// size 4 ship
	for (int j = 0; j < 4; j++) {
		map[5][j] = 4;
	}

	// size 5 ship
	for (int i = 1; i < 6; i++) {
		map[i][5] = 5;
	}
}

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE])
{
	// random number to determine ship direction
	int rDirection = rand();

	// random number to determine which row/col the ship will go
	int rRowCol = (rand() % MAP_SIZE);

	// random number between 0 and space left in row/col after placing ship
	int rSpace = (rand() % ((MAP_SIZE - size) + 1));

	// vertical direction if random number is even
	if (rDirection % 2 == 0) {
		for (int i = rSpace; i < rSpace + size; i++) {
			map[i][rRowCol] = size;
		}
	}
	// horizontal direction if random number is odd
	else {
		for (int j = rSpace; j < rSpace + size; j++) {
			map[rRowCol][j] = size;
		}
	}
}

int CountValues(int value, int map[MAP_SIZE][MAP_SIZE])
{
	// initialise counter
	int count = 0;

	// iterate through the rows and columns of the array and count the occurences of a value
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == value) {
				count++;
			}
		}
	}
	return count;
}

int TopLeftPosition(int size, int* row, int* col, int map[MAP_SIZE][MAP_SIZE])
{
	// iterate through array top to bottom and left to right to find top left position
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == size) {
				*row = i;
				*col = j;

				// determine if horizontal or vertical
				if (map[i][j + 1] == size) {
					return 1;
				}
				else {
					return 2;
				}

			}
		}
	}
}

int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE])
{
	int row, col;
	int direction = TopLeftPosition(size, &row, &col, map);
	// horizontal ship
	if (direction == 1) {
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + size; j++) {
				if ((i >= 0 && i <= MAP_SIZE - 1) && (j >= 0 && j <= MAP_SIZE - 1) &&  // exclude out of bounds
					// exclude corners
					!(i == row - 1 && j == col - 1) && !(i == row - 1 && j == col + size) &&
					!(i == row + 1 && j == col - 1) && !(i == row + 1 && j == col + size)) {
					// check whether element is adjacent to another ship
					if (map[i][j] != 0 && map[i][j] != size) {
						return 0;
					}
				}
			}
		}
	}
	// vertical ship
	else if (direction == 2) {
		for (int i = row - 1; i <= row + size; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				if ((i >= 0 && i <= MAP_SIZE - 1) && (j >= 0 && j <= MAP_SIZE - 1) &&  // exclude out of bounds
					// exclude corners
					!(i == row - 1 && j == col - 1) && !(i == row - 1 && j == col + 1) &&
					!(i == row + size && j == col - 1) && !(i == row + size && j == col + 1)) {
					// check whether element is adjacent to another ship
					if (map[i][j] != 0 && map[i][j] != size) {
						return 0;
					}
				}
			}
		}
	}
	else {
		// in the case that the ship can't be found
		return 0;
	}

	return 1;
}

void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE])
{
	int size, nShips = 0;

	while (nShips < 4) {
		// place the four ships randomly
		AddRandomShip(2, map);
		AddRandomShip(3, map);
		AddRandomShip(4, map);
		AddRandomShip(5, map);
		// iterate through the ships and test their validity
		for (size = 2; size <= 5; size++) {
			if (IsShipValid(size, map) == 0) {
				// reset the map and place a new set of ships if any invalid ships are found
				nShips = 0;
				for (int i = 0; i < MAP_SIZE; i++) {
					for (int j = 0; j < MAP_SIZE; j++) {
						map[i][j] = 0;
					}
				}
				break;
			}
			else {
				nShips++;
			}
		}
	}
}

void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col)
{
	int count = 0;
	int direction;
	int size = map[row][col];

	// determine shot order
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if ((shots[i][j] > count && (shots[i][j] % 1000) > count)) {
				count = (shots[i][j] % 1000);
			}
		}
	}

	if (map[row][col] == 0 && shots[row][col] == 0) { // missed shot
		shots[row][col] = count + 1;
	}
	else if (shots[row][col] == 0) {
		shots[row][col] = 1001 + count;
		direction = TopLeftPosition(size, &row, &col, map);

		// hit horizontal ship
		if (direction == 1) {
			for (int j = col; j < col + size; j++) {
				if (shots[row][j] == 0) {
					return;
				}
			}
			// sink ship
			for (int j = col; j < col + size; j++) {
				shots[row][j] = shots[row][j] + (size - 1) * 1000;
			}
		}
		else {
			for (int i = row; i < row + size; i++) {
				if (shots[i][col] == 0) {
					return;
				}
			}
			// sink ship
			for (int i = row; i < row + size; i++) {
				shots[i][col] = shots[i][col] + (size - 1) * 1000;
			}
		}
	}
}

int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE])
{
	// iterate through map array and compare with shots array to see if the ship is hit
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] != 0 && shots[i][j] < 2000) {
				return 0;
			}
		}
	}
	return 1;
}

/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the required functions should go above
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Provided functions needed for playing the Battleships game:

// First, prototype declarations for the bots:
void GetMoveBot1(int shots[MAP_SIZE][MAP_SIZE], int* row, int* col);
void GetMoveBot2(int shots[MAP_SIZE][MAP_SIZE], int* row, int* col);

// Gets the input for one move from the human player (an alphabetic row and a numeric column)
// This function converts both inputs to numeric values
void GetMoveHuman(int* row, int* col, int player)
{
	char a = ' ';
	int b = -1;
	printf("Player %d: enter move [row/col]: ", player);
	while (!(a >= 'A' && a <= 'Z')) {
		scanf("%c", &a);
	}
	while (!(b >= 0 && b <= 25)) {
		scanf("%d", &b);
	}
	*row = (int)(a - 'A');
	*col = b;
}

// Takes two "shots" arrays as input (which are the visible parts of the game shown to players) and formats them into a string for printing
// The player currently to move is highlighted
void GetDisplayMapString(int shots1[MAP_SIZE][MAP_SIZE], int shots2[MAP_SIZE][MAP_SIZE], int player, char* boardString)
{
	int i, j;
	char numbers[10];
	// Intialise board string to be empty:
	boardString[0] = '\0';
	strcat(boardString, "  ");

	for (i = 0; i < MAP_SIZE; i++) {
		sprintf(numbers, "%d", i % 10);
		strcat(boardString, numbers);
	}
	strcat(boardString, "|");
	for (i = 0; i < MAP_SIZE; i++) {
		sprintf(numbers, "%d", i % 10);
		strcat(boardString, numbers);
	}
	strcat(boardString, "\n  ");

	for (i = 0; i < MAP_SIZE; i++) {
		strcat(boardString, "-");
	}
	strcat(boardString, "|");
	for (i = 0; i < MAP_SIZE; i++) {
		strcat(boardString, "-");
	}
	strcat(boardString, "\n");

	for (i = 0; i < MAP_SIZE; i++) {
		int len = strlen(boardString);
		boardString[len] = (char)('A' + i);
		boardString[len + 1] = '\0';
		strcat(boardString, "|");
		for (j = 0; j < MAP_SIZE; j++) {
			if (shots1[i][j] / HIT > 0) {
				if (shots1[i][j] / HIT == 1) {
					strcat(boardString, "X");
				}
				else {
					sprintf(numbers, "%d", shots1[i][j] / HIT);
					strcat(boardString, numbers);
				}
			}
			else if (shots1[i][j] > 0) {
				strcat(boardString, ".");
			}
			else {
				strcat(boardString, " ");
			}
		}
		strcat(boardString, "|");
		for (j = 0; j < MAP_SIZE; j++) {
			if (shots2[i][j] / HIT > 0) {
				if (shots2[i][j] / HIT == 1) {
					strcat(boardString, "X");
				}
				else {
					sprintf(numbers, "%d", shots2[i][j] / HIT);
					strcat(boardString, numbers);
				}
			}
			else if (shots2[i][j] > 0) {
				strcat(boardString, ".");
			}
			else {
				strcat(boardString, " ");
			}
		}
		strcat(boardString, "|");
		len = strlen(boardString);
		boardString[len] = (char)('A' + i);
		boardString[len + 1] = '\0';
		strcat(boardString, "\n");
	}
	if (player == 1) {
		strcat(boardString, "  P1");
		for (i = 0; i < MAP_SIZE - 2; i++) {
			strcat(boardString, "*");
		}
	}
	else {
		for (i = 0; i < MAP_SIZE; i++) {
			strcat(boardString, " ");
		}
		strcat(boardString, "   P2");
		for (i = 0; i < MAP_SIZE - 2; i++) {
			strcat(boardString, "*");
		}
	}
	strcat(boardString, "\n");
}

// Plays one game of Battleships, beginning with the specified starting player
// Game type = 1 (human vs human) or 2 (human vs bot) or 3 (bot vs bot)
int PlayOneGame(int startingPlayer, int gameType)
{
	int row, col, player, gameOver;

	// String to display the boards
	char displayBoardString[(2 * MAP_SIZE + 5) * (MAP_SIZE + 5)];

	// The maps containing the locations of the ships
	int mapPlayer1[MAP_SIZE][MAP_SIZE] = { 0 };
	int mapPlayer2[MAP_SIZE][MAP_SIZE] = { 0 };

	// The locations of the shots
	int shotsPlayer1[MAP_SIZE][MAP_SIZE] = { 0 };
	int shotsPlayer2[MAP_SIZE][MAP_SIZE] = { 0 };

	player = startingPlayer;
	gameOver = 0;

	// Create random maps for each player
	InitialiseRandomMap(mapPlayer1);
	InitialiseRandomMap(mapPlayer2);

	// Display the board if a human is playing
	if (gameType != 3) {
		GetDisplayMapString(shotsPlayer1, shotsPlayer2, player, displayBoardString);
		printf("%s", displayBoardString);
	}

	// Process one move for the current player
	while (!gameOver) {
		if (gameType == 1) {
			GetMoveHuman(&row, &col, player);
			if (player == 1) {
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			}
			else {
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		}
		else if (gameType == 2) {
			if (player == 1) {
				GetMoveHuman(&row, &col, player);
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			}
			else {
				GetMoveBot1(shotsPlayer2, &row, &col);
				printf("Player 2 (bot) moves: %c%d\n", (char)(row + 'A'), col);
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		}
		else {
			if (player == 1) {
				GetMoveBot1(shotsPlayer1, &row, &col);
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			}
			else {
				GetMoveBot2(shotsPlayer2, &row, &col);
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		}

		// Swap players
		if (!gameOver) {
			player = 3 - player;
		}
		if (gameType != 3) {
			GetDisplayMapString(shotsPlayer1, shotsPlayer2, player, displayBoardString);
			printf("%s", displayBoardString);
		}
	}
	return player;
}

// Play a Battleships tournament
// If the tournament is between a human and a bot, only one game is played
// If the tournament is between two bots, the number of games is requested
void PlayBattleships(void)
{
	int gameType, numberOfGames, result;
	int i, wins1, wins2, player;

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;

	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	// Set win counts to zero
	wins1 = 0;
	wins2 = 0;

	// Player 1 will always start the first game
	// If a tournament is played (between two bots), the starting player alternates
	player = 1;

	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, gameType);
		if (result == 1) {
			wins1++;
		}
		else {
			wins2++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}

	// Show the outcome (of a single game or tournament)
	if (numberOfGames == 1) {
		printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
	}
	else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d\n\n", numberOfGames, wins1, wins2);
	}
}

// The main function for the Battleships program
int main(void)
{
	// Initialise the seed for the random number generator
	srand((unsigned int)time(NULL));

	printf("ENGGEN131 - C Project 2023\n");
	printf("                          ... presents ...\n");
	printf(" ___    __   _____ _____  _     ____  __   _     _   ___   __  \n");
	printf("| |_)  / /\\   | |   | |  | |   | |_  ( (` | |_| | | | |_) ( (` \n");
	printf("|_|_) /_/--\\  |_|   |_|  |_|__ |_|__ _)_) |_| | |_| |_|   _)_) \n");
	printf("\n                __/___            \n");
	printf("          _____/______|           \n");
	printf("  _______/_____\\_______\\_____     \n");
	printf("  \\              < < <       |    \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n");

	PlayBattleships();

	return 0;
}

/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the two bots can be provided below
// The existing implementations are naive:
// - Bot 1 simply takes random shots (without checking for repeated shots)
// - Bot 2 also takes random shots (but makes a single test on each turn for a repeated shot)
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Strategy for Bot 1
void GetMoveBot1(int shots[MAP_SIZE][MAP_SIZE], int* row, int* col)
{
	int rand_row;
	int rand_col;

	rand_row = shots[0][0]; // to prevent compiler warning (because otherwise "shots" array is not accessed)
	rand_row = rand() % MAP_SIZE;
	rand_col = rand() % MAP_SIZE;

	*row = rand_row;
	*col = rand_col;
}

// Strategy for Bot 2
void GetMoveBot2(int shots[MAP_SIZE][MAP_SIZE], int* row, int* col)
{
	int rand_row;
	int rand_col;

	rand_row = shots[0][0]; // to prevent compiler warning (because otherwise "shots" array is not accessed)
	rand_row = rand() % MAP_SIZE;
	rand_col = rand() % MAP_SIZE;

	// If the shot has been tried before, try one more time
	if (shots[rand_row][rand_col] > 0) {
		rand_row = rand() % MAP_SIZE;
		rand_col = rand() % MAP_SIZE;
	}

	*row = rand_row;
	*col = rand_col;
}