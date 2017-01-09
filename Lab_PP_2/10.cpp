#include <iostream>
#include <conio.h>

#define N 5

using namespace std;

void ShowTab(int _tab[]) {

	cout << "wypisanie tablicy" << endl;
	for (int i = 0; i < N; i++) {
		cout << _tab[i] << "  ";
	}

}

void MoveTablica(int _tab[]) {
	int tenmp = _tab[0];
	for (int i = 0; i < N; i++)
	{
		_tab[i] = _tab[i + 1];
	}
	_tab[N-1] = tenmp;

}

void ReadTab(int _tab[]) {
	for (int i = 0; i < N; i++) {
		cin >> _tab[i];
	}
}

int maina() {
	int Tabela[N];


	ReadTab(Tabela);
	ShowTab(Tabela);
	MoveTablica(Tabela);
	cout << endl;
	ShowTab(Tabela);


	_getch();
	return 0;
}