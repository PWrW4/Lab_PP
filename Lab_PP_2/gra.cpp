//Wójcik Wojciech
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

//String to int-internet
int strToInt(string s)
{
	int tmp = 0, i = 0;
	bool m = false;
	if (s[0] == '-') {
		m = true;
		i++;
	}
	for (; i < s.size(); i++)
		tmp = 10 * tmp + s[i] - 48;
	return m ? -tmp : tmp;
}

int sprawdzanie(int kik[20][15]) {
	int spr = 0, idwa, jdwa;
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 19; j++) {
			//lewo-prawo
			if (j <= 15 && (kik[j][i] == 1 || kik[j][i] == -1)) {
				idwa = i;
				jdwa = j;
				do {
					spr++;
					jdwa++;
					if (spr == 5) return kik[j][i];
				} while ((kik[jdwa][idwa] == 1 || kik[jdwa][idwa] == -1) && (kik[j][i] == kik[jdwa][idwa]));
				spr = 0;
			}
			//gora-dol
			if (i <= 10 && (kik[j][i] == 1 || kik[j][i] == -1)) {
				idwa = i;
				jdwa = j;
				do {
					spr++;
					idwa++;
					if (spr == 5) return kik[j][i];
				} while ((kik[jdwa][idwa] == 1 || kik[jdwa][idwa] == -1) && (kik[j][i] == kik[jdwa][idwa]));
				spr = 0;
			}
			//lukos-prawo
			if ((i <= 10 && j <= 15) && (kik[j][i] == 1 || kik[j][i] == -1)) {
				idwa = i;
				jdwa = j;
				do {
					spr++;
					idwa++;
					jdwa++;
					if (spr == 5) return kik[j][i];
				} while ((kik[jdwa][idwa] == 1 || kik[jdwa][idwa] == -1) && (kik[j][i] == kik[jdwa][idwa]));
				spr = 0;
			}
			//lukos-lewo
			if ((i >= 4 && j >= 4) && (kik[j][i] == 1 || kik[j][i] == -1)) {
				idwa = i;
				jdwa = j;
				do {
					spr++;
					idwa++;
					jdwa--;
					if (spr == 5) return kik[j][i];
				} while ((kik[jdwa][idwa] == 1 || kik[jdwa][idwa] == -1) && (kik[j][i] == kik[jdwa][idwa]));
				spr = 0;
			}
		}
	}
	return 0;
}

void rysowanie(int kik[20][15]) {
	char wierszchar[7] = { 'W','I','E','R','S','Z','E' };
	int liczbawierszy = 0, wieszwypisz = 0;

	//Nag³ówek
	cout << endl << endl;
	cout << "                          K O L U M N Y" << endl << endl;
	cout << "           |1|2|3|4|5|6|7|8|9|1|1|1|1|1|1|1|1|1|2|2|" << endl;
	cout << "           | | | | | | | | | |0|1|2|3|4|5|6|7|8|9|0|" << endl;
	cout << "           | | | | | | | | | | | | | | | | | | | | |" << endl;
	cout << "       ----+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+----" << endl;

	//i-wiersze j-kolumny
	for (int i = 0; i <= 14; i++) {
		//Numerowanie Wierszy
		liczbawierszy++;
		if (liczbawierszy<10) {
			cout << "         " << i + 1 << " |";
		}
		else cout << "        " << i + 1 << " |";

		//Rysowanie wierszy
		for (int j = 0; j <= 19; j++) {
			if (kik[j][i] == 1) { cout << "X"; }
			else if (kik[j][i] == -1) { cout << "O"; }
			else { cout << " "; }
			cout << "|";
		}
		cout << endl;

		//Wypisywanie "WIERSZE"
		if ((liczbawierszy>3) && (wieszwypisz<7)) {
			cout << "     " << wierszchar[wieszwypisz] << " ";
			wieszwypisz++;
		}
		else cout << "       ";
		//Linia oddzielajaca wiersze
		cout << "----+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+----" << endl;
	}

	//Stopka
	cout << "           | | | | | | | | | | | | | | | | | | | | |" << endl;
	cout << "           |1|2|3|4|5|6|7|8|9|1|1|1|1|1|1|1|1|1|2|2|" << endl;
	cout << "           | | | | | | | | | |0|1|2|3|4|5|6|7|8|9|0|" << endl << endl;
	cout << "                          K O L U M N Y" << endl << endl;
}

void czyczczeniekik(int kik[20][15]) {
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 19; j++) {
			kik[j][i] = 0;
		}
	}
}

