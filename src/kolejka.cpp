#include "kolejka.hh"

std::istream &operator>>(std::istream &strm, klient &Kli){ //funkcja umożliwiająca wczytanie do systemu klientów, przeciążenie wyjścia
strm>>Kli.imie>>Kli.nazwisko;
if(strm.fail()) //jeżeli coś pójdzie nie tak, wysyłany jest odpowiedni komunikat
strm.setstate(std::ios::failbit);
return strm;
}

std::ostream& operator << (std::ostream &strm, const klient &Kli){ //funkcja umożliwiająca wypisanie klientów, przeciążenie wyjścia
strm<<Kli.imie<<" "<<Kli.nazwisko<<" ";
if(strm.fail())
strm.setstate(std::ios::failbit);
return strm;
}

unsigned int kolejka::rozmiar(){
	return koniec-poczatek;
	}
void kolejka::dodaj(klient x)//dodanie elementu na koniec kolejki
		{
			if(f)//jesli pierwszy element wrzucamy do kolejki
			{
				k = new wezel;    //stworzenie ostatniego elementu 
				k -> osoba = x; //przypisanie wartosci do elementu ostatniego
				p = new wezel; 		//utworzenie pierwszego elementu 
				p -> nastepny = k;  //element pierwszy wskazuje na ostatni
				f = 0;
			}
			else
			{
				el = new wezel;    //stworzenie nowego elementu kolejki
				el -> osoba = x;	//przypisanie wartosci do nowego elementu kolejki
				k -> nastepny = el;	//ostatni do tej pory element wskazuje na utworzony
				k = el;				//element utworzony staje się ostatnim
			}
			++koniec;
		}

int kolejka::usun()// usunięcie pierwszego elementu z kolejki i zwrócenie 1 gdy usunelo, a 0 gdy kolejka jest pusta
		{
			if(koniec-poczatek==0)return 0; //gdy nie ma nic w kolejce zwracamy 0
			el = p;
			p = p->nastepny; //przejscie na następny element kolejki
			delete el;		//usunięcie pierwszego elementu w kolejce
			++poczatek;
      return 1;
		}		
klient kolejka::pierwszy() //pokazanie pierwszego elementu w kolejce
		{
			return p->nastepny->osoba;
		}
klient kolejka::ostatni() //wyznaczenie ostatniego elementu w kolejce
		{
			return k->osoba;
		}	