#include <iostream>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include<windows.h> 

// headers?
using namespace std;
void menu();
void characterselect();

int main() {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 960, 720, TRUE); }
	menu();
	characterselect();
}

void menu() {
	int option = 0;
	cout << "      _ _                          _                                  _     " << endl;
	cout << "   __| (_)_ __ ___   ___ _ __  ___(_) ___  _ __     ___ _ __ __ _ ___| |__  " << endl;
	cout << "  / _` | | '_ ` _ \\ / _ \\ '_ \\/ __| |/ _ \\| '_ \\   / __| '__/ _` / __| '_ \\ " << endl;
	cout << " | (_| | | | | | | |  __/ | | \\__ \\ | (_) | | | | | (__| | | (_| \\__ \\ | | |" << endl;
	cout << "  \\__,_|_|_| |_| |_|\\___|_| |_|___/_|\\___/|_| |_|  \\___|_|  \\__,_|___/_| |_|" << endl << endl;
	cout << "(1) Un jugador\n(2) Dos jugadores";
	cin >> option;
	switch (option) {
	case 1:
		cout << "";
		break;
	case 2:
		cout << "(1) Un jugador\n(2) Dos jugadores";
		break;
	}
}

void characterselect() {
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
}