void wpisywaniekik(int kik[20][15], long int &kolumna, long int &wiersz, int &plusiminus, int &znak, string gracz1, string gracz2) {
	string str;
	if (plusiminus == 1)cout << gracz1 << " wykonuje ruch." << endl;
	else cout << gracz2 << " wykonuje ruch." << endl;
	goto pierwszyraz;
	do {
		if (kik[kolumna][wiersz] == 1 || kik[kolumna][wiersz] == -1) {
			system("cls");
			rysowanie(kik);
			cout << endl << "To pole nie jest puste" << endl << endl;
			if (plusiminus == 1)cout << gracz1 << " wykonuje ruch." << endl;
			else cout << gracz2 << " wykonuje ruch." << endl;
		}
	pierwszyraz:
		kolumna = 1;
		wiersz = 1;
		do {
			if ((wiersz <= 0) || (wiersz >= 16))cout << "Zly nr wiersza!" << endl;
			cout << "Podaj nr. Wiersza:";
			cin >> str;
			wiersz = strToInt(str);
			if ((wiersz == 66989) || (wiersz == 31437)) {
				znak = 66989;
				goto menu;
			}
			else znak = 0;
		} while ((wiersz <= 0) || (wiersz >= 16));
		wiersz -= 1;
		cout << endl;
		do {
			if ((kolumna <= 0) || (kolumna >= 21))cout << "Zly nr kolumny!" << endl;
			cout << "Podaj nr. Kolumny:";
			cin >> str;
			kolumna = strToInt(str);
			if ((kolumna == 66989) || (kolumna == 31437)) {
				znak = 66989;
				goto menu;
			}
			else znak = 0;
		} while ((kolumna <= 0) || (kolumna >= 21));
		kolumna -= 1;
		cout << endl;
	} while (kik[kolumna][wiersz] == 1 || kik[kolumna][wiersz] == -1);
	kik[kolumna][wiersz] = 1 * plusiminus;
	plusiminus *= -1;
menu:
	system("cls");
}

void pomoc() {
	system("cls");
	cout << "tu sie pomaga" << endl;
	getchar();
	cin.get();
	system("cls");
}

//debugowanie
void wypisywaniekikdebug(int kik[20][15]) {
	int debug = 0;
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 19; j++) {
			cout << kik[j][i];
			debug++;
		}
	}
	cout << endl;
	cout << debug;
	cout << endl;
}



int main() {
	//      K   W
	int kik[20][15];
	long int kolumna = 0, wiersz = 0;
	int znak = 66989, plusiminus = 1, casee = 0;
	string gracz1 = "Gracz Pierwszy", gracz2 = "Gracz Drugi", grac;
	//system("mode 80");
	czyczczeniekik(kik);
	do {
		if (znak == 66989) { grac = "1.Kontynuuj gre!"; }
		else { grac = "1.GRAJ!!!"; }
		if ((znak == 66989)) {
			cout << grac << endl << "2.Wprowadz nazwe graczy" << endl << "3.Restart gry" << endl << "4.Pomoc" << endl << "5.Zakoncz gre" << endl << endl << "WSKAZOWKA:Aby wybrac dana opcje wpisz jej numer i nacisnij 'enter'" << endl;
		}
		else {
			cout << grac << endl << "2.Wprowadz nazwe graczy" << endl << "3.Pomoc" << endl << "4.Zakoncz gre" << endl << endl << "WSKAZOWKA:Aby wybrac dana opcje wpisz jej numer i nacisnij 'enter'" << endl;
		}
		cin >> casee;
		system("cls");
		switch (casee) {
		case 1:
			do {
				rysowanie(kik);
				wpisywaniekik(kik, kolumna, wiersz, plusiminus, znak, gracz1, gracz2);
				// sprawdzaniewin(kik);
				if (sprawdzanie(kik) == 1 || sprawdzanie(kik) == -1) {
					casee = 1;
					if (plusiminus == 1) {
						do {
							if (casee != 1)cout << "Zle polecenie!!!" << endl;
							cout << gracz2 << " wygral!" << endl << endl;
							cout << "1.Zobacz plansze" << endl << "2.Powrot do MENU" << endl;
							cin >> casee;
							if (casee == 1) {
								system("cls");
								rysowanie(kik);
								getchar();
								cin.get();
								system("cls");
							}
							else znak = 66989;
						} while (casee != 2);
					}

					if (plusiminus = -1) {
						do {
							if (casee != 1)cout << "Zle polecenie!!!" << endl;
							cout << gracz2 << " wygral!" << endl << endl;
							cout << "1.Zobacz plansze" << endl << "2.Powrot do MENU" << endl;
							cin >> casee;
							if (casee == 1) {
								system("cls");
								rysowanie(kik);
								getchar();
								cin.get();
								system("cls");
							}
							else {
								znak = 66989;
								system("cls");
							}
						} while (casee != 2);
					}
					czyczczeniekik(kik);
				}
			} while (znak != 66989);
			znak = 0;
			break;
		case 2:
			cout << "Nazwa gracza pierwszego:" << endl;
			cin >> gracz1;
			cout << endl << "Nazwa gracza drugiego:" << endl;
			cin >> gracz2;
			cout << endl;
			system("cls");
			cout << "Nazwy zmienione!" << endl;
			break;
		case 3:
			if (znak == 66989) {
				czyczczeniekik(kik);
				system("cls");
				cout << "Gra zrestartowana!" << endl;
				znak = 1;
				plusiminus = 1;
				break;
			}
			else {
				pomoc();
				break;
			}
		case 4:
			if (znak == 66989) {
				pomoc();
				break;
			}
			else {
				goto koniec;
				break;
			}

		case 5:
			goto koniec;
			break;
		}

	} while (1>0);
koniec:

	//           Debugi
	//wpisywaniekik(kik,kolumna,wiersz);
	//rysowanie();
	//wypisywaniekikdebug(kik);
	//cout<<kolumna<<endl<<wiersz;
	//cin.sync();
	//cin.get();
	return 0;
}

