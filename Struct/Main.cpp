#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

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
	int L = 0;

	for (int i = 0; i < N; i++)
	{
		if (!_CarDataBase[i].empty)
			L++;
	}

	return L;
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
	cout << "chcesz dodat cos do bazy" << endl;
	string temp;
	cin >> temp;
	if (temp != "n")
	{
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
			cout << "error w addtodatabase;" << endl;
	}
	
	
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

		if (temp == ">" && i + 1 <= N) {
			i++;
		}
		else {
			if (temp == "<" && i - 1 >= 0)
			{
				i--;
			}
			else {
				if (temp == "d")
				{
					_CarDataBase[i].empty = true;
				}
			}

		}
	} while (temp != "q");

}


//void SaveToFile(KomisStruct _CarDataBase[]) {
//	fstream plik("baza.txt", ios::out);
//	if (plik.good())
//	{
//		cout << "Uzyskano dostep do pliku!" << endl;
//		//plik << "Marka \t\t Model \t\t Cena \t\t Przebieg" << "\n";
//		plik.flush();
//		plik << CountBaseSize(_CarDataBase) << endl;
//		for (int i = 0; i < CountBaseSize(_CarDataBase); i++)
//		{
//			if (!_CarDataBase[i].empty) {
//				plik << _CarDataBase[i].Marka << endl;
//				plik << _CarDataBase[i].Model << endl;
//				plik << _CarDataBase[i].ProdYear << endl;
//				plik << _CarDataBase[i].Price << endl;
//			}
//
//			//plik << "\n";
//			plik.flush();
//		}
//		plik.close();
//		cout << "Saved to file" << endl;
//	}
//}
//
//void TrytoLoad(KomisStruct _CarDataBase[])
//{
//	int basesize;
//
//	fstream plik("baza.txt", ios::in);
//
//	if (plik.good())
//	{
//		cout << "Uzyskano dostep do pliku!" << endl;
//
//		plik >> basesize;
//		cout << basesize;
//		for (int j=0; j < basesize; j++)
//		{
//			_CarDataBase[j].empty = false;
//			plik >> _CarDataBase[j].Marka;
//			plik >> _CarDataBase[j].Model;
//			plik >> _CarDataBase[j].ProdYear;
//			plik >> _CarDataBase[j].Price;
//
//		}
//	}
//	plik.close();
//	cout<<"
//
//}


void TrytoLoad(KomisStruct _CarDataBase[])
{
	int basesize = 0;

	FILE *plik;
	plik = fopen("baza.txt", "r");
	if (plik!=NULL)
	{
		cout << "Uzyskano dostep do pliku!" << endl;

		fscanf(plik, "%d", basesize);

				for (int j=0; j < basesize; j++)
				{
					_CarDataBase[j].empty = false;
					fscanf(plik, "%s%s%d%d", _CarDataBase[j].Model, _CarDataBase[j].Marka, _CarDataBase[j].ProdYear, _CarDataBase[j].Price);
				}

	}
	fclose(plik);
	cout << "otworzono" << endl;
}

void SaveToFile(KomisStruct _CarDataBase[])
{

}

int main() {
	KomisStruct CarDataBase[N];
	KomisStruct Temp;

	TrytoLoad(CarDataBase);


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
