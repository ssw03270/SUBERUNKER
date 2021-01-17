#include "main.h"
#include "util.h"
#include "game.h"

int main() {
	init();
	while (1) {
		int selectedMenu = drawMenu();
		switch (selectedMenu) {
		case 0:
			drawMap();
			// game start
			break;
		case 1:
			drawInfo();
			break;
		case 2:
			// game end
			return 0;
		}
		system("cls");
	}
	return 0;
}


