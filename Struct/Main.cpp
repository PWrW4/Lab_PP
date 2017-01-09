#include <string>
#include <iostream>
#include <fstream>

#define N 100

using namespace std;


struct KomisStruct
{
	bool empty;
	string Marka;
	string Model;
	int ProdYear;
	int Price;

	KomisStruct() {
		empty = true;
	}
};


int CountBaseSize(KomisStruct _CarDataBase[]) {
	int L=0;

	for (int i = 0; i < N; i++)
	{
		if (!_CarDataBase[i].empty)
			L++;
	}

	return L;
}


void SaveToFile(KomisStruct _CarDataBase[]) {
	fstream plik("baza.txt", ios::out);
	if (plik.good())
	{
		plik << "Marka \t\t Model \t\t Cena \t\t Przebieg" << "\n";
		plik.flush();
		cout << CountBaseSize(_CarDataBase) << endl;
		for (int i = 0; i < N; i++)
		{
			if (!_CarDataBase[i].empty)
			{
				plik << _CarDataBase[i].Marka << " \t\t";
				plik << _CarDataBase[i].Marka << " \t\t";
				plik << _CarDataBase[i].ProdYear << " \t\t";
				plik << _CarDataBase[i].Price;
			}

			plik << "\n";
			plik.flush();
		}
		plik.close();
		cout << "Saved to file" << endl;
	}
}




int SearchForEmpty(KomisStruct _CarDataBase[]) {
	for (int i = 0; i < N; i++)
	{
		if (_CarDataBase[i].empty) {
			return i;
		}
	}

	return -1;
}




void AddCarToDataBase(KomisStruct _CarDataBase[]) {
	int i = SearchForEmpty(_CarDataBase);
	cout << i;
	if (i != -1) {

		cout << "Marka" << endl;
		cin >> _CarDataBase[i].Marka;

		cout << "Model" << endl;
		cin >> _CarDataBase[i].Model;

		cout << "ProdYear" << endl;
		cin >> _CarDataBase[i].ProdYear;

		cout << "Price" << endl;
		cin >> _CarDataBase[i].Price;

		_CarDataBase[i].empty = false;



		cout << "Car Added" << endl;

	}
	else
		cout << "error;" << endl;
}


void ShowDataBase(KomisStruct _CarDataBase[], int i) {

	cout << i;

	if (!_CarDataBase[i].empty) {
		cout << "Marka" << endl;
		cout << _CarDataBase[i].Marka << endl;

		cout << "Model" << endl;
		cout << _CarDataBase[i].Model << endl;

		cout << "ProdYear" << endl;
		cout << _CarDataBase[i].ProdYear << endl;

		cout << "Price" << endl;
		cout << _CarDataBase[i].Price << endl;
	}

}

void ViewDataBase(KomisStruct _CarDataBase[]) {
	int i = 0;
	string temp;
	do {

		ShowDataBase(_CarDataBase, i);

		cin >> temp;

		if (temp == ">" && i+1<=N) {
			i++;
		}
		else {
			if (temp == "<" && i-1 >= 0)
			{
				i--;
			}
			else {
				if(temp == "d")
				{
					_CarDataBase[i].empty = true;
				}
			}

		}
	} while (temp != "q");
	
}






int main() {
	KomisStruct CarDataBase[N];
	KomisStruct Temp;

	while (true)
	{
		AddCarToDataBase(CarDataBase);
		cout << endl << endl;
		ViewDataBase(CarDataBase);
		cout << endl << endl;
		SaveToFile(CarDataBase);
	}

	cin.get();
	return 0;
}