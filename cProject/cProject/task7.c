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
