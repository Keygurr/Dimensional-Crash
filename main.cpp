#include <iostream>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <windows.h> 
// headers?

using namespace std;

void gotoxy(int x, int y);
void pushX(int num);
void setLanguage();
void printTitleScreen();
void characterSelect();
void setScreenResolution(int x, int y);
void printLine(int x);
void printCharacter(int n);
void clearEntity();
void clearLine();

// Game config
string language;
bool charUnlocked_1 = false;
bool charUnlocked_2 = true;
struct character {
	string name;
	string hp;
	string mana;
	string attack;
	string def;
};

int main() {
	setScreenResolution(960, 720);
	setlocale(LC_ALL, "spanish");
	//setLanguage();
	//printTitleScreen();
	characterSelect();
}

// Utility functions
void gotoxy(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void clearEntity() {
	for (int i = 3; i < 25; i++) {
		gotoxy(0, i);
		cout << "                                                                                                                                ";
	}
}

void pushX(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

// Game functions
void setScreenResolution(int x, int y) {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 1000, 500, x, y, TRUE); }
}

void printTitleScreen() {
	int option = 0;
	bool over = false;
	int start = 0;
	for (int j = 0; j < 9; j++) {
	system("CLS");
	pushX(j);
	cout << "____   __ ___  ___  ____ __  __  __  __   ___   __  __  ___  __         ___ ____   ___   __  __  __" << endl;
	pushX(j);
	cout << "|| \\\\  || ||\\\\//|| ||    ||\\ || (( \\ ||  // \\\\  ||\\ || // \\\\ ||        //   || \\\\ // \\\\ (( \\ ||  ||" << endl;
	pushX(j);
	cout << "||  )) || || \\/ || ||==  ||\\\\||  \\\\  || ((   )) ||\\\\|| ||=|| ||       ((    ||_// ||=||  \\\\  ||==||" << endl;
	pushX(j);
	cout << "||_//  || ||    || ||___ || \\|| \\_)) ||  \\\\_//  || \\|| || || ||__|     \\\\__ || \\\\ || || \\_)) ||  ||" << endl;
	Sleep(100);
	}
	
}

void setLanguage() {
	int option = 0;
	int start = 0;
	int dash_x = 35;
	int dash_y = 12;
	bool gameover = false;
	language = "English";
	gotoxy(37, 10);
	cout << "    ,- -.   .-,--.         .        .   ";
	gotoxy(37, 11);
	cout << "   /  ,  \\   `\\__  ,-. ,-. |  . ,-. |-. ";
	gotoxy(39, 12);
	cout << " | '|  |    /    | | | | |  | `-. | | ";
	gotoxy(37, 13);
	cout << "   \\  `  /   '`--' ' ' `-| `' ' `-' ' ' ";
	gotoxy(37, 14);
	cout << "    `- -'               ,|              ";
	gotoxy(37, 15);
	cout << "                        `'";
	gotoxy(37, 19);
	cout << "    ,- -.   .-,--.              ~       .  ";
	gotoxy(37, 20);
	cout << "   / ,-, \\   `\\__  ,-. ,-. ,-. ,-. ,-. |  ";
	gotoxy(39, 21);
	cout << " |  /  |    /    `-. | | ,-| | | | | |  ";
	gotoxy(37, 22);
	cout << "   \\ '-` /   '`--' `-' |-' `-^ ' ' `-' `' ";
	gotoxy(37, 23);
	cout << "    `- -'              |                  ";
	gotoxy(37, 24);
	cout << "                       '";
	while (gameover != true) {
		if (start == 0) {
			gotoxy(dash_x, dash_y);
			cout << "--";
			start = 1;
		}
	if (_kbhit()) {
		char tecla = _getch();
		if (tecla == 'w') {
			gotoxy(dash_x, dash_y);
			cout << "  ";
			dash_y = 12;
			gotoxy(dash_x, dash_y);
			cout << "--";
			language = "English";
		}
		if (tecla == 's') {
			gotoxy(dash_x, dash_y);
			cout << "  ";
			dash_y = 21;
			gotoxy(dash_x, dash_y);
			cout << "--";
			language = "Español";;
		}
		if (tecla == 'k') {
			gameover = true;
		}
	}
	}
}

void clearLine() {
	gotoxy(0, 1);
	cout << "                                                                                                                                ";
	gotoxy(0, 1);
}

void characterSelect() {
	system("cls");
	int n = 0;
	setScreenResolution(838, 600);
	printLine(100);
	cout << endl;
	printLine(100);
	bool end = false;
	printCharacter(n);
	while (end != true) {
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'd') {
				n++;
				if (charUnlocked_1 != true && n == 2) {
					n = 1;
				}
				else if (charUnlocked_1 == true && n == 2) {
					n = 2;
				}
				else if (charUnlocked_2 != true && n == 3) {
					n = 2;
				}
				else if (charUnlocked_2 == true && (n == 3 || n == 2)) {
					n = 3;
				}
				if (n > 3) {
					n = 3;
				}
				cout << n;
			}
			if (tecla == 'a') {
				n--;
				if (charUnlocked_1 != true && n == 3 )
					n = 1;
				else if (charUnlocked_1 == true && n == 3)
						n = 2;
				if (n < 0){
					n = 0;
				}
					cout << n;
			}
			if (tecla == 'k') {
				end = true;
			}
			clearLine();
			pushX(26);
			switch (n) {
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "KNIGHT";
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "WIZARD";
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "SAMURAI";
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << "HOLD";
				break;
			default:
				cout << "???";
				break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			clearEntity();
			printCharacter(n);
		}
	}
}

void printLine(int x) {
	x -= 2;
	cout << "+";
	for (int i = 0; i < x; i++) {
		cout << "-";
	}
	cout << "+" << endl;
}

