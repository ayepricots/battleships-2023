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
//				count = (shots[i][j] % 1000);
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
//				shots[row][j] = shots[row][j] + (size - 1) * 1000;
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
