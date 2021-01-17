#include "game.h"
#include "util.h"

int map[20][86];
int maxX = 85, maxY = 19;
int playerX = maxX / 2, playerY = maxY;
int enemyRandomX = maxX / 2, enemyRandomY = 0;

int keyControl() {
	char temp = _getch();

	// input key is arrow
	if (temp == 0) {
		switch (_getch()) {
		case 77:
			return LEFT;
		case 75:
			return RIGHT;
		}
	}
	else {
		switch (temp) {
		case '\t':
			return TAB;
		case '\r':
			return ENTER;
		}
	}

}

void drawInfo() {
	drawTitle();
	int x = 20, y = 12;
	int menuMode = 0;
	gotoxy(x, y);
	std::cout << "          MOVE : LEFT & RIGHT";
	gotoxy(x, y + 1);
	std::cout << "             CHANGE : TAB";
	gotoxy(x, y + 2);
	std::cout << "            SELECT : ENTER";
	gotoxy(x, y + 3);
	std::cout << "         DEVELOPER : TreeNest";
	gotoxy(x, y + 5);
	std::cout << "IF YOU PRESS ENTER KEY, GO TO MAIN MENU";

	while (1) {
		if (_getch() == '\r') {
			system("cls");
			return;
			// return to main menu
		}
	}
}

int drawMenu() {
	drawTitle();
	int x = 40, y = 12;
	int menuMode = 0;
	gotoxy(x - 2, y);
	std::cout << ">   START  ";
	gotoxy(x, y + 1);
	std::cout << "GAME INFO";
	gotoxy(x, y + 2);
	std::cout << "   END   ";

	while (1) {
		int inputNum = keyControl();
		switch (inputNum) {
		case 10:
			// input spacebar
			if (menuMode >= 2) {
				menuMode = 0;
			}
			else {
				menuMode += 1;
			}
			break;
		case 11:
			// select menu
			system("cls");
			return menuMode;
		}
		// reset menu
		for (int i = 0; i <= 2; i++) {
			gotoxy(x - 2, y + i);
			std::cout << "  ";
		}
		// set menu
		gotoxy(x - 2, y + menuMode);
		std::cout << "> ";

	}
}

void drawTitle() {
	std::cout << "\n\n\n\n";
	std::cout << "	 _____  _   _ ______  _____ ______  _   _  _   _  _   __ _____ ______ \n";
	std::cout << "	/  ___|| | | || ___ \\|  ___|| ___ \\| | | || \\ | || | / /|  ___|| ___ \\\n";
	std::cout << "	\\ `--. | | | || |_/ /| |__  | |_/ /| | | ||  \\| || |/ / | |__  | |_/ /\n";
	std::cout << "	 `--. \\| | | || ___ \|  __| |    / | | | || . ` ||    \\ |  __| |    / \n";
	std::cout << "	/\\__/ /| |_| || |_/ /| |___ | |\\ \\ | |_| || |\\  || |\\  \| |___ | |\\ \\ \n";
	std::cout << "	\\____/  \\___/ \\____/ \\____/ \\_| \\_| \\___/ \\_| \\_/\\_| \\_/\\____/ \\_| \\_|\n";

}

void drawMap() {

}