void printCharacter(int n) {
	gotoxy(0, 3);
	int x = 0;
	if (n == 0) {
		x = 37;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		pushX(x);
		cout << "      _,." << endl;
		pushX(x);
		cout << "    ,` -.)" << endl;
		pushX(x);
		cout << "   ( _/-\\\\-._" << endl;
		pushX(x);
		cout << "  /,|`--._,-^|            ," << endl;
		pushX(x);
		cout << "  \\_| |`-._/||          ,'|" << endl;
		pushX(x);
		cout << "    |  `-, / |         /  /" << endl;
		pushX(x);
		cout << "    |     || |        /  /" << endl;
		pushX(x);
		cout << "     `r-._||/   __   /  /  " << endl;
		pushX(x);
		cout << " __,-<_     )`-/  `./  /   " << endl;
		pushX(x);
		cout << "'  \\   `---'   \\   /  /    " << endl;
		pushX(x);
		cout << "    |           |./  /   " << endl;
		pushX(x);
		cout << "    /           //  /       " << endl;
		pushX(x);
		cout << "\\_/' \\         |/  /      " << endl;
		pushX(x);
		cout << " |    |   _,^-'/  /      " << endl;
		pushX(x);
		cout << " |    , ``  (\\/  /_" << endl;
		pushX(x);
		cout << "  \\,.->._    \\X-=/^" << endl;
		pushX(x);
		cout << "  (  /   `-._//^`  " << endl;
		pushX(x);
		cout << "   `Y-.____(__}" << endl;
		pushX(x);
		cout << "   |     {__)" << endl;
		pushX(x);
		cout << "          ()" << endl;
	}
	else if (n == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		x = 26;
		pushX(x);
		cout << "                       /    |" << endl;
		pushX(x);
		cout << "                      /     |" << endl;
		pushX(x);
		cout << "                     /      |" << endl;
		pushX(x);
		cout << "                    /       |" << endl;
		pushX(x);
		cout << "               ___,'        |" << endl;
		pushX(x);
		cout << "             <  -'          :" << endl;
		pushX(x);
		cout << "              `-.__..--'``-,_\\_" << endl;
		pushX(x);
		cout << "                 | / ` :,.)_`>" << endl;
		pushX(x);
		cout << "                 :/ `     ||/)" << endl;
		pushX(x);
		cout << "                 (_.).__,-` |\\" << endl;
		pushX(x);
		cout << "                 /( `.``   `| :" << endl;
		pushX(x);
		cout << "                 \\'`-.)  `  ; ;" << endl;
		pushX(x);
		cout << "                 | `       /-<" << endl;
		pushX(x);
		cout << "                 |     `  /   `." << endl;
		pushX(x);
		cout << " ,-_-..____     /|  `    :__..-'\\" << endl;
		pushX(x);
		cout << "/,'-.__\\\\  ``-./ :`      ;       \\" << endl;
		pushX(x);
		cout << "`\\ `\\  `\\\\  \\ :  (   `  /  ,   `. \\" << endl;
		pushX(x);
		cout << "  \\` \\   \\\\   |  | `   :  :     .\\ \\" << endl;
		pushX(x);
		cout << "   \\ `\\_  ))  :  ;     |  |      ): :" << endl;
		pushX(x);
		cout << "  (`-.-'\\ ||  |\\ \\   ` ;  ;       | |" << endl;
		pushX(x);
		cout << "   \\-_   `;;._   ( `  /  /_       | |" << endl;
		pushX(x);
		cout << "    `-.-.// ,'`-._\\__/_,'         ; |" << endl;
		pushX(x);
	}
	else if (n == 2) {
		x = 26;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		pushX(x);
		cout << "                       \\ \\" << endl;
		pushX(x);
		cout << "                        \\.\\" << endl;
		pushX(x);
		cout << "                         \\.\\" << endl;
		pushX(x);
		cout << "                          \\.\\  " << endl;
		pushX(x);
		cout << "                 _         \\.\\/)" << endl;
		pushX(x);
		cout << "            _ _-' ')__     (\\.\\/)" << endl;
		pushX(x);
		cout << "           /       /  \\.'`'-\\/)\\\\" << endl;
		pushX(x);
		cout << "           \\__ ,.-'(_  Y    (_\\.\\)" << endl;
		pushX(x);
		cout << "            / <     ,\\  \\    ,\\\\.\\\\" << endl;
		pushX(x);
		cout << "            \\_ \\ _. /y(_|    : |\\.\\|" << endl;
		pushX(x);
		cout << "             _\\_\\\\   |       : | \\.\\" << endl;
		pushX(x);
		cout << "            (   `'-._>/ )     \\|  \\.\\" << endl;
		pushX(x);
		cout << "            \\         `:=.    (\\   \\.\\" << endl;
		pushX(x);
		cout << "             \\_      (    `--._)`--'\\.\\=7" << endl;
		pushX(x);
		cout << "            _/|\\_    \\-._     `-:_ /```-3    " << endl;
		pushX(x);
		cout << "           /  |  `-   \\  t--._    Y    _3 " << endl;
		pushX(x);
		cout << "        ,-'   |       /  |   /``'-.\\--T x\\" << endl;
		pushX(x);
		cout << "      _/     _(    ,./  /   (          \\ x\\" << endl;
		pushX(x);
		cout << "         _.-/  \\  /    <     \\          \\ x\\" << endl;
		pushX(x);
		cout << "      <`'  /   |\/      `-.   :          \\_x\\" << endl;
		pushX(x);
		cout << "       \\  /    |           `. |" << endl;
		pushX(x);
		cout << "        \\_|    /             `." << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}