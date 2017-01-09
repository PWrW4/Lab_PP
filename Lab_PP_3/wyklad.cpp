#include <cstdlib>
//#include <malloc.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	int *wsk = NULL;
	wsk = (int*)malloc(sizeof(int));
	 
	cin >> *wsk;

	cout << *wsk;



	_getch();
	cin.get();
	return 0;
}