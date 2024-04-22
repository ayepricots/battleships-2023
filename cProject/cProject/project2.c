///* ENGGEN131 C Project 2023 - Battleships */
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//
//#define MAP_SIZE 7
//#define HIT 1000
//
//// Prototype declarations of required functions
//void PrintArray(int values[MAP_SIZE][MAP_SIZE]);
//void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]);
//void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]);
//int CountValues(int value, int map[MAP_SIZE][MAP_SIZE]);
//int TopLeftPosition(int size, int* row, int* col, int map[MAP_SIZE][MAP_SIZE]);
//int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE]);
//void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]);
//void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col);
//int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE]);
//
//
///******************************************************************************
//*******************************************************************************
//*******************************************************************************
//// Implementations of the required functions should go below
//*******************************************************************************
//*******************************************************************************
//******************************************************************************/
//
//void PrintArray(int values[MAP_SIZE][MAP_SIZE])
//{
//	// iterate through the rows and columns of the array and print their values
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			if (j == MAP_SIZE - 1) {
//				// print the last element in the row w/ a line break and no space  
//				printf("%d\n", values[i][j]);
//			}
//			else {
//				// print the elements in the row seperated by a space
//				printf("%d ", values[i][j]);
//			}
//		}
//	}
//}
//
//void InitialiseMap(int map[MAP_SIZE][MAP_SIZE])
//{
//	// initialise map
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			map[i][j] = 0;
//		}
//	}
//
//	// size 2 ship
//	for (int i = 0; i < 2; i++) {
//		map[i][0] = 2;
//	}
//
//	// size 3 ship
//	for (int j = 1; j < 4; j++) {
//		map[2][j] = 3;
//	}
//
//	// size 4 ship
//	for (int j = 0; j < 4; j++) {
//		map[5][j] = 4;
//	}
//
//	// size 5 ship
//	for (int i = 1; i < 6; i++) {
//		map[i][5] = 5;
//	}
//}
//
//void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE])
//{
//	// random number to determine ship direction
//	int rDirection = rand();
//
//	// random number to determine which row/col the ship will go
//	int rRowCol = (rand() % MAP_SIZE);
//
//	// random number between 0 and space left in row/col after placing ship
//	int rSpace = (rand() % ((MAP_SIZE - size) + 1));
//
//	// vertical direction if random number is even
//	if (rDirection % 2 == 0) {
//		for (int i = rSpace; i < rSpace + size; i++) {
//			map[i][rRowCol] = size;
//		}
//	}
//	// horizontal direction if random number is odd
//	else {
//		for (int j = rSpace; j < rSpace + size; j++) {
//			map[rRowCol][j] = size;
//		}
//	}
//}
//
//int CountValues(int value, int map[MAP_SIZE][MAP_SIZE])
//{
//	// initialise counter
//	int count = 0;
//
//	// iterate through the rows and columns of the array and count the occurences of a value
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			if (map[i][j] == value) {
//				count++;
//			}
//		}
//	}
//	return count;
//}
//
//int TopLeftPosition(int size, int* row, int* col, int map[MAP_SIZE][MAP_SIZE])
//{
//	// iterate through array top to bottom and left to right to find top left position
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			if (map[i][j] == size) {
//				*row = i;
//				*col = j;
//
//				// determine if horizontal or vertical
//				if (map[i][j + 1] == size) {
//					return 1;
//				}
//					return 2;
//
//			}
//		}
//	}
//	return 0;
//}
//
//int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE])
//{
//	int row, col;
//	int direction = TopLeftPosition(size, &row, &col, map);
//	// horizontal ship
//	if (direction == 1) {
//		for (int i = row - 1; i <= row + 1; i++) {
//			for (int j = col - 1; j <= col + size; j++) {
//				if ((i >= 0 && i <= MAP_SIZE - 1) && (j >= 0 && j <= MAP_SIZE - 1) &&  // exclude out of bounds
//					// exclude corners
//					!(i == row - 1 && j == col - 1) && !(i == row - 1 && j == col + size) &&
//					!(i == row + 1 && j == col - 1) && !(i == row + 1 && j == col + size)) {
//					// check whether element is adjacent to another ship
//					if (map[i][j] != 0 && map[i][j] != size) {
//						return 0;
//					}
//				}
//			}
//		}
//	} 
//	// vertical ship
//	else if (direction == 2) {
//		for (int i = row - 1; i <= row + size; i++) {
//			for (int j = col - 1; j <= col + 1; j++) {
//				if ((i >= 0 && i <= MAP_SIZE - 1) && (j >= 0 && j <= MAP_SIZE - 1) &&  // exclude out of bounds
//					// exclude corners
//					!(i == row - 1 && j == col - 1) && !(i == row - 1 && j == col + 1) &&
//					!(i == row + size && j == col - 1) && !(i == row + size && j == col + 1)) {
//					// check whether element is adjacent to another ship
//					if (map[i][j] != 0 && map[i][j] != size) {
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	else {
//		// in the case that the ship can't be found
//		return 0;
//	}
//
//	return 1;
//}
//
//void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE])
//{
//	int size, nShips = 0;
//
//	while (nShips < 4) {
//		// place the four ships randomly
//		AddRandomShip(2, map);
//		AddRandomShip(3, map);
//		AddRandomShip(4, map);
//		AddRandomShip(5, map);
//		// iterate through the ships and test their validity
//		for (size = 2; size <= 5; size++) {
//			if (IsShipValid(size, map) == 0) {
//				// reset the map and place a new set of ships if any invalid ships are found
//				nShips = 0;
//				for (int i = 0; i < MAP_SIZE; i++) {
//					for (int j = 0; j < MAP_SIZE; j++) {
//						map[i][j] = 0;
//					}
//				}
//				break;
//			}
//			else {
//				nShips++;
//			}
//		}
//	}
//}
//
//void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col)
//{
//	int count = 0;
//	int direction;
//	int size = map[row][col];
//
//	// determine shot order
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			if ((shots[i][j] > count && (shots[i][j] % 1000) > count)) {
//					count = (shots[i][j] % 1000);
//			}
//		}
//	}
//	
//	if (map[row][col] == 0 && shots[row][col] == 0) { // missed shot
//		shots[row][col] = count + 1;
//	}
//	else if (shots[row][col] == 0) {
//		shots[row][col] = 1001 + count;
//		direction = TopLeftPosition(size, &row, &col, map);
//
//		// hit horizontal ship
//		if (direction == 1) {
//			for (int j = col; j < col + size; j++) {
//				if (shots[row][j] == 0) {
//					return;
//				}
//			}
//			// sink ship
//			for (int j = col; j < col + size; j++) {
//				shots[row][j] = shots[row][j] + (size - 1)*1000;
//			}
//		}
//		else {
//			for (int i = row; i < row + size; i++) {
//				if (shots[i][col] == 0) {
//					return;
//				}
//			}
//			// sink ship
//			for (int i = row; i < row + size; i++) {
//				shots[i][col] = shots[i][col] + (size - 1) * 1000;
//			}
//		}
//	}
//}
//
//int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE])
//{
//	// iterate through map array and compare with shots array to see if the ship is hit
//	for (int i = 0; i < MAP_SIZE; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			if (map[i][j] != 0 && shots[i][j] < 2000) {
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
///******************************************************************************
//*******************************************************************************
//*******************************************************************************
//// Implementations of the required functions should go above
//*******************************************************************************
//*******************************************************************************
//******************************************************************************/
//
///*************************************************************************
//** You should define your own test functions below
//*************************************************************************/
//
//// Example: a test function for Task One
//void TestPrintArray(void)
//{
//	int map1[MAP_SIZE][MAP_SIZE] = { 0 };
//	printf("Map 1: \n");
//	PrintArray(map1);
//
//	int map2[MAP_SIZE][MAP_SIZE] = { 0 };
//	for (int i = 0; i < MAP_SIZE; i++) {
//		map2[MAP_SIZE - i - 1][i] = i;
//	}
//	printf("\nMap 2:\n");
//	PrintArray(map2);
//}
//
//// Example: a test function for Task Two
//void TestInitialiseMap(void)
//{
//	int map1[MAP_SIZE][MAP_SIZE] = { 0 };
//	InitialiseMap(map1);
//	printf("\nMap: \n");
//	PrintArray(map1);
//}
//
//// Example: a test function for Task Three
//void TestAddRandomShip(void)
//{
//	int map1[MAP_SIZE][MAP_SIZE] = { 0 };
//	int map2[MAP_SIZE][MAP_SIZE] = { 0 };
//
//	AddRandomShip(5, map1);
//
//	printf("\nMap: 1\n");
//	PrintArray(map1);
//
//	int i = 0;
//	while (i < 100) {
//		AddRandomShip(2, map2);
//		AddRandomShip(3, map2);
//		AddRandomShip(4, map2);
//		AddRandomShip(5, map2);
//		i++;
//	}
//
//	printf("\nMap: 2\n");
//	PrintArray(map2);
//}
//
//void TestCountValues(void)
//{
//	int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	int count, shipSize;
//	InitialiseMap(map);
//	PrintArray(map);
//	for (shipSize = 2; shipSize <= 5; shipSize++) {
//		count = CountValues(shipSize, map);
//		printf("The value %d appears %d times\n", shipSize,
//			count);
//	}
//}
//
//void TestTopLeftPosition(void)
//{
//	int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	int row, col, direction, shipSize;
//	InitialiseMap(map);
//	PrintArray(map);
//	for (shipSize = 2; shipSize <= 5; shipSize++) {
//		direction = TopLeftPosition(shipSize, &row, &col, map);
//		printf("Ship %d is at (%d, %d) facing %d\n", shipSize,
//			row, col, direction);
//	}
//}
//
//void TestIsShipValid(void)
//{
//	/*int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	int valid, shipSize;
//	InitialiseMap(map);
//	PrintArray(map);
//	for (shipSize = 2; shipSize <= 5; shipSize++) {
//		valid = IsShipValid(shipSize, map);
//		printf("Is ship %d valid? %d\n", shipSize, valid);
//	}
//
//	int map2[MAP_SIZE][MAP_SIZE] = { 0 };
//	AddRandomShip(2, map2);
//	AddRandomShip(3, map2);
//	AddRandomShip(4, map2);
//	AddRandomShip(5, map2);
//
//	printf("\nMap 2: \n");
//	PrintArray(map2);
//
//	for (shipSize = 2; shipSize <= 5; shipSize++) {
//		valid = IsShipValid(shipSize, map2);
//		printf("Is ship %d valid? %d\n", shipSize, valid);
//	}*/
//
//	int valid, shipSize;
//	int map[7][7] = {
//	  {0, 0, 0, 0, 0, 0, 4},
//	  {0, 0, 0, 0, 0, 0, 4},
//	  {0, 0, 0, 0, 0, 0, 4},
//	  {0, 0, 0, 2, 0, 0, 4},
//	  {0, 0, 0, 2, 0, 0, 0},
//	  {5, 5, 5, 3, 5, 0, 0},
//	  {0, 0, 0, 0, 0, 0, 0}
//	};
//	for (shipSize = 2; shipSize <= 5; shipSize++) {
//		valid = IsShipValid(shipSize, map);
//		printf("Is ship %d valid? %d\n", shipSize, valid);
//	}
//
//}
//
//void TestInitialiseRandomMap(void)
//{
//	int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	InitialiseRandomMap(map);
//	PrintArray(map);
//}
//
//
//void TestFireShot(void)
//{
//	//int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	//int shots[MAP_SIZE][MAP_SIZE] = { 0 };
//	//InitialiseMap(map);
//	//printf("Map:\n");
//	//PrintArray(map);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//FireShot(shots, map, 2, 0);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//FireShot(shots, map, 2, 1);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//FireShot(shots, map, 2, 2);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//FireShot(shots, map, 2, 3);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//FireShot(shots, map, 0, 0);
//	//FireShot(shots, map, 1, 0);
//	//FireShot(shots, map, 2, 0);
//	//FireShot(shots, map, 3, 0);
//	//FireShot(shots, map, 4, 0);
//	//FireShot(shots, map, 5, 0);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//
//	int map[MAP_SIZE][MAP_SIZE] = {
//{3, 0, 0, 0, 0, 5},
//{3, 0, 2, 2, 0, 5},
//{3, 0, 0, 0, 0, 5},
//{0, 0, 0, 0, 0, 5},
//{0, 0, 0, 0, 0, 5},
//{4, 4, 4, 4, 0, 0}
//	};
//
//	int shots[MAP_SIZE][MAP_SIZE] = { 0 };
//	for (int i = 0; i < MAP_SIZE - 1; i++) {
//		for (int j = 0; j < MAP_SIZE; j++) {
//			FireShot(shots, map, i, j);
//		}
//	}
//
//	PrintArray(shots);
//}
//
//void TestCheckGameOver(void)
//{
//	//int map[MAP_SIZE][MAP_SIZE] = { 0 };
//	//int shots[MAP_SIZE][MAP_SIZE] = { 0 };
//	//InitialiseMap(map);
//	//printf("Map:\n");
//	//PrintArray(map);
//	//printf("Shots:\n");
//	//PrintArray(shots);
//	//while (!CheckGameOver(shots, map)) {
//	//	FireShot(shots, map, rand() % MAP_SIZE, rand() % MAP_SIZE);
//	//}
//	//PrintArray(shots);
//
//	//int map[MAP_SIZE][MAP_SIZE] = {
// // {0, 4, 4, 4, 4, 0, 2},
// // {0, 0, 0, 0, 0, 0, 2},
// // {3, 3, 3, 0, 0, 0, 0},
// // {0, 0, 0, 0, 0, 0, 0},
// // {0, 6, 6, 6, 6, 6, 6},
// // {0, 0, 0, 0, 0, 0, 0},
// // {0, 0, 5, 5, 5, 5, 5}
//	//};
//	//int shots[MAP_SIZE][MAP_SIZE] = {
//	//  {17, 4007, 4002, 4047, 4011, 31, 2025},
//	//  {5, 12, 32, 43, 41, 10, 2036},
//	//  {3013, 3033, 3023, 42, 30, 3, 21},
//	//  {34, 15, 27, 1, 40, 49, 28},
//	//  {24, 6037, 6035, 6038, 6029, 6014, 6046},
//	//  {16, 8, 20, 45, 39, 26, 22},
//	//  {9, 44, 5006, 5018, 5019, 5048, 5004}
//	//};
//	//printf("Game over? %d\n", CheckGameOver(shots, map));
//
//	int map[MAP_SIZE][MAP_SIZE] = {
//  {0, 4, 4, 4, 4, 0, 6},
//  {5, 0, 0, 0, 0, 0, 6},
//  {5, 0, 0, 0, 0, 0, 6},
//  {5, 0, 0, 0, 0, 0, 6},
//  {5, 0, 3, 3, 3, 0, 6},
//  {5, 0, 0, 0, 0, 0, 6},
//  {0, 0, 2, 2, 0, 0, 0}
//	};
//	int shots[MAP_SIZE][MAP_SIZE] = {
//	  {36, 4033, 4029, 4009, 4043, 19, 1013},
//	  {5023, 8, 11, 5, 25, 12, 1002},
//	  {5017, 10, 26, 41, 47, 40, 1035},
//	  {5031, 44, 1, 6, 30, 27, 1021},
//	  {5020, 3, 3028, 3022, 3038, 45, 0},
//	  {5015, 46, 24, 18, 32, 34, 1014},
//	  {4, 0, 2037, 2007, 39, 42, 16}
//	};
//	printf("Game over? %d\n", CheckGameOver(shots, map));
//}
//
//
//int main(void)
//{
//	// Initialise the seed for the random number generator
//	srand((unsigned int)time(NULL));
//
//	//TestPrintArray();
//	//TestInitialiseMap();
//	//TestAddRandomShip();
//	//TestCountValues();
//	//TestTopLeftPosition();
//	//TestIsShipValid();
//	//TestInitialiseRandomMap();
//	//TestFireShot();
//	TestCheckGameOver();
//
//	return 0;
//}