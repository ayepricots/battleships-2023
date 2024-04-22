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