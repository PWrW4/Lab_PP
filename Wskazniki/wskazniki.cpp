#include <iostream>
#include <conio.h>

using namespace std;

bool prawda = true;
bool * wsk_bool;
int a = 0, d = 0;
long b;
char c;
int * wsk;


int	main() {

	wsk_bool = &prawda;
	
	cout << d << endl;

	for (int i = 0; i<10;i++) {
		cout << *(wsk_bool + i)<<endl;
}



	_getch();

	return 0;
}