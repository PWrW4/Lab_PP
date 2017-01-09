#include <iostream>
#include <conio.h>

#define N 5

using namespace std;

void ShowTab(double _tab[]) {

	cout << "wypisanie tablicy" << endl;
	for (int i = 0; i < N; i++) {
		cout << _tab[i] << "  ";
	}

}

void ReadTab(double _tab[]) {
	for (int i = 0; i < N; i++) {
		cin >> _tab[i];
	}
}


double Sum(double _tab[]) {
	double _sum=0;
	for (int i = 0; i < N; i++) {
		_sum += _tab[i];
	}
	return _sum;
}

double Srednia(double _tab[]) {
	double _sum = 0;
	for (int i = 0; i < N; i++) {
		_sum += _tab[i];
	}
	return _sum/N;
}


double Max(double _tab[]) {
	double _max = _tab[0];
	for (int i = 1; i < N; i++) {
		if (_tab[i]>_max)
		{
			_max = _tab[i];
		}		
	}
	return _max;
}

double Min(double _tab[]) {
	double _min = _tab[0];
	for (int i = 1; i < N; i++) {
		if (_tab[i]<_min)
		{
			_min = _tab[i];
		}
	}
	return _min;
}

void Kwadrat(double _tab[]) {
	double _kwadratTab[N];
	for (int i = 0; i < N; i++) {
		_kwadratTab[i] = _tab[i] * _tab[i];
	}
	ShowTab(_kwadratTab);
	cout << endl;
}

void ZliczElementy(double _tab[]) {
	int licznik=0;

	for (int i = 0; i < N; i++) {
		if (_tab>0)
		{
			licznik++;
		}
	}
	cout<<"Dodatnie: " << licznik<<endl;
	licznik = 0;

	for (int i = 0; i < N; i++) {
		if (_tab==0)
		{
			licznik++;
		}
	}
	cout << "Rowne 0: " << licznik << endl;
	licznik = 0;

	for (int i = 0; i < N; i++) {
		if (_tab>0)
		{
			licznik++;
		}
	}
	cout << "Ujemne: " << licznik << endl;
}

int man() {
	double Tabela[N];


	ReadTab(Tabela);
	ShowTab(Tabela);
	
	cout << "suma elementow tablicy:" << Sum(Tabela) << endl;
	cout << "srednia elementow tablicy: " << Srednia(Tabela) << endl;
	cout << "minimum elementow tablicy: " << Min(Tabela) << endl;
	cout << "maksimum elementow tablicy: " << Max(Tabela) << endl;
	cout << "kwadrat elementow tablicy: ";
	Kwadrat(Tabela);
	ZliczElementy(Tabela);

	_getch();
	return 0;
}