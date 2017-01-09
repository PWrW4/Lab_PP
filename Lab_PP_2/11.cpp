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

void MoveTablica(int _tab[], int przesuniecie) {
	int tenmp[N];

	if (przesuniecie>0)
	{

	}

	for (int i = 0; i < N; i++)
	{
		_tab[i] = _tab[i + 1];
	}
	_tab[N - 1] = tenmp;

}

void ReadTab(int _tab[]) {
	for (int i = 0; i < N; i++) {
		cin >> _tab[i];
	}
}

int mai() {
	int Tabela[N];
	int przesuniecie;

	ReadTab(Tabela);
	ShowTab(Tabela);
	cout << "przesun tablice o:";
	cin >> przesuniecie;
	MoveTablica(Tabela);
	cout << endl;
	ShowTab(Tabela);


	_getch();
	return 0;
}