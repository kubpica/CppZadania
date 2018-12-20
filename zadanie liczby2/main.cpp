#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int zmiananadec(int liczba){
    int wynik = 0;
    int power = 0;
    while(liczba != 0){
        wynik += liczba%10 * pow(8, power);
        liczba /= 10;
        power++;
    }
    return wynik;
}

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

    while(liczby >> liczba){
        int liczba_dec = zmiananadec(liczba);
        if(pierwszacyfra(liczba_dec) == ostatniacyfra(liczba_dec)) ile++;
    }

    wynik << ile;
    liczby.close();
    wynik.close();

    return 0;
}
