//#include <iostream>
//
//#define N 100
//
//using namespace std;
//
//
//void zamiana(char * Tab,char * wzor,char * zastapienie);
//
//int main() {
//
//	//char CharTab[N];
//
//
//	zamiana("ala ma kota","ma","asd");
//
//	cin.get();
//	return 0;
//}	
//
//void zamiana(char * Tab, char * wzor, char * zastapienie) {
//	bool continuum = true;
//	int wzorL=0;
//	char * Tablica = Tab;
//	
//	for (; *wzor!='\0' ; wzor++)
//	{
//		wzorL++;
//	}
//
//	
//	cout << "test" << endl;
//	while (*Tab!='\0')
//	{
//		if (*wzor == *Tab)
//		{
//			cout << "stest" << endl;
//			bool znalezione = false;
//			for (int i = 1; i<=wzorL ; i++) {
//				if (*wzor + i != *Tab +i)
//				{
//					break;
//				}
//				else
//				{
//					znalezione = true;
//				}
//				
//			}
//
//			if (znalezione) {
//				for (;wzorL>=0; wzorL--)
//				{
//					*(Tab + wzorL) = *(zastapienie + wzorL);
//				}
//			}
//
//		}		
//		*Tab++;
//	}
//
//	cout << Tablica;
//	
//}