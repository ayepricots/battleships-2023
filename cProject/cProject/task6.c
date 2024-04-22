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