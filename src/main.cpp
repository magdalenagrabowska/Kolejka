#include<iostream>
using namespace std;
#include<fstream>
#include<cstdlib>
#include "kolejka.hh"

int main()
{
	srand(time(NULL)); //zmienna potrzebna do wygenerowania losowej liczby osób dołączających do kolejki
	int liczba; //początkowa liczba osób w kolejce
    int odp; //zmienna przechowująca odpowiedź czy zająć się klientem w banku
    int osob_kolejki=0; //zmienna przechowująca ilość osób w kolejce

	kolejka queue; //utworzenie kolejki
	cout<<"Witamy pracownika banku Miłe Chwile"<<endl;
	cout<<"podaj poczatkowa liczbe osob w kolejce"<<endl;
	cin>>liczba;
    
	ifstream wczyt;
    wczyt.open("nazwiska.txt"); //wczytanie początkowej liczby osób w kolejce (dane z pliku)
	for(int i=0;i<liczba;i++){
	klient tmp; //utworzenie tymczasowej klasy klient aby wczytac klientow do kolejki
	wczyt>>tmp;
	queue.dodaj(tmp); 
    osob_kolejki++;
	if(cin.fail()){ //postępowanie w wyniku błędu wczytywania
       cout<<"Blad sie wkradl"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
	}
	}
	while(osob_kolejki!=0){
    cout<<"Pierwsza osoba w kolejce: "<<queue.pierwszy()<<endl; 
    cout<<"Liczba osób w kolejce: "<<queue.rozmiar()<<endl; //wyświetlanie liczby osób w kolejce
    cout<<"Czy chcesz obsłużyć pierwszą osobę w kolejce? 1 to tak, 0 to nie"<<endl;
    cin>>odp;
    if(odp==1)
	{queue.usun();
    osob_kolejki--;
    cout<<"osob w kolejce "<<osob_kolejki<<endl;}
    else if (odp==0){
	cout<<"osoba nadal czeka"<<endl;
	}
	else{
	cout<<"Nierozpoznana wartość. Proszę spróbować ponownie"<<endl;		
	}
    if(cin.fail()){ //postępowanie w wyniku błędu wczytywania
    cout<<"Masz blad!"<<endl;
	cin.clear();
    cin.ignore(1000, '\n');
    } 
    int los_liczba=(rand()%4); //wygenerowanie losowej liczby osób dołączających się do kolejki (liczba od 0 do 4)
	
	if(los_liczba>0 && osob_kolejki<10){ //warunek losowej liczby osób i maksymalnej liczby osób w kolejce
	cout<<"do kolejki dołączyło: "<<los_liczba<<" osób"<<endl;
	for(int i=0;i<los_liczba;i++){
		if(wczyt.eof()){ //postępowanie w wyniku skończenia się danych w pliku z danymi
		wczyt.close();
		wczyt.open("nazwiska.txt");
		}
	klient tmp; //utworzenie tymczasowej klasy klient aby wczytac klientow do kolejki
	wczyt>>tmp;
	queue.dodaj(tmp); 
    osob_kolejki++;
	if(cin.fail()){
       cout<<"Blad sie wkradl"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
	    }
	  }
	}
	else if (los_liczba==0 || osob_kolejki>=10){
		cout<<"Nikt nie dołączył do kolejki"<<endl;
	}
    }
	if(!queue.usun()) //postępowanie, gdy nikogo nie będzie w kolejce
	{cout<<"Kolejka jest pusta, nie ma nic do usuwania"<<endl;
	}
    wczyt.close(); //zamknięcie pliku 
	return 0;
}