#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include <iostream>
using namespace std;
#include <string>

class klient{ //utworzenie nowej klasy klient
	public:
	string imie;
	string nazwisko;
};

std::istream &operator>>(std::istream &strm, klient &Kli);
std::ostream& operator << (std::ostream &strm, const klient &Kli);

class kolejka{
	private:
		bool f; //czy w kolejce cos jest
		struct wezel{
			klient osoba;
			wezel *nastepny;
		};
	unsigned int poczatek, koniec; //początek i koniec kolejki 
	wezel *p,*k,*el; // element początkowy, końcowy, tymczasowy, 
	public:
		kolejka(){ //konstruktor kolejki
			poczatek=koniec=0;f=1;
			}
		~kolejka() //destruktor kolejki
		{
			while(koniec-poczatek>0){
				el = p;
				p = p->nastepny;
				delete el;
				++poczatek;	
			} 
			if(!f)
				delete p;
		}
		unsigned int rozmiar();//liczba elementów
		void dodaj(klient x);//dodanie elementu na koniec kolejki
		int usun();// usunięcie pierwszego elementu z kolejki i zwrócenie 1 gdy usunelo, a 0 gdy kolejka jest pusta
		klient pierwszy(); //pokazanie pierwszego elementu w kolejce
		klient ostatni();  //wyznaczenie ostatniego elementu w kolejce

};
#endif