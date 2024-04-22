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
//				else {
//					return 2;
//				}
//
//			}
//		}
//	}
//}