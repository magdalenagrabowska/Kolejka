
#include "kolejka.hh"
#include <iostream>
using namespace std;
#include <fstream>


int main()
{

    
	kolejka queue; //utworzenie kolejki
    ifstream wczyt;
    wczyt.open("nazwiska.txt");
	for(int i=0;i<2;i++){ //wczytanie dwoch przykladowych osob w kolejce
    klient jeden;
    wczyt>>jeden;
    queue.dodaj(jeden);
    }
    cout<<"Pierwsza osoba w kolejce "<<queue.pierwszy()<<endl;
    cout<<"Ostatnia osoba w kolejce "<<queue.ostatni()<<endl;
    cout<<"Ilosc osob w kolejce"<<queue.rozmiar()<<endl;
    queue.usun();
    cout<<"Pierwsza osoba w kolejce"<<queue.pierwszy()<<endl;
    cout<<"Ilosc osob w kolejce"<<queue.ostatni()<<endl;
    queue.usun();
    if(!queue.usun())
	cout<<"Kolejka jest pusta, nie ma nic do usuwania"<<endl;
    wczyt.close();
    return 0;
}