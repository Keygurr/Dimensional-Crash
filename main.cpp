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
void setScreenResolution();


// Game config
string language;

int main() {
	setScreenResolution();
	setlocale(LC_ALL, "spanish");
	setLanguage();
	printTitleScreen();
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

void pushX(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

// Game functions
void setScreenResolution() {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 1000, 500, 960, 720, TRUE); }
}

void printTitleScreen() {
	int option = 0;
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

void characterSelect() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "                       /    |" << endl;
	cout << "                      /     |" << endl;
	cout << "                     /      |" << endl;
	cout << "                    /       |" << endl;
	cout << "               ___,'        |" << endl;
	cout << "             <  -'          :" << endl;
	cout << "              `-.__..--'``-,_\\_" << endl;
	cout << "                 | / ` :,.)_`>" << endl;
	cout << "                 :/ `     ||/)" << endl;
	cout << "                 (_.).__,-` |\\" << endl;
	cout << "                 /( `.``   `| :" << endl;
	cout << "                 \\'`-.)  `  ; ;" << endl;
	cout << "                 | `       /-<" << endl;
	cout << "                 |     `  /   `." << endl;
	cout << " ,-_-..____     /|  `    :__..-'\\" << endl;
	cout << "/,'-.__\\\\  ``-./ :`      ;       \\" << endl;
	cout << "`\\ `\\  `\\\\  \\ :  (   `  /  ,   `. \\" << endl;
	cout << "  \\` \\   \\\\   |  | `   :  :     .\\ \\" << endl;
	cout << "   \\ `\\_  ))  :  ;     |  |      ): :" << endl;
	cout << "  (`-.-'\\ ||  |\\ \\   ` ;  ;       | |" << endl;
	cout << "   \\-_   `;;._   ( `  /  /_       | |" << endl;
	cout << "    `-.-.// ,'`-._\\__/_,'         ; |" << endl;
	cout << "       \\:: :     /     `     ,   /  |" << endl;
	cout << "        || |    (        ,' /   /   |" << endl;
	cout << "        ||                ,'   /    |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}