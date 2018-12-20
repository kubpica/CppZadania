#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int ostatniacyfra(int liczba){
    while(liczba >= 10){
        liczba /= 10;
    }
    return liczba;
}

int pierwszacyfra(int liczba){
    return liczba % 10;
}

int main()
{

    ifstream liczby;
    ofstream wynik;
    liczby.open("liczby.txt");
    wynik.open("wynik.txt");
    int liczba;
    int ile = 0;

    while(liczby >> oct >> liczba){
        if(pierwszacyfra(liczba) == ostatniacyfra(liczba)) ile++;
    }

    wynik << dec << ile;
    liczby.close();
    wynik.close();

    return 0;
}
