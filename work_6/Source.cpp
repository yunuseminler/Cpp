#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iomanip>

using namespace std;

char sahne[60][25];
char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;
void ustYazdir(int elemanSayisi) {

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
}
void altYazdir(int elemanSayisi) {
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose;
}
void koordinatAta(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sahneCiz() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 60; j++) {
			cout << sahne[j][i];
		}
		cout << endl;
	}
}
void sahneAta() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			sahne[j][i] = '@';
		}
	}
	for (int i = 15; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			sahne[j][i] = '@';
		}
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 35; j < 60; j++) {
			sahne[j][i] = '@';
		}
	}
	for (int i = 15; i < 25; i++) {
		for (int j = 40; j < 60; j++) {
			sahne[j][i] = '@';
		}
	}


}
void AdamCiz(int x, int y) {
	sahne[x][y] = 'o';
	sahne[x - 1][y + 1] = 47;
	sahne[x][y + 1] = 'O';
	sahne[x + 1][y + 1] = 92;
	sahne[x - 1][y + 2] = 47;
	sahne[x + 1][y + 2] = 92;

}
void kursoruGizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahneTemizle() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 60; j++) {
			sahne[j][i] = ' ';
		}
	}
}
void meyveYap(int a, int b) {
	sahne[a][b] = '$';
}
void skorCiz(string ad, int skor) {
	koordinatAta(70, 8);
	ustYazdir(18);
	koordinatAta(70, 9);
	cout << dikey << "Oyuncu :" << setw(10) << ad << dikey;
	koordinatAta(70, 10);
	cout << dikey << "  Skor :" << setw(10) << skor << dikey;
	koordinatAta(70, 11);
	altYazdir(18);
}
void silahyap(int x, int y, int sayac) {
	sahne[x][y] = '!';
	if (sayac == 3) {
		sahne[x][y - 1] = '3';
	}
	else if (sayac == 2) {
		sahne[x][y - 1] = '2';
	}
	else if (sayac == 1) {
		sahne[x][y - 1] = '1';
	}

}
void silahisin(int x, int y) {
	for (int i = 0; i < 24; i++) {
		sahne[x][i] = dikey;
	}
	sahne[x][y] = '!';
}
int main() {
	srand(time(0));
	kursoruGizle();
	int x = 25, y = 5;
	int a = rand() % 19 + 16;
	int b = rand() % 14;
	int silahx;
	int silahindex = 0;
	int silahy;
	int k;
	int sayac;
	int skor = 0;
	string ad;
	cout << setw(25) << "Fruit Rush" << endl << endl << "Isminizi Giriniz : ";
	cin >> ad;
	cout << endl << "                              Hosgeldin " << ad << endl << endl << "Oyundaki kullanabilecegin tuslar su sekildedir" << endl << "Yukari : W" << endl << " Asagi : S" << endl << "  Saga : D" << endl << "  Sola : A" << endl << endl;
	Sleep(1000);
	cout << "Oyunun amaci $ seklindeki meyveleri toplayarak en yuksek puana ulasmaktir. Lazerlere karsi dikkatli ol." << endl << endl;
	Sleep(1000);
	cout << "                                   Oyun Basliyor" << endl;
	Sleep(500);
	cout << "                                          3" << endl << endl;
	Sleep(500);
	cout << "                                          2" << endl << endl;
	Sleep(500);
	cout << "                                          1";
	Sleep(500);
	system("cls");
	while (1) {
		sahneTemizle();
		if (silahindex == 0) {
			sayac = 3;
			k = rand() % 2;
			silahx = rand() % 10 + 25;
			silahy = rand() % 25;
		}
		if (k == 1) {
			silahindex = 1;
			silahyap(silahx, silahy, sayac);

			if (sayac == 0) {
				silahisin(silahx, silahy);
				silahindex = 0;
			}
			sayac--;
		}
		meyveYap(a, b);
		sahneAta();
		AdamCiz(x, y);
		koordinatAta(0, 0);
		sahneCiz();
		skorCiz(ad, skor);

		while (1) {
			int a = getch();
			if (a == 119) {
				y--;
				break;
			}
			else if (a == 115) {
				y++;
				break;
			}
			else if (a == 100) {
				x++;
				break;
			}
			else if (a == 97) {
				x--;
				break;
			}
		}
		if (sahne[x][y] == '@') {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x - 1][y + 1] == '@') {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x + 1][y + 1] == '@') {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x - 1][y + 2] == '@') {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x + 1][y + 2] == '@') {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		if (sahne[x][y] == '$') {
			int c = rand() % 2;
			if (c == 0) {
				a = rand() % 15 + 20;
				b = rand() % 14;
			}
			else if (c == 1) {
				a = rand() % 15 + 25;
				b = rand() % 10 + 15;
			}
			sahneTemizle();
			meyveYap(a, b);
			sahneAta();
			skor++;
		}
		else if (sahne[x - 1][y + 1] == '$') {
			int c = rand() % 2;
			if (c == 0) {
				a = rand() % 15 + 20;
				b = rand() % 14;
			}
			else if (c == 1) {
				a = rand() % 15 + 25;
				b = rand() % 10 + 15;
			}
			sahneTemizle();
			meyveYap(a, b);
			sahneAta();
			skor++;
		}
		else if (sahne[x + 1][y + 1] == '$') {
			int c = rand() % 2;
			if (c == 0) {
				a = rand() % 15 + 20;
				b = rand() % 14;
			}
			else if (c == 1) {
				a = rand() % 15 + 25;
				b = rand() % 10 + 15;
			}
			sahneTemizle();
			meyveYap(a, b);
			sahneAta();
			skor++;
		}
		else if (sahne[x - 1][y + 2] == '$') {
			int c = rand() % 2;
			if (c == 0) {
				a = rand() % 15 + 20;
				b = rand() % 14;
			}
			else if (c == 1) {
				a = rand() % 15 + 25;
				b = rand() % 10 + 15;
			}
			sahneTemizle();
			meyveYap(a, b);
			sahneAta();
			skor++;
		}
		else if (sahne[x + 1][y + 2] == '$') {
			int c = rand() % 2;
			if (c == 0) {
				a = rand() % 15 + 20;
				b = rand() % 14;
			}
			else if (c == 1) {
				a = rand() % 15 + 25;
				b = rand() % 10 + 15;
			}
			sahneTemizle();
			meyveYap(a, b);
			sahneAta();
			skor++;
		}
		if (sahne[x][y] == dikey) {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x - 1][y + 1] == dikey) {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x + 1][y + 1] == dikey) {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x - 1][y + 2] == dikey) {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}
		else if (sahne[x + 1][y + 2] == dikey) {
			koordinatAta(70, 12);
			cout << "Oyun Bitti";
			Sleep(1000);
			koordinatAta(0, 26);
			return 0;
		}

	}


}
